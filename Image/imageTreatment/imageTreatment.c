//
// Created by Jean-Baptiste Salanie on 23/01/2024.
//

#include "imageTreatment.h"
#include "../../Log/fichier_Log.h"
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


    for(int i = 0; i<res->width;i++)
    {
        for (int j = 0; j < res->dimension; j++)
        {
            for (int v = 0; v < res->height; v++)
            {
                fscanf(picture, "%d", &res->image[i][v][j]);
            }
        }
    }
    log_file("analyse_image.c --- Affectation des données dans la structure picture_struct correctement effectuée.");
    return res;
}

void encadrement_objet( picture_struct* input_image, object* input_object_tab ,int* cpt)
{

    log_file("analyse_image.c --- Début de l'analyse de l'image");


    char color;
    int Bool;
    int aire = 6; /*zone morte autour des objets deja detectés*/
    int compteur=0;




    for (int i = 0; i < input_image->height; ++i) /*Parcours de l'image pixel par pixel*/
    {
        for (int j = 0; j <input_image->width; ++j)
        {
            /*mettre la couleur du pixel dans un variable*/
            color = detectercouleur(input_image->image[i][j]);

            if((compteur == 0) && (color != 'N')) /*premiere iteration de l'encadrement*/
            {

                object* buffer=&input_object_tab[compteur]; /*premier pixel trouver on initialise la couleur et les coordonné dans tab[0]*/

                buffer->coor_H = i;
                buffer->coor_B = i;
                buffer->coor_D = j;
                buffer->coor_G = j;

                propagation(buffer,input_image->image,input_image->width,input_image->height);
                verif_objet(buffer);
                donner_position(buffer,input_image->width);
                couleur_objet(buffer,input_image->image);
                nature_objet(buffer,input_image->image);
                compteur++;

            }

            else if(compteur != 0 && color != 'N')
            {

                Bool = 0;

                for(int t = 0 ; t < compteur ; t++)
                {

                    object* buffer = &input_object_tab[t];
                    //si le pixel est dans la zone d'un autre objet

                    if(buffer->nature != 'N')
                    {

                        if(j <= (buffer->coor_D + buffer->coor_D / aire) && (j >= buffer->coor_G - buffer->coor_G/aire) && (i <= buffer->coor_B + buffer->coor_B/aire) && (i >= buffer->coor_H) && Bool == 0)
                        {

                            Bool = 1;
                            //printf("bool = 1\n");
                        }
                    }
                }
                // Si on se trouve dans un objet deja cree, on n'en creer pas un nouveau
                if(Bool == 0){
                    //premier pixel trouver on initialise la couleur et les coordonné dans tab[compteur]
                    object* buffer=&input_object_tab[compteur];


                    buffer->coor_H = i;
                    buffer->coor_B = i;
                    buffer->coor_D = j;
                    buffer->coor_G = j;


                    propagation(buffer,input_image->image,input_image->width,input_image->height);
                    verif_objet(buffer);
                    donner_position(buffer,input_image->width);
                    couleur_objet(buffer,input_image->image);
                    nature_objet(buffer,input_image->image);
                    compteur++;
                }
            }
        }
    }
    *cpt = compteur;
    log_file("imageTreatment.c --- Fin de l'analyse de l'image.");
    char* toSend = (char*)malloc((77+(sizeof(compteur)/4) * sizeof(char)));
    if(toSend == NULL)
    {
        log_file("imageTreatment.c --- Erreur dans l'allocation de la variable toSend dans la fonction encadrement_objet.");
        exit(EXIT_FAILURE);
    }
    sprintf(toSend, "imageTreatment.c --- L'analyse de l'image a trouvé %d potentielle(s) image(s).", compteur);
    log_file(toSend);
    free(toSend);
}

