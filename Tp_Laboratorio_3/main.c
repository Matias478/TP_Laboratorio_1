#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

// Leer!!!!!
//  Problemas al ordenar: no me ordena por nombre a los empleados que se ingresan por consola y puede ser que encuentre problemas en el id cuando no cargue el archivo por csv
// Lo subo en codeblocks por que eclipse no me reconoce el archivo de data.csv por ende las opciones 1,2,8,9 no funcionan por que rompen sin ninguna razon.
// En codeblocks esto no pasa asi que lo subo por aca :). Sepan entender gracias
// ***Matias Ferrari 1°A_2021***

int main()
{
    int option = 0;
    int nextId=1001;
    int flag=0;
    char confirma;
    LinkedList* listaEmpleados = ll_newLinkedList();


   do{
        system("cls");
        printf("  ******LinkedList*******  \n");
        printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
        printf("\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)");
        printf("\n3. Alta de empleado");
        printf("\n4. Modificar datos de empleado");
        printf("\n5. Baja de empleado");
        printf("\n6. Listar empleados");
        printf("\n7. Ordenar empleados");
        printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)");
        printf("\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario)");
        printf("\n10. Salir\n");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                system("cls");
                if(flag==1)
                {
                    printf("Es probable que se sobreescriban algunos empleados. Desea borrarlos?(si=s no=n)");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    if(confirma=='s')
                    {
                        ll_clear(listaEmpleados);
                    }
                }
                controller_loadFromText("data.csv",listaEmpleados);
                BuscarMayorId(listaEmpleados,&nextId);
                system("pause");
                break;
            case 2:
                system("cls");
                if(flag==1)
                {
                    printf("Es probable que se sobreescriban algunos empleados. Desea borrarlos?(si=s no=n)");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    if(confirma=='s')
                    {
                        ll_clear(listaEmpleados);
                    }
                }
                controller_loadFromBinary("data.bin",listaEmpleados);
                BuscarMayorId(listaEmpleados,&nextId);
                system("pause");
                break;
            case 3:
                system("cls");
                if(controller_addEmployee(listaEmpleados, &nextId))
                {
                    nextId++;
                    flag=1;
                }
                system("pause");
                break;
            case 4:
                system("cls");
                controller_editEmployee(listaEmpleados);
                system("pause");
                break;
            case 5:
                system("cls");
                controller_removeEmployee(listaEmpleados);
                system("pause");
                break;
            case 6:
                system("cls");
                controller_ListEmployee(listaEmpleados);
                system("pause");
                break;
            case 7:
                system("cls");
                controller_sortEmployee(listaEmpleados);
                system("pause");
                break;
            case 8:
                system("cls");
                controller_saveAsText("data.csv",listaEmpleados);
                system("pause");
                break;
            case 9:
                system("cls");
                controller_saveAsBinary("data.bin",listaEmpleados);
                system("pause");
                break;
            case 10:
                printf("Gracias por usar este programa :)\n");
                break;
        }
    }while(option != 10);
    return 0;
}



