//
// Created by Jean-Baptiste Salanie on 30/12/2023.
//

#include "Regroupement.h"
#include "../../Log/fichier_Log.h"


bool isWordInDict(char* word, char* dict){
    FILE* dictionnaire = fopen(dict, "r"); //on ouvre le dictionnaire

    if (dictionnaire == NULL) { //Si le programme n'arrive pas à ouvrir le dictionnaire, il renvoie une erreur sur le fichier log

        char* toSend = (char*)malloc(sizeof(char)*(64+ strlen(dict)));
        strcpy(toSend, "Regroupement.c --- Erreur lors de l'ouverture du dictionnaire: ");
        strcat(toSend, dict);
        log_file(toSend);
        free(toSend);
        exit(EXIT_FAILURE);
    }

    char tampon[30];  // Taille de la chaine de caractère temporaire pour stocker les différents mots du dictionnaire
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

bool isWordABackwardMovementWord(char* word, int code_language) {
    if (code_language == 1) {
        return isWordInDict(word, "../Transcription/Dictionnaire/FR/Mouvement/backward_movement.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Transcription/Dictionnaire/EN/Mouvement/backward_movement.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordABackwardMovementWord.");
        exit(EXIT_FAILURE);
    }
}

bool isWordAForwardMovementWord(char* word, int code_language){
    if(code_language == 1) {
        return isWordInDict(word, "../Transcription/Dictionnaire/FR/Mouvement/forward_movement.txt");
    }else if(code_language == 2){
        return isWordInDict(word, "../Transcription/Dictionnaire/EN/Mouvement/forward_movement.txt");
    }else{
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordAForwardMovementWord.");
        exit(EXIT_FAILURE);
    }
}

bool isWordARotationWord(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Transcription/Dictionnaire/FR/Mouvement/rotation.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Transcription/Dictionnaire/EN/Mouvement/rotation.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordARotationWord.");
        exit(EXIT_FAILURE);
    }
}

bool isWordAMovementWord(char*word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Transcription/Dictionnaire/FR/Mouvement/movement.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Transcription/Dictionnaire/EN/Mouvement/movement.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordAMovementWord.");
        exit(EXIT_FAILURE);
    }
}

bool isWordANumber(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Transcription/Dictionnaire/FR/Nombre/number.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Transcription/Dictionnaire/EN/Number/number.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordANumber.");
        exit(EXIT_FAILURE);
    }
}

bool isWordAUnite(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Transcription/Dictionnaire/FR/Unite/unite.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Transcription/Dictionnaire/EN/Unite/unite.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordAUnite.");
        exit(EXIT_FAILURE);
    }
}

bool isWordAnObject(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Transcription/Dictionnaire/FR/Objet/objet.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Transcription/Dictionnaire/EN/Object/object.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordAnObject.");
        exit(EXIT_FAILURE);
    }
}

bool isWordANegation(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Transcription/Dictionnaire/FR/Negation/negation.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Transcription/Dictionnaire/EN/Negation/negation.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordANegation.");
        exit(EXIT_FAILURE);
    }
}



bool isWordABackwardDirection(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Transcription/Dictionnaire/FR/Direction/backward_direction.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Transcription/Dictionnaire/EN/Direction/backward_direction.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordABackwardDirection.");
        exit(EXIT_FAILURE);
    }
}

bool isWordAForwardDirection(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Transcription/Dictionnaire/FR/Direction/forward_direction.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Transcription/Dictionnaire/EN/Direction/forward_direction.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordAForwardDirection.");
        exit(EXIT_FAILURE);
    }
}

bool isWordALeftDirection(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Transcription/Dictionnaire/FR/Direction/left_direction.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Transcription/Dictionnaire/EN/Direction/left_direction.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordALeftDirection.");
        exit(EXIT_FAILURE);
    }
}

bool isWordARightDirection(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Transcription/Dictionnaire/FR/Direction/right_direction.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Transcription/Dictionnaire/EN/Direction/right_direction.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordARightDirection.");
        exit(EXIT_FAILURE);
    }
}

