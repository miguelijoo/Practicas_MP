#include<stdio.h>

float media(int n1, int n2){
    float media=0;
    media=(n1+n2)/2.0;
    return media;
}

void media2(int n1, int n2, float *resultado2){
    *resultado2=(n1+n2)/2.0;
}

int main(){
    int n1=0, n2=0;
    printf("Introduzca el valor de los dos numeros para hacer su media: \n");
    scanf("%d", &n1);
    scanf("%d", &n2);
    float resultado=media(n1,n2);
    if(resultado!=(n1+n2)/2.0){
        printf("El primer programa no funciona. \n");
    }
    else if(resultado==(n1+n2)/2.0){
        printf("El primer programa funciona. \n");
    }
    float resultado2=0;
    media2(n1,n2, &resultado2);
    if(resultado2!=(n1+n2)/2.0){
        printf("El segundo programa no funciona. \n");
    }
    else if(resultado2==(n1+n2)/2.0){
        printf("El segundo programa funciona. \n");
    }
    return 0;
}