//
// Created by Jean-Baptiste Salanie on 28/12/2023.
//

#ifndef PROJET_FIL_ROUGE_CLION_FICHIER_LOG_H
#define PROJET_FIL_ROUGE_CLION_FICHIER_LOG_H


#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>



char* date();

int log_file(char* texte_A_Ajouter_Dans_Le_Fichier_Log);

int log_file_init();


#endif //PROJET_FIL_ROUGE_CLION_FICHIER_LOG_H
