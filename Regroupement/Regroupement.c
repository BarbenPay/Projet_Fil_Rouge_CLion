//
// Created by Jean-Baptiste Salanie on 30/12/2023.
//

#include "Regroupement.h"
#include "../Log/logFile.h"
#include <ctype.h>


bool isWordInDict(char* word, char* dict){
    FILE* dictionnaire = fopen(dict, "r"); //on ouvre le dictionnaire

    if (dictionnaire == NULL)
    { //Si le programme n'arrive pas à ouvrir le dictionnaire, il renvoie une erreur sur le fichier log
        char* toSend = (char*)malloc(sizeof(char)*(64 + strlen(dict)));
        strcpy(toSend,"Regroupement.c --- Erreur lors de l'ouverture du dictionnaire: ");
        strcat(toSend, dict);
        log_file(toSend);
        free(toSend);
        return false;
    }

    char* tampon = (char*) malloc( 30 * sizeof(char));  // Taille de la chaine de cractère temporaire pour stocker les différents mots du dictionnaire
    bool isFound = false;


    for(int i = 0; i < strlen(word); i++){
        if( isupper(word[i])){
            word[i] =(char)tolower(word[i]);
        }
    }

    while (fscanf(dictionnaire, "%s", tampon) == 1) { //lire chaque mot dans le dictionnaire et le stocker dans tampon
        if (strcmp(tampon, word) == 0) { //Si tampon et le mot cherché sont égaux
            isFound = true;
            break;  // on sort de la boucle dès que le mot est trouvé
        }
    }

    // Fermer le fichier de dictionnaire
    fclose(dictionnaire);
    free(tampon);
    return isFound;

}

bool isWordABackwardMovementWord(char* word, int code_language) {
    if (code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Movement/backward_movement.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Dictionnaire/EN/Movement/backward_movement.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordABackwardMovementWord.");
        exit(EXIT_FAILURE);
    }
}

bool isWordAForwardMovementWord(char* word, int code_language){
    if(code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Movement/forward_movement.txt");
    }else if(code_language == 2){
        return isWordInDict(word, "../Dictionnaire/EN/Movement/forward_movement.txt");
    }else{
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordAForwardMovementWord.");
        exit(EXIT_FAILURE);
    }
}

bool isWordARotationWord(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Movement/rotation.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Dictionnaire/EN/Movement/rotation.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordARotationWord.");
        exit(EXIT_FAILURE);
    }
}

bool isWordAMovementWord(char*word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Movement/movement.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Dictionnaire/EN/Movement/movement.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordAMovementWord.");
        exit(EXIT_FAILURE);
    }
}

bool isWordACentimeterUnite(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Unite/centimeter.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Dictionnaire/EN/Unite/centimeter.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordACentimeterUnite.");
        exit(EXIT_FAILURE);
    }
}

bool isWordAMeterUnite(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Unite/meter.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Dictionnaire/EN/Unite/meter.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordAMeterUnite.");
        exit(EXIT_FAILURE);
    }
}

bool isWordADegreeUnite(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Unite/degree.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Dictionnaire/EN/Unite/degree.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordADegreeUnite.");
        exit(EXIT_FAILURE);
    }
}

bool isWordASphere(char* word, int code_language)
{
    if (code_language == 1)
    {
        return isWordInDict(word, "../Dictionnaire/FR/Objet/sphere.txt");
    }
    else if (code_language == 2)
    {
        return isWordInDict(word, "../Dictionnaire/EN/Object/sphere.txt");
    }
    else
    {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordASphere.");
        exit(EXIT_FAILURE);
    }
}

bool isWordACube(char* word, int code_language)
{
    if (code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Objet/cube.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Dictionnaire/EN/Object/cube.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordACube.");
        exit(EXIT_FAILURE);
    }
}

bool isWordANegation(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Negation/negation.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Dictionnaire/EN/Negation/negation.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordANegation.");
        exit(EXIT_FAILURE);
    }
}

bool isWordANumber(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Nombre/number.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Dictionnaire/EN/Number/number.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordANegation.");
        exit(EXIT_FAILURE);
    }
}

bool isWordABackwardDirection(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Direction/backward_direction.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Dictionnaire/EN/Direction/backward_direction.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordABackwardDirection.");
        exit(EXIT_FAILURE);
    }
}

bool isWordAForwardDirection(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Direction/forward_direction.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Dictionnaire/EN/Direction/forward_direction.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordAForwardDirection.");
        exit(EXIT_FAILURE);
    }
}

bool isWordALeftDirection(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Direction/left_direction.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Dictionnaire/EN/Direction/left_direction.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordALeftDirection.");
        exit(EXIT_FAILURE);
    }
}

bool isWordARightDirection(char* word, int code_language){
    if (code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Direction/right_direction.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Dictionnaire/EN/Direction/right_direction.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordARightDirection.");
        exit(EXIT_FAILURE);
    }
}

