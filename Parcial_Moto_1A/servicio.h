#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;//(comienza en 20000)
    char descripcion[25];
    float precio;
}eServicio;

void MostrarServicios(eServicio servicios[],int tam);
void MostrarServicio(eServicio servicios);

int ValidarIdServicio(int id, eServicio servicios[],int tam);
int CargarDescripcionServicios(int id, eServicio servicios[],int tam, char desc[]);

#endif // SERVICIO_H_INCLUDED
