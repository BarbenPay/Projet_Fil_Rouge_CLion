//
// Created by Jean-Baptiste Salanie on 01/01/2024.
//

#ifndef PROJET_FIL_ROUGE_CLION_ANALYSE_H
#define PROJET_FIL_ROUGE_CLION_ANALYSE_H

#include "../Regroupement/Regroupement.h"

int charToNumber(char* numberChar);



int foundColorObjectBoolToHandleForwardMovementToObject(int objectCode, int yellowCode, int blueCode, int redCode);

int foundColorObjectBoolToHandleRotatingMovementToObject(int objectCode, int yellowCode, int blueCode, int redCode);




int handleForwardMovementToObject (int sphereCode, int yellowCode, int blueCode, int redCode);

int handleRotatingMovementToObject (int objectCode, int yellowCode, int blueCode, int redCode);




int analyse(sentenceTypeStruct* phrase);

#endif //PROJET_FIL_ROUGE_CLION_ANALYSE_H
