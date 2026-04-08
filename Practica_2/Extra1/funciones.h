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
 * @param alto Número de filas de la matriz.
 * @param ancho Número de columnas de la matriz.
 * @return Devuelve un puntero a puntero a float que es la matriz creada, o NULL si no se ha podido crear por falta de memoria.
 */
void generarruido(float **imagen, int alto, int ancho);
/**
 * @fn vodi generarruido(float **imagen, int alto, int ancho)
 * @brief Se encarga de generar números aleatorios para cada casilla de memoria creada en la matriz, es decir, en una matriz 3x3 tendríamos 9 huecos listos para ser ocupados por datos tipo float y esta función asigna a cada hueco de memoria un float entre 0 y 255. Esto se hace recorriendo la matriz como si fuese un array unidimensional mediante aritmética de punteros, recorriéndose la fila 0 desde el inicio hasta el final ya que es en esta fila donde se han generado todos los huecos de memoria para los datos float y el puntero que empieza en la posición 0 de este array de floats es el que permite recorrer el array al completo sin saltarse nada.
 * @param imagen Matriz creada en la función crearimagen.
 * @param alto Número de filas de la matriz.
 * @param ancho Número de columnas de la matriz.
 */

void aplicarumbral(float **imagen, int alto, int ancho, float umbral);
/**
 * @fn void aplicarumbral(float **imagen, int alto, int ancho, float umbral)
 * @brief Se encarga de aplicar un umbral a la matriz establecido por el usuario. Al recorrer esta matriz, que se hace en este caso como si fuese una matriz normal, con doble corchete, se va comparando cada número de la matriz con el umbral establecido por el usuario y si el número es menor que el umbral se pone 0 en dicha casilla y si es mayor o igual se deja como está.
 * @param imagen Matriz creada en la función crearimagen.
 * @param alto Número de filas de la matriz.
 * @param ancho Número de columnas de la matriz.
 * @param umbral Número introducido por el usuario que se usará como umbral para la comparación de dígitos.
 */

void destruirimagen(float ***imagen);
/**
 * @fn void destruirimagen(float ***imagen)
 * @brief Se encarga de liberar la memoria reservada para la matriz creada en la función. Primero se libera el array de floats creado en la fila 0 y una vez liberado este array se libera el array de punteros que serían las filas de la matriz y se pone a NULL para que no ocupe más espacio en memoria.
 * @param imagen Matriz que vamos a liberar
 */

#endif