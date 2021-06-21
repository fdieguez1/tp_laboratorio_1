#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "ui.h"
#include "inputs.h"
#include "parser.h"

int findEmployee(LinkedList* pArrayListEmployee, int id)
{
    int indice = -1;
    Employee* auxEmp;
    if(pArrayListEmployee != NULL)
    {
        if(ll_len(pArrayListEmployee) > 0)
        {
            for(int i=0; i< ll_len(pArrayListEmployee); i++)
            {
                auxEmp =  (Employee*)ll_get(pArrayListEmployee, i);
                if(auxEmp != NULL && auxEmp->id == id)
                {
                    indice = i;
                    break;
                }
            }
        }
    }
    return indice;
}

int getNextId(LinkedList* pArrayListEmployee)
{
    int maxVal = -1;
    int tam = 0;
    int i;
    int cant = 0;
    Employee* employeeAux;
    if(pArrayListEmployee != NULL)
    {
        tam = ll_len(pArrayListEmployee);

        if(tam > 0)
        {
            for(i = 0; i < tam; i++)
            {
                employeeAux = (Employee*)ll_get(pArrayListEmployee, i);

                if(employeeAux != NULL)
                {
                    if(cant == 0)
                    {
                        maxVal= employeeAux->id;
                    }
                    else
                    {
                        if(employeeAux->id > maxVal
                                && employeeAux->id < 1000)
                        {
                            maxVal= employeeAux->id;
                        }
                    }

                    cant++;
                }
            }
        }
        if(cant > 0)
        {
            maxVal++;
        }
        else
        {
            maxVal= 1;
        }
    }

    return maxVal;
}

int findPlace(LinkedList* pArrayListEmployee, int* pIndice)
{
    int todoOk = 0;
    *pIndice = -1;
    Employee* employeeAux = NULL;
    if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0 && pIndice != NULL)
    {
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            employeeAux = (Employee*)ll_get(pArrayListEmployee, i);
            if(employeeAux == NULL)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
int getBiggestId(LinkedList* pArrayListEmployee, int* id)
{
    int todoOk = 0;
    Employee* auxEmp = NULL;
    int mayorId;
    if(pArrayListEmployee != NULL)
    {
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmp = (Employee*)ll_get(pArrayListEmployee, i);
            if(i==0 || auxEmp->id > mayorId)
            {
                mayorId = auxEmp->id;
            }
        }
        *id = mayorId + 1;
        todoOk =1;
    }
    return todoOk;
}

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* f = NULL;
    if(pArrayListEmployee != NULL && path != NULL)
    {
        f = fopen(path, "r");
        if(f != NULL)
        {
            parser_EmployeeFromText(f, pArrayListEmployee);
            todoOk = 1;
        }
        else
        {
            printf("Error al abrir el archivo\n");
        }
    }
    fclose(f);
    return todoOk;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* f = NULL;
    if(pArrayListEmployee != NULL)
    {
        f = fopen(path, "rb");
        if(f != NULL)
        {
            parser_EmployeeFromBinary(f, pArrayListEmployee);
            todoOk = 1;
        }
        else
        {
            printf("No se pudo abrir el archivo\n");
        }
    }
    return todoOk;
}

