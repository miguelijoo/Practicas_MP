#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * @file funciones.h
 * @author Miguel Ángel Alijo Fernández
 * @brief Estas son las funciones usadas para permitir la ejecución correcta de mi código
 * @date 07-04-2026
*/
float **crearimagen(int alto, int ancho);
/**
 * @fn float crearimagen(int alto, int ancho)
 * @brief Se encarga de reservar la memoria necesaria para poder crear la matriz sin problemas. En primer lugar se crea un array de punteros que serán las filas de una matriz. Sin embargo, la creación de las columnas de la matriz no se harán fila por fila, sino que se pondrán todos los huecos en los que se introducirán los números en m[0], es decir, el puntero inicial del array de punteros es el que apunta al inicio de toda la fila de datos de la matriz. Los demás punteros de dicho array apuntarán al inicio de cada fila que sería cada n columnas respecto del anterior. Para una matriz 3x3 tendríamos un array de punteros de 3 casillas donde el primero es el que apunta al inicio de toda la fila consecutiva de datos float y los otros 2 punteros se encargan de apuntar 3 cajas de datos float después de donde empieza a apuntar el anterior.
 */
void generarruido(float **imagen, int alto, int ancho);

void aplicarumbral(float **imagen, int alto, int ancho, float umbral);

void destruirimagen(float ***imagen);

#endif