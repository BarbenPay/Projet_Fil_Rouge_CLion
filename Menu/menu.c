//
// Created by mc2 on 09/01/24.
//
#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "../Image/header.h"
#include "../Découpage/Decoupage.h"
#include "../Log/fichier_Log.h"
#include "../Regroupement/Regroupement.h"
#include "../Analyse_Phrase/Analyse.h"

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

    free(res);
    free(typeWord);

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
    FILE* picture = fopen("../Image/banque/IMG_5389.txt", "r");
    int largeur = -1;
    int longueur = -1;
    int dimension = -1;
    fscanf(picture,"%d %d %d",&largeur,&longueur,&dimension);
    int*** matrice = (int***)malloc(largeur * sizeof(int**));
    for(int i = 0; i < largeur; i++){
        matrice[i] = (int**)malloc(longueur * sizeof(int*));
        for (int j = 0; j < longueur; j++){
            matrice[i][j]=(int*)malloc(sizeof(int)* dimension);
        }
    }


    for(int i = 0; i<largeur;i++) {
        for (int j = 0; j < dimension; j++) {
            for (int v = 0; v < longueur; v++) {
                fscanf(picture, "%d", &matrice[i][v][j]);
            }
        }
    }
    objet tab[10];
    int compteur_objet=0;
    int* p= &compteur_objet;
    if(largeur > 400|| longueur > 400){
        printf("l'image est trop volumineuse");
    }
    if(dimension != 3){
        printf("la photo n'est pas en couleur");
    }
    remplirMatriceImage(matrice,largeur,longueur);
    bin_pixel(matrice,largeur,longueur);
    saturation(matrice,largeur,longueur);
    quantification(matrice,longueur,largeur,tab,p);
    for (int i=0;i<compteur_objet;i++){
        objet* tempon = &tab[i];
        donner_position(tempon,largeur);
        verif_objet(tempon);
        nature_objet(tempon,matrice);
        encadrement(matrice, longueur, largeur,tempon);
    }
    //sortie_image(image_origine,longueur,largeur,dimmention);
    if(compteur_objet != 0){
        for(int x=0;x<compteur_objet;x++){
            objet* tempon2 =&tab[x];
            sortie_objet(tempon2,compteur_objet);
        }
    }
    else{printf("pas d'objet dans l'image\n");}
    printf("%d,%d",compteur_objet,*p);
}