int controller_addEmployee(LinkedList* pArrayListEmployee, int* pId)
{
    int todoOk = 0;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    Employee* nuevoEmpleado = NULL;
    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("Alta de empleado\n\n");
        if(*pId == -1)
        {
            printf("\nNo se encontro lugar en el sistema\n");
        }
        else
        {
            printf("Ingrese Nombre: ");
            getString(nombre);
            utn_getNumero(&horasTrabajadas, "Ingrese las horas trabajadas: ", "Error!!! --> Ingrese un numero valido", 0, 9999999, 100);
            utn_getNumero(&sueldo, "Ingrese el sueldo: ", "Error!!! --> Ingrese un numero valido", 0, 9999999, 100);

            nuevoEmpleado = newEmployeeParam(*pId, nombre, horasTrabajadas, sueldo);

            if(nuevoEmpleado != NULL)
            {
                ll_add(pArrayListEmployee, (Employee*)nuevoEmpleado);
                (*pId)++;
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmp = employee_new();
    Employee* auxNuevoEmpParam;
    int todoOk = 0;
    int indice;
    int id;
    system("cls");
    if(ll_len(pArrayListEmployee)== 0)
    {
        todoOk = -1;
    }
    else
    {
        system("cls");
        printf("Modificar empleado\n\n");
        controller_ListEmployee(pArrayListEmployee);
        utn_getNumero(&id, "Ingrese un Id:", "Error!!! --> Ingrese un numero correcto", 0,999999,100);
        if(pArrayListEmployee != NULL)
        {
            indice = findEmployee(pArrayListEmployee, id);
            if(indice == -1)
            {
                printf("Error!!! --> No se encontro el empleado ingresado");
            }
            else
            {
                printf("\n\nId                  Nombre Horas    Sueldo\n");
                mostrarEmpleado((Employee*) ll_get(pArrayListEmployee, indice));
                auxEmp = (Employee*) ll_get(pArrayListEmployee, indice);
                if(auxEmp != NULL)
                {
                    auxNuevoEmpParam = newEmployeeParam(auxEmp->id, auxEmp->nombre,auxEmp->horasTrabajadas, auxEmp->sueldo);

                    switch(editUI())
                    {
                    case 1:
                        printf("Ingrese Nombre: ");
                        getString(auxNuevoEmpParam->nombre);
                        employee_setNombre(auxNuevoEmpParam, auxNuevoEmpParam->nombre);
                        ll_set(pArrayListEmployee, indice, (Employee*)auxNuevoEmpParam);
                        printf("\n\nId                  Nombre Horas    Sueldo\n");
                        mostrarEmpleado((Employee*) ll_get(pArrayListEmployee, indice));
                        todoOk = 1;
                        break;
                    case 2:
                        utn_getNumero(&auxNuevoEmpParam->horasTrabajadas, "\nIngrese las horas trabajadas: ","Error ingrese un numero valido", 0, 100000, 10);
                        employee_setHorasTrabajadas(auxNuevoEmpParam, auxNuevoEmpParam->horasTrabajadas);
                        ll_set(pArrayListEmployee, indice, (Employee*)auxNuevoEmpParam);
                        printf("\n\nId                  Nombre Horas    Sueldo\n");
                        mostrarEmpleado((Employee*) ll_get(pArrayListEmployee, indice));
                        todoOk = 1;
                        break;
                    case 3:
                        utn_getNumero(&auxNuevoEmpParam->sueldo, "\nIngrese el sueldo: ", "Error ingrese un numero valido", 0, 2000000, 10);
                        employee_setSueldo(auxNuevoEmpParam, auxNuevoEmpParam->sueldo);
                        ll_set(pArrayListEmployee, indice, (Employee*)auxNuevoEmpParam);
                        printf("\n\nId                  Nombre Horas    Sueldo\n");
                        mostrarEmpleado((Employee*) ll_get(pArrayListEmployee, indice));
                        todoOk = 1;
                        break;
                    }
                }
            }

        }
    }
    return todoOk;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int indice;
    int id;
    char confirma;
    Employee* auxEmp = employee_new();
    system("cls");
    if(ll_len(pArrayListEmployee)== 0)
    {
        todoOk = -1;
    }
    else
    {
        printf("Baja empleados\n\n");
        controller_ListEmployee(pArrayListEmployee);
        utn_getNumero(&id, "Ingrese Id: ", "Error --> Ingrese un id valido", 1, 99999999,100);
        indice = findEmployee(pArrayListEmployee, id);
        if(indice == -1)
        {
            printf("\tNo existe un empleado con el legajo %d\n\n", id);
        }
        else
        {
            auxEmp =  (Employee*)ll_get(pArrayListEmployee, indice);
            if(auxEmp != NULL)
            {
                printf("\n\nId                  Nombre Horas    Sueldo\n");
                mostrarEmpleado(auxEmp);
                askForChar(&confirma, "Confirma baja? s/n :", "Error --> Ingrese una opcion valida", 100);
                if(confirma == 'S' || confirma == 's')
                {
                    if(ll_remove(pArrayListEmployee, indice) == 0)
                    {
                        todoOk = 1;
                        employee_delete(auxEmp);
                        auxEmp = NULL;
                    }
                }
                else
                {
                    printf("\nBaja cancelada por el usuario\n");
                }
            }
        }
    }
    return todoOk;
}
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* auxEmp = NULL;
    if(pArrayListEmployee != NULL)
    {
        printf("\n\nId                  Nombre Horas    Sueldo\n");
        for(int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmp = (Employee*)ll_get(pArrayListEmployee, i);
            mostrarEmpleado(auxEmp);
            todoOk = 1;
        }
    }
    return todoOk;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char salir = 's';

    do
    {
        switch(sortUI())
        {
        case 1:
            printf("Iniciando ordenamiento");
            ll_sort(pArrayListEmployee, employee_cmpId, 0);
            controller_ListEmployee(pArrayListEmployee);
            break;
        case 2:
            printf("Iniciando ordenamiento");
            ll_sort(pArrayListEmployee, employee_cmpSalary, 0);
            controller_ListEmployee(pArrayListEmployee);
            break;
        case 3:
            printf("Iniciando ordenamiento");
            ll_sort(pArrayListEmployee, employee_cmpName, 0);
            controller_ListEmployee(pArrayListEmployee);
            break;
        case 4:
            printf("Iniciando ordenamiento");
            ll_sort(pArrayListEmployee, employee_cmpHours, 0);
            controller_ListEmployee(pArrayListEmployee);
            break;
        case 5:
            askForChar(&salir, "Realmente desea salir? s/n: ", "Error!!! --> Ingrese una opcion valida", 10);
            break;
        default:
            printf("Error!!! --> ingrese una opcion valida.");
            break;
        }
    }
    while(salir == 'n');
    return todoOk;
}

int controller_saveAsText(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char confirma = 's';
    char path[128];
    int cant;
    int flagError = 0;
    Employee* auxEmp = employee_new();
    FILE* f = NULL;
    printf("\nPath por defecto 'data.csv'\n");
    askForString(path,"Ingrese un path para el archivo de texto: ", 128);
    f = fopen(path, "r");
    if(f != NULL)
    {
        askForChar(&confirma, "ATENCION!!! --> El archivo existe y se va a sobrescribir. Confirma? s/n: ", "Error!!! --> Ingrese un caracter valido", 10);
    }
    fclose(f);
    if(confirma == 's')
    {
        f = fopen(path, "w");
        if(f == NULL)
        {
            printf("Error!!! --> No se pudo abrir el archivo\n");
        }
        else
        {
            fprintf(f, "id,nombre,sexo,sueldo\n");

            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmp = (Employee*)ll_get(pArrayListEmployee, i);
                if(auxEmp != NULL)
                {
                    cant = fprintf(f, "%d,%s,%d,%d\n", auxEmp->id,auxEmp->nombre,auxEmp->horasTrabajadas,auxEmp->sueldo);//ree
                    if(cant < 4)
                    {
                        flagError = 1;
                        break;
                    }
                }
            }

        }
        fclose(f);
    }
    if(flagError)
    {
        printf("Error!!! --> Ocurrio un problema al guardar los empleados en el archivo\n");
    }
    else
    {
        todoOk = 1;
    }
    return todoOk;
}

