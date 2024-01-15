//
// Created by mc2 on 15/01/24.
//

#ifndef PROJET_FIL_ROUGE_CLION_HEADER_H
#define PROJET_FIL_ROUGE_CLION_HEADER_H

int largeur;
int hauteur;
typedef struct objet objet;
struct objet{
    int coor_H;
    int coor_G;
    int coor_D;
    int coor_B;
    char couleur;
    char nature;
    char position;
};
void bin_pixel(int matriceimage[1920][1080][3],int largeur,int hauteur);
void verif_objet(objet* test);
void nature_objet(objet* test,int image_bin [1920][1080][3]);
void remplirMatriceImage(int MatriceImage[1920][1080][3],int largeur,int hauteur);
void propagation(objet* test,int image[1920][1080][3]);
void propagation_sous_f(objet* test,int image[1920][1080][3],int s_couleur[3]);
void donner_position(objet* test,int largeur);
void saturation(int image[1920][1080][3],int largeur,int hauteur);
char detecter_couleur(int rouge, int vert, int bleu);
void quantification(int image[1920][1080][3], int hauteur, int largeur, objet tab[50],int cpt);
void encadrement(int image[1920][1080][3], int hauteur, int largeur,objet *test);
void sortie_image(int image[1920][1080][3],int hauteur,int largeur,int dimmention);
void sortie_objet(objet *test,int compteur_objet);

#endif //PROJET_FIL_ROUGE_CLION_HEADER_H
