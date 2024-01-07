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
    int isBackwardMovementWordPresent = -1, isForwardMovementWordPresent = -1, isRotatingWordPresent = -1, isMovementWordPresent = -1, isForwardDirectionPresent = -1, isBackwardDirectionPresent = -1, isRightDirectionPresent = -1, isLeftDirectionPresent = -1,isNumberPresent = -1, isObjectPresent = -1, isNegationPresent = 0, isThereUnite = 0;

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
            isThereUnite += 1; // si isThereUnite est égale à 1, alors le programme peut savoir que l'unité est le mètre
        }else if(phrase[i]->typeWord == 51){
            isThereUnite += 2; // si isThereUnite est égale à 2, alors le programme peut savoir que l'unité est le centimètre
        }
    } //Analyse des types de mots pour pouvoir comprendre la phrase et initilisation des variables


    if(isNegationPresent ==0 )
    {

        if(isNumberPresent != 0)
        {

            if((isThereUnite == 1) || (isThereUnite == 2))
            {

                if(isForwardMovementWordPresent != -1)
                {
                    log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'avant avec une spécification de la distance.");
                    if(isThereUnite == 1)
                    {
                        printf("Le robot va avancer de %d mètre(s).\n", charToNumber(phrase[isNumberPresent]->word));
                    }
                    else
                    {
                        printf("Le robot va avancer de %d centimètre(s).\n", charToNumber(phrase[isNumberPresent]->word));
                    }
                    log_file("Analyse.c --- Traitement correctement effectué.");
                    return 1;
                }
                else if(isBackwardMovementWordPresent != -1)
                {

                    log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'arrière avec une spécification de la distance.");
                    if(isThereUnite == 1)
                    {

                        printf("Le robot va reculer de %d mètre(s).\n", charToNumber(phrase[isNumberPresent]->word));

                    }
                    else
                    {

                        printf("Le robot va reculer de %d centimètre(s).\n", charToNumber(phrase[isNumberPresent]->word));

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
                            printf("Le robot va avancer de %d mètre(s).\n", charToNumber(phrase[isNumberPresent]->word));
                        }
                        else
                        {
                            printf("Le robot va avancer de %d centimètre(s).\n", charToNumber(phrase[isNumberPresent]->word));
                        }
                        log_file("Analyse.c --- Traitement correctement effectué.");
                        return 1;
                    }
                    else if(isBackwardDirectionPresent != -1)
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'arrière avec une spécification de la distance.");
                        if(isThereUnite == 1)
                        {

                            printf("Le robot va reculer de %d mètre(s).\n", charToNumber(phrase[isNumberPresent]->word));

                        }
                        else
                        {

                            printf("Le robot va reculer de %d centimètre(s).\n", charToNumber(phrase[isNumberPresent]->word));

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
                    printf("L'unité de base de ce programme est le mètre.\nSi vous souhaitiez utiliser le centimètre, n'oubliez pas de préciser l'unité ;).\nLe robot va avancer de %d mètre(s).\n", charToNumber(phrase[isNumberPresent]->word));
                    log_file("Analyse.c --- Traitement correctement effectué.");
                    return 1;
                }
                else if(isBackwardMovementWordPresent != -1)
                {

                    log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'arrière avec une spécification de la distance.");
                    printf("L'unité de base est le mètre. Si vous souhaitiez utiliser le centimètre, n'oubliez pas de préciser l'unité ;).\nLe robot va reculer de %d mètre(s).\n", charToNumber(phrase[isNumberPresent]->word));
                    log_file("Analyse.c --- Traitement correctement effectué.");
                    return 1;

                }
                else if(isMovementWordPresent != -1)
                {
                    if(isForwardDirectionPresent != -1)
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'avant avec une spécification de la distance.");
                        printf("L'unité de base est le mètre. Si vous souhaitiez utiliser le centimètre, n'oubliez pas de préciser l'unité ;).\nLe robot va avancer de %d mètre(s).\n", charToNumber(phrase[isNumberPresent]->word));
                        log_file("Analyse.c --- Traitement correctement effectué.");
                        return 1;
                    }
                    else if(isBackwardDirectionPresent != -1)
                    {
                        log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'arrière avec une spécification de la distance.");
                        printf("L'unité de base est le mètre. Si vous souhaitiez utiliser le centimètre, n'oubliez pas de préciser l'unité ;).\nLe robot va reculer de %d mètre(s).\n", charToNumber(phrase[isNumberPresent]->word));
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
            else
            {
                log_file("Analyse.c --- Le traitement de la phrase n'est pas parvenu à trouver le sens de la phrase.");
                printf("Le traitement de la phrase n'est pas parvenu a déterminer le sens de la phrase car vous avez rentré 2 unités.\nle robot ne va rien faire.\n");
                return 0;
            }
        }
        else
        {
            if(isThereUnite == 0)
            {

                if(isForwardMovementWordPresent != -1)
                {
                    log_file("Analyse.c --- Le traitement de la phrase a déterminé qu'elle signifiait un mouvement vers l'avant sans spécification de la distance");
                    printf("Le robot va avancer d'un mètre.\n");
                    log_file("Analyse.c --- Traitement correctement effectué.");
                    return 1;
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