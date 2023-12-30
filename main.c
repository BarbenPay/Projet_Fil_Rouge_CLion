#include <stdio.h>
#include <stdlib.h>
#include "Découpage/Decoupage.h"
#include "Log/fichier_Log.h"
#include "Regroupement/Regroupement.h"

int main() {

    log_file_init();
    Phrase* res;
    res = decoupage("Avance de 10 metre");
    for (int i = 0; i<res->wordNumber; i++) {
        printf("%s\n", res->wordArray[i]);
    }
    wordTypeStruct ** typeWord;
    typeWord = sentenceToWordTypeArray(res);
    for(int i = 0; i<res->wordNumber;i++){

        printf("Le mot %s est de type %d\n",typeWord[i]->word, typeWord[i]->typeWord);
    }

    free(res);





    return 0;

}