bool isWordAConjunction(char* word, int code_language)
{
    if (code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Conjonction/conjunction.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Dictionnaire/EN/Conjunction/conjunction.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordARightDirection.");
        exit(EXIT_FAILURE);
    }
}

bool isWordAYellowColor(char* word, int code_language)
{
    if (code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Color/yellow.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Dictionnaire/EN/Color/yellow.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordAYellowColor.");
        exit(EXIT_FAILURE);
    }
}

bool isWordABlueColor(char* word, int code_language)
{
    if (code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Color/blue.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Dictionnaire/EN/Color/blue.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordABlueColor.");
        exit(EXIT_FAILURE);
    }
}

bool isWordARedColor(char* word, int code_language)
{
    if (code_language == 1) {
        return isWordInDict(word, "../Dictionnaire/FR/Color/red.txt");
    } else if (code_language == 2) {
        return isWordInDict(word, "../Dictionnaire/EN/Color/red.txt");
    } else {
        log_file("Regroupement.c --- Erreur dans le code de la langue dans la fonction isWordARedColor.");
        exit(EXIT_FAILURE);
    }
}



////////////////////////////////////////// Code ////////////////////////////////////////////////////
// -1. Rien /
// 1. backward_movement / 2. forward_movement / 3. rotating_movement / 4. movement /
// 10. forward_direction / 11. backward_direction / 12. right_direction / 13. left_direction /
// 20. number /
// 30. sphere/ 31. cube /
// 40. negation /
// 50. meter / 51. centimeter / 52. degree /
// 60. conjonction /
// 70. yellow / 71. blue / 72. red /
////////////////////////////////////////////////////////////////////////////////////////////////////


