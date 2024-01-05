//
// Created by Jean-Baptiste Salanie on 01/01/2024.
//

#include "Analyse.h"
#include "../Log/fichier_Log.h"

int charToNumber(char* numberChar){
    log_file("Analyse.c --- Démarrage de la transcription du nombre de la forme char vers la forme int.");
    return (strtol(numberChar, NULL, 10));
}

int analyse(wordTypeStruct** phrase, Phrase* wordArray){

    log_file("Analyse.c --- Démarage du traitement de la phrase.");
    int isForwardMovementWordPresent = -1, isNumberPresent = -1, isUnitePresent = -1, isNegationPresent = 0;

    for( int i = 0; i < wordArray->wordNumber ; i++ ){
        if(phrase[i]->typeWord == 1){
            isForwardMovementWordPresent = i;
        }else if(phrase[i]->typeWord == 2){
            isNumberPresent = i;
        }else if(phrase[i]->typeWord == 3){
            isUnitePresent = i;
        }else if(phrase[i]->typeWord == 4){
            isNegationPresent +=1;
        }
    } //Analyse des types de mots pour pouvoir comprendre la phrase et initilisation des variables

    if((isForwardMovementWordPresent != - 1) && (isUnitePresent != -1) && (isNumberPresent != -1) && (isNegationPresent != 2)){ //Phrase de mouvement vers l'avant avec spécification de la distance
        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'avant avec une spécification de la distance.");
        printf("Le robot va avancer de %d %s.\n", charToNumber(phrase[isNumberPresent]->word), phrase[isUnitePresent]->word);
        return 1;
    }else if((isForwardMovementWordPresent != -1) && ( isNegationPresent != 2)){
        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'avant sans spécification de la distance");
        printf("Le robot va avancer d'un mètre.\n");
        return 1;
    }else{
        log_file("Analyse.c --- Le traitement de la phrase n'est pas parvenu à trouver le sens de la phrase.");
        printf("Le robot ne va rien faire.\n");
        return 0;
    }

}