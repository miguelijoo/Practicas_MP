#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

void rellenavector(int v[], int inf, int sup){
    for(int i=0;i<TAM;i++){
        v[i]=inf + (rand() % (sup-inf+1));
        printf("%d \n", v[i]);
    }
}
void indices(int v[], int *impares[], int *entre3[], int *imparestot, int *entre3tot){
    for(int i=0;i<TAM;i++){
        if(v[i]%3==0){
            entre3[*entre3tot]=&v[i];
            *entre3tot+=1;
        }
        if(v[i]%2!=0){
            impares[*imparestot]=&v[i];
            *imparestot+=1;
        }
    }
}
int main(){
    time_t t;
    srand((int) time(&t));
    int inf=0, sup=0, v[TAM], *impares[TAM], *entre3[TAM], imparestot=0, entre3tot=0;
    printf("Introduce un valor minimo y uno maximo para generar los numeros aleatorios del array: \n");
    scanf("%d", &inf);
    scanf("%d", &sup);
    rellenavector(v, inf, sup);
    indices(v, impares, entre3, &imparestot, &entre3tot);
    printf("El vector de impares es: ");
    for(int i=0;i<imparestot;i++){
        printf("%d ", *impares[i]);
    }
    printf("\n");
    printf("El vector de divisibles entre 3 es: ");
    for(int i=0;i<entre3tot;i++){
        printf("%d ",*entre3[i]);
    }
}