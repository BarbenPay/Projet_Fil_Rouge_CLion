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

typedef struct sentenceTypeStruct{
    wordTypeStruct** words;
    int numberOfWord;
}sentenceTypeStruct;

typedef struct sentencesStruct{
    sentenceTypeStruct** sentences;
    int numberOfSentence;
}sentencesStruct;


bool isWordInDict(char* word, char* dict); // Définit si le mot est dans le dictionnaire passé en paramètre

bool isWordAForwardMovementWord(char* word, int code_language);//Définit si le mot est un verbe de mouvement vers l'avant

bool isWordABackwardMovementWord(char* word, int code_language);//Définit si le mot est un verbe de mouvement vers l'arrière

bool isWordAMovementWord(char*word, int code_language);

bool isWordANumber(char* word, int code_language); // Définit si le mot est un nombre

bool isWordAMeterUnite(char* word, int code_language); // Définit si le mot représente le mot "Mètre"

bool isWordACentimeterUnite(char* word, int code_language); // Définit si le mot représente le mot "Centimètre"

bool isWordADegreeUnite(char* word, int code_language);

bool isWordAnObject(char* word, int code_language);

bool isWordANegation(char* word, int code_language); // Définit si le mot est un mot de négation

bool isWordARotationWord(char* word, int code_language); // Définit si le mot est un verbe de rotation

bool isWordABackwardDirection(char* word, int code_language);

bool isWordAForwardDirection(char* word, int code_language);

bool isWordALeftDirection(char* word, int code_language);

bool isWordARightDirection(char* word, int code_language);

int wordType(char* word, int code_language); // Renvoie le code du type du mot

wordTypeStruct* init_wordTypeStruct(); // Initialise une structure wordTypeStruct

sentenceTypeStruct* init_sentenceTypeStruct();

sentencesStruct* init_sentencesStruct();

sentencesStruct* sentencesToAnalysedSentencesTab(Phrase* phrase, int code_language); // Analyse de la phrase et renvoie une structure composé du nombre de phrase et de la chaine de caractère du mot




#endif //PROJET_FIL_ROUGE_CLION_REGROUPEMENT_H
