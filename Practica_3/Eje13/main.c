#include <stdio.h>
#include "funciones.h"
#include <string.h>

int main(){
    printf("Introduzca la cadena de caracteres: ");
    char cad[200], letra;
    fgets(cad, 200, stdin);
    if(cad[strlen(cad)-1]=='\n'){
        cad[strlen(cad)-1]='\0';
    }
    printf("Introduzca la letra para ver cuánto se repite: ");
    scanf("%c", &letra);
    int i=0, cont=0;
    int num=contarletra(cad, letra, i, cont);
    printf("La letra %c aparece %d veces.\n", letra, num);
}