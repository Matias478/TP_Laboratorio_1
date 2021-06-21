#include "Employee.h"

Employee* employee_new()
{
    Employee* pEmpleado;

    pEmpleado = (Employee*)malloc(sizeof(Employee));
    if(pEmpleado!=NULL)
    {
        employee_setId(pEmpleado, 0);
        employee_setNombre(pEmpleado, " ");
        employee_setHorasTrabajadas(pEmpleado, 0);
        employee_setSueldo(pEmpleado, 0);
    }
    return pEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmpleado;
    pEmpleado = employee_new();

    if(pEmpleado!=NULL)
    {
        if(!(employee_setId(pEmpleado,atoi(idStr)) &&
             employee_setNombre(pEmpleado,nombreStr) &&
             employee_setHorasTrabajadas(pEmpleado,atoi(horasTrabajadasStr)) &&
             employee_setSueldo(pEmpleado,atof(sueldoStr))))
        {
            employee_delete(pEmpleado);
            pEmpleado=NULL;
        }
    }
    return pEmpleado;
}

int employee_setId(Employee* this,int id)
{
    int retorno = 0;
    if(this != NULL && id >0)
    {
        this->id= id;
        retorno = 1;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = 0;
    if(this != NULL && id !=NULL)
    {
        *id = this->id;
        retorno= 1;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = 0;
    if(this !=NULL && nombre !=NULL && strlen(nombre)<25 && strlen(nombre)>2)
    {
        strcpy(this->nombre ,nombre);
        retorno = 1;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 0;
    if(this !=NULL && nombre !=NULL)
    {
        strcpy(nombre, this->nombre);//(this->nombre ,nombre);
        retorno= 1;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 0;
    if(this != NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,float sueldo)
{
    int retorno = 0;
    if(this != NULL && sueldo > 0)
    {
        this->sueldo= sueldo;
        retorno = 1;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,float* sueldo)
{
    int retorno = 0;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }
    return retorno;
}

void employee_delete(Employee* this)
{
    free(this);
}

/** \brief
 *
 * \param this Employee*
 * \return int
 *
 */
int employee_listAnEmployee(Employee* this)
{
    int retorno=0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;

    if(this!=NULL && employee_getId(this, &id)
                  && employee_getNombre(this, nombre)
                  && employee_getHorasTrabajadas(this,&horasTrabajadas)
                  && employee_getSueldo(this, &sueldo))
    {
        printf(" %4d   %15s\t  %4d\t\t  %.2f\n",
               id,
               nombre,
               horasTrabajadas,
               sueldo);
        retorno=1;
    }

    return retorno;
}

int employee_FindById(LinkedList* pArrayListEmployee, int id)
{
    Employee* auxEmployee;
    int auxId;
    int index=-1;
    int len;

    if(pArrayListEmployee != NULL)
    {
        len=ll_len(pArrayListEmployee);

        for(int i=0; i<len; i++)
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee, i);
            //auxId=auxEmployee->id;
            employee_getId(auxEmployee, &auxId);
            if(id == auxId)
            {
                index=i;
                break;
            }
        }
    }
    return index;

}

int ModificarDatoPorId(Employee* miEmpleado)
{
    int opcion;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;
    do
    {
        printf("Que desea modificar?: ");
        printf("\n1.Nombre.\n2.Horas trabajadas.\n3.Sueldo.\n4.Salir\nIngrese opcion: ");
        scanf("%d", &opcion);
        while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4)
        {
            printf("Opcion incorrecta. Reingresela: ");
            printf("\n1.Nombre.\n2.Horas trabajadas.\n3.Sueldo.\n4.Salir\nIngrese opcion: ");
            scanf("%d", &opcion);
        }
        switch(opcion)
        {
        case 1:
            TolowerToupperName("nuevo nombre del empleado",auxNombre);
            employee_setNombre(miEmpleado,auxNombre);
            system("cls");
            break;
        case 2:
            printf("Ingrese nuevas horas trabajadas del empleado: ");
            scanf("%d",&auxHorasTrabajadas);
            employee_setHorasTrabajadas(miEmpleado,auxHorasTrabajadas);
            system("cls");
            break;
        case 3:
            printf("Ingrese nuevo sueldo del empleado: ");
            scanf("%d",&auxSueldo);
            employee_setSueldo(miEmpleado,auxSueldo);
            system("cls");
            break;
        }
    }
    while(opcion!=4);
    return opcion;
}

int employee_CompareById(void* e1, void* e2)
{
    int compare=0;
    Employee* emp1;
    Employee* emp2;
    int id1;
    int id2;
    if(e1!=NULL && e2!=NULL)
    {
        emp1=(Employee*)e1;
        emp2=(Employee*)e2;
        employee_getId(emp1,&id1);
        employee_getId(emp2,&id2);

        if(id1>id2)
        {

            compare=1;
        }
        else
        {
            if(id1<id2)
            {
                compare=-1;
            }
        }
    }
    return compare;
}

int employee_CompareByName(void* e1, void* e2)
{
    int retorno;
    Employee* emp1;
    Employee* emp2;
    char nombre1[128];
    char nombre2[128];
    if(e1!=NULL && e2!=NULL)
    {
        emp1=(Employee*)e1;
        emp2=(Employee*)e2;
        employee_getNombre(emp1,nombre1);
        employee_getNombre(emp2,nombre2);

        retorno = strcmp(emp1->nombre,emp2->nombre);
    }

    return retorno;
}

int employee_CompareByHT(void* e1, void* e2)
{
    int compare=0;
    Employee* emp1;
    Employee* emp2;
    int HT1;
    int HT2;
    if(e1!=NULL && e2!=NULL)
    {
        emp1=(Employee*)e1;
        emp2=(Employee*)e2;
        employee_getHorasTrabajadas(emp1,&HT1);
        employee_getHorasTrabajadas(emp2,&HT2);

        if(HT1>HT2)
        {

            compare=1;
        }
        else
        {
            if(HT1<HT2)
            {
                compare=-1;
            }
        }
    }
    return compare;
}

int employee_CompareBySueldo(void* e1, void* e2)
{
    int compare=0;
    Employee* emp1;
    Employee* emp2;
    float sueldo1;
    float sueldo2;
    if(e1!=NULL && e2!=NULL)
    {
        emp1=(Employee*)e1;
        emp2=(Employee*)e2;
        employee_getSueldo(emp1,&sueldo1);
        employee_getSueldo(emp2,&sueldo2);

        if(sueldo1>sueldo2)
        {

            compare=1;
        }
        else
        {
            if(sueldo1<sueldo2)
            {
                compare=-1;
            }
        }
    }
    return compare;
}

void criterioOrdenamiento(LinkedList* pArrayListEmployee)
{
    int opcion;
    if (pArrayListEmployee!=NULL)
    {
        do

        {
            system("cls");
            printf("        ***Seleccione el criterio de ordenamiento***     \n");
            printf("1. Por su id:\n");
            printf("2. Por su sueldo:\n");
            printf("3. Por sus horas trabajadas:\n");
            printf("4. Por sus nombres:\n");
            printf("5. Salir\n");
            scanf("%d",&opcion);
            //fflush(stdin);
            switch(opcion)
            {
                case 1:
                    printf("Ingrese la opcion si 1(ascendente) o 2(decendente)\n");
                    scanf("%d",&opcion);
                    if(opcion==1)
                    {
                        ll_sort(pArrayListEmployee,employee_CompareById,1);
                        controller_ListEmployee(pArrayListEmployee);
                    }
                    else
                    {
                        ll_sort(pArrayListEmployee,employee_CompareById,0);
                        controller_ListEmployee(pArrayListEmployee);
                    }
                    //fflush(stdin);
                    system("pause");
                    break;
                case 2:
                    printf("Ingrese la opcion si 1(ascendente) o 2(decendente)\n");
                    scanf("%d",&opcion);
                    if(opcion==1)
                    {
                        ll_sort(pArrayListEmployee,employee_CompareBySueldo,1);
                        controller_ListEmployee(pArrayListEmployee);
                    }
                    else
                    {
                        ll_sort(pArrayListEmployee,employee_CompareBySueldo,0);
                        controller_ListEmployee(pArrayListEmployee);
                    }
                    //fflush(stdin);
                    system("pause");
                break;
                case 3:
                    printf("Ingrese la opcion si 1(ascendente) o 2(decendente)\n");
                    scanf("%d",&opcion);
                    if(opcion==1)
                    {
                        ll_sort(pArrayListEmployee,employee_CompareByHT,1);
                        controller_ListEmployee(pArrayListEmployee);
                    }
                    else
                    {
                        ll_sort(pArrayListEmployee,employee_CompareByHT,0);
                        controller_ListEmployee(pArrayListEmployee);
                    }
                    //fflush(stdin);
                    system("pause");
                    break;
                case 4:
                    printf("Ingrese la opcion si 1(ascendente) o 2(decendente)\n");
                    scanf("%d",&opcion);
                    if(opcion==1)
                    {
                        ll_sort(pArrayListEmployee,employee_CompareByName,1);
                        controller_ListEmployee(pArrayListEmployee);
                    }
                    else
                    {
                        ll_sort(pArrayListEmployee,employee_CompareByName,0);
                        controller_ListEmployee(pArrayListEmployee);
                    }
                    //fflush(stdin);
                    system("pause");
                    break;
            }
        }while(opcion!=5);
    }
    //fflush(stdin);
}

/** \brief
 *
 * \param pArrayListEmployee LinkedList*
 * \param pId int*
 * \return int
 *
 */
int BuscarMayorId(LinkedList* pArrayListEmployee,int* pId)
{
    int todoOk=0;
    Employee* auxEmp=NULL;
    int mayor;
    if(pArrayListEmployee!=NULL)
    {
        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxEmp=(Employee*) ll_get(pArrayListEmployee,i);
            if(i==0 || auxEmp->id>mayor)
            {
                mayor=auxEmp->id;
            }
        }
        *pId=mayor+1;
        todoOk=1;
    }

    return todoOk;
}

/** \brief comando por parámetro la primera letra del nombre se convierte en mayúsculas y el resto en minúsculas
 *
 * \param name[] char
 * \param nombres char*
 * \return void
 *
 */
void TolowerToupperName(char name[],char* nombres)
{
    char nombre[128];
    int len;

    printf("ingrese su %s: ",name);
    fflush(stdin);
    scanf("%s",nombre);

    strcpy(nombres,nombre);
    strdup(nombres);
    len = strlen(nombres);
    nombres[0]=toupper(nombres[0]);
    for(int i=0; i<len; i++)
    {
        if(isspace(nombre[i]))
        {
            nombre[i+1]=toupper(nombre[i+1]);
        }
    }
    strcpy(nombres,nombre);
}


