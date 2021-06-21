#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "inputs.h"

int menu()
{
    int opcion;
    system("cls");
    printf("Sistema de gestion de empleados\n");
    printf("\n\n");
    printf("1-Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2-Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
    printf("3-Alta de empleado\n");
    printf("4-Modificar datos de empleado\n");
    printf("5-Baja de empleado\n");
    printf("6-Listar empleados\n");
    printf("7-Ordenar empleados\n");
    printf("8-Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9-Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
    printf("10-Salir\n");
    utn_getNumero(&opcion, "Elija una opcion: ", "Error!!! --> Ingrese un numero valido\n", 1, 10, 10);
    return opcion;
}


int editUI()
{
    int opcion;
    system("cls");
    printf("Edicion de empleado\n");
    printf("\n\n");
    printf("1-Editar el nombre\n");
    printf("2-Editar las horas trabajadas\n");
    printf("3-Editar el salario\n");
    utn_getNumero(&opcion, "Ingrese la opcion: ", "Error!!! --> Reingrese una opcion valida: ", 1, 3, 100);
    return opcion;
}

int sortUI()
{
    int opcion;
    system("cls");
    printf("Ordenamiento de empleados\n");
    printf("\n\n");
    printf("1-Por id ascendente\n");
    printf("2-Por salario ascendente\n");
    printf("3-Por nombre ascendente\n");
    printf("4-Por horas trabajadas ascendente\n");
    printf("5-Cancelar\n");
    utn_getNumero(&opcion, "Ingrese la opcion: ", "Error!!! --> Reingrese una opcion valida: ", 1, 4, 10);
    return opcion;
}