// -1 : RIEN
//  0 : NEGATION
//  1 : NOMBRE
//  2 : MOUVEMENT
//  21 : AVANT   // 22 : ARRIERE   // 23 : ROTATION
                                   // 231 : GAUCHE   // 232 : DROITE
//  3 : DIRECTION
//  31 : CUBE   // 32 : BOULE   // 23 : POSITION
                                // 231 : GAUCHE   // 232 : MILIEU   //  233 : DROITE
//  4 : UNITE

// Code // -1. Rien / 1. backward_movement / 2. forward_movement / 3. rotating_movement / 4. movement / 10. forward_direction /
// 11. backward_direction / 12. right_direction / 13. left_direction / 20. number / 30. object / 40. negation / 50. unite
int wordType (char* word, int code_language){
    if(isWordABackwardMovementWord(word, code_language)) {
        char *toSend = (char *) malloc(sizeof(char) * (58 + strlen(word)));
        strcpy(toSend, "Regroupement.c --- Verbe de mouvement vers l'arrière trouvé.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 1;
    }else if(isWordAForwardMovementWord(word, code_language)){
        char* toSend = (char*) malloc(sizeof (char) * (68 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Verbe de mouvement vers l'avant trouvé.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 2;
    }else if(isWordARotationWord(word, code_language)){
        char* toSend = (char*) malloc(sizeof (char) * (54 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Verbe de rotation trouvé.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 3;
    }else if(isWordAMovementWord(word, code_language)){
        char* toSend = (char*) malloc(sizeof (char) * (55 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Verbe de mouvement trouvé.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 4;
    }else if(isWordAForwardDirection(word, code_language)) {
        char *toSend = (char *) malloc(sizeof(char) * (60 + strlen(word)));
        strcpy(toSend, "Regroupement.c --- Direction vers l'avant trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 10;
    }else if(isWordABackwardDirection(word, code_language)) {
        char *toSend = (char *) malloc(sizeof(char) * (62 + strlen(word)));
        strcpy(toSend, "Regroupement.c --- Direction vers l'arrière trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 11;
    }else if(isWordARightDirection(word, code_language)) {
        char *toSend = (char *) malloc(sizeof(char) * (62 + strlen(word)));
        strcpy(toSend, "Regroupement.c --- Direction vers la droite trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 12;
    }else if(isWordALeftDirection(word, code_language)) {
        char *toSend = (char *) malloc(sizeof(char) * (62 + strlen(word)));
        strcpy(toSend, "Regroupement.c --- Direction vers la gauche trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 13;
    }else if(isWordANumber(word, code_language)){
        char* toSend = (char*) malloc(sizeof (char) * (43 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Nombre trouvé.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 20;
    }else if(isWordAnObject(word, code_language)){
        char* toSend = (char*) malloc(sizeof (char) * (43 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Objet trouvé.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 30;
    }else if (isWordANegation(word, code_language)){
        char* toSend = (char*) malloc(sizeof (char) * (58 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Négation potentielle trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 40;
    }else if(isWordAUnite(word, code_language)){
        char* toSend = (char*) malloc(sizeof (char) * (43 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Unité trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 50;
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

wordTypeStruct** sentenceToWordTypeArray(Phrase* phrase, int code_language){
    log_file("Regroupement.c --- Démarrage de l'analyse de la phrase.");
    wordTypeStruct** res = (wordTypeStruct**) malloc(sizeof (wordTypeStruct*) * phrase->wordNumber );
    if (res == NULL){
        log_file("Regroupement.c --- Erreur d'allocation de mémoire pour wordTypeStruct dans sentenceToWordTypeArray.");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < phrase->wordNumber; i++){
        res[i] = init_wordTypeStruct();
        res[i]->typeWord = wordType(phrase->wordArray[i], code_language);
        res[i]->word = strdup(phrase->wordArray[i]);
        if(res[i]->typeWord==-2){
            log_file("Regroupement.c --- Erreur dans l'initialisation de la valeur typeWord.");
            exit(EXIT_FAILURE);
        }
    }
    log_file("Regroupement.c --- Analyse correctement effectuée.");
    return res;
}