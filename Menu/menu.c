//
// Created by mc2 on 09/01/24.
//

#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "../Découpage/Decoupage.h"
#include "../Log/logFile.h"
#include "../Regroupement/Regroupement.h"
#include "../Analyse_Phrase/Analyse.h"
#include "../Image/imageTreatmentCalling.h"


bool verif(char c, inputWithLanguageChoice v) {
    char * liste[50] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20"};
    for(int i = 0; i < c; i ++)
    {
        if(strcmp((const char *) v.inputTab, (const char *) liste[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

inputWithLanguageChoice input() {
    inputWithLanguageChoice res;
    fgets(res.inputTab, 100, stdin);
    int len = (int)strlen(res.inputTab);
    if (len > 0 && res.inputTab[len - 1] == '\n')
    {
        res.inputTab[len - 1] = '\0';
    }
    return res;
}

void choix_langue()
{
    printf("\nSélectionez la langue : \n\nFrançais : 1 \nEnglish : 2 \n\n");
    inputWithLanguageChoice buffer = input();
    while(!verif(2, buffer))
    {
        printf("\nSélection incorecte, essayer encore : \n\n");
        buffer = input();
    }
    if(strcmp((const char *) buffer.inputTab, "1") == 0)
    {
        buffer.languageCode = 1;
    }
    else
    {
        buffer.languageCode = 2;
    }
    choix_test(buffer);
}

void choix_test(inputWithLanguageChoice inputBuffer)
{
    if (inputBuffer.languageCode == 1)
    {
        printf("\nSélectionez ce que vous voulez tester : \n\nTraitement d'image : 1 \nTraitement de commande : 2 \n\nRetour : 3 \n\n");
    }
    else
    {
        printf("\nSelect what you want to test : \n\nImage processing : 1 \nOrder processing : 2 \n\nBack : 3 \n\n");
    }

    inputWithLanguageChoice newBuffer = input();
    while (!verif(3, inputBuffer))
    {
        if (inputBuffer.languageCode == 1)
        {
            printf("\nSélection incorrecte, essayer encore : \n\n");
        }
        else
        {
            printf("\nIncorrect selection, try again : \n\n");
        }
        newBuffer = input();
    }
    if(strcmp((const char *) newBuffer.inputTab, "1") == 0)
    {
        newBuffer.languageCode = 1;
        traitement_image(inputBuffer);
    }
    else if(strcmp((const char *) newBuffer.inputTab, "2") == 0)
    {
        newBuffer.languageCode = 2;
        traitement_commande(inputBuffer);
    }
    else
    {
        choix_langue();
    }
}

void traitement_commande(inputWithLanguageChoice inputBuffer)
{
    if (inputBuffer.languageCode == 1) {
        printf("\nSaissez votre commande : \n\n");
    }
    else
    {
        printf("\nEnter your order : \n\n");
    }
    inputWithLanguageChoice sentenceToSendToAnalysis = input();
    Phrase* res;
    res = decoupage(sentenceToSendToAnalysis.inputTab);
#ifdef DEBUG
    for (int i = 0; i<res->wordNumber; i++)
    {
        printf("%s\n", res->wordArray[i]);
    }
#endif
    sentencesStruct* typeWord;
    typeWord = sentencesToAnalysedSentencesTab(res, inputBuffer.languageCode);

    freePhrase(res);
#ifdef DEBUG
    for(int indexPhrase = 0; indexPhrase < typeWord->numberOfSentence; indexPhrase++)
    {
        for (int i = 0; i < typeWord->sentences[indexPhrase]->numberOfWord; i++) {
            printf("Le mot %s est de type %d\n", typeWord->sentences[indexPhrase]->words[i]->word , typeWord->sentences[indexPhrase]->words[i]->typeWord);
        }
    }
#endif
    for(int indexPhrase = 0; indexPhrase < typeWord->numberOfSentence; indexPhrase++)
    {
        analyse(typeWord->sentences[indexPhrase], inputBuffer);
    }

    freeStructures(typeWord);

    printf("\nNouvelle commande : 1 \nRetour : 2 \n\n");
    inputWithLanguageChoice newBuffer = input();
    while(strcmp((const char *) newBuffer.inputTab, "1") != 0 && strcmp((const char *) newBuffer.inputTab, "2") != 0)
    {
        if (inputBuffer.languageCode == 1)
        {
            printf("\nSélection incorrecte, essayer encore : \n\n");
        }
        else
        {
            printf("\nIncorrect selection, try again : \n\n");
        }
        newBuffer = input();
    }
    if(strcmp((const char *) newBuffer.inputTab, "1") == 0)
    {
        log_file("\n");
        traitement_commande(inputBuffer);
    }
    else
    {
        log_file("\n");
        choix_test(inputBuffer);
    }

}

char * choixImage(inputWithLanguageChoice inputBuffer)
{
    if (inputBuffer.languageCode == 1) {
        printf("\nPour choisir l'image à traiter, entrez un nombre entre 1 et 20 : \n\n");
    }
    else
    {
        printf("\nTo choose the image to process, enter a number between 1 and 20 : \n\n");
    }

    inputWithLanguageChoice imageNumber = input();
    while (!verif(20, imageNumber)) {
        if (inputBuffer.languageCode == 1) {
            printf("\nSélection incorrecte, essayer encore : \n\n");
        } else {
            printf("\nIncorrect selection, try again : \n\n");
        }
        imageNumber = input();
    }

    char * image = (char*)malloc(27 * sizeof(char));
    strcpy(image, "../Image/Banque/IMG_");

    if (verif(9, imageNumber)) {
        strcat(image, "0");
    }
    strcat(image, imageNumber.inputTab);
    strcat(image, ".txt");

    return image;
}

void traitement_image(inputWithLanguageChoice languageChoice)
{
    char* imageAdress = choixImage(languageChoice);
    structObject* res = imageTreatmentCalling(imageAdress);
#ifdef DEBUG
    for (int i = 0; i < res->counter; i ++){
        printf("Objet n %d \n",i+1);
        printf("Limite gauche= %d \n",res->objectTab[i]->coor_G);
        printf("Limite droite= %d \n",res->objectTab[i]->coor_D);
        printf("Limite haute= %d \n",res->objectTab[i]->coor_H);
        printf("Limite bas= %d \n",res->objectTab[i]->coor_B);
        printf("Couleur = %c \n",res->objectTab[i]->couleur);
        printf("Nature = %c \n",res->objectTab[i]->nature);
        printf("Position = %c \n",res->objectTab[i]->position);
    }
#endif
    free(imageAdress);
    freeObjectStruct(res);

    printf("\nNouvelle image : 1 \nRetour : 2 \n\n");
    inputWithLanguageChoice newBuffer = input();
    while(!verif(2, newBuffer))
    {
        if (languageChoice.languageCode == 1)
        {
            printf("\nSélection incorrecte, essayer encore : \n\n");
        }
        else
        {
            printf("\nIncorrect selection, try again : \n\n");
        }
        newBuffer = input();
    }
    if(strcmp((const char *) newBuffer.inputTab, "1") == 0)
    {
        traitement_image(languageChoice);
    }
    else
    {
        choix_test(languageChoice);
    }
}