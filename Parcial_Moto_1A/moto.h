#include "tipo.h"
#include "color.h"
#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int cilindrada;//Las cilindradas pueden ser: 50, 125, 500, 600, 750
    int isEmpty;
}eMoto;

void InicializarMotos(eMoto motos[], int tam);
void MostrarStructMoto(eMoto unaMoto, eTipo tipos[],int tamT,eColor colores[],int tamC);
void MostrarMotos(eMoto motos[],int tamM,eTipo tipos[], int tamT,eColor colores[],int tamC);
int BuscarLibre(eMoto motos[],int tam);
int BuscarMoto(eMoto motos[], int tam, int id);
void TolowerToupperMarca(char brand[],char* marcas);

int AltaMotos(eMoto motos[], int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC,int* pId);
int ModificarMotos(eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC);
int BajaMotos(eMoto motos[],int tamM, eTipo tipos[],int tamT,eColor colores[],int tamC);
int CargarMarcaMoto(int id, eMoto motos[],int tam, char marca[]);

#endif // MOTO_H_INCLUDED
