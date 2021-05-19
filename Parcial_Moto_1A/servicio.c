#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

void MostrarServicios(eServicio servicios[],int tam)
{
    printf("*********lista de Servicios**********\n");
    printf("Id\tDescripcion\t Precio\n");
    for(int i=0;i<tam;i++)
    {
        MostrarServicio(servicios[i]);
    }
}
void MostrarServicio(eServicio servicios)
{
    printf("%d\t%10s\t %.2f\n",servicios.id,servicios.descripcion,servicios.precio);
}

int ValidarIdServicio(int id, eServicio servicios[],int tam)
{
    int valido=0;
    if(servicios!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            if(servicios[i].id==id)
            {
                valido=1;
                break;
            }
        }
    }
    return valido;
}

int CargarDescripcionServicios(int id, eServicio servicios[],int tam, char desc[])
{
    int todoOk=0;

    if(id>=20000 && id <=20003 && servicios!=NULL && tam>0 && desc!=NULL)
    {
        for(int i =0;i<tam;i++)
        {
            if(servicios[i].id==id)
            {
                strcpy(desc,servicios[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}
