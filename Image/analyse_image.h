//
// Created by Jean-Baptiste Salanie on 23/01/2024.
//

#ifndef PROJET_FIL_ROUGE_CLION_ANALYSE_IMAGE_H
#define PROJET_FIL_ROUGE_CLION_ANALYSE_IMAGE_H

typedef struct image
{
    int height;
    int width;
    int dimension;
    int *** image;
}picture_struct;

typedef struct objet{
    int coor_H;
    int coor_G;
    int coor_D;
    int coor_B;
    char couleur;
    char nature;
    char position;
}object;



picture_struct* pictureStructFromFileAdress(char* adress);

void encadrement_objet( picture_struct* input_image, object* input_object_tab ,int* cpt);

char detectercouleur(int* rgb);

void propagation(object* input_struct_object,int*** input_image,int width,int height);

void verif_objet(object* input_struct_object);

char detectionGris(int r, int g, int b);

#endif //PROJET_FIL_ROUGE_CLION_ANALYSE_IMAGE_H
