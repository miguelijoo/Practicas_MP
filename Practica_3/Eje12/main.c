#include <stdio.h>
#include "funciones.h"
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    printf("Introduce el tamaño del vector a crear y un valor superior e inferior para los numeros de dentro:");
    int n, sup, inf;
    scanf("%d", &n);
    scanf("%d", &sup);
    scanf("%d", &inf);
    int v[n], iz=0, de=n-1;
    printf("El vector actual es: ");
    for(int i=0;i<n;i++){
        v[i]=(rand()%(sup-inf+1))+inf;
        printf("%d ", v[i]);
    }
    printf("\n");
    invertir(v, iz, de);
    printf("El vector invertido es: ");
    for(int i=0;i<n;i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}