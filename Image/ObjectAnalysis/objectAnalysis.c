//
// Created by Jean-Baptiste Salanie on 24/01/2024.
//

#include "objectAnalysis.h"
#include "../ColorAnalysis/colorAnalysis.h"


void propagation(object* input_struct_object,int*** input_image,int width,int height)
{
    int i=1;
    int centre_horizontal;
    int centre_vertical;
    /*propa vers le bas avec verif pixel couleur*/
    while((detectercouleur(input_image[input_struct_object->coor_H + i][input_struct_object->coor_G]) != 'N') && ((input_struct_object->coor_H + i) <= height))
    {
        input_struct_object->coor_B = input_struct_object->coor_H+i;
        i++;
    }
    i=1;
    /*propa vers la droite avec verif pixel couleur*/
    /*on commence en bas et vers la droite*/
    while(((input_struct_object->coor_G+i) <= width-1) && (detectercouleur(input_image[input_struct_object->coor_B][input_struct_object->coor_G + i]) != 'N')){
        input_struct_object->coor_D = input_struct_object->coor_G+i;
        i++;
        //printf("propa vers droite");
    }
    /*boucle de verif avec centre*/
    for(int iteration = 0; iteration<2;iteration++){
        centre_horizontal = input_struct_object->coor_D - ((input_struct_object->coor_D - input_struct_object->coor_G)/2);
        centre_vertical = input_struct_object->coor_B - ((input_struct_object->coor_B - input_struct_object->coor_H)/2);
        //printf("centre hori : %d ", centre_horizontal);
        //printf("centre verti : %d ", centre_vertical);
        i=1;
        //propagation vers gauche
        while((centre_horizontal-i >=0)&&(detectercouleur(input_image[centre_vertical][centre_horizontal - i]) != 'N')){
            if(input_struct_object->coor_G > centre_horizontal - i){
                input_struct_object->coor_G = centre_horizontal - i;
            }
            i++;
            //printf("propa vers gauche +1");
        }
        i=1;
        //propagation vers D
        while(((centre_horizontal + i) <= width-1) && (detectercouleur(input_image[centre_vertical][centre_horizontal + i]) != 'N')){
            if(input_struct_object->coor_D < centre_horizontal + i){
                input_struct_object->coor_D = centre_horizontal + i;
            }
            i++;
            //printf("propa vers droite +1");
        }
        i=1;
        //propagation vers bas
        while(detectercouleur(input_image[centre_vertical + i][centre_horizontal]) != 'N' && (centre_vertical + i) <= height){
            if(input_struct_object->coor_B < centre_vertical + i){
                input_struct_object->coor_B = centre_vertical + i;
            }
            i++;
            //printf("propa vers bas +1");
        }
    }
}

void verif_objet(object* input_struct_object)
{
    int limite = 10;


    if( input_struct_object->coor_B != input_struct_object->coor_H ){
        if(input_struct_object->coor_B - input_struct_object->coor_H < limite || input_struct_object->coor_D - input_struct_object->coor_G < limite){
            input_struct_object->nature = 'N';
        }
        if(((input_struct_object->coor_D - input_struct_object->coor_G) / (double)(input_struct_object->coor_B - input_struct_object->coor_H)) > 1.5 || (input_struct_object->coor_D - input_struct_object->coor_G) / (double)(input_struct_object->coor_B - input_struct_object->coor_H) < 0.65){
            input_struct_object->nature = 'N';
        }
    }
    else{
        input_struct_object->nature = 'N';
        input_struct_object->position = 'N';
    }
}

void donner_position(object* input_struct_object,int width)
{
    if(input_struct_object->nature != 'N')
    {

        if(input_struct_object->coor_G + ((input_struct_object->coor_D - input_struct_object->coor_G)/2) < 2 * width/5)
        {
            input_struct_object->position = 'G';
        }
        else if(input_struct_object->coor_G + ((input_struct_object->coor_D - input_struct_object->coor_G)/2) < 3 * width / 5)
        {
            input_struct_object->position = 'M';
        }
        else if(input_struct_object->coor_G + ((input_struct_object->coor_D - input_struct_object->coor_G)/2) < width)
        {
            input_struct_object->position = 'D';
        }
        else
        {
            input_struct_object->position = 'N';
        }
    }
}

