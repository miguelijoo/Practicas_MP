#include <stdio.h>
#define F 3
#define C 3

void imprime(int matriz[F][C], int f, int c){
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int m[F][C];
    for(int i=0;i<F;i++){
        for(int j=0;j<C;j++){
            m[i][j]=0;
        }
    }
    int fila=0, columna=0;
    printf("Introduzca las coordenadas del mapa del tesoro: \n");
    scanf("%d %d", &fila, &columna);
    m[fila][columna]=1;
    imprime(m, F, C);
    return 0;
}