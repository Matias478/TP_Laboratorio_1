#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "moto.h"

void InicializarMotos(eMoto motos[], int tam)
{
    for(int i=0;i<tam;i++)
    {
        motos[i].isEmpty=1;
    }
}

void MostrarStructMoto(eMoto unaMoto, eTipo tipos[],int tamT,eColor colores[],int tamC)
{
    char descripcion[20];
    char nombreColor[20];

    if(CargarDescripcionTipo(unaMoto.idTipo,tipos,tamT,descripcion)&&CargarDescripcionColor(unaMoto.idColor,colores,tamC,nombreColor))
    {
        printf("%d\t%10s\t%10s \t%10s \t%5d\t \n"
           ,unaMoto.id
           ,unaMoto.marca
           ,descripcion
           ,nombreColor
           ,unaMoto.cilindrada);
    }
}

void MostrarMotos(eMoto motos[],int tamM,eTipo tipos[], int tamT,eColor colores[],int tamC)
{
    int flag = 1;
    printf("*****************Lista de empleados*******************\n");
    printf("ID \t Marca \t Tipo  \t\t Color \t\t Cilindrada\t \n");
    for(int i=0;i<tamM;i++)
    {
        if(!motos[i].isEmpty)
        {
            MostrarStructMoto(motos[i], tipos, tamT,colores,tamC);
            flag=0;
        }
    }
    if(flag==1)
    {
        printf("\tNo hay empleados que mostrar");
    }
    printf("\n\n");
}

int BuscarLibre(eMoto motos[],int tam)
{
    int index=-1;
    for(int i=0;i<tam;i++)
    {
        if(motos[i].isEmpty)
        {
            index=i;
            break;
        }
    }
    return index;
}

int BuscarMoto(eMoto motos[], int tam, int id)
{
    int index=-1;
    for(int i=0;i<tam;i++)
    {
        if(motos[i].id==id && !motos[i].isEmpty)
        {
            index=i;
            break;
        }
    }
    return index;
}

int AltaMotos(eMoto motos[], int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC,int* pId)
{
    eMoto auxMoto;
    int todoOk=0;
    int indice;
    int idTipo;
    int idColor;

    system("cls");
    printf("        Alta Moto       \n");
    printf("\nID:%d\n", *pId);

    if(motos!=NULL && tamM>0 && tipos!=NULL && tamT>0 && colores!=NULL && tamC>0 && pId!=NULL)
    {
        indice=BuscarLibre(motos,tamM);

        if(indice !=-1)
        {
            TolowerToupperMarca(auxMoto.marca,"Marca: ");

            printf("Ingrese la cilindrada(50, 125, 500, 600, 750): \n");
            scanf("%d", &auxMoto.cilindrada);
            if(auxMoto.cilindrada!=50 && auxMoto.cilindrada!=125 && auxMoto.cilindrada!=500 && auxMoto.cilindrada != 600 && auxMoto.cilindrada !=750)
            {
                printf("\nIngreso una cilindrada fuera de los limites.Reingrese la cilindrada(50, 125, 500, 600, 750): ");
                scanf("%d", &auxMoto.cilindrada);
            }

            MostrarTipos(tipos, tamT);
            printf("Ingrese el id del tipo:");
            scanf("%d", &idTipo);

            if(idTipo<1000 || idTipo>1004)
            {
                printf("El id no corresponde a ningun campo establecido. Reingrese el id: \n");
                scanf("%d", &idTipo);
            }else
            {
                auxMoto.idTipo=idTipo;
            }

            MostrarColores(colores, tamC);
            printf("Ingrese el id del Color:");
            scanf("%d", &idColor);

            if(idColor<10000 || idColor>10004)
            {
                printf("El id no corresponde a ningun campo establecido. Reingrese el id: \n");
                scanf("%d", &idColor);
            }else
            {
                auxMoto.idColor=idColor;
            }

            auxMoto.id=*pId;
            (*pId)++;//*pLegajo = *pLegajo+1;
            auxMoto.isEmpty=0;
            motos[indice]=auxMoto;
            todoOk=1;
        }else
        {
            printf("No hay lugar en el sistema\n");
        }
    }

    return todoOk;
}

