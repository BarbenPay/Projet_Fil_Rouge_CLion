//
// Created by mc2 on 15/01/24.
//

#include "header.h"
#include <stdio.h>
void main(void){
    int largeur=0;   /* a definir */
    int hauteur=0;
    int dimmention;
    scanf("%d",&largeur);
    scanf("%d",&hauteur);
    scanf("%d",&dimmention);
    if(dimmention != 3){
        printf("la photo n'est pas en couleur");
    }
    int image[1920][1080][3];
    int image_origine[1920][1080][3];
    objet tab[10];
    int compteur_objet=0;
    int *p= &compteur_objet;

    for(int a=0,a<hauteur,a++){
        for(int b=0,b<largeur,b++){
            for(int c=0,c<3,c++){
                image_origine[b][a][c]=image[b][a][c];
            }
        }
    }

    remplirMatriceImage(image,largeur,hauteur);
    bin_pixel(image,largeur,hauteur);
    saturation(image,largeur,hauteur);
    quantification(image,hauteur,largeur,tab,p);
    for (int i=0,i<compteur_objet,i++){
        donner_position(tab[i],largeur);
        verif_objet(tab[i]);
        nature_objet(tab[i],image);
        encadrement(image_origine, hauteur, largeur,tab[i]);
    }
    sortie_image(image_origine,hauteur,largeur,dimmention);

    if(compteur_objet != 0){
        for(int x=0,x<compteur_objet,x++){
            sortie_objet(tab[x],compteur_objet);
        }
    }
}