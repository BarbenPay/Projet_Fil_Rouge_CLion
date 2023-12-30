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


bool isWordInDict(char* word, char* dict);


bool isWordAMovementWord(char* word);
bool isWordANumber(char* word);
int wordType(char* word);
wordTypeStruct* init_wordTypeStruct();
wordTypeStruct** sentenceToWordTypeArray(Phrase* phrase);




#endif //PROJET_FIL_ROUGE_CLION_REGROUPEMENT_H
