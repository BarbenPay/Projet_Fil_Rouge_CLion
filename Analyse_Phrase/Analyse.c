//
// Created by Jean-Baptiste Salanie on 01/01/2024.
//

#include "Analyse.h"
#include "../Log/logFile.h"
#include "../Image/imageTreatmentCalling.h"


int charToNumber(char* numberChar){
    log_file("Analyse.c --- Démarrage de la transcription du nombre de la forme char vers la forme int.");
    return (int)strtol(numberChar, NULL, 10);
}




int foundColorObjectBoolToHandleForwardMovementToObject(int objectCode, int yellowCode, int blueCode, int redCode, inputWithLanguageChoice languageChoice)
{
    structObject* tmp = imageTreatmentCalling(choixImage(languageChoice));

    if (tmp == NULL )
    {
        log_file("Analyse.c --- Erreur dans lors de la sauvegarde des données du traitement d'image.");
        exit(EXIT_FAILURE);
    }

    if ((yellowCode || blueCode || redCode) == 0)
    {
        int foundObjectBool =  isThereASpecificObject (tmp, (char)((objectCode == 1) ? 'S' : (objectCode == 2) ? 'C' : '\0'));
        if(foundObjectBool == 1)
        {
            int toSendSize = 146;
            char* toSend = (char*)malloc( toSendSize * sizeof(char));

            if(toSend == NULL)
            {
                free(toSend);
                log_file("Analyse.c --- Erreur lors de l'allocation mémoire pour toSend dans foundColorObjectBoolToHandleForwardMovementToObject().");
                exit(EXIT_FAILURE);
            }
            strcpy(toSend,"");
            snprintf(toSend,toSendSize,"Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers %s sans spécification de la distance",(objectCode == 1) ? "une sphère" : (objectCode == 2) ? "un cube" : "\0");

            log_file(toSend);
            printf("Le robot va avancer d'un mètre vers %s.\n", (objectCode == 1) ? "la première boule detectée" : (objectCode == 2) ? "le premier cube détecté" : '\0');
            log_file("Analyse.c --- Traitement correctement effectué.\n\n");
            free(toSend);
            return -2;
        }
        else
        {
            int toSendSize = 200;
            char* toSend = (char*)malloc( toSendSize * sizeof(char));

            if(toSend == NULL)
            {
                free(toSend);
                log_file("Analyse.c --- Erreur lors de l'allocation mémoire pour toSend dans foundColorObjectBoolToHandleForwardMovementToObject().");
                exit(EXIT_FAILURE);
            }
            strcpy(toSend,"");
            snprintf(toSend,toSendSize,"Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers %s sans spécification de la distance, cependant elle n'a pas trouvé d'objets qui convenaient.",(objectCode == 1) ? "une sphère" : (objectCode == 2) ? "un cube" : '\0');
            log_file(toSend);
            printf("Le robot ne va pas bouger.\n");
            log_file("Analyse.c --- Traitement correctement effectué.\n\n");
            free(toSend);
            return -3;
        }

    }

    int foundColorObjectBool = isThereASpecificObjectWithColor(tmp, (char)((objectCode == 1) ? 'S' : (objectCode == 2) ? 'C' : '\0'), (char)((yellowCode) ? 'J' : (blueCode) ? 'B' : (redCode) ? 'O' : '\0'));
    return foundColorObjectBool;

}

