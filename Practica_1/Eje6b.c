#include <stdio.h>

void media(int n1, int n2, float *resultado){
    *resultado=(n1+n2)/2.0;
}

int main(){
    int n1=0, n2=0;
    float resultado=0;
    printf("Introduce 2 numeros para hacer su media aritmetica: \n");
    scanf("%d", &n1);
    scanf("%d", &n2);
    media(n1,n2, &resultado);
    printf("La media es: %.3f", resultado);
    return 0;
}