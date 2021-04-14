/*
 * Funciones.h
 *
 *  Created on: 12 abr. 2021
 *      Author: MATIAS
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>


/** \brief float Hace la suma de dos numeros ingresados
 *
 * \param float Uno de los valores al cual se le aplica la operacion
 * \param float Otro de los valores
 * \return El resultado de la suma de los numeros
 *
 */
float sumarNumeros(float, float);

/** \brief float Hace la resta de dos numeros ingresados
 *
 * \param float Uno de los numeros que participa en la operacion
 * \param float Otro de los numeros que tambien participa
 * \return El resultado de la resta
 *
 */
float restarNumeros(float, float);

/** \brief float Realiza la multiplicacion de dos numeros ingresados
 *
 * \param float Uno de los numeros que participa en la operacion
 * \param float Otro de los numeros que tambien participa en la operacion
 * \return El resultado de la multiplicacion
 *
 */
float multiplicarNumeros(float, float);

/** \brief float Realiza la division de dos numeros ingresados
 *
 * \param float Uno de los numeros que participa en la operacion
 * \param float Otro de los numeros que tambien participa en la operacion
 * \return El resultado de la division
 *
 */
float dividirNumeros(float, float);

/** \brief int Calcula el factorial de un numero entero
 *
 * \param int El valor sobre el cual se calcula el factorial
 * \return int El resultado del factorial del numero
 *
 */
long long int factorizarNumeroA(int );

/** \brief int Calcula el factorial de un numero entero
 *
 * \param int El valor sobre el cual se calcula el factorial
 * \return int El resultado del factorial del numero
 *
 */
long long int factorizarNumeroB(int );

/** \brief int Contiene el menu con las opciones a elejir
 *
 *
 *
 * \return la opcion que se elijio
 *
 */
int menu();


#endif /* FUNCIONES_H_ */
