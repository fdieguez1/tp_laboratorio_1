#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int idEmployee = 1;
    int cantidadEmpleados = 0;
    char salir = 'n';
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados == NULL)
    {
        printf("No se pudo crear el linkedlist");
        exit(1);
    }
    while (salir == 'n')
    {
        cantidadEmpleados = ll_len(listaEmpleados);
        switch(menu())
        {
        case 1:
            if(controller_loadFromText("data.csv",listaEmpleados))
            {
                getBiggestId(listaEmpleados, &idEmployee);
                printf("\nCarga de empleados exitosa\n");
            }
            else
            {
                printf("Error!!! --> Problemas en la carga del archivo .csv\n");
            }
            break;
        case 2:
            if(controller_loadFromBinary("data.bin", listaEmpleados))
            {
                getBiggestId(listaEmpleados, &idEmployee);
                printf("\nCarga de empleados exitosa\n");
            }
            else
            {
                printf("Error!!! --> Problemas en la carga del archivo .bin\n");
            }
            break;
        case 3:
            if(controller_addEmployee(listaEmpleados, &idEmployee))
            {

                printf("\n--> Alta exitosa\n");

            }
            else
            {
                printf("Error!!! --> Problemas en la alta de empleado\n");
            }
            break;
        case 4:
            if(controller_editEmployee(listaEmpleados) == 1)
            {
                printf("\n--> Modificacion exitosa\n");
            }
            else if(controller_editEmployee(listaEmpleados) == -1)
            {
                printf("Error!!! --> No hay empleados cargados\n");
            }
            else
            {
                printf("\nOperacion finalizada\n");
            }
            break;
        case 5:
            if(controller_removeEmployee(listaEmpleados)==1)
            {
                printf("\n--> Baja exitosa\n");
            }
            else if(controller_removeEmployee(listaEmpleados)== -1)
            {
                printf("Error!!! --> No hay empleados cargados\n");
            }
            else
            {
                printf("\nOperacion finalizada\n");
            }
            break;
        case 6:
            if(cantidadEmpleados == 0)
            {
                printf("Error!!! --> No hay empleados cargados\n");
            }
            else
            {
                controller_ListEmployee(listaEmpleados);
            }
            break;
        case 7:
            if(cantidadEmpleados != 0)
            {
                    controller_sortEmployee(listaEmpleados);

            }
            else
            {
                printf("Error!!! --> No hay empleados cargados\n");
            }
            break;
        case 8:
            if(!controller_saveAsText(listaEmpleados))
            {
                printf("Error!!! --> No se logro guardar los empleados\n");
            }
            else
            {
                printf("\n--> Operacion terminada\n");
            }
            break;
        case 9:
            if(!controller_saveAsBinary(listaEmpleados))
            {
                printf("Error!!! --> No se logro guardar los empleados\n");
            }
            else
            {
                printf("\n--> Operacion terminada\n");
            }
            break;
        case 10:
            askForChar(&salir,"\nDesea continuar? --> s/n","Error ingrese un caracter", 10 );
            break;
        default:
            printf("Error!!! --> Opcion incorrecta, reintente\n");
            break;
        }
        system("pause");
    }
    return 0;
}



