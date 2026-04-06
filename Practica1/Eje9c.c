#include <stdio.h>

struct monomio{
    int coef;
    int grado;
};

void leermonomio(struct monomio v[], int n){
    for(int i=0;i<n;i++){
        scanf("%d", &v[i].coef);
        scanf("%d", &v[i].grado);
    }
}

void imprimirmonomio(struct monomio v[], int n){
    for(int i=0;i<n;i++){
        printf(" %dx^%d ", v[i].coef, v[i].grado);
        if(i<n-1){
            printf("+");
        }
    }
}

int main(){
    struct monomio v[3];
    printf("Introduzca coeficiente y grado de cada monomio: \n");
    leermonomio(v, 3);
    imprimirmonomio(v, 3);
}