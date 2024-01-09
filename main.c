#include <stdio.h>
#include <stdlib.h>
#include "Découpage/Decoupage.h"
#include "Log/fichier_Log.h"
#include "Regroupement/Regroupement.h"
#include "Analyse_Phrase/Analyse.h"
#include "Menu/menu.h"

int main() {

    log_file_init();
    int langue = choix_langue();
    viderBuffer();
    int test = choix_test(langue);

    if (test == 4) {
        char phrase[100];
        printf("\nSaissez votre commande : \n\n");
        viderBuffer();
        fgets(phrase, 100, stdin);
        Phrase* res;
        res = decoupage(phrase);
        for (int i = 0; i<res->wordNumber; i++) {
            printf("%s\n", res->wordArray[i]);
        }
        wordTypeStruct ** typeWord;
        typeWord = sentenceToWordTypeArray(res, langue);
        for(int i = 0; i<res->wordNumber;i++){

            printf("Le mot %s est de type %d\n",typeWord[i]->word, typeWord[i]->typeWord);
        }
        analyse(typeWord,res);

        free(res);
        free(typeWord);
    }
    return 0;
}
