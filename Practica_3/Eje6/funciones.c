#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "funciones.h"

void rellenarfichero(char *nombre, int nelemen, int inf, int sup){
    FILE *fichero;
    fichero=fopen(nombre, "wb");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero\n");
        return;
    }
    int *v;
    v=(int*) malloc(nelemen*sizeof(int));
    for(int i=0;i<nelemen;i++){
        v[i]=(rand() % (sup-inf+1)) + inf;
    }
    fwrite(v, sizeof(int), nelemen, fichero);
    fclose(fichero);
    free(v);
}

void leerfichero(char *nombre, int nelemen){
    FILE *fichero;
    fichero=fopen(nombre, "rb");
    if(fichero==NULL){
        printf("Introduzca el nombre del fichero correcto.\n");
        return;
    }
    int *v;
    v=(int *) malloc(nelemen*sizeof(int));
    int leidos;
    leidos=fread(v, sizeof(int), nelemen, fichero);
    if(leidos!=nelemen){
        return;
    }
    float mpares=0;
    int cont=0;
    for(int i=0;i<nelemen;i++){
        if(v[i]%2==0){
            mpares+=v[i];
            cont+=1;
        }
    }
    if(cont>0){
        mpares=mpares/cont;
    
    printf("La media de los numeros pares del fichero es: %.2f\n", mpares);
    }
    else{
        printf("No hay numeros pares en el fichero.\n");
    }
    fclose(fichero);
    free(v);
}