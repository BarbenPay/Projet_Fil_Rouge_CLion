//
// Created by mc2 on 15/01/24.
//

#ifndef PROJET_FIL_ROUGE_CLION_HEADER_H
#define PROJET_FIL_ROUGE_CLION_HEADER_H

struct objet{
    int coor_H;
    int coor_G;
    int coor_D;
    int coor_B;
    char couleur;
    char nature;
    char position;
};
typedef struct objet objet;
void bin_pixel(int*** matrice,int largeur,int hauteur);
void verif_objet(objet* test);
void nature_objet(objet* test,int*** image);
void remplirMatriceImage(int*** image,int largeur,int hauteur);
void propagation(objet* test,int*** image);
void propagation_sous_f(objet* test,int*** image,int s_couleur[3]);
void donner_position(objet* test,int largeur);
void saturation(int*** image,int largeur,int hauteur);
char detecter_couleur(int rouge, int vert, int bleu);
void quantification(int*** image, int hauteur, int largeur, objet tab[10],int *cpt);
void encadrement(int*** image, int hauteur, int largeur,objet *test);
void sortie_image(int*** image,int hauteur,int largeur,int dimmention);
void sortie_objet(objet *test,int compteur_objet);

#endif //PROJET_FIL_ROUGE_CLION_HEADER_H
