//
// Created by Jean-Baptiste Salanie on 01/01/2024.
//

#ifndef PROJET_FIL_ROUGE_CLION_ANALYSE_H
#define PROJET_FIL_ROUGE_CLION_ANALYSE_H

#include "../Regroupement/Regroupement.h"
#include "../Menu/menu.h"

int charToNumber(char* numberChar);

int foundColorObjectBoolToHandleForwardMovementToObject(int objectCode, int yellowCode, int blueCode, int redCode, Valeur langue);

int foundColorObjectBoolToHandleRotatingMovementToObject(int objectCode, int yellowCode, int blueCode, int redCode, Valeur langue);

int handleForwardMovementToObject (int sphereCode, int yellowCode, int blueCode, int redCode, Valeur langue);

int handleRotatingMovementToObject (int objectCode, int yellowCode, int blueCode, int redCode, Valeur langue);

int analyse(sentenceTypeStruct* phrase, Valeur langue);

#endif //PROJET_FIL_ROUGE_CLION_ANALYSE_H