void couleur_objet(object* input_struct_object,int*** input_image)
{
    int pos_horizontal = input_struct_object->coor_G + ((input_struct_object->coor_D - input_struct_object->coor_G)/2);

    int pos_vertical = input_struct_object->coor_H + ((input_struct_object->coor_B - input_struct_object->coor_H)/6);

    input_struct_object->couleur = detectercouleur(input_image[pos_vertical][pos_horizontal]);
}

/*donne la nature Sphere ou Cube*/
void nature_objet(object* input_struct_object,int*** input_image)
{
    /*test si l'objet n'as pas déja été tester et donner comme Non conforme*/
    if ( input_struct_object->nature == 'N')
    {
        return;
    }
    if ( input_struct_object->couleur != 'J' && input_struct_object->couleur != 'O' && input_struct_object->couleur != 'B')
    {
        input_struct_object->nature = 'N';
        return;
    }
    int delta = 15;
    int pourcentage = 10;
    /*coin tester haut gauche*/
    /*teste si le conctour est carré don soit sphere soit cube*/
    if(input_struct_object->coor_D - input_struct_object->coor_G + delta > input_struct_object->coor_B - input_struct_object->coor_H && input_struct_object->coor_D - input_struct_object->coor_G - delta < input_struct_object->coor_B - input_struct_object->coor_H){
        /*determine si sphere ou cube en regardent dans un coin si la couleur de l'objet y est*/
        if(input_struct_object->couleur == 'B'){
            if(detectercouleur(input_image[input_struct_object->coor_H + (input_struct_object->coor_B - input_struct_object->coor_H) / pourcentage ][input_struct_object->coor_G + (input_struct_object->coor_D - input_struct_object->coor_G) / pourcentage ]) == 'B'){
                input_struct_object->nature = 'C';
            }
            else{
                input_struct_object->nature = 'S';
            }
        }

        else if(input_struct_object->couleur == 'J'){
            if(detectercouleur(input_image[input_struct_object->coor_H + (input_struct_object->coor_B - input_struct_object->coor_H) / pourcentage ][input_struct_object->coor_G + (input_struct_object->coor_D - input_struct_object->coor_G) / pourcentage ]) == 'J'){
                input_struct_object->nature = 'C';
            }
            else{
                input_struct_object->nature = 'S';
            }
        }

        else if(input_struct_object->couleur == 'O'){
            if(detectercouleur(input_image[input_struct_object->coor_H + (input_struct_object->coor_B - input_struct_object->coor_H) / pourcentage ][input_struct_object->coor_G + (input_struct_object->coor_D - input_struct_object->coor_G) / pourcentage ]) == 'O'){
                input_struct_object->nature = 'C';
            }
            else{
                input_struct_object->nature = 'S';
            }
        }
    }
        /*la meme chose que au dessus mais ne detecte que si c'est un cube de travers*/
    else if((input_struct_object->coor_D - input_struct_object->coor_G) / (input_struct_object->coor_B - input_struct_object->coor_H) > 1){
        if(input_struct_object->couleur == 'B'){
            if(detectercouleur(input_image[input_struct_object->coor_H + (input_struct_object->coor_B - input_struct_object->coor_H) / pourcentage ][input_struct_object->coor_G + (input_struct_object->coor_D - input_struct_object->coor_G) / pourcentage ]) == 'B'){
                input_struct_object->nature = 'C';
            }
            else{
                input_struct_object->nature = 'N';
            }
        }

        else if(input_struct_object->couleur == 'J'){
            if(detectercouleur(input_image[input_struct_object->coor_H + (input_struct_object->coor_B - input_struct_object->coor_H) / pourcentage ][input_struct_object->coor_G + (input_struct_object->coor_D - input_struct_object->coor_G) / pourcentage ]) == 'J'){
                input_struct_object->nature = 'C';
            }
            else{
                input_struct_object->nature = 'N';
            }
        }

        else if(input_struct_object->couleur == 'O'){
            if(detectercouleur(input_image[input_struct_object->coor_H + (input_struct_object->coor_B - input_struct_object->coor_H) / pourcentage ][input_struct_object->coor_G + (input_struct_object->coor_D - input_struct_object->coor_G) / pourcentage ]) == 'O'){
                input_struct_object->nature = 'C';
            }
            else{
                input_struct_object->nature = 'N';
            }
        }
    }
    else{
        input_struct_object->nature = 'N';
    }
}