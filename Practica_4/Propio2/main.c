#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

int main(){
    srand(time(NULL));
    printf("Introduzca un límite inferior y uno superior para establecer los números aleatorios del vector: ");
    int sup, inf;
    scanf("%d", &inf);
    scanf("%d", &sup);
    while(sup<inf){
        printf("Introduzca primero el límite inferior y luego el superior: ");
        scanf("%d", &inf);
        scanf("%d", &sup);
    }
    int *v=NULL;
    crearvector(&v, inf, sup);
    return 0;
}