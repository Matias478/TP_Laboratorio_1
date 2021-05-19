#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "moto.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idMoto;
    int idServicio;
    eFecha fechaTrabajo;
    int isEmpty;
}eTrabajo;

int BuscarLibreTrabajo(eTrabajo trabajos[],int tam);
int AltaTrabajo(eTrabajo trabajos[],int tamTr,eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC,eServicio servicios[],int tamS,int* pId);

void MostrarTrabajo(eTrabajo unTrabajo,eServicio servicios[],int tamS,eMoto motos[],int tamM);
void MostrarTrabajos(eTrabajo trabajos[],int tamTr,eServicio servicios[],int tamS,eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC);


#endif // TRABAJO_H_INCLUDED
