#include <stdio.h>
#include <stdlib.h>
#include "moto.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "fecha.h"
#define TAMT 4
#define TAMC 5
#define TAMS 4
#define TAMM 50
#define TAMTR 50
//Matias Ferrari!!!

int main()
{
    eTipo tipos[TAMT]={{1000,"Enduro"},
                        {1001,"Chopera"},
                        {1002,"Scooter"},
                        {1003,"Ciclomotor"},
                            };

    eColor colores[TAMC]={{10000,"Gris"},
                        {10001,"Negro"},
                        {10002,"Blanco"},
                        {10003,"Azul"},
                        {10004,"Rojo"},
                            };
    eServicio servicios[TAMC]={
                        {20000,"Limpieza",250},
                        {20001,"Ajuste",300},
                        {20002,"Baleanceo",17},
                        {20003,"Cadena",190},
                               };
    eMoto motos[TAMM];
    eTrabajo trabajos[TAMTR];
    int opcion;
    int nextId=2000;
    int nextIdTrabajo=3000;
    InicializarMotos(motos,TAMM);
    do
    {
        system("cls");
        printf("*******ABM Motos*******\n");
        printf("\nIngrese\n1. Alta Moto");
        printf("\n2. Modificar Moto");
        printf("\n3. Baja Moto");
        printf("\n4. Listar Motos");
        printf("\n5. Listar Tipos");
        printf("\n6. Listar Colores");
        printf("\n7. Listar Servicios");
        printf("\n8. Alta Trabajo");
        printf("\n9. Listar Trabajos");
        printf("\n10. Salir\n");
        printf("Ingrese su opcion:\n ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                if(AltaMotos(motos,TAMM,tipos,TAMT,colores,TAMC,&nextId))
                {
                    printf("\nAlta exitosa!!!\n");
                }else{
                    printf("\nNo se pudieron cargar los datos\n");
                }
                system("pause");
            break;
            case 2:
                  if(ModificarMotos(motos,TAMM,tipos,TAMT,colores,TAMC))
                {
                    printf("\nModificacion exitosa!!!\n");
                }else{
                    printf("\nNo se pudieron modificar los datos\n");
                }
                system("pause");
            break;
             case 3:
                if(BajaMotos(motos,TAMM,tipos,TAMT,colores,TAMC))
                {
                    printf("\nBaja exitosa!!!\n");
                }else{
                    printf("\nNo se pudieron dar de baja los datos\n");
                }
                system("pause");
            break;
             case 4:
                    MostrarMotos(motos,TAMM,tipos,TAMT,colores,TAMC);
                system("pause");
            break;
             case 5:
                    MostrarTipos(tipos,TAMT);
                system("pause");
            break;
             case 6:
                    MostrarColores(colores,TAMC);
                system("pause");
            break;
             case 7:
                    MostrarServicios(servicios,TAMS);
                system("pause");
            break;
             case 8:
                  if(AltaTrabajo(trabajos,TAMTR,motos,TAMM,tipos,TAMT,colores,TAMC,servicios,TAMS,&nextIdTrabajo))
                {
                    printf("\nAlta exitosa!!!\n");
                }else{
                    printf("\nNo se pudieron cargar los datos\n");
                }
                system("pause");
            break;
             case 9:
                    MostrarTrabajos(trabajos,TAMTR,servicios,TAMS,motos,TAMM,tipos,TAMT,colores,TAMC);
                system("pause");
            break;
             case 10:
                    printf("\nGracias por usar este programa,Hasta luego\n");
                system("pause");
            break;
        }
    }while(opcion!=10);
    return 0;
}
