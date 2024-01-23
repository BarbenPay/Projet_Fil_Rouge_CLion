//
// Created by Jean-Baptiste Salanie on 21/01/2024.
//

#ifndef PROJET_FIL_ROUGE_CLION_TRAITEMENT_IMAGE_H
#define PROJET_FIL_ROUGE_CLION_TRAITEMENT_IMAGE_H

typedef struct image
{
    int height;
    int width;
    int dimension;
    int *** image;
}picture_struct;

typedef struct image_binaire
{
    int height;
    int width;
    int dimension;
    int *** image;
}binary_picture_struct;


picture_struct* pictureStructFromFileAdress(char* adress);

binary_picture_struct* binaryPictureStructFromPictureStruct (picture_struct* input_struct);

void saveBinaryImageToJpg(binary_picture_struct *binary_struct);

#endif //PROJET_FIL_ROUGE_CLION_TRAITEMENT_IMAGE_H
