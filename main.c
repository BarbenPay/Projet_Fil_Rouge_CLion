#include "Log/fichier_Log.h"
#include "Menu/menu.h"

int main()
{
    log_file_init();
    Valeur langue = choix_langue();
    Valeur test = choix_test(langue);
    if (test.i == 1)
    {
    //    traitement_commande(langue);
        printf("\nNouvelle commande : 1 \nRetour au choix du test : 2 \n\n");

    }
    return 0;
}
