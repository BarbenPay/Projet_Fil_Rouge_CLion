//
// Created by mc2 on 15/01/24.
//

#include "header.h"
#include <stdio.h>
void main(void){
    int largeur;   /* a definir */
    int hauteur;
    int dimmention;
    int image[400][400][3];
    int image_origine[400][400][3];
    objet tab[10];
    int compteur_objet=0;
    int* p= &compteur_objet;
    scanf("%d",&largeur);
    scanf("%d",&hauteur);
    scanf("%d",&dimmention);
    if(largeur > 400|| hauteur > 400){
        printf("l'image est trop volumineuse");
    }
    if(dimmention != 3){
        printf("la photo n'est pas en couleur");
    }
    remplirMatriceImage(image,largeur,hauteur);
    for(int a=0;a < largeur;a++){
        for(int b=0;b < hauteur;b++){
            image_origine[a][b][0]=image[a][b][0];
            image_origine[a][b][1]=image[a][b][1];
            image_origine[a][b][2]=image[a][b][2];

        }
    }
    bin_pixel(image,largeur,hauteur);
    saturation(image,largeur,hauteur);
    quantification(image,hauteur,largeur,tab,p);
    for (int i=0;i<compteur_objet;i++){
        objet* tempon = &tab[i];
        donner_position(tempon,largeur);
        verif_objet(tempon);
        nature_objet(tempon,image);
        encadrement(image_origine, hauteur, largeur,tempon);
    }
    //sortie_image(image_origine,hauteur,largeur,dimmention);
    if(compteur_objet != 0){
        for(int x=0;x<compteur_objet;x++){
            objet* tempon2 =&tab[x];
            sortie_objet(tempon2,compteur_objet);
        }
    }
    else{printf("pas d'objet dans l'image\n");}
    printf("%d,%d",compteur_objet,*p);
}