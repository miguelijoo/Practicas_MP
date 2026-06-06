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
    qsort(v, 15, sizeof(int), compararasc);
    printf("Vector ordenado: ");
    for(int i=0;i<15;i++){
        printf("%d, ", v[i]);
    }
    printf("\nIntroduzca un número para buscarlo en el vector: ");
    int valor=0;
    scanf("%d", &valor);
    int x=buscarvalor(v, 15, valor);
    if(x==-1){
        printf("El valor no estaba en el vector.\n");
    }
    else{
        printf("El valor estaba en la posición %d del vector\n", x);
    }
    return 0;
}