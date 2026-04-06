#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main(){
    char cadena[50];
    printf("Introduce la frase: ");
    fgets(cadena, 50, stdin);
    char **vstrings=separarpalabras(cadena, strlen(cadena));
    return 0;
}