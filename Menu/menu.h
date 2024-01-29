//
// Created by mc2 on 09/01/24.
//

#ifndef PROJET_FIL_ROUGE_CLION_MENU_H
#define PROJET_FIL_ROUGE_CLION_MENU_H


typedef struct valeur
{
    char inputTab[100];
    int languageCode;
}inputWithLanguageChoice;

inputWithLanguageChoice input();
void choix_langue();
void choix_test(inputWithLanguageChoice);
char * choixImage(inputWithLanguageChoice);
void traitement_commande(inputWithLanguageChoice);
void traitement_image(inputWithLanguageChoice);

#endif //PROJET_FIL_ROUGE_CLION_MENU_H
