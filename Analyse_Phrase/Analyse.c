//
// Created by Jean-Baptiste Salanie on 01/01/2024.
//

#include <assert.h>
#include "Analyse.h"
#include "../Log/logFile.h"
#include "../Image/imageTreatmentCalling.h"

int charToNumber(char* numberChar){
    log_file("Analyse.c --- Démarrage de la transcription du nombre de la forme char vers la forme int.");
    return (int)strtol(numberChar, NULL, 10);
}

int analyseIfObjectDetected (int movementCode ,int spherePresent, int cubePresent, int yellowPresent, int bluePresent, int redPresent)
{
    assert((spherePresent != cubePresent)&&(((yellowPresent ^ bluePresent) ^ redPresent )||(!yellowPresent && !bluePresent && !redPresent)));

    switch (movementCode) { //1 si forward, 2 si rotation

        case 1:

            if(spherePresent == 1)
            {
                structObject* tmp = imageTreatmentCalling(choice);
                int positionObject = isThereASpecificObjectWithColor(tmp,'S');
                switch (positionObject){

                    case -1:
                        break;
                    case 0:

                        break;
                    case 1:
                        break;
                }

                if(yellowPresent == 1 && bluePresent == 0 && redPresent == 0)
                {

                    int positionObject = isThereASpecificObjectWithColor(tmp,'S','Y');

                    log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers la sphère jaune sans spécification de la distance");
                    printf("Le robot va avancer d'un mètre vers la boule jaune.\n");
                    log_file("Analyse.c --- Traitement correctement effectué.");
                    return 1;
                }
                else if (yellowPresent == 0 && bluePresent == 1 && redPresent == 0)
                {
                    structObject* tmp = imageTreatmentCalling(choice);
                    int positionObject = isThereASpecificObjectWithColor(tmp,'S','B');
                    log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers la sphère bleue sans spécification de la distance");
                    printf("Le robot va avancer d'un mètre vers la boule bleue.\n");
                    log_file("Analyse.c --- Traitement correctement effectué.");
                    return 1;
                }
                else if (yellowPresent == 0 && bluePresent == 0 && redPresent == 1)
                {
                    structObject* tmp = imageTreatmentCalling(choice);
                    int positionObject = isThereASpecificObjectWithColor(tmp,'S','O');
                    log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers la sphère rouge sans spécification de la distance");
                    printf("Le robot va avancer d'un mètre vers la boule rouge.\n");
                    log_file("Analyse.c --- Traitement correctement effectué.");
                    return 1;
                }
            }
    }



}

