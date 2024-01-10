//
// Created by mc2 on 09/01/24.
//

#ifndef PROJET_FIL_ROUGE_CLION_MENU_H
#define PROJET_FIL_ROUGE_CLION_MENU_H

#include "../Découpage/Decoupage.h"
#include "../Log/fichier_Log.h"
#include "../Regroupement/Regroupement.h"
#include "../Analyse_Phrase/Analyse.h"

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
void traitement_commande(Valeur);

#endif //PROJET_FIL_ROUGE_CLION_MENU_H
