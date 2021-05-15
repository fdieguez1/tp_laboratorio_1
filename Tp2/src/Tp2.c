/*
 ============================================================================
 Name        : Tp2.c
 Author      : Dieguez Fernando
 Version     : 1.0
 Description : Trabajo practico Nº2 para TUP UTN Fra
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "ArrayEmployees.h"
#include "inputs.h"

#define CLEAR_SIZE 2
#define TOTAL_MAXIMO_EMPLEADOS 1000
#define MAX_STRING_LENGHT 51

int main(void) {
	setbuf(stdout, NULL);
	Employee empleados[TOTAL_MAXIMO_EMPLEADOS];
	int running = 1;
	int option = -1;
	int informOption = -1;
	int confirm = 0;
	int newId = 1;
	char name[MAX_STRING_LENGHT];
	char lastname[MAX_STRING_LENGHT];
	float salary = 0;
	int sector = 0;
	int existAny = 0;

	int nameOk = 0;
	int lastnameOk = 0;
	int salaryOk = 0;
	int sectorOk = 0;
	int addOk = 0;
	int optionOk = 0;
	int informOptionOk = 0;

	int idOk = 0;
	int id;

	initEmployees(empleados, TOTAL_MAXIMO_EMPLEADOS);

	while(running){
		showMenu();
		optionOk = utn_getNumero(&option, "Ingrese una opcion ", "ERROR ", 1,5, 20);
		if (optionOk){
			myClearForEclipse(CLEAR_SIZE);
			switch(option){
			case -1: //ERROR EN INTENTOS
				printf("ERROR Demasiados intentos, finalizando el programa");
				running = 0;
				break;
			case 1: //ALTA EMPLEADO
				nameOk = askForString(name, "Ingrese nombre ", MAX_STRING_LENGHT);
				lastnameOk = askForString(lastname, "Ingrese apellido ", MAX_STRING_LENGHT);
				salaryOk = myGetFloat(&salary, "Ingrese un salario ", "ERROR ", 0.00, 999999.00, 20);
				sectorOk = utn_getNumero(&sector, "Ingrese un sector ", "ERROR ", 1, 10, 20);
				if (sectorOk && salaryOk && lastnameOk && nameOk){
					addOk = addEmployee(empleados, TOTAL_MAXIMO_EMPLEADOS, newId, name, lastname,salary, sector);
				}
				else {
					printf("ERROR EN LA CARGA DE DATOS, REINTENTE ");
				}
				if (addOk)
				{
					printf("Carga correcta de empleado con id: %d \n", newId);
					newId++;
				}
				else
				{
					printf("ERROR Fallo la carga de empleado");
				}

				break;
			case 2://MODIFICACION EMPLEADO
				existAny = printEmployees(empleados, TOTAL_MAXIMO_EMPLEADOS);
				if (existAny){
					idOk = utn_getNumero(&id,"Ingrese el numero de empleado para la edicion", "Error al ingresar el numero", 0, TOTAL_MAXIMO_EMPLEADOS, 100);
					if (idOk)
					{
						int editOk = editEmployeeById(empleados,TOTAL_MAXIMO_EMPLEADOS,id, name, lastname, salary, sector);
						if (editOk != -1)
						{
							printf("Edicion exitosa, id: %d\n", id);
						}
						else
						{
							printf("ERROR Empleado no encontrado, revise el numero ingresado e intente nuevamente");
						}
					}
					else
					{
						printf("ERROR Demasiados intentos, abortando la operacion");
					}
				}
				else {
					printf("ERROR No hay empleados cargados");
				}
				break;
			case 3://BAJA EMPLEADO
				existAny = printEmployees(empleados, TOTAL_MAXIMO_EMPLEADOS);
				if (existAny){
					idOk = utn_getNumero(&id,"Ingrese el numero de empleado para la baja", "Error al ingresar el numero", 1, TOTAL_MAXIMO_EMPLEADOS, 100);
					if (idOk)
					{
						int deleteOk = removeEmployeeById(empleados, TOTAL_MAXIMO_EMPLEADOS, id);
						if (deleteOk != -1)
						{
							printf("Baja logica exitosa, id: %d\n", id);
						}
						else
						{
							printf("ERROR Empleado no encontrado, revise el numero ingresado e intente nuevamente");
						}

					}
					else
					{
						printf("ERROR Demasiados intentos, abortando la operacion");
					}
				}
				else{
					printf("ERROR No hay empleados cargados");
				}
				break;
			case 4://INFORMES
				informSubMenu();
				informOptionOk = utn_getNumero(&informOption, "Ingrese una opcion ", "ERROR ", 1, 2, 20);
				if (informOptionOk){
					if (informOption == 1){

						int sorted = sortEmployees(empleados, TOTAL_MAXIMO_EMPLEADOS, 0);
						if (sorted == -1){
							printf("ERROR No se pudo ordenar");
						}
						existAny = printEmployees(empleados, TOTAL_MAXIMO_EMPLEADOS);
						if (!existAny){

							printf("ERROR No hay empleados cargados");
						}
					}
					else {
						existAny = printSalaries(empleados, TOTAL_MAXIMO_EMPLEADOS);
						if (!existAny){
							printf("ERROR No hay empleados cargados");
						}
					}
				}
				else {
					printf("ERROR Demasiados intentos, abortando la operacion");
				}
				break;
			case 5://SALIR
				confirm = showAlert("Esta seguro que desea salir?");
				if (confirm)
				{
					running = 0;
					printf("Programa finalizado\n");
				}
				break;
			}
		}
		else {
			printf("ERROR al obtener la opcion");
		}
	}
	return EXIT_SUCCESS;
}
