/*
 ============================================================================
 Name        : TP_N°2_Laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 500

int main(void) {

	setbuf(stdout, NULL);

	 eEmpleado nomina[TAM];
	    int opcion;
	    int flag=0;
	    int nextId=20000;
	    initEmployees(nomina,TAM);
	    do
	    {
	        system("cls");
	        printf("*******ABM Empleados*******\n");
	        printf("\n1.Altas\n");
	        printf("\n2.Modificar\n");
	        printf("\n3.Baja\n");
	        printf("\n4.Informar\n");
	        printf("\n5.Salir\n");
	        printf("\nIngrese su opcion: ");
	        scanf("%d", &opcion);

	         switch(opcion)
	        {
	            case 1:
	                if(addEmployee(nomina,TAM,&nextId))
	                {
	                    printf("\nAlta exitosa!!!\n");
	                    ActivarFlag(&flag);
	                }else{
	                    printf("\nNo se pudieron cargar los datos\n");
	                }
	                system("pause");
	            break;
	            case 2:
	                if(flag==1)
	                {
	                    if(ModifyEmployees(nomina,TAM))
	                    {
	                        printf("\nModificacion exitosa!!!\n");
	                    }else{
	                        printf("\nNo se pudieron modificar los datos\n");
	                    }
	                }else{
	                    printf("\nDebe cargar al menos un empleado para acceder a las modificaciones\n");
	                }
	                system("pause");
	            break;
	            case 3:
	                 if(flag==1)
	                {
	                    if(removeEmployees(nomina,TAM))
	                    {
	                        printf("\nBaja exitosa!!!\n");
	                    }else{
	                        printf("\nNo se pudo hacer la baja del empleado\n");
	                    }
	                }else{
	                    printf("\nDebe cargar al menos un empleado para acceder a las bajas\n");
	                }
	               system("pause");
	            break;
	            case 4:
	                if(flag==1)
	                {
	                    Informes(nomina,TAM);
	                }else
	                {
	                    printf("\nDebe cargar al menos un empleado para acceder a informes\n");
	                }
	                system("pause");
	            break;
	            case 5:
	                printf("\nHasta luego, gracias por usar este programa\n");
	            break;
	        }

	    }while(opcion!=5);

	return EXIT_SUCCESS;
}
