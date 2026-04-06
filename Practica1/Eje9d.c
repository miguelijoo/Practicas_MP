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

struct monomio mayorgrado(struct monomio v[], int n){
    struct monomio mayor=v[1];
    for(int i=0;i<n;i++){
        if(v[i].grado>mayor.grado){
            mayor=v[i];
        }
    }
    return mayor;
}

struct monomio menorgrado(struct monomio v[], int n){
struct monomio menor=v[1];
    for(int i=0;i<n;i++){
        if(v[i].grado<menor.grado){
            menor=v[i];
        }
    }
    return menor;
}

int main(){
    struct monomio v[3];
    printf("Introduzca coeficiente y grado de cada monomio: \n");
    leermonomio(v, 3);
    struct monomio mayor=mayorgrado(v, 3);
    struct monomio menor=menorgrado(v, 3);
    printf("El monomio de menor grado es %dx^%d y el de menor grado %dx^%d", mayor.coef, mayor.grado, menor.coef, menor.grado);
}