//
// Created by mc2 on 09/01/24.
//
#include <stdio.h>
#include <string.h>
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

Valeur choix_langue()
{
    printf("\nSélectioner la langue : \n\nFrançais : 1 \nEnglish : 2 \n\n");
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
    return l;
}

Valeur choix_test(Valeur l)
{
    if (l.i == 1)
    {
        printf("\nSélectioner ce que vous voulez tester : \n\nTraitement d'image : 1 \nTraitement de commande : 2 \n\n");
    }
    else
    {
        printf("\nSelect what you want to test : \n\nImage processing : 1 \nOrder processing : 2 \n\n");
    }
    Valeur v;
    input(v);
    while (strcmp((const char *) v.c, "1") != 0 && strcmp((const char *) v.c, "2") != 0)
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
    }
    else
    {
        v.i = 2;
    }
    return v;
}

void traitement_commande(const char * langue)
{
    char phrase[100];
    if (langue == "1") {
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
    int num_langue;
    if (strcmp((const char *) langue, "1") == 0)
    {
        num_langue = 1;
    }
    else
    {
        num_langue = 2;
    }
    typeWord = sentenceToWordTypeArray(res, num_langue);
    for(int i = 0; i<res->wordNumber;i++)
    {
        printf("Le mot %s est de type %d\n",typeWord[i]->word, typeWord[i]->typeWord);
    }
    analyse(typeWord,res);

    free(res);
    free(typeWord);
}