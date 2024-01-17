//
// Created by mc2 on 15/01/24.
//

#include <stdlib.h>
#include "header.h"
#include <stdio.h>
/*binarise les val des pixel*/
void bin_pixel(int*** matrice,int largeur,int hauteur){
    int val_pixel;
    int seuil;
    seuil = 255 / 16;
    for(int i=0;i < 3;i++){
        for(int j=0;j < hauteur;j++){
            for(int k=0;k < largeur;k++){
                val_pixel = matrice[k][j][i];
                matrice[k][j][i] = val_pixel / seuil;
            }
        }
    }
}

/*dit objet non conforme si trop allonger ou trop petit*/
void verif_objet(objet *test){
    int limite = 10;
    if(test->coor_B - test->coor_H < limite || test->coor_D - test->coor_G < limite){
        test->nature = 'N';
    }
    if((test->coor_D - test->coor_G) / (test->coor_B - test->coor_H) > 1.5 || (test->coor_D - test->coor_G) / (test->coor_B - test->coor_H) < 0.65){
        test->nature = 'N';
    }

}

/*donne la nature Sphere ou Cube*/
void nature_objet(objet *test,int*** image){
    /*test si l'objet n'as pas déja été tester et donner comme Non conforme*/
    if(test->nature == 'N'){
        return;
    }
    int delta = 10;
    int pourcentage = 10;
    int seuil_couleur [3];
    /*teste si le conctour est carré don soit sphere soit cube*/
    if(test->coor_D - test->coor_G + delta > test->coor_B - test->coor_H && test->coor_D - test->coor_G - delta < test->coor_B - test->coor_H){
        /*determine si sphere ou cube en regardent dans un coin si la couleur de l'objet y est*/
        if(test->couleur == 'R'){
            seuil_couleur[0] = 16;
            seuil_couleur[1] = 0;
            seuil_couleur[2] = 0;
            if(image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][0] == seuil_couleur[0] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][1] == seuil_couleur[1] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][2] == seuil_couleur[2]){
                test->nature = 'C';
            }
            else{
                test->nature = 'S';
            }
        }

        else if(test->couleur == 'V'){
            seuil_couleur[0] = 0;
            seuil_couleur[1] = 16;
            seuil_couleur[2] = 0;
            if(image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][0] == seuil_couleur[0] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][1] == seuil_couleur[1] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][2] == seuil_couleur[2]){
                test->nature = 'C';
            }
            else{
                test->nature = 'S';
            }
        }

        else if(test->couleur == 'B'){
            seuil_couleur[0] = 0;
            seuil_couleur[1] = 0;
            seuil_couleur[2] = 16;
            if(image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][0] == seuil_couleur[0] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][1] == seuil_couleur[1] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][2] == seuil_couleur[2]){
                test->nature = 'C';
            }
            else{
                test->nature = 'S';
            }
        }

        else if(test->couleur == 'J'){
            seuil_couleur[0] = 16;
            seuil_couleur[1] = 16;
            seuil_couleur[2] = 0;
            if(image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][0] == seuil_couleur[0] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][1] == seuil_couleur[1] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][2] == seuil_couleur[2]){
                test->nature = 'C';
            }
            else{
                test->nature = 'S';
            }
        }

        else if(test->couleur == 'M'){
            seuil_couleur[0] = 16;
            seuil_couleur[1] = 0;
            seuil_couleur[2] = 16;
            if(image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][0] == seuil_couleur[0] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][1] == seuil_couleur[1] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][2] == seuil_couleur[2]){
                test->nature = 'C';
            }
            else{
                test->nature = 'S';
            }
        }

        else if(test->couleur == 'O'){
            seuil_couleur[0] = 16;
            seuil_couleur[1] = 9;
            seuil_couleur[2] = 0;
            if(image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][0] == seuil_couleur[0] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][1] == seuil_couleur[1] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][2] == seuil_couleur[2]){
                test->nature = 'C';
            }
            else{
                test->nature = 'S';
            }
        }
    }
