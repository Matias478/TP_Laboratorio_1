#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

int CargarDescripcionColor(int id, eColor colores[],int tam, char desc[])
{
    int todoOk=0;

    if(id>=10000 && id <=10004 && colores!=NULL && tam>0 && desc!=NULL)
    {
        for(int i =0;i<tam;i++)
        {
            if(colores[i].id==id)
            {
                strcpy(desc,colores[i].nombreColor);
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}

void MostrarColores(eColor colores[],int tam)
{
    printf("*********lista de Colores**********\n");
    printf("id\t Descripcion\n");
    for(int i=0;i<tam;i++)
    {
        MostrarColor(colores[i]);
    }
}
void MostrarColor(eColor color)
{
    printf("%d\t %s\n",color.id,color.nombreColor);
}