int foundColorObjectBoolToHandleRotatingMovementToObject(int objectCode, int yellowCode, int blueCode, int redCode, inputWithLanguageChoice languageChoice)
{
    structObject* tmp = imageTreatmentCalling(choixImage(languageChoice));

    if ((yellowCode || blueCode || redCode) == 0)
    {
        int foundObjectBool =  isThereASpecificObject (tmp, (char)((objectCode == 1) ? 'S' : (objectCode == 2) ? 'C' : '\0'));
        if(foundObjectBool)
        {
            int toSendSize = 146;
            char* toSend = (char*)malloc( toSendSize * sizeof(char));

            if(toSend == NULL)
            {
                free(toSend);
                log_file("Analyse.c --- Erreur lors de l'allocation mémoire pour toSend dans foundColorObjectBoolToHandleRotatingMovementToObject().");
                exit(EXIT_FAILURE);
            }
            strcpy(toSend,"");
            snprintf(toSend,toSendSize,"Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement de rotation vers %s.",(objectCode == 1) ? "une sphère" : (objectCode == 2) ? "un cube" : "\0");
            log_file(toSend);
            printf("Le robot va se tourner vers %s.\n", (objectCode == 1) ? "la première boule detectée" : (objectCode == 2) ? "le premier cube détecté" : '\0');
            log_file("Analyse.c --- Traitement correctement effectué.\n\n");
            free(toSend);
            return -2;
        }
        else
        {
            int toSendSize = 200;
            char* toSend = (char*)malloc( toSendSize * sizeof(char));

            if(toSend == NULL)
            {
                free(toSend);
                log_file("Analyse.c --- Erreur lors de l'allocation mémoire pour toSend dans foundColorObjectBoolToHandleRotatingMovementToObject().");
                exit(EXIT_FAILURE);
            }
            strcpy(toSend,"");
            snprintf(toSend,toSendSize,"Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement de rotation vers %s, cependant elle n'a pas trouvé d'objets qui convenaient.",(objectCode == 1) ? "une sphère" : (objectCode == 2) ? "un cube" : '\0');
            log_file(toSend);
            printf("Le robot ne va pas bouger.\n");
            log_file("Analyse.c --- Traitement correctement effectué.\n\n");
            free(toSend);
            return -3;
        }

    }

    int foundColorObjectBool = isThereASpecificObjectWithColor(tmp, (char)((objectCode == 1) ? 'S' : (objectCode == 2) ? 'C' : '\0'), (char)((yellowCode) ? 'J' : (blueCode) ? 'B' : (redCode) ? 'O' : '\0'));
    return foundColorObjectBool;

}

int foundColorObjectBoolToHandleForwardMovementToObjectWithNumberAndUnite(int objectCode, int yellowCode, int blueCode, int redCode, int number,int uniteCode,
                                                                          inputWithLanguageChoice languageChoice)
{
    structObject* tmp = imageTreatmentCalling(choixImage(languageChoice));

    if (tmp == NULL )
    {
        log_file("Analyse.c --- Erreur dans lors de la sauvegarde des données du traitement d'image.");
        exit(EXIT_FAILURE);
    }

    if ((yellowCode || blueCode || redCode) == 0) {
        int foundObjectBool = isThereASpecificObject(tmp,(char) ((objectCode == 1) ? 'S' : (objectCode == 2) ? 'C' : '\0'));
        if (foundObjectBool == 1) {
            int toSendSize = 146;
            char *toSend = (char *) malloc(toSendSize * sizeof(char));

            if (toSend == NULL) {
                free(toSend);
                log_file(
                        "Analyse.c --- Erreur lors de l'allocation mémoire pour toSend dans foundColorObjectBoolToHandleForwardMovementToObject().");
                exit(EXIT_FAILURE);
            }
            strcpy(toSend, "");
            snprintf(toSend, toSendSize,"Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement "
                                        "vers %s avec spécification de la distance",(objectCode == 1) ? "une sphère" : (objectCode == 2) ? "un cube" : "\0");

            log_file(toSend);
            if(uniteCode==1)
            {
                printf("Le robot va avancer de %d mètre(s) vers %s.\n",
                       number,
                       (objectCode == 1) ? "la première boule detectée" : (objectCode == 2) ? "le premier cube détecté": '\0');
            }
            else if (uniteCode == 2)
            {
                printf("Le robot va avancer de %d centimètre(s) vers %s.\n",
                       number,
                       (objectCode == 1) ? "la première boule detectée" : (objectCode == 2) ? "le premier cube détecté": '\0');
            }
            log_file("Analyse.c --- Traitement correctement effectué.\n\n");
            free(toSend);
            return -2;
        } else {
            int toSendSize = 200;
            char *toSend = (char *) malloc(toSendSize * sizeof(char));

            if (toSend == NULL) {
                free(toSend);
                log_file(
                        "Analyse.c --- Erreur lors de l'allocation mémoire pour toSend dans foundColorObjectBoolToHandleForwardMovementToObject().");
                exit(EXIT_FAILURE);
            }
            strcpy(toSend, "");
            snprintf(toSend, toSendSize,
                     "Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers %s avec spécification de la distance, "
                     "cependant elle n'a pas trouvé d'objets qui convenaient.",
                     (objectCode == 1) ? "une sphère" : (objectCode == 2) ? "un cube" : '\0');
            log_file(toSend);
            printf("Le robot ne va pas bouger.\n");
            log_file("Analyse.c --- Traitement correctement effectué.\n\n");
            free(toSend);
            return -3;
        }
    }
    int foundColorObjectBool = isThereASpecificObjectWithColor(tmp, (char)((objectCode == 1) ? 'S' : (objectCode == 2) ? 'C' : '\0'),
                                                               (char)((yellowCode) ? 'J' : (blueCode) ? 'B' : (redCode) ? 'O' : '\0'));
    return foundColorObjectBool;
}




