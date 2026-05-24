#include <stdio.h>
#include "funciones.h"

int main(){
    printf("Introduzca un número para ver si es triangular o no: ");
    int num, x=1, res=0;
    scanf("%d", &num);
    int j=triangular(num, x, res);
    if(j==0){
        printf("El numero no es triangular.");
    }
    else if(j==1){
        printf("El numero es triangular.");
    }
}