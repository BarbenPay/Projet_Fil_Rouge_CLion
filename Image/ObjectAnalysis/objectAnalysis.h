//
// Created by Jean-Baptiste Salanie on 24/01/2024.
//

#ifndef PROJET_FIL_ROUGE_CLION_OBJECTANALYSIS_H
#define PROJET_FIL_ROUGE_CLION_OBJECTANALYSIS_H

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

void propagation(object* input_struct_object,int*** input_image,int width,int height);

void verif_objet(object* input_struct_object);

void donner_position(object* test,int largeur);

void couleur_objet(object* input_struct_object,int*** input_image);

void nature_objet(object* input_struct_object,int*** input_image);

#endif //PROJET_FIL_ROUGE_CLION_OBJECTANALYSIS_H