int handleForwardMovementToObject (int objectCode, int yellowCode, int blueCode, int redCode, inputWithLanguageChoice languageChoice)
{
    int foundColorObject = foundColorObjectBoolToHandleForwardMovementToObject(objectCode,yellowCode,blueCode,redCode,languageChoice);

    if(foundColorObject == 1){
        int toSendSize = 146;
        char* toSend = (char*)malloc(toSendSize * sizeof(char));

        if(toSend == NULL)
        {
            free(toSend);
            log_file("Analyse.c --- Erreur lors de l'allocation mémoire pour toSend dans handleForwardMovementToObject().");
            exit(EXIT_FAILURE);
        }
        strcpy(toSend,"");
        snprintf(toSend,toSendSize,"Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers %s %s sans spécification de la distance.", (objectCode == 1) ? "la sphère" : (objectCode == 2) ? "le cube" : '\0' ,(yellowCode) ? "jaune" : (blueCode) ? "bleue" : (redCode) ? "rouge" : "");
        log_file(toSend);
        printf("Le robot va avancer d'un mètre vers %s %s.\n", (objectCode == 1) ? "la sphère" : (objectCode == 2) ? "le cube" : '\0',(yellowCode) ? "jaune" : (blueCode) ? "bleue" : (redCode) ? "rouge" : "");
        log_file("Analyse.c --- Traitement correctement effectué.\n\n");
        free(toSend);
        return 1;

    }
    else if((foundColorObject == -2) || (foundColorObject == -3))
    {
        return foundColorObject;
    }
    else
    {
        int toSendSize = 200;
        char* toSend = (char*)malloc( toSendSize * sizeof(char));

        if(toSend == NULL)
        {
            free(toSend);
            log_file("Analyse.c --- Erreur lors de l'allocation mémoire pour toSend dans handleForwardMovementToObject().");
            exit(EXIT_FAILURE);
        }
        strcpy(toSend,"");
        snprintf(toSend,toSendSize,"Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers %s %s sans spécification de la distance, cependant elle n'a pas trouvé d'objets qui convenaient.", (objectCode == 1) ? "une sphère" : (objectCode == 2) ? "un cube" : '\0',(yellowCode) ? "jaune" : (blueCode) ? "bleue" : (redCode) ? "rouge" : "");
        log_file(toSend);
        printf("Le robot ne va pas bouger.\n");
        log_file("Analyse.c --- Traitement correctement effectué.\n\n");
        free(toSend);
        return 0;
    }
}

