//
// Created by Jean-Baptiste Salanie on 21/01/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include "traitement_image.h"
#include "../Log/fichier_Log.h"

#define SEUIL_BINAIRE 60

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

    res->image = (int***)malloc(res->width * sizeof(int**));
    for(int i = 0; i < res->width; i++){
        res->image[i] = (int**)malloc(res->height * sizeof(int*));
        for (int j = 0; j < res->height; j++){
            res->image[i][j]=(int*)malloc(sizeof(int)* res->dimension);
        }
    }


    for(int i = 0; i<res->width;i++) {
        for (int j = 0; j < res->dimension; j++) {
            for (int v = 0; v < res->height; v++) {
                fscanf(picture, "%d", &res->image[i][v][j]);
            }
        }
    }
    return res;
}

binary_picture_struct* binaryPictureStructFromPictureStruct (picture_struct* input_struct)
{
    log_file("traitement_image.c --- Démarrage de la binarisation de l'image.");

    binary_picture_struct* res = (binary_picture_struct *)malloc(sizeof(binary_picture_struct));
    if ( res == NULL )
    {
        log_file("traitement_image.c --- Erreur dans lors de l'allocation mémoire de la structure binary_picture_struct.");
        exit(EXIT_FAILURE);
    }

    res->height = input_struct->height;
    res->width = input_struct->width;
    res->dimension = input_struct->dimension;

    res->image = (int***)malloc(res->width * sizeof(int**));
    for(int i = 0; i < res->width; i++){
        res->image[i] = (int**)malloc(res->height * sizeof(int*));
        for (int j = 0; j < res->height; j++){
            res->image[i][j]=(int*)malloc(res->dimension * sizeof(int));
        }
    }

    for (int width = 0; width < res->width; width++)
    {
        for (int height = 0; height < res->height; height++)
        {
            int isAboveThreshold = 0;
            for (int i = 0; i < res->dimension; i++)
            {
                if (input_struct->image[width][height][i] > SEUIL_BINAIRE)
                {
                    isAboveThreshold = 1;
                    break;  // Sortir de la boucle dès qu'une composante est supérieure au seuil
                }
            }

            if (isAboveThreshold)
            {
                res->image[width][height][0] = 255;
                res->image[width][height][1] = 255;
                res->image[width][height][2] = 255;
            }
            else
            {
                res->image[width][height][0] = 0;
                res->image[width][height][1] = 0;
                res->image[width][height][2] = 0;
            }
        }
    }

    return res;

}

void saveBinaryImageToJpg(binary_picture_struct *binary_struct)
{
    log_file("traitement_image.c --- Sauvegarde de l'image binaire au format JPG.");

    FILE *output_file = fopen("../binary_picture_tmp.png", "wb");
    if (output_file == NULL)
    {
        log_file("traitement_image.c --- Erreur lors de l'ouverture du fichier de sortie.");
        exit(EXIT_FAILURE);
    }

    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);
    jpeg_stdio_dest(&cinfo, output_file);

    cinfo.image_width = w;
    cinfo.image_height = binary_struct->height;
    cinfo.input_components = binary_struct->dimension;
    cinfo.in_color_space = JCS_RGB;

    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, 75, TRUE);

    jpeg_start_compress(&cinfo, TRUE);

    JSAMPROW row_pointer[1];
    int row_stride = cinfo.image_width * cinfo.input_components;

    for (int height = 0; height < binary_struct->height; height++)
    {
        row_pointer[0] = (JSAMPROW)&binary_struct->image[height][0][0];
        jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_compress(&cinfo);
    fclose(output_file);
    jpeg_destroy_compress(&cinfo);
}