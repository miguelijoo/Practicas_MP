#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main(){
    int num=0, longitud=0, tam1=0, tam2=0;
    int *v;
    printf("Introduce la longitud del vector que vamos a crear: ");
    scanf("%d", &longitud);
    printf("\n");
    printf("Introduce el numero que vamos a usar para crear 2 vectores: ");
    scanf("%d", &num);
    printf("\n");
    v=(int*) calloc(longitud, sizeof(int));
    if(v==NULL){
        printf("Error, no hay memoria suficiente. \n");
        return -1;
    }
    printf("Rellene el vector a continuacion: \n");
    for(int i=0;i<longitud;i++){
        scanf("%d", &v[i]);
    }
    int *vectormayor=elementomayor(v, longitud, num, &tam1);
    int *vectormenor=elementomenor(v, longitud, num, &tam2);
    printf("Los numeros mayores que %d son: ", num);
    for(int i=0;i<tam1;i++){
        printf("%d ", vectormayor[i]);
    }
    printf("Los numeros menores que %d son: ", num);
    for(int i=0;i<tam2;i++){
        printf("%d ", vectormenor[i]);
    }
    return 0;
}