int controller_saveAsBinary(LinkedList* pArrayListEmployee)
{
    int todoOk= 0;
    int cant;
    char path[128];
    Employee * auxEmp = NULL;
    int flag = 0;
    FILE* f = NULL;
    char confirma = 's';
    printf("\nPath por defecto 'data.bin'\n");
    askForString(path,"Ingrese un path para el archivo binario: ", 128);
    f = fopen(path, "rb");
    if(f != NULL)
    {
        askForChar(&confirma, "ATENCION!!! --> el archivo existe y se va a sobrescribir. Confirma? s/n: ", "Error!!! -> Ingrese un caracter valido", 10);
        todoOk = -1;
    }
    fclose(f);
    if(confirma == 's')
    {
        f = fopen(path,"wb");
        if(f == NULL)
        {
            printf("Error!!! --> No se pudo abrir el archivo\n");
        }
        else
        {
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmp = (Employee*)ll_get(pArrayListEmployee, i);
                if( auxEmp != NULL)
                {
                    cant = fwrite(auxEmp, sizeof(Employee), 1, f);
                    if(cant < 1)
                    {
                        flag = 1;
                    }
                }
            }

        }
        fclose(f);
    }

    if(flag)
    {
        printf("Error!!! --> Ocurrio un problema al guardar los empleados en el archivo\n");
    }
    else
    {
        todoOk= 1;
    }

    return todoOk;
}


