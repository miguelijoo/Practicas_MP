#include <stdio.h>
#include <math.h>

void estadisticasVector(int v[], int n, float *media, float *varianza, float *desviacion){
    int suma=0;
    for(int i=0;i<5;i++){
            scanf("%d", &v[i]);
            printf("El elemento %d del vector es %d \n", i+1, v[i]);
            suma=suma+v[i];
        }
    *media=suma/n;
    printf("La media es: %.3f\n", *media);
    for(int i=0;i<5;i++){
        *varianza=*varianza+pow((v[i]-*media), 2);
    }
    *varianza=*varianza/n;
    printf("La varianza de los datos es: %.3f \n", *varianza);
    *desviacion=sqrt(*varianza);
    printf("La desviacion tipica de los datos es: %.3f \n", *desviacion);
}

//Se debería hacer la muestra de resultados en la función main ya que ahí es donde se pone a prueba que los punteros se han ejecutado correctamente.

int main(){
    int v[5];
    float media=0, varianza=0, desviacion=0;
    printf("Rellene los valores del vector: \n");
    estadisticasVector(v, 5, &media, &varianza, &desviacion);
}