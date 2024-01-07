#include <stdlib.h>
#include <stdio.h>

char choix_langue() {
    char l;
    printf("\nSélectioner la langue : \n\nEnglish : E \nFrançais : F \n\n");
    scanf("%s", &l);
    while(l != 'E' && l != 'F') {
        printf("\nSélection incorecte, essayer encore : \n\n");
        scanf("%s", &l);
    }
    return l;
}

char choix_test(char l) {
    if(l == 'F') {
        printf("\nSélectioner ce que vous voulez tester : \n\nTraitement d'image : 1 \nTraitement de commande : 2 \n\n");
    } else {
        printf("\nSelect what you want to test : \n\nImage processing : 1 \nOrder processing : 2 \n\n");
    }
    int t;
    scanf("%d", &t);
    while(t != 1 && t != 2) {
        if(l == 'F') {
            printf("\nSélection incorrecte, essayer encore : \n\n");
        } else {
            printf("\nIncorrect selection, try again : \n\n");
        }
        scanf("%d", &t);
    }
    return t;
}

int main(){
    char l = choix_langue();
    int t = choix_test(l);
    if(t == 2) {
        system("make main.out");
    }
    return 0;
}
