#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM_MAX 100

int esprefijo(char cad[], char pref[]){
    int j=0;
    for(int i=0;i<strlen(cad);i++){
        cad[i]=toupper(cad[i]);
        pref[j]=toupper(pref[j]);
        if(cad[i]==pref[j]){
            j++;
        }
    }
    if(j==strlen(pref)){
        return 1;
    }
    else{
        return 0;
    }
}

int essufijo(char cad[], char suf[]){
    int j=0;
    for(int i=0;i<strlen(cad);i++){
        cad[i]=toupper(cad[i]);
        suf[j]=toupper(suf[j]);
        if(cad[i]==suf[j]){
            j++;
        }
    }
    if(strlen(suf)==j){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char cad[TAM_MAX], pref[TAM_MAX], suf[TAM_MAX];
    printf("Introduce la primera cadena: \n");
    fgets(cad,TAM_MAX, stdin);
    printf("Introduce el prefijo: \n");
    fgets(pref, TAM_MAX, stdin);
    printf("Introduce el sufijo: \n");
    fgets(suf, TAM_MAX, stdin);
    int x=esprefijo(cad, pref);
    if(x==1){
        printf("La palabra %s es prefijo. \n", pref);
    }
    else{
        printf("La palabra %s no es pref.\n", pref);
    }
    int y=essufijo(cad, suf);
    if(y==1){
        printf("La palabra %s es sufijo.", suf);
    }
    else{
        printf("La palabra %s no es sufijo", suf);
    }
}