#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

void crearvector(int **v, int inf, int sup){
    *v=(int*) malloc(15*sizeof(int));
    if(*v==NULL){
        printf("No se ha podido crear el vector.\n");
        exit -1;
    }
    printf("Vector actual: ");
    for(int i=0;i<15;i++){
        (*v)[i]=(rand()%(sup-inf+1))-inf;
        printf("%d, ", (*v)[i]);
    }
}