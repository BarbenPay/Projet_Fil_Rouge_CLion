//
// Created by jean-baptiste on 25/12/23.
//
#include "Decoupage.h"

#include <string.h>
#include <stdlib.h>
#include "../Log/fichier_Log.h"



Phrase * init_Sentence(){ //Permet d'initialiser la phrase la structure de la phrase qui sera utilisé en sortie du découpage
    Phrase * res = (Phrase *) malloc(sizeof(Phrase));

    if(res == NULL){
        log_file("Découpage.c --- Erreur d'allocation de mémoire pour la structure Phrase.");
        exit(EXIT_FAILURE);
    }

    res->wordArray = NULL;

    res->wordNumber = 0;

    return res;
} //initialise une structure de type Phrase


Phrase* decoupage(char* phrase){ // découpe la phrase en une structure composé du nombre de mot et du tableau des différents mots de la phrase




    int lenght_sentence = strlen( phrase )+1; /* Taille de la phrase sans le caractère null de fin de chaine */

    char* toSend = (char*)malloc(sizeof(char)*(36+ lenght_sentence));

    strcpy(toSend,"Démarrage du découpage de la phrase: ");

    strcat(toSend,phrase);

    log_file(toSend); //Affichage dans le fichier log du démarage de la fonction découpage

    free(toSend);

    Phrase* res = init_Sentence(); //initialisation de la phrase de sortie

    char* tmp_word = (char*) malloc(sizeof(char)*50); /* String temporaire stockant le mot, il sera modifier pour avoir une taille conforme au mot */

    if (tmp_word == NULL){
        log_file("Découpage.c --- Erreur d'allocation de mémoire pour tmp_word");
        exit(EXIT_FAILURE);
    }

    memset(tmp_word, 0, sizeof(char) * 50);


    int number_of_word = 0;






    for (int i = 0; i < lenght_sentence; i++){

        if ((phrase[i]== ' ')||(phrase[i]=='\0') || (phrase[i] == '\'')){

            if (strlen(tmp_word) != 0){

                char* right_size_word_tmp = (char*) malloc(sizeof(char) * strlen(tmp_word) + 1);

                if (right_size_word_tmp == NULL){
                    log_file("Découpage.c --- Erreur d'allocation de mémoire pour right_size_word_tmp");
                    exit(EXIT_FAILURE);
                }

                strcpy(right_size_word_tmp,tmp_word);

                res->wordArray = (char**) realloc(res->wordArray, sizeof(char*) * (number_of_word + 1));

                if (res->wordArray== NULL){
                    log_file("Découpage.c --- Erreur dans la ré-allocation de mémoire pour res.");
                    exit(EXIT_FAILURE);
                }

                res->wordArray[number_of_word] = right_size_word_tmp;

                number_of_word += 1;

                memset(tmp_word, 0, sizeof(char) * 50);


            }

        }else{

            if (strlen(tmp_word)==0){


                tmp_word[0] = phrase[i];

            }else{

                tmp_word[strlen(tmp_word)] = phrase[i];

            }
        }
    }

    free(tmp_word);
    res->wordNumber = number_of_word;
    log_file("Découpage.c --- Découpage correctement effectué.");
    return res;

}// Découpage de la phrase passée en paramètre et renvoie une structure composée des différents mots en chaîne de caractère