int handleForwardMovementToObjectWithNumberAndUnite(int objectCode, int yellowCode, int blueCode, int redCode, int number, int uniteCode,
                                                   inputWithLanguageChoice languageChoice)
{

    int foundColorObject = foundColorObjectBoolToHandleForwardMovementToObjectWithNumberAndUnite(objectCode,yellowCode,blueCode,redCode,number, uniteCode,
                                                                                                 languageChoice);

    if(foundColorObject == 1){
        int toSendSize = 146;
        char* toSend = (char*)malloc(toSendSize * sizeof(char));

        if(toSend == NULL)
        {
            free(toSend);
            log_file("Analyse.c --- Erreur lors de l'allocation mémoire pour toSend dans handleForwardMovementToObject().");
            exit(EXIT_FAILURE);
        }
        strcpy(toSend,"");
        snprintf(toSend,toSendSize,"Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers %s %s avec spécification de la distance.", (objectCode == 1) ? "la sphère" : (objectCode == 2) ? "le cube" : '\0' ,(yellowCode) ? "jaune" : (blueCode) ? "bleue" : (redCode) ? "rouge" : "");
        log_file(toSend);
        free(toSend);
        if(uniteCode == 1)
        {
            printf("Le robot va avancer de %d mètre(s) vers %s %s.\n",
                   number,
                   (objectCode == 1) ? "la sphère" : (objectCode == 2) ? "le cube" : '\0',
                   (yellowCode) ? "jaune" : (blueCode) ? "bleue" : (redCode) ? "rouge" : "");
        }
        else if(uniteCode == 2)
        {
            printf("Le robot va avancer de %d centimètre(s) vers %s %s.\n",
                   number,
                   (objectCode == 1) ? "la sphère" : (objectCode == 2) ? "le cube" : '\0',
                   (yellowCode) ? "jaune" : (blueCode) ? "bleue" : (redCode) ? "rouge" : "");
        }
        log_file("Analyse.c --- Traitement correctement effectué.\n\n");
        return 1;

    }
    else if((foundColorObject == -2) || (foundColorObject == -3))
    {
        return foundColorObject;
    }
    else
    {
        int toSendSize = 200;
        char* toSend = (char*)malloc( toSendSize * sizeof(char));

        if(toSend == NULL)
        {
            free(toSend);
            log_file("Analyse.c --- Erreur lors de l'allocation mémoire pour toSend dans handleForwardMovementToObject().");
            exit(EXIT_FAILURE);
        }
        strcpy(toSend,"");
        snprintf(toSend,toSendSize,"Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers %s %s avec spécification de la distance, "
                                   "cependant elle n'a pas trouvé d'objets qui convenaient.",
                                   (objectCode == 1) ? "une sphère" : (objectCode == 2) ? "un cube" : '\0',
                                   (yellowCode) ? "jaune" : (blueCode) ? "bleue" : (redCode) ? "rouge" : "");
        log_file(toSend);
        printf("Le robot ne va pas bouger.\n");
        log_file("Analyse.c --- Traitement correctement effectué.\n\n");
        free(toSend);
        return 0;
    }
}

int handleRotatingMovementToObject (int objectCode, int yellowCode, int blueCode, int redCode, inputWithLanguageChoice languageChoice)
{
    int foundColorObject = foundColorObjectBoolToHandleRotatingMovementToObject(objectCode,yellowCode,blueCode,redCode,languageChoice);

    if(foundColorObject == 1){

        int toSendSize = 146;
        char* toSend = (char*)malloc( toSendSize * sizeof(char));

        if(toSend == NULL)
        {
            free(toSend);
            log_file("Analyse.c --- Erreur lors de l'allocation mémoire pour toSend dans handleRotatingMovementToObject().");
            exit(EXIT_FAILURE);
        }
        strcpy(toSend,"");
        snprintf(toSend,toSendSize,"Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement de rotation vers %s %s.", (objectCode == 1) ? "une sphère" : (objectCode == 2) ? "un cube" : '\0' ,(yellowCode) ? "jaune" : (blueCode) ? "bleue" : (redCode) ? "rouge" : "");
        log_file(toSend);
        printf("Le robot va se tourner vers %s %s.\n", (objectCode == 1) ? "la sphère" : (objectCode == 2) ? "le cube" : '\0',(yellowCode) ? "jaune" : (blueCode) ? "bleue" : (redCode) ? "rouge" : "");
        log_file("Analyse.c --- Traitement correctement effectué.\n\n");
        free(toSend);
        return 1;

    }
    else if ((foundColorObject == -2)||(foundColorObject == -3))
    {
        return foundColorObject;
    }
    else
    {
        int toSendSize = 200;
        char* toSend = (char*)malloc( toSendSize * sizeof(char));

        if(toSend == NULL)
        {
            free(toSend);
            log_file("Analyse.c --- Erreur lors de l'allocation mémoire pour toSend dans handleRotatingMovementToObject().");
            exit(EXIT_FAILURE);
        }
        strcpy(toSend,"");
        snprintf(toSend,toSendSize,"Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement de rotation vers %s %s, cependant elle n'a pas trouvé d'objets qui convenaient.", (objectCode == 1) ? "une sphère" : (objectCode == 2) ? "un cube" : '\0',(yellowCode) ? "jaune" : (blueCode) ? "bleue" : (redCode) ? "rouge" : "");
        log_file(toSend);
        printf("Le robot ne va pas bouger.\n");
        log_file("Analyse.c --- Traitement correctement effectué.\n\n");
        free(toSend);
        return 0;
    }
}





