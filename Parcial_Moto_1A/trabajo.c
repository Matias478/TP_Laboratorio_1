#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "trabajo.h"

int BuscarLibreTrabajo(eTrabajo trabajos[],int tam)
{
    int index=-1;
    for(int i=0;i<tam;i++)
    {
        if(trabajos[i].isEmpty)
        {
            index=i;
            break;
        }
    }
    return index;
}

int AltaTrabajo(eTrabajo trabajos[],int tamTr,eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC,eServicio servicios[],int tamS,int* pId)
{
    eTrabajo auxTrabajo;
    int todoOk=0;
    int indice;
    int id;
    int idServicios;
    if(motos!=NULL && tipos!=NULL && trabajos!=NULL && colores!=NULL && servicios!=NULL && pId!=NULL && tamM>0 && tamT>0 &&tamC>0&& tamS>0&& tamTr>0)
    {
        printf("       Alta Trabajos     \n");
        indice=BuscarLibreTrabajo(trabajos,tamTr);
        if(indice==-1)
        {
            printf("No hay mas lugar\n");
        }else
        {
            MostrarMotos(motos,tamM,tipos,tamT,colores,tamC);
            printf("\nIngrese id de moto:");
            scanf("%d",&id);
            while(BuscarMoto(motos,tamM,id)==-1)
            {
                printf("No existe una moto con ese ID.Reingrse ID:\n");
                scanf("%d",&id);
            }
            auxTrabajo.idMoto=id;
            MostrarServicios(servicios,tamS);
            printf("Ingrese id servicio: ");
            scanf("%d", &idServicios);
            while(!ValidarIdServicio(idServicios,servicios,tamS))
            {
                printf("Id invalido.Reingrese id servicio: ");
                scanf("%d", &idServicios);
            }
            auxTrabajo.idServicio=idServicios;
            printf("Ingrse fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d", &auxTrabajo.fechaTrabajo.dia,&auxTrabajo.fechaTrabajo.mes,&auxTrabajo.fechaTrabajo.anio);
            auxTrabajo.id=*pId;
            (*pId)++;
            auxTrabajo.isEmpty=0;
            trabajos[indice]=auxTrabajo;
            todoOk=1;
        }
    }

    return todoOk;
}

void MostrarTrabajos(eTrabajo trabajos[],int tamTr,eServicio servicios[],int tamS,eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC)
{
    int flag = 1;
    printf("*****************Lista de Trabajos*******************\n");
    printf("ID\tMarca\t\tServicio\t\tFecha \n");
    for(int i=0;i<tamTr;i++)
    {
        if(!trabajos[i].isEmpty)
        {
            MostrarTrabajo(trabajos[i],servicios,tamS,motos,tamM);
            flag=0;
        }
    }
    if(flag==1)
    {
        printf("\tNo hay empleados que mostrar");
    }
    printf("\n\n");
}

void MostrarTrabajo(eTrabajo unTrabajo,eServicio servicios[],int tamS,eMoto motos[],int tamM)
{
    char marcaMoto[20];
    char descripcionServicios[20];
    if(CargarMarcaMoto(unTrabajo.idMoto,motos,tamM,marcaMoto)&&
       CargarDescripcionServicios(unTrabajo.idServicio,servicios,tamS,descripcionServicios))
    {
        printf(" %d\t %10s \t%10s \t%02d/%02d/%02d\n"
               ,unTrabajo.id
               ,marcaMoto
               ,descripcionServicios
               ,unTrabajo.fechaTrabajo.dia
               ,unTrabajo.fechaTrabajo.mes
               ,unTrabajo.fechaTrabajo.anio);
    }
}
