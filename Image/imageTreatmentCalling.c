//
// Created by Jean-Baptiste Salanie on 24/01/2024.
//

#include <printf.h>
#include "imageTreatmentCalling.h"


void sortie_objet(object* inputObject,int x)
{
        printf("Objet n %d \n",x+1);
        printf("Limite gauche= %d \n",inputObject->coor_G);
        printf("Limite droite= %d \n",inputObject->coor_D);
        printf("Limite haute= %d \n",inputObject->coor_H);
        printf("Limite bas= %d \n",inputObject->coor_B);
        printf("Couleur = %c \n",inputObject->couleur);
        printf("Nature = %c \n",inputObject->nature);
        printf("Position = %c \n",inputObject->position);
        printf("\n\n");
}

void imageTreatmentCalling(char* pictureAdress)
{

    picture_struct* original_image = pictureStructFromFileAdress(pictureAdress);

    structObject* ObjectArray = encadrement_objet(original_image);

    if (ObjectArray->counter > 0)
    {

        for(int i = 0; i < ObjectArray->counter; i++)
        {

            sortie_objet(ObjectArray->objectTab[i],i);

        }

    }
    else
    {
        printf("pas d'objet dans l'image\n");
    }



}
