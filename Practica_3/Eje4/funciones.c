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
    int uds, c;
    while(fgets(titaut, 50, fichero)!=NULL){
        printf("\nTitulo: %s", titaut);
        fgets(titaut, 50, fichero);
        printf("Autor: %s", titaut);
        fscanf(fichero,"%f %d", &precio, &uds);
        printf("Precio: %.2f\n", precio);
        printf("Unidades: %d\n", uds);
        while(c=fgetc(fichero)!='\n' && c!=EOF);
    }
    fclose(fichero);
}

void hacerstruct(FILE *fichero, char *nombre, libro **libros, int *k){
    fichero=fopen(nombre, "r");
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
        fscanf(fichero, "%f %d", &((*libros)[i].precio), &((*libros)[i].unidades));
        while(fgetc(fichero)!='\n');
        i+=1;
    }
    *k=n;
    fclose(fichero);
}

void subirprecio(FILE *fichero, char *nombre, libro *libros, int n){
    fichero=fopen(nombre, "w");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    printf("Introduzca un porcentaje para subir el precio de los libros: ");
    float porcentaje=0;
    scanf("%f", &porcentaje);
    porcentaje=(porcentaje/100)+1;
    for(int i=0;i<n;i++){
        libros[i].precio*=porcentaje;
    }
    for(int i=0;i<n;i++){
        fprintf(fichero,"%s",libros[i].titulo);
        fprintf(fichero,"%s", libros[i].autor);
        fprintf(fichero,"%.2f %d\n", libros[i].precio, libros[i].unidades);
    }
    fclose(fichero);
}

void venderlibros(FILE *fichero, char *nombre, libro *libros, int n){
    fichero=fopen(nombre, "w+");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    printf("Introduce el nombre del libro y las unidades a vender: ");
    char titulo[50];
    while(getchar()!='\n');
    fgets(titulo, 50, stdin);
    int uds;
    scanf("%d", &uds);
    while(getchar()!='\n');
    int encontrado=0;
    for(int i=0;i<n && encontrado==0;i++){
        if(strcmp(titulo, libros[i].titulo)==0){
            encontrado+=1;
            if(uds>=libros[i].unidades){
                libros[i].unidades=0;
            }
            else if(uds<libros[i].unidades){
                libros[i].unidades-=uds;
            }
        }
    }
    for(int i=0;i<n;i++){
        fprintf(fichero,"%s",libros[i].titulo);
        fprintf(fichero,"%s", libros[i].autor);
        fprintf(fichero,"%.2f %d\n", libros[i].precio, libros[i].unidades);
    }
    fclose(fichero);
}
void nuevofichero(FILE *fichero, char *nombre){
    FILE *fichero2;
    fichero=fopen(nombre, "r");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    fichero2=fopen("catalogo extra", "w");
    if(fichero2==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    printf("Introduzca el numero de unidades a partir de las que debe tener un libro en stock para conservarlo en otro fichero aparte: ");
    int min=0;
    scanf("%d", &min);
    while(min<0){
        printf("Error, introduzca un numero mayor que 0\n");
        scanf("%d", &min);
    }
    while(getchar()!='\n');
    char titulo[50], autor[50];
    float precio;
    int uds;
    while(fgets(titulo, 50, fichero)!=NULL){
        fgets(autor, 50, fichero);
        fscanf(fichero, "%f %d", &precio, &uds);
        while(fgetc(fichero)!='\n');
        if(uds<min){
            fprintf(fichero2,"%s", titulo);
            fprintf(fichero2,"%s", autor);
            fprintf(fichero2,"%.2f %d\n", precio, uds);
        }
    }
    fclose(fichero);
    fclose(fichero2);
}

void renovarfichero(FILE *fichero, char *nombre){
    FILE *fichero2;
    fichero=fopen(nombre, "r");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    fichero2=fopen("reemplazo", "w");
    if(fichero2==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    char titulo[50], autor[50];
    float precio;
    int uds;
    while(fgets(titulo, 50, fichero)!=NULL){
        fgets(autor, 50, fichero);
        fscanf(fichero, "%f %d", &precio, &uds);
        while(fgetc(fichero)!='\n');
        if(uds!=0){
            fprintf(fichero2,"%s", titulo);
            fprintf(fichero2,"%s", autor);
            fprintf(fichero2,"%.2f %d\n", precio, uds);
        }
    }
    fclose(fichero);
    fclose(fichero2);
    remove(nombre);
    rename("reemplazo", nombre);
}