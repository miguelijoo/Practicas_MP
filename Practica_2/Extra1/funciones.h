#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float **crearimagen(int alto, int ancho);
void generarruido(float **imagen, int alto, int ancho);
void aplicarumbral(float **imagen, int alto, int ancho, float umbral);
void destruirimagen(float ***imagen);