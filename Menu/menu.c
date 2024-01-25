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


void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

Valeur input() {
    Valeur l;
    fgets(l.c, 100, stdin);
    int len = strlen(l.c);
    if (len > 0 && l.c[len - 1] == '\n')
    {
        l.c[len - 1] = '\0';
    }
    return l;
}

void choix_langue()
{
    printf("\nSélectionez la langue : \n\nFrançais : 1 \nEnglish : 2 \n\n");
    Valeur l = input();
    while(strcmp((const char *) l.c, "1") != 0 && strcmp((const char *) l.c, "2") != 0)
    {
        printf("\nSélection incorecte, essayer encore : \n\n");
        l = input();
    }
    if(strcmp((const char *) l.c, "1") == 0)
    {
        l.i = 1;
    }
    else
    {
        l.i = 2;
    }
    choix_test(l);
}

void choix_test(Valeur l)
{
    if (l.i == 1)
    {
        printf("\nSélectionez ce que vous voulez tester : \n\nTraitement d'image : 1 \nTraitement de commande : 2 \n\nRetour : 3 \n\n");
    }
    else
    {
        printf("\nSelect what you want to test : \n\nImage processing : 1 \nOrder processing : 2 \n\nBack : 3 \n\n");
    }
    Valeur v;
    v = input();
    while (strcmp((const char *) v.c, "1") != 0 && strcmp((const char *) v.c, "2") != 0 && strcmp((const char *) v.c, "3") != 0)
    {
        if (l.i == 1)
        {
            printf("\nSélection incorrecte, essayer encore : \n\n");
        }
        else
        {
            printf("\nIncorrect selection, try again : \n\n");
        }
        v = input();
    }
    if(strcmp((const char *) v.c, "1") == 0)
    {
        v.i = 1;
        traitement_image();
    }
    else if(strcmp((const char *) v.c, "2") == 0)
    {
        v.i = 2;
        traitement_commande(l);
    }
    else
    {
        choix_langue();
    }
}

void traitement_commande(Valeur l)
{
    Valeur v;
    if (l.i == 1) {
        printf("\nSaissez votre commande : \n\n");
    }
    else
    {
        printf("\nEnter your order : \n\n");
    }
    v = input();
    Phrase* res;
    res = decoupage(v.c);
    for (int i = 0; i<res->wordNumber; i++)
    {
        printf("%s\n", res->wordArray[i]);
    }
    sentencesStruct* typeWord;
    typeWord = sentencesToAnalysedSentencesTab(res, l.i);

    freePhrase(res);

    for(int indexPhrase = 0; indexPhrase < typeWord->numberOfSentence; indexPhrase++)
    {
        for (int i = 0; i < typeWord->sentences[indexPhrase]->numberOfWord; i++) {
            printf("Le mot %s est de type %d\n", typeWord->sentences[indexPhrase]->words[i]->word , typeWord->sentences[indexPhrase]->words[i]->typeWord);
        }
    }
    for(int indexPhrase = 0; indexPhrase < typeWord->numberOfSentence; indexPhrase++)
    {
        analyse(typeWord->sentences[indexPhrase]);
    }

    freeStructures(typeWord);

    Valeur p;
    printf("\nNouvelle commande : 1 \nRetour : 2 \n\n");
    p = input();
    while(strcmp((const char *) p.c, "1") != 0 && strcmp((const char *) p.c, "2") != 0)
    {
        if (l.i == 1)
        {
            printf("\nSélection incorrecte, essayer encore : \n\n");
        }
        else
        {
            printf("\nIncorrect selection, try again : \n\n");
        }
        p = input();
    }
    if(strcmp((const char *) p.c, "1") == 0)
    {
        traitement_commande(l);
    }
    else
    {
        choix_test(l);
    }

}

void traitement_image()
{

    structObject* res = imageTreatmentCalling("../Image/Banque/IMG_20.txt");

    freeObjectStruct(res);

}