#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funciones.h"

void buscarlibro(FILE *fichero, char *nombre){
    fichero=fopen(nombre, "r");
    int n=0;
    printf("Introduce el nombre del libro a buscar: ");
    char titulo[50];
    while(getchar() != '\n');
    fgets(titulo, 50, stdin);
    char titulobuscado[50];
    while(fscanf(fichero,"%s", titulobuscado)!=EOF){
        if(strcmp(titulo, titulobuscado)==1){
            printf("El libro existe en el catálogo");
            n+=1;
        }
    }
    if(n==0){
        printf("No se ha encontrado el libro");
    }
    fclose(fichero);
}

void añadirlibro(FILE *fichero, char *nombre){
    fichero=fopen(nombre, "w+");
    printf("Introduce el nombre del libro a añadir: ");
    char titulo[50];
    while(getchar()!='\n');
    fgets(titulo, 50, stdin);
    char titulobuscado[50];
    int encontrado =0;
    while(fscanf(fichero, "%s", titulobuscado) && encontrado == 0){
        
    }
}