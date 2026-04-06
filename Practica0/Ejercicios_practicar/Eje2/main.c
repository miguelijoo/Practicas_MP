#include <stdio.h>
#define MAX 7

void rellenarTemperaturas(int temp[], int max){
    for(int i=0;i<max;i++){
        scanf("%d", &temp[i]);
    }
}

int maxtemp(int temp[], int max){
    int maximovalor=temp[0];
    for(int i=0;i<max;i++){
        if(temp[i]>maximovalor){
            maximovalor=temp[i];
        }
    }
    return maximovalor;
}

int mintemp(int temp[], int max){
    int minimovalor=temp[0];
    for(int i=0;i<max;i++){
        if(temp[i]<minimovalor){
            minimovalor=temp[i];
        }
    }
    return minimovalor;
}

int main(){
    int temp[MAX];
    printf("Introduce las temperaturas de la semana: \n");
    rellenarTemperaturas(temp, MAX);
    printf("La temperatura mas alta de la semana es: %d \n", maxtemp(temp, MAX));
    printf("La temperatura mas baja de la semana es: %d \n", mintemp(temp, MAX));
    return 0;
}