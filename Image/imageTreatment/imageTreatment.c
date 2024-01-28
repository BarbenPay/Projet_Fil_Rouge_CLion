//
// Created by Jean-Baptiste Salanie on 23/01/2024.
//

#include "imageTreatment.h"
#include "../../Log/logFile.h"
#include "../ColorAnalysis/colorAnalysis.h"


picture_struct* pictureStructFromFileAdress(char* adress)
{
    log_file("traitement_image.c --- Initialisation de la structure picture_struct.");

    picture_struct* res = (picture_struct*)malloc(sizeof(picture_struct));
    if ( res == NULL )
    {
        log_file("traitement_image.c --- Erreur dans lors de l'allocation mémoire de la structure picture_struct.");
        exit(EXIT_FAILURE);
    }

    FILE* picture = fopen(adress, "r");
    if( picture == NULL )
    {
        log_file("traitement_image.c --- Erreur dans l'ouverture de l'image originale.");
        exit(EXIT_FAILURE);
    }

    fscanf(picture,"%d %d %d",&res->width,&res->height,&res->dimension);

    if(res->dimension != 3)
    {
        log_file("analyse_image.c --- L'analyse de l'image a détecté que l'image n'était pas en couleur. L'analyse ne peut donc pas interpréter cette image.");
        exit(EXIT_FAILURE);
    }

    res->image = (int***)malloc(res->width * sizeof(int**));
    for(int i = 0; i < res->width; i++)
    {
        res->image[i] = (int**)malloc(res->height * sizeof(int*));
        for (int j = 0; j < res->height; j++)
        {
            res->image[i][j]=(int*)malloc(sizeof(int)* res->dimension);
        }
    }

    for (int j = 0; j < res->dimension; j++)
    {
        for(int i = 0; i<res->height;i++)
        {
            for (int v = 0; v < res->width; v++)
            {
                fscanf(picture, "%d", &res->image[i][v][j]);
            }
        }
    }
    log_file("analyse_image.c --- Affectation des données dans la structure picture_struct correctement effectuée.");

    return res;
}

structObject* initStructObject()
{

    structObject* res = (structObject*)malloc(sizeof(structObject));

    res->objectTab=NULL;
    res->counter=0;

    return res;

}

void createNewObject(structObject* inputStructObject, int horizontalIndex, int verticalIndex, picture_struct* input_image)
{
    inputStructObject->objectTab=(object**) realloc(inputStructObject->objectTab, (inputStructObject->counter+1) * sizeof(object*));

    if (inputStructObject->objectTab == NULL)
    {
        free(inputStructObject->objectTab);
        log_file("Erreur lors de la réallocation de mémoire pour input_object_tab.");
        exit(EXIT_FAILURE);
    }

    object* tmp = (object*) malloc (sizeof(object));


    tmp->coor_H = horizontalIndex;
    tmp->coor_B = horizontalIndex;
    tmp->coor_D = verticalIndex;
    tmp->coor_G = verticalIndex;

    propagation(tmp, input_image->image, input_image->width, input_image->height);
    verif_objet(tmp);
    donner_position(tmp, input_image->width);
    couleur_objet(tmp, input_image->image);
    nature_objet(tmp, input_image->image);


    if ( tmp->nature == 'N')
    {

        free (tmp);

    }
    else
    {

        inputStructObject->objectTab[inputStructObject->counter] = tmp;

        inputStructObject->counter++;
    }



}

