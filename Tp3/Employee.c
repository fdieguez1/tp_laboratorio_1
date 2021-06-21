#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevoEmpleado = employee_new();
    if(nuevoEmpleado != NULL)
    {
        if(!(employee_setId(nuevoEmpleado, atoi(idStr))
                && employee_setNombre(nuevoEmpleado, nombreStr)
                && employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr))
                && employee_setSueldo(nuevoEmpleado, atoi(sueldoStr))))
        {
            employee_delete(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }
    return nuevoEmpleado;
}

Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*)malloc(sizeof(Employee));
    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, " ");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }
    return nuevoEmpleado;
}


Employee* newEmployeeParam(int id, char* nombre, int horas, int sueldo)
{
    Employee* nuevoEmpleado = employee_new();
    if(nuevoEmpleado != NULL)
    {
        if(!(employee_setId(nuevoEmpleado, id)
                && employee_setNombre(nuevoEmpleado, nombre)
                && employee_setHorasTrabajadas(nuevoEmpleado, horas)
                && employee_setSueldo(nuevoEmpleado, sueldo)))
        {
            employee_delete(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }
    return nuevoEmpleado;
}


int mostrarEmpleado(Employee* this)
{
    int todoOk = 0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    if(this != NULL && employee_getId(this, &id)
            && employee_getNombre(this, nombre) && employee_getHorasTrabajadas(this, &horasTrabajadas)
            && employee_getSueldo(this, &sueldo))
    {
        printf("%5d %20s %5d %10d\n", id, nombre, horasTrabajadas, sueldo);
        todoOk = 1;
    }
    return todoOk;
}


int employee_setId(Employee* this, int id)
{
    int todoOk=0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}


int employee_getId(Employee* this,int* id)
{
    int todoOk=0;
    if(this != NULL && id != NULL)
    {
        (*id) = this->id;
        todoOk = 1;
    }
    return todoOk;
}
//getters
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk=0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;

}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk=0;
    if(this != NULL && horasTrabajadas != NULL)
    {
        (*horasTrabajadas) = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk=0;
    if(this != NULL && sueldo != NULL)
    {
        (*sueldo) = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}


//Setters
int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk=0;
    if(this != NULL && nombre != NULL && strlen(nombre) > 2 && strlen(nombre) < 129)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=0;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk=0;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}


int employee_delete(Employee* this)
{
    int todoOk=0;
    if(this != NULL)
    {
        free(this);
        todoOk = 1;
    }
    return todoOk;
}

int employee_cmpId(void* a, void* b)
{
    int ret= 0;
    Employee* aux = NULL;
    Employee* aux2 = NULL;
    if(a != NULL && b != NULL)
    {
        aux = (Employee*) a;
        aux2 = (Employee*)b;
        if(aux->id < aux2->id)
        {
            ret = 1;
        }
        else if(aux->id > aux2->id)
        {
            ret = -1;
        }
    }
    return ret;
}


int employee_cmpName(void* a, void* b)
{
    int ret= 0;
    Employee* aux = NULL;
    Employee* aux2 = NULL;
    if(a != NULL && b != NULL)
    {
        aux = (Employee*) a;
        aux2 = (Employee*)b;
        ret = strcmp(aux2->nombre, aux->nombre);
    }
    return ret;
}
int employee_cmpHours(void* a, void* b)
{
    int ret= 0;
    Employee* aux = NULL;
    Employee* aux2 = NULL;
    if(a != NULL && b != NULL)
    {
        aux = (Employee*) a;
        aux2 = (Employee*)b;
        if(aux->horasTrabajadas < aux2->horasTrabajadas)
        {
            ret = 1;
        }
        else if(aux->horasTrabajadas > aux2->horasTrabajadas)
        {
            ret = -1;
        }
    }
    return ret;
}

int employee_cmpSalary(void* a, void* b)
{
    int ret= 0;
    Employee* aux = NULL;
    Employee* aux2 = NULL;
    if(a != NULL && b != NULL)
    {
        aux = (Employee*) a;
        aux2 = (Employee*)b;
        if(aux->sueldo < aux2->sueldo)
        {
            ret = 1;
        }
        else if(aux->sueldo > aux2->sueldo)
        {
            ret = -1;
        }
    }
    return ret;
}

