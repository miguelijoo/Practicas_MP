#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funciones.h"

void buscarlibro(FILE *fichero, char *nombre){
    fichero=fopen(nombre, "r");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    int n=0;
    printf("Introduce el nombre del libro a buscar: ");
    char titulo[50], basura[50];
    while(getchar() != '\n');
    fgets(titulo, 50, stdin);
    if(titulo[strlen(titulo)-1]=='\n'){
            titulo[strlen(titulo)-1]='\0';
    }
    char titulobuscado[50];
    while(fgets(titulobuscado, 50, fichero)!=NULL && n==0){
        if(titulobuscado[strlen(titulobuscado)-1]=='\n'){
            titulobuscado[strlen(titulobuscado)-1]='\0';
        }
        if(strcmp(titulo, titulobuscado)==0){
            printf("El libro existe en el catálogo");
            n+=1;
        }
        fgets(basura, 50, fichero);
        fgets(basura, 50, fichero); /* Nos garantizamos que las dos siguientes líneas después del título se van a quedar en una variable basura y no donde necesitamos realmente ver el título, por si el usuario es tontito y pone autor para buscar en vez del título.*/
    }
    if(n==0){
        printf("No se ha encontrado el libro");
    }
    fclose(fichero);
}

void anadirlibro(FILE *fichero, char *nombre){
    fichero=fopen(nombre, "a+");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    printf("Introduce el nombre del libro a añadir para comprobar si ya esta en la base de datos: ");
    char titulo[50], basura[50];
    while(getchar()!='\n');
    fgets(titulo, 50, stdin);
    if(titulo[strlen(titulo)-1]=='\n'){
        titulo[strlen(titulo)-1]='\0';
    }
    char titulobuscado[50];
    int encontrado =0;
    rewind(fichero);
    while(fgets(titulobuscado, 50, fichero)!=NULL && encontrado == 0){
        if(titulobuscado[strlen(titulobuscado)-1]=='\n'){
            titulobuscado[strlen(titulobuscado)-1]='\0';
        }
        if(strcmp(titulo, titulobuscado)==0){
            printf("Su libro ya existe en la base de datos");
            encontrado+=1;
        }
        fgets(basura, 50, fichero);
        fgets(basura, 50, fichero);
    }
    if(encontrado==0){
        fprintf(fichero,"%s\n", titulo);
        printf("Nombre del autor: ");
        char autor[50];
        fgets(autor, 50, stdin);
        if(autor[strlen(autor)-1]=='\n'){
            autor[strlen(autor)-1]='\0';
        }
        fprintf(fichero,"%s\n", autor);
        printf("Precio: ");
        float precio=0;
        scanf("%f", &precio);
        printf("Unidades del producto: ");
        int uds=0;
        scanf("%d", &uds);
        fprintf(fichero,"%.2f %d\n", precio, uds);
    }
    fclose(fichero);
}

void contarlibros(FILE *fichero, char *nombre){
    fichero=fopen(nombre, "r");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    char titulo[50], basura[50];
    int n=0;
    while(fgets(titulo, 50, fichero)!=NULL){
        n+=1;
        fgets(basura, 50, fichero);
        fgets(basura, 50, fichero);
    }
    printf("Hay %d libros diferentes en el stock.\n", n);
    fclose(fichero);
}

void listarlibros(FILE *fichero, char *nombre){
    fichero=fopen(nombre, "r");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    char titaut[50];
    float precio;
    int uds;
    while(fgets(titaut, 50, fichero)!=NULL){
        printf("\nTitulo: %s", titaut);
        fgets(titaut, 50, fichero);
        printf("Autor: %s", titaut);
        fscanf(fichero,"%f %d", &precio, &uds);
        printf("Precio: %.2f\n", precio);
        printf("Unidades: %d\n", uds);
        while(fgetc(fichero)!='\n');
    }
    fclose(fichero);
}

void hacerstruct(FILE *fichero, char *nombre, libro **libros){
    fichero=fopen(nombre, 'r');
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    char titaut[50];
    char basura[50];
    int n=0;
    while(fgets(titaut, 50, fichero)!=NULL){
        fgets(basura, 50, fichero);
        fgets(basura, 50, fichero);
        n+=1;
    }
    *libros=(libro*) malloc(n*sizeof(libro));
    int i=0;
    rewind(fichero);
    while(fgets((*libros)[i].titulo, 50, fichero)!=NULL && i<n){
        fgets((*libros)[i].autor, 50, fichero);
        fscanf("%f %d", &((*libros)[i].precio), &((*libros)[i].unidades));
        while(fgetc(fichero)!='\n');
        i+=1;
    }
    fclose(fichero);
}