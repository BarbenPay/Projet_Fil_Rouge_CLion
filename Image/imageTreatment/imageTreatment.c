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

    inputStructObject->objectTab[inputStructObject->counter] = (object*) malloc (sizeof(object));


    inputStructObject->objectTab[inputStructObject->counter]->coor_H = horizontalIndex;
    inputStructObject->objectTab[inputStructObject->counter]->coor_B = horizontalIndex;
    inputStructObject->objectTab[inputStructObject->counter]->coor_D = verticalIndex;
    inputStructObject->objectTab[inputStructObject->counter]->coor_G = verticalIndex;

    propagation(inputStructObject->objectTab[inputStructObject->counter], input_image->image, input_image->width, input_image->height);
    verif_objet(inputStructObject->objectTab[inputStructObject->counter]);
    donner_position(inputStructObject->objectTab[inputStructObject->counter], input_image->width);
    couleur_objet(inputStructObject->objectTab[inputStructObject->counter], input_image->image);
    nature_objet(inputStructObject->objectTab[inputStructObject->counter], input_image->image);

    inputStructObject->counter++;
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

    sprintf(toSend, "imageTreatment.c --- L'analyse de l'image a trouvé %d potentielle(s) image(s).", res->counter);
    log_file(toSend);
    free(toSend);


    return res;
}


