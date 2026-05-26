#include <stdio.h>
#include "funciones.h"
#include <string.h>

int contarletra(char *cad, char letra, int i, int cont){ /*A tener en cuenta, si pongo la letra e y la cadena es "Este es mi amigo", la letra e se cuenta 2 veces ya que la "E" no se detectaría, solamente la "e".*/
    if(cad[i]=='\0'){
        return cont;
    }
    else{
        if(cad[i]==letra){
            cont+=1;
        }
        return contarletra(cad, letra, i+1, cont);
    }
}