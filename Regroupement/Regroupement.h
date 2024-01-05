//
// Created by Jean-Baptiste Salanie on 30/12/2023.
//

#ifndef PROJET_FIL_ROUGE_CLION_REGROUPEMENT_H
#define PROJET_FIL_ROUGE_CLION_REGROUPEMENT_H

#include <stdbool.h>
#include <stdio.h>
#include"../Découpage/Decoupage.h"



typedef struct wordtype{
    int typeWord;
    char* word;
}wordTypeStruct;


bool isWordInDict(char* word, char* dict); // Définit si le mot est dans le dictionnaire passé en paramètre

bool isWordAForwardMovementWord(char* word);//Définit si le mot est verbe de mouvement vers l'avant

bool isWordABackwardMovementWord(char* word);//Définit si le mot est un verbe de mouvement vers l'arrière

bool isWordANumber(char* word); // Définit si le mot est un nombre

bool isWordAUnite(char* word); // Définit si le mot est une unité

bool isWordANegation(char* word); // Définit si le mot est un mot de négation

int wordType(char* word); // Renvoie le code du type du mot

wordTypeStruct* init_wordTypeStruct(); // Initialise une structure wordTypeStruct

wordTypeStruct** sentenceToWordTypeArray(Phrase* phrase); // Analyse de la phrase et renvoie un tableau de la structure composé du code et de la chaine de caractère du mot




#endif //PROJET_FIL_ROUGE_CLION_REGROUPEMENT_H
