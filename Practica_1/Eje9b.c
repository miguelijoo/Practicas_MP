#include <stdio.h>

struct monomio{
    int coef;
    int grado;
};

void imprimirmonomio(struct monomio m1copia){
    printf("El coeficiente es: %d \n", m1copia.coef);
    printf("El grado es: %d \n", m1copia.grado);
}

int main(){
    struct monomio m1;
    printf("Pon los datos del monomio: \n");
    scanf("%d", &m1.coef);
    scanf("%d", &m1.grado);
    imprimirmonomio(m1);
}