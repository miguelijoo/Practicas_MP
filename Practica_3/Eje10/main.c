#include <stdio.h>
#include "funciones.h"

int main(){
    printf("Introduzca el dividendo y el divisor:\n");
    int x, y, n=0;
    scanf("%d", &x);
    scanf("%d", &y);
    while(x<y){
        printf("Introduzca primero el dividendo y luego el divisor:\n");
        scanf("%d", &x);
        scanf("%d", &y);
    }
    int num=div(x, y, n);
    printf("El cociente es %d.\n", num);
    return 0;
}