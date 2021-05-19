#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED


typedef struct
{
    int id;//comienza en 1000
    char descripcion[20];
}eTipo;

int CargarDescripcionTipo(int id, eTipo tipos[],int tam, char desc[]);
void MostrarTipos(eTipo tipos[],int tam);
void MostrarTipo(eTipo tipo);

#endif // TIPO_H_INCLUDED