/*la meme chose que au dessus mais ne detecte que si c'est un cube de travers*/
    else if((test->coor_D - test->coor_G) / (test->coor_B - test->coor_H) > 1.5){

        if(test->couleur == 'R'){
            seuil_couleur[0] = 16;
            seuil_couleur[1] = 0;
            seuil_couleur[2] = 0;
            if(image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][0] == seuil_couleur[0] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][1] == seuil_couleur[1] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][2] == seuil_couleur[2]){
                test->nature = 'C';
            }
            else{
                test->nature = 'N';
            }
        }

        else if(test->couleur == 'V'){
            seuil_couleur[0] = 0;
            seuil_couleur[1] = 16;
            seuil_couleur[2] = 0;
            if(image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][0] == seuil_couleur[0] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][1] == seuil_couleur[1] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][2] == seuil_couleur[2]){
                test->nature = 'C';
            }
            else{
                test->nature = 'N';
            }
        }

        else if(test->couleur == 'B'){
            seuil_couleur[0] = 0;
            seuil_couleur[1] = 0;
            seuil_couleur[2] = 16;
            if(image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][0] == seuil_couleur[0] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][1] == seuil_couleur[1] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][2] == seuil_couleur[2]){
                test->nature = 'C';
            }
            else{
                test->nature = 'N';
            }
        }

        else if(test->couleur == 'J'){
            seuil_couleur[0] = 16;
            seuil_couleur[1] = 16;
            seuil_couleur[2] = 0;
            if(image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][0] == seuil_couleur[0] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][1] == seuil_couleur[1] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][2] == seuil_couleur[2]){
                test->nature = 'C';
            }
            else{
                test->nature = 'N';
            }
        }

        else if(test->couleur == 'M'){
            seuil_couleur[0] = 16;
            seuil_couleur[1] = 0;
            seuil_couleur[2] = 16;
            if(image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][0] == seuil_couleur[0] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][1] == seuil_couleur[1] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][2] == seuil_couleur[2]){
                test->nature = 'C';
            }
            else{
                test->nature = 'N';
            }
        }

        else if(test->couleur == 'O'){
            seuil_couleur[0] = 16;
            seuil_couleur[1] = 9;
            seuil_couleur[2] = 0;
            if(image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][0] == seuil_couleur[0] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][1] == seuil_couleur[1] && image[test->coor_G + (test->coor_D - test->coor_G) / pourcentage ][test->coor_H + (test->coor_B - test->coor_H) / pourcentage ][2] == seuil_couleur[2]){
                test->nature = 'C';
            }
            else{
                test->nature = 'N';
            }
        }
    }
}
/*fonction pour remplir une matrice 3d avec les donné venant de la cam*/
void remplirMatriceImage(int*** image,int largeur,int hauteur){
    int pixel;
    for(int k=0;k < 3;k++){
        for(int j=0;j < hauteur;j++){
            for(int i=0;i < largeur;i++){
                scanf("%d",&pixel);
                image[i][j][k]=pixel;
            }
        }
    }
}
/*test des pixel sur les coté pour definir les */
void propagation(objet *test,int*** image){
    int s_couleur[3];
    if(test->couleur=='O'){
        s_couleur[0]=16;
        s_couleur[1]=9;
        s_couleur[2]=0;
        propagation_sous_f(test,image,s_couleur);
    }
    else if(test->couleur=='B'){
        s_couleur[0]=0;
        s_couleur[1]=0;
        s_couleur[2]=16;
        propagation_sous_f(test,image,s_couleur);
    }
    else if(test->couleur=='J'){
        s_couleur[0]=16;
        s_couleur[1]=16;
        s_couleur[2]=0;
        propagation_sous_f(test,image,s_couleur);
    }
}

