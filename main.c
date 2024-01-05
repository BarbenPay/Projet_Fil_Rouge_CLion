#include <stdio.h>
#include <stdlib.h>
#include "Découpage/Decoupage.h"
#include "Log/fichier_Log.h"
#include "Regroupement/Regroupement.h"
#include "Analyse_Phrase/Analyse.h"

int main() {

    log_file_init();
    Phrase* res;
    res = decoupage("N'avance pas");
    for (int i = 0; i<res->wordNumber; i++) {
        printf("%s\n", res->wordArray[i]);
    }
    wordTypeStruct ** typeWord;
    typeWord = sentenceToWordTypeArray(res);
    for(int i = 0; i<res->wordNumber;i++){

        printf("Le mot %s est de type %d\n",typeWord[i]->word, typeWord[i]->typeWord);
    }
    analyse(typeWord,res);

    free(res);
    free(typeWord);





    return 0;

}
