//
// Created by mc2 on 09/01/24.
//

#ifndef PROJET_FIL_ROUGE_CLION_MENU_H
#define PROJET_FIL_ROUGE_CLION_MENU_H


typedef struct valeur
{
    char c[100];
    int i;
}
Valeur;

Valeur input();
void choix_langue();
void choix_test(Valeur);
char * choixImage(Valeur);
void traitement_commande(Valeur);
void traitement_image(Valeur);

#endif //PROJET_FIL_ROUGE_CLION_MENU_H
