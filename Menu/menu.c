//
// Created by mc2 on 09/01/24.
//
#include <stdio.h>
#include "menu.h"
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

int choix_langue()
{
    int l;
    printf("\nSélectioner la langue : \n\nFrançais : 1 \nEnglish : 2 \n\n");
    scanf("%d", &l);
    while(l != 1 && l != 2)
    {
        printf("\nSélection incorecte, essayer encore : \n\n");
        viderBuffer();
        scanf("%d", &l);
    }
    return l;
}

int choix_test(int l)
{
    if (l == 1)
    {
        printf("\nSélectioner ce que vous voulez tester : \n\nTraitement d'image : 3 \nTraitement de commande : 4 \n\n");
    }
    else
    {
        printf("\nSelect what you want to test : \n\nImage processing : 3 \nOrder processing : 4 \n\n");
    }
    int t;
    scanf("%d", &t);
    while (t != 3 && t != 4)
    {
        if (l == 1)
        {
            printf("\nSélection incorrecte, essayer encore : \n\n");
        }
        else
        {
            printf("\nIncorrect selection, try again : \n\n");
        }
        viderBuffer();
        scanf("%d", &t);
    }
    return t;
}

void traitement_commande(int langue)
{
    char phrase[100];
    if (langue == 1) {
        printf("\nSaissez votre commande : \n\n");
    }
    else
    {
        printf("\nEnter your order : \n\n");
    }
    viderBuffer();
    fgets(phrase, 100, stdin);
    Phrase* res;
    res = decoupage(phrase);
    for (int i = 0; i<res->wordNumber; i++)
    {
        printf("%s\n", res->wordArray[i]);
    }
    wordTypeStruct ** typeWord;
    typeWord = sentenceToWordTypeArray(res, langue);
    for(int i = 0; i<res->wordNumber;i++)
    {
        printf("Le mot %s est de type %d\n",typeWord[i]->word, typeWord[i]->typeWord);
    }
    analyse(typeWord,res);

    free(res);
    free(typeWord);
}