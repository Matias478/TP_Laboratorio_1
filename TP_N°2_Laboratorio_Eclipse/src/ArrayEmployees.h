/*
 * ArrayEmployees.h
 *
 *  Created on: 14 may. 2021
 *      Author: MATIAS
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
    int id;
    char nombre[21];
    char apellido[21];
    float sueldo;
    int sector;
    int isEmpty;//1 si esta vacio y 0 si no lo esta
}eEmpleado;

/** \brief Indicar que todas las posciciones en el array estan vacias
 *
 * \param lista[] eEmpleado array de la lista de empleados
 * \param tam int tamanio del array
 * \return int retorna -1 si hay un error y retorna 0 si esta todo ok
 *
 */
int initEmployees(eEmpleado lista[], int tam);

/** \brief Recibe una estructura que busca al empleado por id y devuelve si dicho id fue encontrado o no
 *
 * \param lista[] eEmpleado array de la lista de empleados
 * \param tam int tamanio del array
 * \return int retorna -1 si hay algun error y sino retorna la variable index en la posicion i
 *
 */
int buscarLibre(eEmpleado lista[], int tam);

/** \brief añade en una lista existente de empleados los valores recibidos como parámetros en la primera posición vacía
 *
 * \param lista[] eEmpleado array de la lista de empleados
 * \param tam int tamanio del array
 * \param pId int*
 * \return int retorna 0 si hay algun error o no hay espacio y 1 si esta todo bien
 *
 */
int addEmployee(eEmpleado lista[], int tam, int* pId);

/** \brief encuentra un empleado por Id
 *
 * \param lista[] eEmpleado array de la lista de empleados
 * \param tam int tamaño del array
 * \param id int puntero a la variable nextId
 * \return int retorna la posicion i en el array
 *
 */
int findEmployeeById(eEmpleado lista[], int tam,int id);

/** \brief Muestra un empleado
 *
 * \param unEmpleado eEmpleado
 * \return void
 *
 */
void MostrarEmpleado(eEmpleado unEmpleado);

/** \brief Muestra la lista de todos los empleado cargados
 *
 * \param lista[] eEmpleado array de empleados
 * \param tam int tamaño del array
 * \return void
 *
 */
void MostrarEmpleados(eEmpleado lista[], int tam);

/** \brief remueve un empleado por id (y coloca el isEmpty en 1)
 *
 * \param lista[] eEmpleado array de empleados
 * \param tam int tamaño del array
 * \return int retorna 0 si hay algun error o no hay espacio y 1 si esta todo bien
 *
 */
int removeEmployees(eEmpleado lista[] , int tam);

/** \brief Modifica los datos de un empleado por id
 *
 * \param lista[] eEmpleado array de empleados
 * \param tam int tamaño del array
 * \return int retorna 0 si hay algun error o no hay espacio y 1 si esta todo bien
 *
 */
int ModifyEmployees(eEmpleado lista[] , int tam);

/** \brief Ordena a la lista de empleados
 *
 * \param lista[] eEmpleado array de empleados
 * \param tam int tamaño del array
 * \param order int criterio de ordenamiento (1 ascendente) o (0 descendente)
 * \return int devuelve 0 si hay algun error y 1 si esta todo ok
 *
 */
int sortEmployees(eEmpleado lista[],int tam,int order);

/** \brief realiza el total, promedio y la cant de empleados que superan el promedio de salarios
 *
 * \param lista[] eEmpleado array de empleados
 * \param tam int tamaño del array
 * \return int devuelve 0 si hay algun error y 1 si esta todo ok
 *
 */
int TotalSalarios(eEmpleado lista[],int tam);
/** \brief llama a la funcion que muestra la lista de empleados
 *
 * \param lista[] eEmpleado array de empleados
 * \param tam int tamaño del array
 * \return int devuelve 0 si hay algun error y 1 si esta todo ok
 *
 */
int printEmployees(eEmpleado lista[], int tam);

/** \brief es un subMenu que muestra las opciones de ordenamiento y la de los salarios
 *
 * \param lista[] eEmpleado array de empleados
 * \param tam int tamaño del array
 * \return int devuelve 0 si hay algun error y 1 si esta todo ok
 *
 */
int Informes(eEmpleado lista[],int tam);

/** \brief Activa y cambia el valor de una bandera
 *
 * \param a int* Puntero a la bandera
 * \return void
 *
 */
void ActivarFlag(int* a);

/** \brief comando por parámetro la primera letra del nombre se convierte en mayúsculas y el resto en minúsculas
 *
 * \param name[] char
 * \param nombres char*
 * \return void
 *
 */
void TolowerToupperName(char name[],char* nombres);

/** \brief valida si lo que si ingreso es un numero
 *
 * \param   number[] char
 * \return int
 *
 */
int validNumber(char number[]);

/** \brief valida si lo que si ingreso es una cadena
 *
 * \param nombre[] char
 * \return int
 *
 */
int validarNombre(char nombre[]);

#endif /* ARRAYEMPLOYEES_H_ */
