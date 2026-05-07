#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funciones.h"

void buscarlibro(char *nombre){
    FILE *fichero;
    fichero=fopen(nombre, "rb");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    int n=0;
    printf("Introduce el nombre del libro a buscar: ");
    char titulo[50];
    while(getchar() != '\n');
    fgets(titulo, 50, stdin);
    if(titulo[strlen(titulo)-1]=='\n'){
            titulo[strlen(titulo)-1]='\0';
    }
    libro libro_buscado;
    while(fread(&libro_buscado, sizeof(libro), 1, fichero)==1){
        if(strcmp(libro_buscado.titulo, titulo)==0){
            printf("El libro esta en el catalogo.\n");
            n=1;
            break;
        }
    }
    if(n!=1){
        printf("No se ha encontrado el libro.\n");
    }
    fclose(fichero);
}

void anadirlibro(char *nombre){
    FILE *fichero;
    fichero=fopen(nombre, "a+b");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero.");
        return;
    }
    printf("Introduce el nombre del libro a añadir para comprobar si ya esta en la base de datos: ");
    char titulo[50];
    while(getchar()!='\n');
    fgets(titulo, 50, stdin);
    if(titulo[strlen(titulo)-1]=='\n'){
        titulo[strlen(titulo)-1]='\0';
    }
    int encontrado =0;
    rewind(fichero);
    libro libro_anadir;
    while(fread(&libro_anadir, sizeof(libro), 1, fichero)==1){
        if(strcmp(libro_anadir.titulo, titulo)==0){
            printf("El libro esta en el catalogo.\n");
            encontrado+=1;
            break;
        }
    }
    if(encontrado==0){
        strcpy(libro_anadir.titulo, titulo);
        printf("Nombre del autor: ");
        fgets(libro_anadir.autor, 50, stdin);
        if(libro_anadir.autor[strlen(libro_anadir.autor)-1]=='\n'){
            libro_anadir.autor[strlen(libro_anadir.autor)-1]='\0';
        }
        printf("Precio: ");
        scanf("%f", &(libro_anadir.precio));
        while(getchar()!='\n');
        printf("Unidades del producto: ");
        scanf("%d", &(libro_anadir.unidades));
        fwrite(&libro_anadir, sizeof(libro), 1, fichero);
    }
    fclose(fichero);
}

void contarlibros(char *nombre){
    FILE *fichero;
    fichero=fopen(nombre, "rb");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    libro contador;
    int n=0;
    while(fread(&contador, sizeof(contador), 1, fichero)==1){
        n+=1;

    }
    printf("Hay %d libros diferentes en el stock.\n", n);
    fclose(fichero);
}

void listarlibros(char *nombre){
    FILE *fichero;
    fichero=fopen(nombre, "rb");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero.");
        return;
    }
    libro mostrarlibro;
    while(fread(&mostrarlibro, sizeof(libro), 1, fichero)==1){
        printf("\nTitulo: %s", mostrarlibro.titulo);
        printf("\nAutor: %s", mostrarlibro.autor);
        printf("\nPrecio: %.2f\n", mostrarlibro.precio);
        printf("Unidades: %d\n", mostrarlibro.unidades);
    }
    fclose(fichero);
}

void hacerstruct(char *nombre, libro **libros, int *k){
    FILE *fichero;
    fichero=fopen(nombre, "rb");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    libro libroleido;
    while(fread(&libroleido, sizeof(libro), 1, fichero)==1){
        *k+=1;
    }
    *libros=(libro*) malloc((*k)*sizeof(libro));
    int i=0;
    rewind(fichero);
    fread(*libros, sizeof(libro), *k, fichero);
    fclose(fichero);
}

void subirprecio(char *nombre, libro *libros, int n){
    FILE *fichero;
    fichero=fopen(nombre, "wb");
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
    fwrite(libros, sizeof(libro), n, fichero);
    fclose(fichero);
}

void venderlibros(char *nombre, libro *libros, int n){
    FILE *fichero;
    fichero=fopen(nombre, "w+b");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    printf("Introduce el nombre del libro y las unidades a vender: ");
    char titulo[50];
    while(getchar()!='\n');
    fgets(titulo, 50, stdin);
    if(titulo[strlen(titulo)-1]=='\n'){
        titulo[strlen(titulo)-1]='\0';
    }
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
    fwrite(libros, sizeof(libro), n, fichero);
    fclose(fichero);
}
void nuevofichero(char *nombre){
    FILE *fichero;
    FILE *fichero2;
    fichero=fopen(nombre, "rb");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    fichero2=fopen("catalogo extra", "wb");
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
    libro libroactualizado;
    while(fread(&libroactualizado, sizeof(libro), 1, fichero)==1){
        if(libroactualizado.unidades<min){
            fwrite(&libroactualizado, sizeof(libro), 1, fichero2);
        }
    }
    fclose(fichero);
    fclose(fichero2);
}

void renovarfichero(char *nombre){
    FILE *fichero;
    FILE *fichero2;
    fichero=fopen(nombre, "rb");
    if(fichero==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    fichero2=fopen("reemplazo", "wb");
    if(fichero2==NULL){
        printf("No se ha podido abrir el fichero");
        return;
    }
    libro libroleido;
    while(fread(&libroleido, sizeof(libro), 1, fichero)==1){
        if(libroleido.unidades!=0){
            fwrite(&libroleido, sizeof(libro), 1, fichero2);
        }
    }
    fclose(fichero);
    fclose(fichero2);
    remove(nombre);
    rename("reemplazo", nombre);
}