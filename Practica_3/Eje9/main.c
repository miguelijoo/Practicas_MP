#include <stdio.h>
#include "funciones.h"

int main(){
    printf("Introduzca 2 números para sacar el M.C.D.\n");
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    while(y>x){
        printf("Introduzca primero el numero grande y luego el pequeño.\n");
        scanf("%d", &x);
        scanf("%d", &y);
    }
    int num=mcd(x, y);
    printf("El M.C.D. de %d y %d es: %d\n", x, y, num);
    return 0;
}