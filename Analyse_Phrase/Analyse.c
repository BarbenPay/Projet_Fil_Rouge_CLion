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
    int isBackwardMovementWordPresent = -1, isForwardMovementWordPresent = -1, isRotatingWordPresent = -1, isMovementWordPresent = -1, isForwardDirectionPresent = -1, isBackwardDirectionPresent = -1, isRightDirectionPresent = -1, isLeftDirectionPresent = -1,isNumberPresent = -1, isObjectPresent = -1, isNegationPresent = 0, isUnitePresent = -1;

    for( int i = 0; i < wordArray->wordNumber ; i++ ){
        if(phrase[i]->typeWord == 1){
            isBackwardMovementWordPresent = i;
        }else if(phrase[i]->typeWord == 2){
            isForwardMovementWordPresent = i;
        }else if(phrase[i]->typeWord == 3){
            isRotatingWordPresent = i;
        }else if(phrase[i]->typeWord == 4){
            isMovementWordPresent = i;
        }else if(phrase[i]->typeWord == 10){
            isForwardDirectionPresent = i;
        }else if(phrase[i]->typeWord == 11){
            isBackwardDirectionPresent = i;
        }else if(phrase[i]->typeWord == 12){
            isRightDirectionPresent = i;
        }else if(phrase[i]->typeWord == 13){
            isLeftDirectionPresent = i;
        }else if(phrase[i]->typeWord == 20){
            isNumberPresent = i;
        }else if(phrase[i]->typeWord == 30){
            isObjectPresent = i;
        }else if(phrase[i]->typeWord == 40){
            isNegationPresent += 1;
        }else if(phrase[i]->typeWord == 50){
            isUnitePresent = i;
        }
    } //Analyse des types de mots pour pouvoir comprendre la phrase et initilisation des variables

    if((isForwardMovementWordPresent != - 1) && (isUnitePresent != -1) && (isNumberPresent != -1) && (isNegationPresent != 2)){ //Phrase de mouvement vers l'avant avec spécification de la distance
        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'avant avec une spécification de la distance.");
        printf("Le robot va avancer de %d %s.\n", charToNumber(phrase[isNumberPresent]->word), phrase[isUnitePresent]->word);
        log_file("Analyse.c --- Traitement correctement effectué.");
        return 1;
    }else if((isForwardMovementWordPresent != -1) && ( isNegationPresent != 2)){
        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'avant sans spécification de la distance");
        printf("Le robot va avancer d'un mètre.\n");
        log_file("Analyse.c --- Traitement correctement effectué.");
        return 1;
    }else if((isBackwardMovementWordPresent != -1) && (isUnitePresent != -1) && (isNumberPresent != -1) && (isNegationPresent != 2)){
        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'arrière avec une spécification de la distance.");
        printf("Le robot va reculer de %d %s.\n", charToNumber(phrase[isNumberPresent]->word), phrase[isUnitePresent]->word);
        log_file("Analyse.c --- Traitement correctement effectué.");
        return 1;
    }else if((isBackwardMovementWordPresent != -1) && (isNegationPresent != 2)){
        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'arrière sans spécification de la distance");
        printf("Le robot va reculer d'un mètre.\n");
        log_file("Analyse.c --- Traitement correctement effectué.");
        return 1;
    }else if((isRotatingWordPresent != -1) && (isDirectionPresent != -1) && (isNegationPresent != 2)){
        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait une rotation avec une spécification du sens.");
        printf("Le robot va s'orienter vers la %s.\n", phrase[isDirectionPresent]->word);
        log_file("Analyse.c --- Traitement correctement effectué.");
        return 1;
    }else if((isRotatingWordPresent != -1) && (isNegationPresent != 2)){
        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait une rotation sans spécification du sens.");
        printf("Le robot va s'orienter vers la droite.\n");
        log_file("Analyse.c --- Traitement correctement effectué.");
        return 1;
    }




    else{
        log_file("Analyse.c --- Le traitement de la phrase n'est pas parvenu à trouver le sens de la phrase.");
        printf("Le robot ne va rien faire.\n");
        return 0;
    }

}