int wordType (char* word, int code_language){
    if(isWordABackwardMovementWord(word, code_language))
    {
        char *toSend = (char *) malloc(sizeof(char) * (71 + strlen(word)));
        strcpy(toSend, "Regroupement.c --- Verbe de mouvement vers l'arrière trouvé.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 1;
    }
    else if(isWordAForwardMovementWord(word, code_language))
    {
        char* toSend = (char*) malloc(sizeof (char) * (69 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Verbe de mouvement vers l'avant trouvé.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 2;
    }
    else if(isWordARotationWord(word, code_language))
    {
        char* toSend = (char*) malloc(sizeof (char) * (55 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Verbe de rotation trouvé.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 3;
    }
    else if(isWordAMovementWord(word, code_language))
    {
        char* toSend = (char*) malloc(sizeof (char) * (56 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Verbe de mouvement trouvé.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 4;
    }
    else if(isWordAForwardDirection(word, code_language))
    {
        char *toSend = (char *) malloc(sizeof(char) * (61 + strlen(word)));
        strcpy(toSend, "Regroupement.c --- Direction vers l'avant trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 10;
    }
    else if(isWordABackwardDirection(word, code_language))
    {
        char *toSend = (char *) malloc(sizeof(char) * (63 + strlen(word)));
        strcpy(toSend, "Regroupement.c --- Direction vers l'arrière trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 11;
    }
    else if(isWordARightDirection(word, code_language))
    {
        char *toSend = (char *) malloc(sizeof(char) * (63 + strlen(word)));
        strcpy(toSend, "Regroupement.c --- Direction vers la droite trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 12;
    }
    else if(isWordALeftDirection(word, code_language))
    {
        char *toSend = (char *) malloc(sizeof(char) * (63 + strlen(word)));
        strcpy(toSend, "Regroupement.c --- Direction vers la gauche trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 13;
    }
    else if(isWordANumber(word, code_language))
    {
        char* toSend = (char*) malloc(sizeof (char) * (44 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Nombre trouvé.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 20;
    }
    else if(isWordASphere(word, code_language))
    {
        char* toSend = (char*) malloc(sizeof (char) * (43 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Mot \"Sphère\" trouvé.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 30;
    }
    else if(isWordACube(word, code_language))
    {
        char* toSend = (char*) malloc(sizeof (char) * (43 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Mot \"Cube\" trouvé.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 31;
    }
    else if (isWordANegation(word, code_language))
    {
        char* toSend = (char*) malloc(sizeof (char) * (59 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Négation potentielle trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 40;
    }
    else if(isWordAMeterUnite(word, code_language))
    {
        char* toSend = (char*) malloc(sizeof (char) * (54 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Unité \"Mètre\" trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 50;
    }
    else if(isWordACentimeterUnite(word, code_language))
    {
        char* toSend = (char*) malloc(sizeof (char) * (59 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Unité \"Centimètre\" trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 51;
    }
    else if(isWordADegreeUnite(word, code_language))
    {
        char* toSend = (char*) malloc(sizeof (char) * (54 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Unité \"Degré\" trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 52;
    }
    else if(isWordAConjunction(word, code_language))
    {
        char* toSend = (char*) malloc(sizeof (char) * (58 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Connecteur de phrase trouvé.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 60;
    }
    else if(isWordAYellowColor(word, code_language))
    {
        char* toSend = (char*) malloc(sizeof (char) * (58 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Couleur jaune trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 70;
    }
    else if(isWordABlueColor(word, code_language))
    {
        char* toSend = (char*) malloc(sizeof (char) * (58 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Couleur bleue trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 71;
    }
    else if(isWordARedColor(word, code_language))
    {
        char* toSend = (char*) malloc(sizeof (char) * (58 + strlen(word)));
        strcpy(toSend,"Regroupement.c --- Couleur rouge trouvée.     Mot: ");
        strcat(toSend, word);
        log_file(toSend);
        free(toSend);
        return 72;
    }
    else
    {
        char* toSend = (char*) malloc(sizeof (char) * (46 + strlen(word)));
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

sentenceTypeStruct* init_sentenceTypeStruct()
{
    sentenceTypeStruct* res = (sentenceTypeStruct*)malloc(sizeof(sentenceTypeStruct));
    if(res == NULL)
    {
        log_file("Regroupement.c --- Erreur d'allocation de mémoire pour sentenceTypeStruct.");
        exit(EXIT_FAILURE);
    }
    res->words = NULL;
    res->numberOfWord = 0;
    return res;
}

sentencesStruct* init_sentencesStruct(){
    sentencesStruct* res = (sentencesStruct*)malloc(sizeof(sentencesStruct));
    if(res == NULL){
        log_file("Regroupement.c --- Erreur d'allocation de mémoire pour sentenceTypeStruct.");
        exit(EXIT_FAILURE);
    }
    res->numberOfSentence = -1;
    res->sentences = NULL;
    return res;
}

sentencesStruct* sentencesToAnalysedSentencesTab(Phrase* phrase, int code_language)
{
    log_file("Regroupement.c --- Démarrage de l'analyse de la phrase.");
    sentencesStruct* res = init_sentencesStruct();
    int decalage = 0;
    if(phrase->wordNumber != 0)
    {
        res->numberOfSentence = 1;
    }
    else
    {
        log_file("Regroupement.c --- L'analyse de la phrase a reçu en entré une phrase sans mot.");
        exit(EXIT_FAILURE);
    }
    res->sentences = (sentenceTypeStruct**)malloc(sizeof(sentenceTypeStruct*));
    res->sentences[res->numberOfSentence - 1] = init_sentenceTypeStruct();
    for(int i = 0; i< phrase->wordNumber; i++){
        int wordTypeToKnowIfItIsAConJunction = wordType(phrase->wordArray[i],code_language);
        if(wordTypeToKnowIfItIsAConJunction != 60)
        {
            res->sentences[res->numberOfSentence-1]->words = (wordTypeStruct**)realloc(res->sentences[res->numberOfSentence-1]->words, ((i-decalage)+1)*sizeof(wordTypeStruct*));
            res->sentences[res->numberOfSentence-1]->words[i-decalage] = init_wordTypeStruct();
            res->sentences[res->numberOfSentence-1]->words[i-decalage]->typeWord = wordTypeToKnowIfItIsAConJunction;
            res->sentences[res->numberOfSentence-1]->words[i-decalage]->word = strdup(phrase->wordArray[i]);
            if(res->sentences[res->numberOfSentence-1]->words[i-decalage]->typeWord == -2)
            {
                log_file("Regroupement.c --- Erreur dans l'initialisation de la valeur typeWord.");
                exit(EXIT_FAILURE);
            }
            res->sentences[res->numberOfSentence-1]->numberOfWord += 1;
        }
        else
        {
            decalage = i + 1;
            res->numberOfSentence += 1;

            res->sentences = (sentenceTypeStruct**) realloc(res->sentences,res->numberOfSentence * sizeof(sentenceTypeStruct*));
            if(res->sentences == NULL)
            {
                log_file("Regroupement.c --- Erreur dans la ré-allocation de la mémoire de res->sentences.");
                exit(EXIT_FAILURE);
            }

            res->sentences[res->numberOfSentence-1] = init_sentenceTypeStruct();
            if(res->sentences[res->numberOfSentence-1]==NULL)
            {
                log_file("Regroupement.c --- Erreur dans l'allocation de la mémoire de res->sentence[res->numberOfSentence].");
                exit(EXIT_FAILURE);
            }

        }
    }
    log_file("Regroupement.c --- Analyse correctement effectuée.");
    return res;
}

void freeStructures(sentencesStruct* sentences)
{
    if (sentences == NULL)
    {
        return; // Rien à libérer si la structure est NULL
    }

    for (int i = 0; i < sentences->numberOfSentence; i++)
    {
        if (sentences->sentences[i] != NULL)
        {
            for (int j = 0; j < sentences->sentences[i]->numberOfWord; j++)
            {
                if (sentences->sentences[i]->words[j] != NULL)
                {
                    free(sentences->sentences[i]->words[j]->word);
                    free(sentences->sentences[i]->words[j]);
                }
            }
            free(sentences->sentences[i]->words);
            free(sentences->sentences[i]);
        }
    }

    free(sentences->sentences);
    free(sentences);
}
