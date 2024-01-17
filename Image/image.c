//
// Created by Jean-Baptiste Salanie on 15/01/2024.
//


#include <stdio.h>
#include <stdlib.h>


int*** open_picture(char* address_picture){
    FILE* picture = fopen(address_picture, "r");
    int largeur = -1;
    int longueur = -1;
    int dimension = -1;
    fscanf(picture,"%d %d %d",&largeur,&longueur,&dimension);
    int*** matrice = (int***)malloc(largeur * sizeof(int**));
    for(int i = 0; i < largeur; i++){
        matrice[i] = (int**)malloc(longueur * sizeof(int*));
        for (int j = 0; j < longueur; j++){
            matrice[i][j]=(int*)malloc(sizeof(int)* dimension);
        }
    }


    for(int i = 0; i<largeur;i++){
        for(int j = 0; j<dimension;j++){
            for(int v = 0; v<longueur;v++){
                fscanf(picture,"%d", &matrice[i][v][j]);
            }
        }
    }
    return matrice;
}
