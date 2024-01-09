#include <stdlib.h>
#include <stdio.h>

void viderBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

int choix_langue() {
    int l;
    printf("\nSélectioner la langue : \n\nEnglish : 1 \nFrançais : 2 \n\n");
    scanf("%d", &l);
    while(l != 1 && l != 2) {
        printf("\nSélection incorecte, essayer encore : \n\n");
        viderBuffer();
        scanf("%d", &l);
    }
    return l;
}

int choix_test(int l) {
    if(l == 2) {
        printf("\nSélectioner ce que vous voulez tester : \n\nTraitement d'image : 3 \nTraitement de commande : 4 \n\n");
    } else {
        printf("\nSelect what you want to test : \n\nImage processing : 3 \nOrder processing : 4 \n\n");
    }
    int t;
    scanf("%d", &t);
    while(t != 3 && t != 4) {
        if(l == 2) {
            printf("\nSélection incorrecte, essayer encore : \n\n");
        } else {
            printf("\nIncorrect selection, try again : \n\n");
        }
        viderBuffer();
        scanf("%d", &t);
    }
    return t;
}

int main(){
    int l = choix_langue();
    viderBuffer();
    int t = choix_test(l);
    if(t == 4) {
        system("make main.out; ./main.out");
    }
    return 0;
}