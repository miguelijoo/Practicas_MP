#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "funciones.h"

void rellenarfichero(char *nombre, int nelemen, int inf, int sup){
    FILE *fichero;
    fichero=fopen(nombre, "wb");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    int v[nelemen];
    for(int i=0;i<nelemen;i++){
        v[i]=(rand() % (sup-inf+1)) + inf;
    }
    fwrite(v, sizeof(int), nelemen, fichero);
    fclose(fichero);
}