int ModificarMotos(eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC)
{
    int todoOk=0;
    int auxId;
    int index;
    int opcion;
    int idColor;
    system("cls");
    printf("       Modificar Moto      \n");
    MostrarMotos(motos,tamM,tipos,tamT,colores,tamC);
    printf("Ingrese el ID de la moto: \n");
    scanf("%d", &auxId);

    index=BuscarMoto(motos,tamM,auxId);
     if(index==-1)
    {
        printf("No existe un empleado con ese ID. Reingrse ID:\n");
        scanf("%d",&auxId);
        index=BuscarMoto(motos,tamM,auxId);
    }
    if(index!=-1)
    {
         for(int i=0;i<tamM;i++)
        {
            if(motos[i].id==auxId && motos[i].isEmpty==0)
            {
                do{
                        system("cls");
                        MostrarStructMoto(motos[index],tipos,tamT,colores,tamC);
                        printf("\nIngrese la opcion modificar: \n");
                        printf("\n1. Modificar el Color\n");
                        printf("\n2. Modificar la Cilindrada\n");
                        printf("\n3. Salir de las modificaciones\n");
                        printf("\nOpcion a modificar: ");
                        scanf("%d", &opcion);

                        switch(opcion)
                        {
                            case 1:
                                MostrarColores(colores, tamC);
                                printf("Ingrese el nuevo Color:");
                                scanf("%d", &idColor);

                                if(idColor<10000 || idColor>10004)
                                {
                                    printf("El id no corresponde a ningun campo establecido. Reingrese el id: \n");
                                    scanf("%d", &idColor);
                                }else
                                {
                                    motos[i].idColor=idColor;
                                }
                                system("pause");
                                break;
                            case 2:
                                printf("Ingrese la nueva cilindrada(50, 125, 500, 600, 750): \n");
                                scanf("%d", &motos[i].cilindrada);
                                if(motos[i].cilindrada!=50 && motos[i].cilindrada!=125 && motos[i].cilindrada!=500 && motos[i].cilindrada != 600 && motos[i].cilindrada !=750)
                                {
                                    printf("\nIngreso una cilindrada fuera de los limites.Reingrese la cilindrada(50, 125, 500, 600, 750): ");
                                    scanf("%d", &motos[i].cilindrada);
                                }
                                system("pause");
                                break;
                            case 3:
                                printf("\nFin de las Modificaciones\n");
                                system("pause");
                                break;
                        }

                }while(opcion!=3);
                 todoOk=1;
            }
        }
    }
    return todoOk;
}

int BajaMotos(eMoto motos[],int tamM, eTipo tipos[],int tamT,eColor colores[],int tamC)
{
    int todoOk=0;
    int id;
    int index;
    char confirma;

    system("cls");
    printf("       Baja de Moto\n    ");
    MostrarMotos(motos,tamM,tipos,tamT,colores,tamC);
    printf("\nIngrese ID: ");
    scanf("%d", &id);

    index=BuscarMoto(motos,tamM,id);
    if(index==-1)
    {
        printf("El ID elegido no existe. Reingrese el ID: \n");
        scanf("%d", &id);
        index=BuscarMoto(motos,tamM,id);
   }
    if(index!=-1)
    {
        printf("La moto a dar de baja es: \n");
        MostrarStructMoto(motos[index],tipos,tamT,colores,tamC);
        printf("\nCofirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            motos[index].isEmpty=1;
            todoOk=1;
        }else
        {
            printf("Baja cancelada por el usuario\n");
        }
    }
    return todoOk;
}

int CargarMarcaMoto(int id, eMoto motos[],int tam, char marca[])
{
    int todoOk=0;
    int indice;

    if(motos!=NULL && tam>0 && marca!=NULL)
    {
        indice=BuscarMoto(motos,tam,id);
        if(indice!=-1)
        {
            strcpy(marca,motos[indice].marca);
            todoOk=1;
        }
    }
    return todoOk;
}



void TolowerToupperMarca(char brand[],char* marcas)
{
    char marca[51];//19
    char buffer[128];
    int len;
    printf("Ingrese su %s ",marcas);
    fflush(stdin);
    gets(buffer);
    while(isalpha(strlen(buffer)>51)==1)
    {
        printf("Reingrese su %s ",marcas);
        fflush(stdin);
        gets(buffer);
    }
    strcpy(marca,buffer);
    strlwr(marca);
    len = strlen(marca);
    marca[0]=toupper(marca[0]);
    for(int i=0; i<len; i++)
    {
        if(isspace(marca[i]))
        {
            marca[i+1]=toupper(marca[i+1]);
        }
    }
    strcpy(brand,marca);
}