/*sous fonction pour simplifier la propagation*/
void propagation_sous_f(objet *test,int*** image,int s_couleur[3]){
    int i=1;
    while(image[test->coor_G][test->coor_H+i][0] == s_couleur[0] && image[test->coor_G][test->coor_H+i][1] == s_couleur[1] && image[test->coor_G][test->coor_H+i][2] == s_couleur[2]){
        test->coor_B = test->coor_B - 1;
        i++;
    }
    i=1;
    int centre_horizontal;
    int centre_vertical;
    while(image[test->coor_D+i][test->coor_B][0] == s_couleur[0] && image[test->coor_D+i][test->coor_B][1] == s_couleur[1] && image[test->coor_D+i][test->coor_B][2] == s_couleur[2]){
        test->coor_D = test->coor_D + 1;
    }
    for(int iteration = 0; iteration<2;iteration++){
        centre_horizontal = test->coor_D - ((test->coor_D - test->coor_G)/2);
        centre_vertical = test->coor_B - ((test->coor_B - test->coor_H)/2);
        i=1;
        while(image[centre_horizontal - i][centre_vertical][0] == s_couleur[0] && image[centre_horizontal - i][centre_vertical][1] == s_couleur[1] && image[centre_horizontal - i][centre_vertical][2] == s_couleur[2]){
            if(test->coor_G > centre_horizontal - i){
                test->coor_G = centre_horizontal - i;
            }
            i++;

        }
        i=1;
        while(image[centre_horizontal + i][centre_vertical][0] == s_couleur[0] && image[centre_horizontal +i][centre_vertical][1] == s_couleur[1] && image[centre_horizontal + i][centre_vertical][2] == s_couleur[2]){
            if(test->coor_D < centre_horizontal + i){
                test->coor_D = centre_horizontal + i;
            }
            i++;
        }
        i=1;
        while(image[centre_horizontal][centre_vertical + i][0] == s_couleur[0] && image[centre_horizontal][centre_vertical + i][1] == s_couleur[1] && image[centre_horizontal][centre_vertical + i][2] == s_couleur[2]){
            if(test->coor_B < centre_vertical + i){
                test->coor_B = centre_vertical + i;
            }
            i++;
        }
    }
}

void donner_position(objet* test,int largeur){
    if(test->coor_G + ((test->coor_D - test->coor_G)/2) < largeur/3){
        test->position = 'G';
    }
    else if(test->coor_G + ((test->coor_D - test->coor_G)/2) < 2 * largeur / 3){
        test->position = 'M';
    }
    else if(test->coor_G + ((test->coor_D - test->coor_G)/2) < largeur){
        test->position = 'D';
    }
    else{
        test->position = 'N';
    }
}

void saturation(int*** image,int largeur,int hauteur){
    char color;
    int orange[3];
    int bleu[3];
    int jaune[3];
    int gris[3];
    orange[0] = 16;
    orange[1] = 9;
    orange[2] = 0;
    bleu[0] = 0;
    bleu[1] = 0;
    bleu[2] = 16;
    jaune[0] = 16;
    jaune[1] = 16;
    jaune[2] = 0;
    gris[0] = 0;
    gris[1] = 0;
    gris[2] = 0;
    /*parcourir l'image et faire les changement*/
    for(int j=0;j<hauteur;j++){
        for(int i=0;i<largeur;i++){
            color = detecter_couleur(image[i][j][0], image[i][j][1], image[i][j][2]);
            if(color == 'O'){
                image[i][j][0]=orange[0];
                image[i][j][1]=orange[1];
                image[i][j][2]=orange[2];
            }
            else if(color == 'B'){
                image[i][j][0]=bleu[0];
                image[i][j][1]=bleu[1];
                image[i][j][2]=bleu[2];
            }
            else if(color == 'J'){
                image[i][j][0]=jaune[0];
                image[i][j][1]=jaune[1];
                image[i][j][2]=jaune[2];
            }
            else{
                image[i][j][0]=0;
                image[i][j][1]=0;
                image[i][j][2]=0;
            }
        }
    }
}

