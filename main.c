#include "Log/fichier_Log.h"
#include "Menu/menu.h"

int main()
{
    log_file_init();
    int langue = choix_langue();
    viderBuffer();
    int test = choix_test(langue);

    if (test == 4)
    {
        traitement_commande(langue);
        printf("Nouvelle");
    }
    return 0;
}