int analyse(sentenceTypeStruct* phrase){

    log_file("Analyse.c --- Démarage du traitement de la phrase.");
    int isBackwardMovementWordPresent = -1, isForwardMovementWordPresent = -1, isRotatingWordPresent = -1, isMovementWordPresent = -1, isForwardDirectionPresent = -1, isBackwardDirectionPresent = -1, isRightDirectionPresent = -1, isLeftDirectionPresent = -1,isNumberPresent = -1, isSphereObjectPresent = -1, isCubeObjectPresent = -1, isNegationPresent = 0, isThereUnite = 0, isYellowColorPresent = -1,isBlueColorPresent = -1,isRedColorPresent = -1;

    for (int i = 0; i < phrase->numberOfWord; i++) {
        int wordType = phrase->words[i]->typeWord;

        switch (wordType) {
            case 1: isBackwardMovementWordPresent = i; break;
            case 2: isForwardMovementWordPresent = i; break;
            case 3: isRotatingWordPresent = i; break;
            case 4: isMovementWordPresent = i; break;
            case 10: isNumberPresent = i; break;
            case 30: isSphereObjectPresent = 1; break;
            case 31: isCubeObjectPresent = 1; break;
            case 40: isNegationPresent += 1; break;
            case 50: isThereUnite += 1; break;
            case 51: isThereUnite += 2; break;
            case 52: isThereUnite += 3; break;
            case 70: isYellowColorPresent = 1; break;
            case 71: isBlueColorPresent = 1; break;
            case 72: isRedColorPresent = 1; break;
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
                    log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'avant avec une spécification de la distance.");
                    if(isThereUnite == 1)
                    {
                        printf("Le robot va avancer de %d mètre(s).\n", charToNumber(phrase->words[isNumberPresent]->word));
                    }
                    else
                    {
                        printf("Le robot va avancer de %d centimètre(s).\n", charToNumber(phrase->words[isNumberPresent]->word));
                    }
                    log_file("Analyse.c --- Traitement correctement effectué.");
                    return 1;
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
                    log_file("Analyse.c --- Traitement correctement effectué.");
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
                        log_file("Analyse.c --- Traitement correctement effectué.");
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
                        log_file("Analyse.c --- Traitement correctement effectué.");
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
            else if (isThereUnite == 0)
            {

                if(isForwardMovementWordPresent != -1)
                {
                    log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'avant avec une spécification de la distance.");
                    printf("L'unité de base de ce programme est le mètre.\nSi vous souhaitiez utiliser le centimètre, n'oubliez pas de préciser l'unité ;).\nLe robot va avancer de %d mètre(s).\n", charToNumber(phrase->words[isNumberPresent]->word));
                    log_file("Analyse.c --- Traitement correctement effectué.");
                    return 1;
                }
                else if(isBackwardMovementWordPresent != -1)
                {

                    log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'arrière avec une spécification de la distance.");
                    printf("L'unité de base est le mètre. Si vous souhaitiez utiliser le centimètre, n'oubliez pas de préciser l'unité ;).\nLe robot va reculer de %d mètre(s).\n", charToNumber(phrase->words[isNumberPresent]->word));
                    log_file("Analyse.c --- Traitement correctement effectué.");
                    return 1;

                }
                else if(isMovementWordPresent != -1)
                {
                    if(isForwardDirectionPresent != -1)
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'avant avec une spécification de la distance.");
                        printf("L'unité de base est le mètre. Si vous souhaitiez utiliser le centimètre, n'oubliez pas de préciser l'unité ;).\nLe robot va avancer de %d mètre(s).\n", charToNumber(phrase->words[isNumberPresent]->word));
                        log_file("Analyse.c --- Traitement correctement effectué.");
                        return 1;
                    }
                    else if(isBackwardDirectionPresent != -1)
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'arrière avec une spécification de la distance.");
                        printf("L'unité de base est le mètre. Si vous souhaitiez utiliser le centimètre, n'oubliez pas de préciser l'unité ;).\nLe robot va reculer de %d mètre(s).\n", charToNumber(phrase->words[isNumberPresent]->word));
                        log_file("Analyse.c --- Traitement correctement effectué.");
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
                        log_file("Analyse.c --- Traitement correctement effectué.");
                        return 1;
                    }
                else if(isLeftDirectionPresent != -1)
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement de rotation vers la gauche avec une spécification de l'angle.");
                        printf("Le robot va tourner de %d degré(s) vers la gauche.\n", charToNumber(phrase->words[isNumberPresent]->word));
                        log_file("Analyse.c --- Traitement correctement effectué.");
                        return 1;
                    }
                else
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement de rotation vers la droite avec une spécification de l'angle.");
                        printf("Le sens principale de ce programme est le sens horaire.\nLe robot va tourner de %d degré(s) vers la droite.\n", charToNumber(phrase->words[isNumberPresent]->word));
                        log_file("Analyse.c --- Traitement correctement effectué.");
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
                    log_file("Analyse.c --- Traitement correctement effectué.");
                    return 1;
                }
                else if (isLeftDirectionPresent != -1) {
                    log_file(
                            "Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement de rotation vers la gauche sans spécification de l'angle.");
                    printf("Le robot va tourner de 90 degrés vers la gauche.\n");
                    log_file("Analyse.c --- Traitement correctement effectué.");
                    return 1;
                }
                else if (isBackwardDirectionPresent != -1) {
                    log_file(
                            "Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement de rotation vers l'arrière sans spécification de l'angle.");
                    printf("Le robot va tourner de 180 degrés vers la droite.\n");
                    log_file("Analyse.c --- Traitement correctement effectué.");
                    return 1;
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
                    log_file("Analyse.c --- Traitement correctement effectué.");
                    return 1;
                }
            }
            else if(isThereUnite == 0)
            {

                if(isForwardMovementWordPresent != -1)
                {
                     if(isSphereObjectPresent==1)
                    {
                        if(isYellowColorPresent == 1 && isBlueColorPresent == 0 && isRedColorPresent == 0)
                        {
                            structObject* tmp = imageTreatmentCalling(choice);
                            int positionObject = isThereASpecificObjectWithColor(tmp,'S','Y');
                            if(positionObject)
                            {
                                log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers la sphère jaune sans spécification de la distance");
                                printf("Le robot va avancer d'un mètre vers la boule jaune.\n");
                                log_file("Analyse.c --- Traitement correctement effectué.");
                                return 1;
                            }
                            else
                            {
                                log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers la sphère jaune sans spécification de la distance, cependant elle n'a pas trouvé d'objets qui convenaient.");
                                printf("Le robot ne va pas bouger.\n");
                                log_file("Analyse.c --- Traitement correctement effectué.");
                                return 1;
                            }

                        }
                        else if (isYellowColorPresent == 0 && isBlueColorPresent == 1 && isRedColorPresent == 0)
                        {
                            structObject* tmp = imageTreatmentCalling(choice);
                            int positionObject = isThereASpecificObjectWithColor(tmp,'S','B');
                            log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers la sphère bleue sans spécification de la distance");
                            printf("Le robot va avancer d'un mètre vers la boule bleue.\n");
                            log_file("Analyse.c --- Traitement correctement effectué.");
                            return 1;
                        }
                        else if (isYellowColorPresent == 0 && isBlueColorPresent == 0 && isRedColorPresent == 1)
                        {
                            structObject* tmp = imageTreatmentCalling(choice);
                            int positionObject = isThereASpecificObjectWithColor(tmp,'S','O');
                            log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers la sphère rouge sans spécification de la distance");
                            printf("Le robot va avancer d'un mètre vers la boule rouge.\n");
                            log_file("Analyse.c --- Traitement correctement effectué.");
                            return 1;
                        }


                    }
                     else if(isCubeObjectPresent == 1)
                     {
                         if(isYellowColorPresent == 1 && isBlueColorPresent == 0 && isRedColorPresent == 0)
                         {
                             structObject* tmp = imageTreatmentCalling(choice);
                             int positionObject = isThereASpecificObjectWithColor(tmp,'S','Y');
                             log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers le cube jaune sans spécification de la distance");
                             printf("Le robot va avancer d'un mètre vers le cube jaune.\n");
                             log_file("Analyse.c --- Traitement correctement effectué.");
                             return 1;
                         }
                         else if (isYellowColorPresent == 0 && isBlueColorPresent == 1 && isRedColorPresent == 0)
                         {
                             structObject* tmp = imageTreatmentCalling(choice);
                             log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers le cube bleue sans spécification de la distance");
                             printf("Le robot va avancer d'un mètre vers le cube bleue.\n");
                             log_file("Analyse.c --- Traitement correctement effectué.");
                             return 1;
                         }
                         else if (isYellowColorPresent == 0 && isBlueColorPresent == 0 && isRedColorPresent == 1)
                         {
                             structObject* tmp = imageTreatmentCalling(choice);
                             int positionObject = isThereASpecificObjectWithColor(tmp,'S','O');
                             log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers le cube rouge sans spécification de la distance");
                             printf("Le robot va avancer d'un mètre vers le cube rouge.\n");
                             log_file("Analyse.c --- Traitement correctement effectué.");
                             return 1;
                         }
                     }
                     else
                     {
                         log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'avant sans spécification de la distance");
                         printf("Le robot va avancer d'un mètre.\n");
                         log_file("Analyse.c --- Traitement correctement effectué.");
                         return 1;
                     }
                }
                else if (isBackwardMovementWordPresent != -1)
                {
                    log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'arrière sans spécification de la distance");
                    printf("Le robot va reculer d'un mètre.\n");
                    log_file("Analyse.c --- Traitement correctement effectué.");
                    return 1;
                }
                else if (isMovementWordPresent != -1)
                {
                    if(isForwardDirectionPresent != -1)
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'avant sans spécification de la distance");
                        printf("Le robot va avancer d'un mètre.\n");
                        log_file("Analyse.c --- Traitement correctement effectué.");
                        return 1;
                    }
                    else if(isBackwardDirectionPresent != -1)
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'arrière sans spécification de la distance");
                        printf("Le robot va reculer d'un mètre.\n");
                        log_file("Analyse.c --- Traitement correctement effectué.");
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
                    printf("Le traitement de la phrase n'est pas parvenu a déterminer le sens de la phrase.\nle robot ne va rien faire.\n");
                    return 0;
                }


            }
            else
            {
                log_file("Analyse.c --- Le traitement de la phrase n'est pas parvenu à trouver le sens de la phrase.");
                printf("Le traitement de la phrase n'est pas parvenu a déterminer le sens de la phrase.\nle robot ne va rien faire.\n");
                return 0;
            }
        }

    }
    else
    {
        log_file("Analyse.c --- Le traitement de la phrase a décelé une négation.");
        printf("Le robot ne va rien faire.\n");
        return 0;
    }
}