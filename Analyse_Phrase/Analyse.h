//
// Created by Jean-Baptiste Salanie on 01/01/2024.
//

#ifndef PROJET_FIL_ROUGE_CLION_ANALYSE_H
#define PROJET_FIL_ROUGE_CLION_ANALYSE_H

#include "../Regroupement/Regroupement.h"
#include "../Menu/menu.h"

int charToNumber(char* numberChar);




int foundColorObjectBoolToHandleForwardMovementToObject(int objectCode, int yellowCode, int blueCode, int redCode, inputWithLanguageChoice langue);

int foundColorObjectBoolToHandleRotatingMovementToObject(int objectCode, int yellowCode, int blueCode, int redCode, inputWithLanguageChoice langue);

int foundColorObjectBoolToHandleForwardMovementToObjectWithNumberAndUnite(int objectCode, int yellowCode, int blueCode, int redCode, int number, int uniteCode,
                                                                          inputWithLanguageChoice languageChoice);




int handleForwardMovementToObject (int sphereCode, int yellowCode, int blueCode, int redCode, inputWithLanguageChoice langue);

int handleRotatingMovementToObject (int objectCode, int yellowCode, int blueCode, int redCode, inputWithLanguageChoice langue);

int handleForwardMovementToObjectWithNumberAndUnite(int objectCode, int yellowCode, int blueCode, int redCode, int number, int uniteCode,
                                                    inputWithLanguageChoice languageChoice);

int analyse(sentenceTypeStruct* phrase, inputWithLanguageChoice langue);

#endif //PROJET_FIL_ROUGE_CLION_ANALYSE_H
