#include <stdio.h>
#include <math.h>

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

int evaluarmonomio(struct monomio v[], int n, int puntocopia){
    int resultado=0;
    for(int i=0;i<n;i++){
        resultado+=v[i].coef*pow(puntocopia, v[i].grado);
    }
    return resultado;
}

int main(){
    struct monomio v[3];
    printf("Introduzca coeficiente y grado de cada monomio: \n");
    leermonomio(v, 3);
    printf("Introduzca un punto a evaluar: ");
    int punto=0;
    scanf("%d", &punto);
    int x=evaluarmonomio(v, 3, punto);
    printf("El monomio en ese punto vale: %d",x);
}