structObject* encadrement_objet(picture_struct* input_image)
{

    log_file("analyse_image.c --- Début de l'analyse de l'image");

    structObject * res = initStructObject();

    char color;
    int Bool;
    int aire = 6; /*zone morte autour des objets déjà détectés*/

    for (int i = 0; i < input_image->height; ++i)
    {
        for (int j = 0; j < input_image->width; ++j)
        {
            color = detectercouleur(input_image->image[i][j]);

            if ((res->counter == 0) && (color != 'N'))
            {
                createNewObject(res, i, j, input_image);
            } else if (res->counter != 0 && color != 'N') {
                Bool = 0;

                for (int t = 0; t < res->counter; t++)
                {
                    object* buffer = res->objectTab[t];

                    if (buffer->nature != 'N')
                    {
                        if (j <= (buffer->coor_D + buffer->coor_D / aire) &&
                            (j >= buffer->coor_G - buffer->coor_G / aire) &&
                            (i <= buffer->coor_B + buffer->coor_B / aire) &&
                            (i >= buffer->coor_H) && Bool == 0)
                        {
                            Bool = 1;
                        }
                    }
                }

                if (Bool == 0)
                {
                    createNewObject(res, i, j, input_image);
                }
            }
        }
    }

    log_file("imageTreatment.c --- Fin de l'analyse de l'image.");
    char* toSend = (char*)malloc((77 + (sizeof(res->counter) / 4) * sizeof(char)));
    if (toSend == NULL)
    {
        free(toSend);
        log_file("imageTreatment.c --- Erreur dans l'allocation de la variable toSend dans la fonction encadrement_objet.");
        exit(EXIT_FAILURE);
    }

    sprintf(toSend, "imageTreatment.c --- L'analyse de l'image a trouvé %d potentielle(s) objet(s).", res->counter);
    log_file(toSend);
    free(toSend);
    objectTabToLogFile(res);


    return res;
}

void objectTabToLogFile(structObject* inputStructObject)
{

    for (int i = 0; i < inputStructObject->counter;i ++)
    {
        object* tmp = inputStructObject->objectTab[i];
        if(tmp->nature == 'S')
        {

            int coordHorizontal = (tmp->coor_G + (tmp->coor_D - tmp->coor_G)/2);
            int coordVertical = (tmp->coor_H + (tmp->coor_B - tmp->coor_H)/2);

            char* toSend = (char*)malloc(91 * sizeof(char));

            switch (tmp->couleur)
            {

                case 'O':
                    sprintf(toSend,"imageTreatment.c --- Une sphère orange a été détectée aux coordonnées (x= %d, y= %d).", coordHorizontal,coordVertical);
                    break;
                case 'B':
                    sprintf(toSend,"imageTreatment.c --- Une sphère bleue a été détectée aux coordonnées (x= %d, y= %d).", coordHorizontal,coordVertical);
                    break;
                case 'J':
                    sprintf(toSend,"imageTreatment.c --- Une sphère jaune a été détectée aux coordonnées (x= %d, y= %d).", coordHorizontal,coordVertical);
                    break;

            }
            log_file(toSend);
            free(toSend);
        }
        else if (tmp->nature == 'C')
        {

            int coordHorizontal = (tmp->coor_G + (tmp->coor_D - tmp->coor_G)/2);
            int coordVertical = (tmp->coor_H + (tmp->coor_B - tmp->coor_H)/2);

            char* toSend = (char*)malloc( 87 * sizeof(char));
            switch (tmp->couleur)
            {

                case 'O':
                    sprintf(toSend,"imageTreatment.c --- Un cube orange a été détecté aux coordonnées (x= %d, y= %d).", coordHorizontal,coordVertical);
                    break;
                case 'B':
                    sprintf(toSend,"imageTreatment.c --- Un cube bleu a été détecté aux coordonnées (x= %d, y= %d).", coordHorizontal,coordVertical);
                    break;
                case 'J':
                    sprintf(toSend,"imageTreatment.c --- Un cube jaune a été détecté aux coordonnées (x= %d, y= %d).", coordHorizontal,coordVertical);
                    break;

            }
            log_file(toSend);
            free(toSend);

        }

    }

}

int isThereASpecificObjectWithColor (structObject* inputStructObject, char shape, char color)
{

    for(int i = 0; i < inputStructObject->counter; i ++)
    {
        if(inputStructObject->objectTab[i]->nature == shape)
        {
            if(inputStructObject->objectTab[i]->couleur == color)
            {
                return 1;
            }
        }


    }
    return -1;

}

int isThereASpecificObject (structObject* inputStructObject, char shape)
{

    for(int i = 0; i < inputStructObject->counter; i ++)
    {
        if(inputStructObject->objectTab[i]->nature == shape)
        {
            return 1;
        }


    }
    return -1;

}

void freeObjectStruct(structObject* inputStructObject)
{

    for (int i = 0; i < inputStructObject->counter; i++)
    {

        free(inputStructObject->objectTab[i]);

    }

    free(inputStructObject);

}
