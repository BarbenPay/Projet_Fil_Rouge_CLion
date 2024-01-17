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

void viderBuffer();
Valeur input();
void choix_langue();
void choix_test(Valeur);
void traitement_commande(Valeur langue);
void traitement_image();

#endif //PROJET_FIL_ROUGE_CLION_MENU_H
