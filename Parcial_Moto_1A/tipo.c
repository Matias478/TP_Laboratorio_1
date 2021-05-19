#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"


int CargarDescripcionTipo(int id, eTipo tipos[],int tam, char desc[])
{
    int todoOk=0;

    if(id>=1000 && id <=1003 && tipos!=NULL && tam>0 && desc!=NULL)
    {
        for(int i =0;i<tam;i++)
        {
            if(tipos[i].id==id)
            {
                strcpy(desc,tipos[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}

void MostrarTipos(eTipo tipos[],int tam)
{
    printf("*********lista de Tipos**********\n");
    printf("id\t Descripcion\n");
    for(int i=0;i<tam;i++)
    {
        MostrarTipo(tipos[i]);
    }
}
void MostrarTipo(eTipo tipo)
{
    printf("%d\t %s\n",tipo.id,tipo.descripcion);
}
