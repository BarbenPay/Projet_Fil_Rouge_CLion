//
// Created by Jean-Baptiste Salanie on 30/12/2023.
//

#include "Regroupement.h"
#include "../Log/fichier_Log.h"


bool isWordInDict(char* word, char* dict){
    FILE* dictionnaire = fopen(dict, "r"); //on ouvre le dictionnaire

    if (dictionnaire == NULL) { //Si le programme n'arrive pas à ouvrir le dictionnaire, il renvoie une erreur sur le fichier log
        char* toSend = "Regroupement.c --- Erreur lors de l'ouverture du dictionnaire: ";
        strcat(toSend, dict);
        log_file(toSend);
        free(toSend);
        return false;
    }

    char tampon[30];  // Taille de la chaine de cractère temporaire pour stocker les différents mots du dictionnaire
    bool isFound = false;


    while (fscanf(dictionnaire, "%s", tampon) == 1) { //lire chaque mot dans le dictionnaire et le stocker dans tampon
        if (strcmp(tampon, word) == 0) { //Si tampon et le mot cherché sont égaux
            isFound = true;
            break;  // on sort de la boucle dès que le mot est trouvé
        }
    }

    // Fermer le fichier de dictionnaire
    fclose(dictionnaire);

    return isFound;

}

bool isWordAMovementWord(char* word){
    return isWordInDict(word, "../Dictionnaire/Forward_movement_FR.txt");
}

bool isWordANumber(char* word){
    return isWordInDict(word, "../Dictionnaire/number_FR.txt");
}

int wordType (char* word){ //-1. Rien / 1. Mouvement / .2. Nombre
    if(isWordAMovementWord(word)){
        return 1;
    }else if(isWordANumber(word)){
        return 2;
    }else{
        return -1;
    }
}

wordTypeStruct* init_wordTypeStruct(){
    wordTypeStruct* res = (wordTypeStruct*) malloc(sizeof(wordTypeStruct));
    res->typeWord = -2;
    res->word = NULL;
    return res;
}

wordTypeStruct** sentenceToWordTypeArray(Phrase* phrase){
    wordTypeStruct** res = (wordTypeStruct**) malloc(sizeof (wordTypeStruct*) * phrase->wordNumber );
    for(int i = 0; i < phrase->wordNumber; i++){
        res[i] = init_wordTypeStruct();
        res[i]->typeWord = wordType(phrase->wordArray[i]);
        res[i]->word = phrase->wordArray[i];
        if(res[i]->typeWord==-2){

        }
    }

    return res;
}