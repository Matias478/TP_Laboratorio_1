#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;//comienza en 10000
    char nombreColor[20];
}eColor;

int CargarDescripcionColor(int id, eColor colores[],int tam, char desc[]);
void MostrarColores(eColor colores[],int tam);
void MostrarColor(eColor color);

#endif // COLOR_H_INCLUDED
