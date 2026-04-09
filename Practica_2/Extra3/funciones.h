/**
 * @file funciones.h
 * @author Miguel Ángel Alijo Fernández
 * @brief Este fichero contiene los prototipos de las funciones relacionadas con la reserva de memoria de la matriz, la comparación de los valores de la matriz para ver si son positivos o negativos y la liberación de memoria final.
 * @date 09-04-2026
 * @version 1.0.0
 */
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * @fn double **crearmatriz(int fil, int col)
 * @brief Esta función es la encargada de reservar memoria para generar la matriz y comprobar que hay memoria suficiente para dicha reserva. La reserva se hará generando primero un array de punteros que serán las filas de la matriz y posteriormente estos punteros de este array serán los arrays de datos double, es decir, las columnas de la matriz.
 * @param matriz Es la matriz a rellenar
 * @param fil Filas de la matriz
 * @param col Columnas de la matriz
 * @return Devuelve un puntero doble de tipo double, que sería la matriz generada en la función.
 */
double **crearmatriz(int fil, int col);
/**
 * @fn void comparar(double **matriz, int fil, int col, int *pos, int *neg)
 * @brief Esta función se encarga de comparar cada valor de la matriz para establecer si es positivo o negativo.
 * @param matriz Es la matriz
 * @param fil Filas de la matriz
 * @param col Columnas de la matriz
 * @return No devuelve nada pero modifica en el main los valores pasados por referencia para saber cuántos valores positivos y negativos tiene la matriz.
 */
void comparar(double **matriz, int fil, int col, int *pos, int *neg);
/**
 * @fn void liberarmatriz(double ***matriz, int fil)
 * @brief Esta función es la encargada de liberar la memoria que ocupa la matriz, liberando primero los arrays de datos tipo double y tras esto los pone a NULL. Una vez hecho este proceso se libera el array de punteros y se pone el puntero doble a NULL. Este proceso se hace mediante paso por referencia.
 * @param matriz Es la matriz
 * @param fil Filas de la matriz
 * @return No devuelve nada. Sólo libera la memoria que ocupaba la matriz.
 */
void liberarmatriz(double ***matriz, int fil);
#endif