void quantification(int*** image, int hauteur, int largeur, objet tab[10],int *cpt){
    char color;
    *cpt = 0;
    int Bool;
    int compteur=0;
    /*Parcours de l'image pixel par pixel*/
    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            if(image[j][i][3]==16){
                color = 'B';
            }
            if(image[j][i][2]==9){
                color = 'O';
            }
            if(image[j][i][2]==16){
                color = 'J';
            }
            if(compteur == 0 && color != 'N'){
                objet* tempon=&tab[compteur];
                tempon->couleur = color;
                tempon->coor_H = i;
                tempon->coor_B = i;
                tempon->coor_D = j;
                tempon->coor_G = j;
                propagation(tempon,image);
                compteur++;
                printf("%d",compteur);
            }
            else if(compteur != 0 && color != 'N'){
                for(int t=0;t < compteur;t++){
                    /*si le pixel est dans la zone d'un autre objet*/
                    if((j < tab[t].coor_D) && (j > tab[t].coor_G )&& (i < tab[t].coor_B )&& (i > tab[t].coor_H )&& (Bool == 0 )&& (tab[t].couleur == color )){
                        Bool = 1;
                    }
                }
                /* Si on se trouve dans un objet deja cree, on n'en crée pas un nouveau*/
                if(Bool == 0 && color != 'N'){
                    objet* tempon2=&tab[*cpt];
                    tempon2->couleur = color;
                    tempon2->coor_H = i;
                    tempon2->coor_B = i;
                    tempon2->coor_D = j;
                    tempon2->coor_G = j;
                    propagation(tempon2,image);
                    compteur++;
                }
                Bool = 0;
                printf("%d",compteur);
            }
        }
    }
    *cpt = compteur;
}



char detecter_couleur(int rouge, int vert, int bleu) {
    // Seuils pour déterminer la couleur dominante
    int seuilOrange = 10;
    int seuilBleu = 7;
    int seuilJaune = 13;
    int seuilGris = 2; // Ajustez ce seuil en fonction de la tolérance souhaitée pour le gris

    // Calculer la différence maximale permise pour considérer le pixel comme gris
    int diffMaxGris = seuilGris;

    // Calculer les différences entre les composantes RGB
    int diffR = abs(rouge - vert);
    int diffG = abs(vert - bleu);
    int diffB = abs(bleu - rouge);

    // Vérifier la proximité des valeurs par rapport aux seuils
    if (diffR <= diffMaxGris && diffG <= diffMaxGris && diffB <= diffMaxGris) {
        return 'N';
    } else if (rouge >= seuilOrange && vert >= seuilOrange && bleu < seuilBleu) {
        return 'O';
    } else if (rouge < seuilBleu && vert < seuilBleu && bleu >= seuilBleu) {
        return 'B';
    } else if (rouge >= seuilJaune && vert >= seuilJaune && bleu < seuilBleu) {
        return 'J';
    } else {
        return 'N';
    }
}

void encadrement(int*** image, int hauteur, int largeur,objet *test){
    for(int i=test->coor_G;i<test->coor_D;i++){
        image[i][test->coor_H][0]=0;
        image[i][test->coor_H][1]=255;
        image[i][test->coor_H][2]=0;
        image[i][test->coor_B][0]=0;
        image[i][test->coor_B][1]=255;
        image[i][test->coor_B][2]=0;
    }
    for(int j=test->coor_H;j<test->coor_B;j++){
        image[test->coor_G][j][0]=0;
        image[test->coor_G][j][1]=255;
        image[test->coor_G][j][2]=0;
        image[test->coor_D][j][0]=0;
        image[test->coor_D][j][1]=255;
        image[test->coor_D][j][2]=0;
    }
}

void sortie_image(int*** image,int hauteur,int largeur,int dimmention){
    printf("%d",largeur);
    printf("%d",hauteur);
    printf("%d \n",dimmention);
    for(int k=0;k < 3;k++){
        for(int j=0;j < largeur;j++){
            for(int i=0;i < hauteur;i++){
                printf("%d,",image[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void sortie_objet(objet *test,int compteur_objet){
    printf("Objet n %d \n",compteur_objet+1);
    printf("Limite gauche= %d \n",test->coor_G);
    printf("Limite droite= %d \n",test->coor_D);
    printf("Limite haute= %d \n",test->coor_D);
    printf("Limite droite= %d \n",test->coor_D);
    printf("Couleur = %c \n",test->couleur);
    printf("Nature = %c \n",test->nature);
    printf("Position = %c \n",test->position);
}