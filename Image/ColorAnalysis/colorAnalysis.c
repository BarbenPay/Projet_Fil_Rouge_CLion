//
// Created by Jean-Baptiste Salanie on 24/01/2024.
//

#include "colorAnalysis.h"
#include <stdlib.h>
#include "../../Log/logFile.h"





char detectercouleur(int* rgb)
{
    char couleur;

    if (detectionGris(rgb[0],rgb[1],rgb[2]) == 1)
    {
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

int detectionGris(int r, int g, int b)
{
    int seuilGris = 30;

    // Calculer les différences entre les composantes RGB
    int diffR = abs(r - b);
    int diffG = abs(g - b);
    int diffB = abs(b - r);

    // Vérifier la proximité des valeurs par rapport aux seuils
    if (diffR <= seuilGris && diffG <= seuilGris && diffB <= seuilGris) {
        return 1;
    }else{
        return 0;
    }
}

int quantificationDeuxBits(int valeur)
{
    // Appliquer un masque pour conserver seulement les 2 premiers bits
    int masque = 0b11000000; // Masque binaire 11000000 (192 en décimal)
    int resultat = (valeur & masque) >> 6; // Décalage pour obtenir le résultat sur les 2 premiers bits
    return resultat;

}

char detectionCouleur(int valeur) {
    // Détermination des plages pour chaque couleur
    if (valeur >= 45 && valeur <= 48)
    {
        return 'R';
    }
    else if (valeur >= 48 && valeur <= 57)
    {
        return 'O';
    }
    else if (valeur >= 59 && valeur <= 61)
    {
        return 'J';
    }
    else if (valeur >= 14 && valeur <= 40)
    {
        return 'M';
    }
    else if (valeur >= 1 && valeur <= 8)
    {
        return 'B';
    }
    else
    {
        return 'N'; // On ne prend pas le blanc // Couleur non détecté
    }

}