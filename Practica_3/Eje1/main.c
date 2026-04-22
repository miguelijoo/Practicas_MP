#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char nombre[30];
    printf("Introduzca el nombre del fichero: ");
    fgets(nombre, 30, stdin);
    if(nombre[strlen(nombre)-1]=='\n'){
        nombre[strlen(nombre)-1]='\0';
    }
    FILE *fichero;
    fichero=fopen(nombre, "w+");
    if(fichero==NULL){
        printf("El fichero no existe.");
        return -1;
    }
    printf("Rellene el fichero con una frase: \n");
    char frase[40];
    fgets(frase, 40, stdin);
    fprintf(fichero,"%s",frase);

    FILE *ficheromayus;
    ficheromayus=fopen("Mayusculas.txt", "w");
    if(ficheromayus==NULL){
        printf("El fichero no existe.");
        return -1;
    }
    char fraseleida[100];
    rewind(fichero);
    fgets(fraseleida, 100, fichero);
    for(int i=0;i<strlen(fraseleida);i++){
        fraseleida[i]=toupper(fraseleida[i]);
    }
    fprintf(ficheromayus,"%s", fraseleida);
    fclose(fichero);
    fclose(ficheromayus);
}