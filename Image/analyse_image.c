//
// Created by Jean-Baptiste Salanie on 23/01/2024.
//

#include "analyse_image.h"
#include "../Log/fichier_Log.h"


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
                    //printf("dans objet");
                }
                //printf("compteur :%d ",compteur);
            }
        }
    }
    *cpt = compteur;
}



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
        //printf("propa vers bas");
    }
    i=1;
    /*propa vers la droite avec verif pixel couleur*/
    /*on commence en bas et vers la droite*/
    while(detectercouleur(input_image[input_struct_object->coor_B][input_struct_object->coor_G + i]) != 'N' && (input_struct_object->coor_G+i) <= width ){
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
        while(detectercouleur(input_image[centre_vertical][centre_horizontal - i]) != 'N' && (centre_horizontal - i) >= 0){
            if(input_struct_object->coor_G > centre_horizontal - i){
                input_struct_object->coor_G = centre_horizontal - i;
            }
            i++;
            //printf("propa vers gauche +1");
        }
        i=1;
        //propagation vers D
        while(detectercouleur(input_image[centre_vertical][centre_horizontal + i]) != 'N' && (centre_horizontal + i) <= width){
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





char detectercouleur(int* rgb)
{
    char couleur;


    if (detectionGris(rgb[0],rgb[1],rgb[2]) == 'N'){
        return 'N';
    }


    // Appliquer la quantification sur les 2 premiers bits pour chaque composante
    int resultatRouge = quantificationDeuxBits(rgb[0]);
    int resultatVert = quantificationDeuxBits(rgb[1]);
    int resultatBleu = quantificationDeuxBits(rgb[2]);

    // Organiser les résultats dans un seul nombre sur 6 bits
    int resultatFinal = (resultatRouge << 4) | (resultatVert << 2) | resultatBleu;

    couleur = detectionCouleur(resultatFinal);

    return couleur;
}



void verif_objet(object* input_struct_object)
{
    int limite = 10;


    if( input_struct_object->coor_B != input_struct_object->coor_H ){
        if(input_struct_object->coor_B - input_struct_object->coor_H < limite || input_struct_object->coor_D - input_struct_object->coor_G < limite){
            input_struct_object->nature = 'N';
        }
        if((input_struct_object->coor_D - input_struct_object->coor_G) / (input_struct_object->coor_B - input_struct_object->coor_H) > 1.5 || (input_struct_object->coor_D - input_struct_object->coor_G) / (input_struct_object->coor_B - input_struct_object->coor_H) < 0.65){
            input_struct_object->nature = 'N';
        }
    }
    else{
        input_struct_object->nature = 'N';
        input_struct_object->position = 'N';
    }
}


char detectionGris(int r, int g, int b){
    int seuilGris = 30;

    // Calculer la différence maximale permise pour considérer le pixel comme gris
    int diffMaxGris = seuilGris;

    // Calculer les différences entre les composantes RGB
    int diffR = abs(r - b);
    int diffG = abs(g - b);
    int diffB = abs(b - r);

    // Vérifier la proximité des valeurs par rapport aux seuils
    if (diffR <= diffMaxGris && diffG <= diffMaxGris && diffB <= diffMaxGris) {
        return 'N';
    }
}
