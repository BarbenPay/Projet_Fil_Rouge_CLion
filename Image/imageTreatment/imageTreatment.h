//
// Created by Jean-Baptiste Salanie on 23/01/2024.
//

#ifndef PROJET_FIL_ROUGE_CLION_IMAGETREATMENT_H
#define PROJET_FIL_ROUGE_CLION_IMAGETREATMENT_H

#include "../ObjectAnalysis/objectAnalysis.h"


picture_struct* pictureStructFromFileAdress(char* adress);

structObject* initStructObject();

void createNewObject(structObject* inputStructObject, int horizontalIndex, int verticalIndex, picture_struct* input_image);

structObject* encadrement_objet(picture_struct* input_image);

void objectTabToLogFile(structObject* inputStructObject);

void freeObjectStruct(structObject* inputStructObject);

#endif //PROJET_FIL_ROUGE_CLION_IMAGETREATMENT_H
