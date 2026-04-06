#include <stdio.h>

struct monomio{
    int coef;
    int grado;
};

void leermonomio(struct monomio *m1){
    scanf("%d", &m1->coef);
    scanf("%d", &m1->grado);
}

int main(){
    struct monomio m1;
    printf("Introduce los datos del monomio: \n");
    leermonomio(&m1);
    return 0;
}