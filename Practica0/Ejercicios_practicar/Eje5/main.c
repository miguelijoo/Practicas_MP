#include <stdio.h>
#include <string.h>

struct articulo{
    char nombre[100];
    int cantidad;
    float precio;
};

void rellenararticulo(struct articulo item[], int n){
    for(int i=0;i<n;i++){
        printf("Introduzca nombre del item: \n");
        fgets(item[i].nombre, 100, stdin);
        getchar();
        printf("Introduce cantidad: \n");
        scanf("%d", &item[i].cantidad);
        printf("Introduzca precio: \n");
        scanf("%f", &item[i].precio);
    }
}

void imprimir(struct articulo item[], int n){
    for(int i=0;i<n;i++){
        printf("%s \n", item[i].nombre);
        printf("%d \n",item[i].cantidad);
        printf("%f \n", item[i].precio);
}
}

int main(){
struct articulo item[3];
rellenararticulo(item, 3);
imprimir(item, 3);
}