#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_MAX 100

void estadisticasCadena(char cad[], int *ndigitos, int *nmin, int *nmayus, int *nespacios){
    for(int i=0;i<strlen(cad);i++){
        if(isdigit(cad[i])){
            *ndigitos+=1;
        }
        if(islower(cad[i])){
            *nmin+=1;
        }
        if(isupper(cad[i])){
            *nmayus+=1;
        }
        if(isspace(cad[i])){
            *nespacios+=1;
        }
    }
    *nespacios-=1;
}

int main(){
    char cad[TAM_MAX];
    int ndigitos=0, nmin=0, nmayus=0, nespacios=0;
    printf("Introduzca una cadena de caracteres para ver sus digitos, sus mayusculas, minusculas y espacios: ");
    fgets(cad, TAM_MAX, stdin);
    estadisticasCadena(cad, &ndigitos, &nmin, &nmayus, &nespacios);
    printf("La cadena tiene %d digitos. \n", ndigitos);
    printf("La cadena tiene %d minusculas. \n", nmin);
    printf("La cadena tiene %d mayusculas. \n", nmayus);
    printf("La cadena tiene %d espacios. \n", nespacios);
    return 0;
}