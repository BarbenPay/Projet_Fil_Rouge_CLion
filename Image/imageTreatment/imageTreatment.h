//
// Created by Jean-Baptiste Salanie on 23/01/2024.
//

#ifndef PROJET_FIL_ROUGE_CLION_IMAGETREATMENT_H
#define PROJET_FIL_ROUGE_CLION_IMAGETREATMENT_H

#include "../ObjectAnalysis/objectAnalysis.h"


picture_struct* pictureStructFromFileAdress(char* adress);

void encadrement_objet( picture_struct* input_image, object* input_object_tab ,int* cpt);

void propagation(object* input_struct_object,int*** input_image,int width,int height);

void verif_objet(object* input_struct_object);

#endif //PROJET_FIL_ROUGE_CLION_IMAGETREATMENT_H
