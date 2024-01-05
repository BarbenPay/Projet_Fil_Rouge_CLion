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

bool isWordAUnite(char* word){
    return isWordInDict(word, "../Dictionnaire/unite_FR.txt");
}

bool isWordANegation(char* word){
    return isWordInDict(word, "../Dictionnaire/negation_FR.txt");
}

int wordType (char* word){ //-1. Rien / 1. Mouvement Forward / 2. Nombre / 3. Unité
    if(isWordAMovementWord(word)){
        char* toSend = (char*) malloc(sizeof (char) * (68 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Verbe de mouvement vers l'avant trouvé.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 1;
    }else if(isWordANumber(word)){
        char* toSend = (char*) malloc(sizeof (char) * (43 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Nombre trouvé.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 2;
    }else if(isWordAUnite(word)){
        char* toSend = (char*) malloc(sizeof (char) * (43 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Unité trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 3;
    }else if (isWordANegation(word)){
        char* toSend = (char*) malloc(sizeof (char) * (58 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Négation potentielle trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 4;
    }else{
        char* toSend = (char*) malloc(sizeof (char) * (45 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Mot non reconnu.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return -1;
    }
}

wordTypeStruct* init_wordTypeStruct(){
    wordTypeStruct* res = (wordTypeStruct*) malloc(sizeof(wordTypeStruct));
    if (res == NULL){
        log_file("Regroupement.c --- Erreur d'allocation de mémoire pour wordTypeStruct.");
        exit(EXIT_FAILURE);
    }
    res->typeWord = -2;
    res->word = NULL;
    return res;
}

wordTypeStruct** sentenceToWordTypeArray(Phrase* phrase){
    log_file("Regroupement.c --- Démarrage de l'analyse de la phrase.");
    wordTypeStruct** res = (wordTypeStruct**) malloc(sizeof (wordTypeStruct*) * phrase->wordNumber );
    if (res == NULL){
        log_file("Regroupement.c --- Erreur d'allocation de mémoire pour wordTypeStruct dans sentenceToWordTypeArray.");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < phrase->wordNumber; i++){
        res[i] = init_wordTypeStruct();
        res[i]->typeWord = wordType(phrase->wordArray[i]);
        res[i]->word = phrase->wordArray[i];
        if(res[i]->typeWord==-2){
            log_file("Regroupement.c --- Erreur dans l'initialisation de la valeur typeWord.");
            exit(EXIT_FAILURE);
        }
    }
    log_file("Regroupement.c --- Analyse correctement effectuée.");
    return res;
}

