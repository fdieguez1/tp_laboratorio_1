#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmp = NULL;
    int cant;
    char buffer[4][128];
    int todoOk = 0;
    int id;
    char nombre[128];
    int sueldo;
    int horas;
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);//lectura fantasma del encabezado
    do
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        if(cant < 4)
        {
            break;
        }
        id = atoi(buffer[0]);
        strcpy( nombre, buffer[1]);
        horas = atoi(buffer[2]);
        sueldo = atoi(buffer[3]);
        auxEmp = newEmployeeParam(id, nombre, horas, sueldo);
        if(auxEmp != NULL)
        {
            ll_add(pArrayListEmployee, (Employee*)auxEmp);
            todoOk = 1;
        }
    }
    while(!feof(pFile));
    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee auxiliarEmp;
    Employee* auxiliar = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            if(fread((Employee*)&auxiliarEmp, sizeof(Employee), 1, pFile) == 1)
            {
                auxiliar = newEmployeeParam(auxiliarEmp.id, auxiliarEmp.nombre, auxiliarEmp.horasTrabajadas, auxiliarEmp.sueldo);
                if(auxiliar != NULL && ll_add(pArrayListEmployee, (Employee*)auxiliar) == 0)
                {
                    todoOk = 1;
                }
            }
        }
    }

    return todoOk;
}
