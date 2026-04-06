#include <stdio.h>
#include <ctype.h>
#include <string.h>

int contarvocales(char cad[], int max, int n){
    for(int i=0;i<strlen(cad);i++){
        cad[i]=toupper(cad[i]);
        if(cad[i]=='A' || cad[i]=='E' || cad[i]=='I' || cad[i]=='O' || cad[i]=='U'){
            n++;
        }
    }
    return n;
}

void rellenar(char cad[], int max){
    for(int i=0;i<strlen(cad);i++){
        if(cad[i]==' '){
            cad[i]='_';
        }
    }
}

#define MAX 40
int main(){
    char nombre[MAX];
    printf("Introduce tu nombre: ");
    fgets(nombre, MAX, stdin);
    printf("\n");
    int x=0;
    int n=contarvocales(nombre, MAX, x);
    printf("Hay %d vocales en el nombre. \n", n);
    rellenar(nombre, MAX);
    for(int i=0;i<strlen(nombre);i++){
        printf("%s", nombre);
    }
    return 0;
}