int analyse(sentenceTypeStruct* phrase, inputWithLanguageChoice languageChoice){

    log_file("Analyse.c --- Démarrage du traitement de la phrase.");
    int isBackwardMovementWordPresent = -1, isForwardMovementWordPresent = -1, isRotatingWordPresent = -1, isMovementWordPresent = -1, isForwardDirectionPresent = -1, isBackwardDirectionPresent = -1, isRightDirectionPresent = -1, isLeftDirectionPresent = -1,isNumberPresent = -1, isSphereObjectPresent = -1, isCubeObjectPresent = -1, isNegationPresent = 0, isThereUnite = 0, isYellowColorPresent = 0,isBlueColorPresent = 0,isRedColorPresent = 0;

    for (int i = 0; i < phrase->numberOfWord; i++) {
        int wordType = phrase->words[i]->typeWord;

        switch (wordType) {
            case 1: isBackwardMovementWordPresent = i; break;
            case 2: isForwardMovementWordPresent = i; break;
            case 3: isRotatingWordPresent = i; break;
            case 4: isMovementWordPresent = i; break;
            case 10: isForwardDirectionPresent = 1; break;
            case 11: isBackwardDirectionPresent = 1; break;
            case 12: isRightDirectionPresent = 1; break;
            case 13: isLeftDirectionPresent = 1; break;
            case 20: isNumberPresent = i; break;
            case 30: isSphereObjectPresent = 1; break;
            case 31: isCubeObjectPresent = 1; break;
            case 40: isNegationPresent += 1; break;
            case 50: isThereUnite += 1; break;
            case 51: isThereUnite += 2; break;
            case 52: isThereUnite += 3; break;
            case 70: isYellowColorPresent = 1; break;
            case 71: isBlueColorPresent = 1; break;
            case 72: isRedColorPresent = 1; break;
            default: break;
        }
    } //Analyse des types de mots pour pouvoir comprendre la phrase et initilisation des variables


    if(isNegationPresent ==0 )
    {

        if(isNumberPresent != -1)
        {

            if((isThereUnite == 1) || (isThereUnite == 2))
            {

                if(isForwardMovementWordPresent != -1)
                {
                    if (isSphereObjectPresent == 1)
                    {
                        int toReturn = handleForwardMovementToObjectWithNumberAndUnite(1,isYellowColorPresent,isBlueColorPresent,
                                                                        isRedColorPresent,
                                                                        charToNumber(phrase->words[isNumberPresent]->word),
                                                                        isThereUnite,languageChoice);
                        return toReturn;
                    }
                    else if(isCubeObjectPresent == 1)
                    {
                        int toReturn = handleForwardMovementToObjectWithNumberAndUnite(1,isYellowColorPresent,isBlueColorPresent,
                                                                        isRedColorPresent,
                                                                        charToNumber(phrase->words[isNumberPresent]->word),
                                                                        isThereUnite,languageChoice);
                        return toReturn;
                    }
                    else
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait "
                                 "un mouvement vers l'avant avec une spécification de la distance.");
                        if (isThereUnite == 1) {
                            printf("Le robot va avancer de %d mètre(s).\n",
                                   charToNumber(phrase->words[isNumberPresent]->word));
                        } else {
                            printf("Le robot va avancer de %d centimètre(s).\n",
                                   charToNumber(phrase->words[isNumberPresent]->word));
                        }
                        log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                        return 1;
                    }
                }
                else if(isBackwardMovementWordPresent != -1)
                {

                    log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'arrière avec une spécification de la distance.");
                    if(isThereUnite == 1)
                    {

                        printf("Le robot va reculer de %d mètre(s).\n", charToNumber(phrase->words[isNumberPresent]->word));

                    }
                    else
                    {

                        printf("Le robot va reculer de %d centimètre(s).\n", charToNumber(phrase->words[isNumberPresent]->word));

                    }
                    log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                    return 1;

                }
                else if(isMovementWordPresent != -1)
                {
                    if(isForwardDirectionPresent != -1)
                    {

                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'avant avec une spécification de la distance.");
                        if(isThereUnite == 1)
                        {
                            printf("Le robot va avancer de %d mètre(s).\n", charToNumber(phrase->words[isNumberPresent]->word));
                        }
                        else
                        {
                            printf("Le robot va avancer de %d centimètre(s).\n", charToNumber(phrase->words[isNumberPresent]->word));
                        }
                        log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                        return 1;
                    }
                    else if(isBackwardDirectionPresent != -1)
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'arrière avec une spécification de la distance.");
                        if(isThereUnite == 1)
                        {

                            printf("Le robot va reculer de %d mètre(s).\n", charToNumber(phrase->words[isNumberPresent]->word));

                        }
                        else
                        {

                            printf("Le robot va reculer de %d centimètre(s).\n", charToNumber(phrase->words[isNumberPresent]->word));

                        }
                        log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                        return 1;

                    }
                    else if (isSphereObjectPresent == 1)
                    {
                        int toReturn = handleForwardMovementToObjectWithNumberAndUnite(1,isYellowColorPresent,isBlueColorPresent,
                                                                                       isRedColorPresent,
                                                                                       charToNumber(phrase->words[isNumberPresent]->word),
                                                                                       isThereUnite,languageChoice);
                        return toReturn;
                    }
                    else if(isCubeObjectPresent == 1)
                    {
                        int toReturn = handleForwardMovementToObjectWithNumberAndUnite(1,isYellowColorPresent,isBlueColorPresent,
                                                                                       isRedColorPresent,
                                                                                       charToNumber(phrase->words[isNumberPresent]->word),
                                                                                       isThereUnite,languageChoice);
                        return toReturn;
                    }
                    else
                    {

                        log_file("Analyse.c --- Le traitement de la phrase n'est pas parvenu à trouver le sens de la phrase.");
                        printf("Le traitement de la phrase n'est pas parvenu a déterminer le sens de la phrase.\nVeuillez précisez la direction dans laquelle le robot doit évoluer.\n le robot ne bouge  pas.\n");
                        return 0;

                    }


                }
                else
                {

                    log_file("Analyse.c --- Le traitement de la phrase n'est pas parvenu à trouver le sens de la phrase.");
                    printf("Le traitement de la phrase n'est pas parvenu a déterminer le sens de la phrase, le robot ne va rien faire.\n");
                    return 0;

                }

            }
            else if (isThereUnite == 0)
            {

                if(isForwardMovementWordPresent != -1)
                {
                    log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'avant avec une spécification de la distance.");
                    printf("L'unité de base de ce programme est le mètre.\nSi vous souhaitiez utiliser le centimètre, n'oubliez pas de préciser l'unité ;).\nLe robot va avancer de %d mètre(s).\n", charToNumber(phrase->words[isNumberPresent]->word));
                    log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                    return 1;
                }
                else if(isBackwardMovementWordPresent != -1)
                {

                    log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'arrière avec une spécification de la distance.");
                    printf("L'unité de base est le mètre. Si vous souhaitiez utiliser le centimètre, n'oubliez pas de préciser l'unité ;).\nLe robot va reculer de %d mètre(s).\n", charToNumber(phrase->words[isNumberPresent]->word));
                    log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                    return 1;

                }
                else if(isMovementWordPresent != -1)
                {
                    if(isForwardDirectionPresent != -1)
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'avant avec une spécification de la distance.");
                        printf("L'unité de base est le mètre. Si vous souhaitiez utiliser le centimètre, n'oubliez pas de préciser l'unité ;).\nLe robot va avancer de %d mètre(s).\n", charToNumber(phrase->words[isNumberPresent]->word));
                        log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                        return 1;
                    }
                    else if(isBackwardDirectionPresent != -1)
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'arrière avec une spécification de la distance.");
                        printf("L'unité de base est le mètre. Si vous souhaitiez utiliser le centimètre, n'oubliez pas de préciser l'unité ;).\nLe robot va reculer de %d mètre(s).\n", charToNumber(phrase->words[isNumberPresent]->word));
                        log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                        return 1;

                    }
                    else
                    {

                        log_file("Analyse.c --- Le traitement de la phrase n'est pas parvenu à trouver le sens de la phrase.");
                        printf("Le traitement de la phrase n'est pas parvenu a déterminer le sens de la phrase.\nVeuillez précisez la direction dans laquelle le robot doit évoluer.\n le robot ne bouge  pas.\n");
                        return 0;

                    }


                }
                else
                {

                    log_file("Analyse.c --- Le traitement de la phrase n'est pas parvenu à trouver le sens de la phrase.");
                    printf("Le traitement de la phrase n'est pas parvenu a déterminer le sens de la phrase, le robot ne va rien faire.\n");
                    return 0;

                }


            }
            if(isRotatingWordPresent != -1)
            {
                if(isRightDirectionPresent != -1)
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement de rotation vers la droite avec une spécification de l'angle.");
                        printf("Le robot va tourner de %d degré(s) vers la droite.\n", charToNumber(phrase->words[isNumberPresent]->word));
                        log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                        return 1;
                    }
                else if(isLeftDirectionPresent != -1)
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement de rotation vers la gauche avec une spécification de l'angle.");
                        printf("Le robot va tourner de %d degré(s) vers la gauche.\n", charToNumber(phrase->words[isNumberPresent]->word));
                        log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                        return 1;
                    }
                else
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement de rotation vers la droite avec une spécification de l'angle.");
                        printf("Le sens principale de ce programme est le sens horaire.\nLe robot va tourner de %d degré(s) vers la droite.\n", charToNumber(phrase->words[isNumberPresent]->word));
                        log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                        return 1;
                    }

            }
            else
            {
                log_file("Analyse.c --- Le traitement de la phrase n'est pas parvenu à trouver le sens de la phrase.");
                printf("Le traitement de la phrase n'est pas parvenu a déterminer le sens de la phrase car vous avez rentré 2 unités.\nle robot ne va rien faire.\n");
                return 0;
            }
        }
        else
        {
            if(isRotatingWordPresent != -1) {
                if (isRightDirectionPresent != -1) {
                    log_file(
                            "Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement de rotation vers la droite sans spécification de l'angle.");
                    printf("Le robot va tourner de 90 degrés vers la droite.\n");
                    log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                    return 1;
                }
                else if (isLeftDirectionPresent != -1) {
                    log_file(
                            "Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement de rotation vers la gauche sans spécification de l'angle.");
                    printf("Le robot va tourner de 90 degrés vers la gauche.\n");
                    log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                    return 1;
                }
                else if (isBackwardDirectionPresent != -1) {
                    log_file(
                            "Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement de rotation vers l'arrière sans spécification de l'angle.");
                    printf("Le robot va tourner de 180 degrés vers la droite.\n");
                    log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                    return 1;
                }

                else if(isSphereObjectPresent==1)
                {
                     int toReturn = handleRotatingMovementToObject(1,isYellowColorPresent,isBlueColorPresent,isRedColorPresent,languageChoice);
                    return toReturn;
                }
                else if(isCubeObjectPresent == 1)
                {
                    int toReturn = handleRotatingMovementToObject(2,isYellowColorPresent,isBlueColorPresent,isRedColorPresent,languageChoice);
                    return toReturn;
                }

                else if (isThereUnite == 3)
                {
                    log_file("Analyse.c --- Le traitement de la phrase n'est pas parvenu à trouver le sens de la phrase.");
                    printf("Le traitement de la phrase n'est pas parvenu a déterminer le sens de la phrase.\nle robot ne va rien faire.\n");
                    return 0;
                }
                else
                {
                    log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement de rotation vers la droite avec une spécification de l'angle.");
                    printf("Le sens principale de ce programme est le sens horaire.\nDe plus vous n'avez pas précisez l'angle.\nLe robot va tourner de 90 degrés vers la droite.\n");
                    log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                    return 1;
                }
            }
            else if(isThereUnite == 0)
            {

                if(isForwardMovementWordPresent != -1)
                {
                    if(isSphereObjectPresent==1)
                    {
                        int toReturn = handleForwardMovementToObject(1,isYellowColorPresent,isBlueColorPresent,isRedColorPresent,languageChoice);
                        return toReturn;
                    }
                    else if(isCubeObjectPresent == 1)
                    {
                        int toReturn = handleForwardMovementToObject(2,isYellowColorPresent,isBlueColorPresent,isRedColorPresent,languageChoice);
                        return toReturn;
                    }
                    else
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'avant sans spécification de la distance");
                        printf("Le robot va avancer d'un mètre.\n");
                        log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                        return 1;
                    }
                }
                else if (isBackwardMovementWordPresent != -1)
                {
                    log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'arrière sans spécification de la distance");
                    printf("Le robot va reculer d'un mètre.\n");
                    log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                    return 1;
                }
                else if (isMovementWordPresent != -1)
                {
                    if(isForwardDirectionPresent != -1)
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'avant sans spécification de la distance");
                        printf("Le robot va avancer d'un mètre.\n");
                        log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                        return 1;
                    }
                    else if(isBackwardDirectionPresent != -1)
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'arrière sans spécification de la distance");
                        printf("Le robot va reculer d'un mètre.\n");
                        log_file("Analyse.c --- Traitement correctement effectué.\n\n");
                        return 1;
                    }
                    else if(isSphereObjectPresent==1)
                    {
                        int toReturn = handleForwardMovementToObject(1,isYellowColorPresent,isBlueColorPresent,isRedColorPresent,languageChoice);
                        return toReturn;
                    }
                    else if(isCubeObjectPresent == 1)
                    {
                        int toReturn = handleForwardMovementToObject(2,isYellowColorPresent,isBlueColorPresent,isRedColorPresent,languageChoice);
                        return toReturn;
                    }
                    else
                    {
                        log_file("Analyse.c --- Le traitement de la phrase n'est pas parvenu à trouver le sens de la phrase.\n\n");
                        printf("Le traitement de la phrase n'est pas parvenu a déterminer le sens de la phrase.\nVeuillez précisez la direction dans laquelle le robot doit évoluer.\n le robot ne bouge  pas.\n");
                        return 0;
                    }
                }
                else
                {
                    log_file("Analyse.c --- Le traitement de la phrase n'est pas parvenu à trouver le sens de la phrase.\n\n");
                    printf("Le traitement de la phrase n'est pas parvenu a déterminer le sens de la phrase.\nle robot ne va rien faire.\n");
                    return 0;
                }


            }
            else
            {
                log_file("Analyse.c --- Le traitement de la phrase n'est pas parvenu à trouver le sens de la phrase.\n\n");
                printf("Le traitement de la phrase n'est pas parvenu a déterminer le sens de la phrase.\nle robot ne va rien faire.\n");
                return 0;
            }
        }

    }
    else
    {
        log_file("Analyse.c --- Le traitement de la phrase a décelé une négation.\n\n");
        printf("Le robot ne va rien faire.\n");
        return 0;
    }
}