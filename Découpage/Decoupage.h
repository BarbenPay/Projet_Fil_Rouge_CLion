//
// Created by Jean-Baptiste Salanie on 28/12/2023.
//

#ifndef PROJET_FIL_ROUGE_CLION_DECOUPAGE_H
#define PROJET_FIL_ROUGE_CLION_DECOUPAGE_H



typedef struct etStruct{
    int wordNumber;
    char** wordArray;
} Phrase;

Phrase * init_Sentence();
Phrase * decoupage (char* phrase);

#endif //PROJET_FIL_ROUGE_CLION_DECOUPAGE_H
