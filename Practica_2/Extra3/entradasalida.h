/**
 * @file entradasalida.h
 * @author Miguel Ángel Alijo Fernández
 * @brief Este fichero contiene los prototipos de las funciones que se usan en la biblioteca generada.
 * @date 09-04-2026
 * @version 1.0.0
 */
#ifndef ENTRADASALIDA_H
#define ENTRADASALIDA_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @fn void rellenarmatriz(double **matriz, int fil, int col, double max, double min)
 * @brief Esta función es la encargada de rellenar de datos la matriz. Se rellena con números aleatorios generados en un rango establecido por el usuario.
 * @param matriz Es la matriz a rellenar
 * @param fil Filas de la matriz
 * @param col Columnas de la matriz
 * @param max Valor máximo del rango de números aleatorios a generar
 * @param min Valor mínimo del rango de números aleatorios a generar
 * @return No devuelve nada, sólo modifica los valores que tendrá la matriz en su interior.
 */
void rellenarmatriz(double **matriz, int fil, int col, double max, double min);
/**
 * @fn void mostrarmatriz(double **matriz, int fil, int col)
 * @brief Esta función es la encargada de mostrar la matriz por pantalla
 * @param matriz Es la matriz a rellenar
 * @param fil Filas de la matriz
 * @param col Columnas de la matriz
 * @return No devuelve nada, sólo muestra la matriz en pantalla.
 */
void mostrarmatriz(double **matriz, int fil, int col);

#endif