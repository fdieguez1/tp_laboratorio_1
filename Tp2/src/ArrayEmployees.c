/*
 * ArrayEmployees.c
 *
 */
#include "ArrayEmployees.h"
#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "inputs.h"
#define MAX_STRING_LENGTH 51
#define CLEAR_SIZE 2



int initEmployees(Employee* list, int len)
{
	int ret = -1;
	if (list != NULL && len > 0){
		ret = 0;
		for (int i = 0; i < len; i++){
			list[i].isEmpty = 1;

		}
	}
	return ret;
}


int addEmployee(Employee* list, int len, int id, char name[],char
		lastName[],float salary,int sector){
	int ret = -1;
	int place = findPlaceInEmployeeArray(list, len);
	if (place != -1){

		list[place].id = id;
		strcpy(list[place].name, name);
		strcpy(list[place].lastName, lastName);
		list[place].salary = salary;
		list[place].sector = sector;
		list[place].isEmpty = 0;
		ret = 1;
	}
	return ret;
}

int findEmployeeById(Employee* list, int len,int id){
	int ret = -1;
	if (list != NULL && len > 0 && id > 0){
		for(int i = 0; i < len; i++){
			if (list[i].id == id && !list[i].isEmpty){
				ret = i;
			}
		}
	}
	return ret;
}

int removeEmployeeById(Employee* list, int len,int id){
	int ret = -1;
	if (list != NULL && len > 0 && id > 0){
		int index = findEmployeeById(list, len, id);
		if (index >= 0){
			list[index].isEmpty = 1;
			ret = 1;
		}
	}
	return ret;
}

int swapEmploye(Employee *employeeA, Employee *employeeB)
{
	int ret = 0;
	if (employeeA != NULL && employeeB != NULL)
	{
		Employee aux;
		aux = *employeeA;
		*employeeA = *employeeB;
		*employeeB = aux;
		ret = 1;
	}
	return ret;
}

int sortEmployees(Employee* list, int len, int order){
	int ret = -1;

	if (list != NULL && len > 0 && order >= 0 && order<= 1)
	{
		for(int i = 0; i < len-1; i++)
		{
			for(int j = i+1; j < len ; j++)
			{
				if (list[i].isEmpty || list[j].isEmpty){
					continue;
				}
				char lastnameA[MAX_STRING_LENGTH];
				strcpy(lastnameA,list[i].lastName);
				stringToLower(lastnameA);
				char lastnameB[MAX_STRING_LENGTH];
				strcpy(lastnameB,list[j].lastName);
				stringToLower(lastnameB);
				if (order)
				{

					if (strcmp(lastnameA,lastnameB) < 0 || (strcmp(lastnameA,lastnameB) == 0 && list[i].sector < list[j].sector))
					{
						swapEmploye(&list[i],&list[j]);
					}
				}
				else
				{
					if (strcmp(lastnameA,lastnameB) > 0 || (strcmp(lastnameA,lastnameB) == 0 && list[i].sector > list[j].sector))
					{
						swapEmploye(&list[i],&list[j]);
					}
				}

			}
		}
		ret = 1;
	}
	return ret;
}

int printEmployees(Employee* list, int length){
	int ret = -1;
	int flagExistAny = 0;
	if (list != NULL && length > 0){
		for (int i = 0; i < length; i++){
			if (!list[i].isEmpty){
				flagExistAny = 1;
			}
		}
	}
	if (flagExistAny){
		ret = flagExistAny;
		printf("ID\t\t\tNOMBRE\t\t\tAPELLIDO\tSALARIO\t\tSECTOR\n");
		for (int i = 0; i < length; i++){
			if (!list[i].isEmpty){
				printf("%4d\t%23s\t%23s\t\t%6.2f\t%4d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
			}
		}
	}
	else {
		ret = 0;
	}
	return ret;
}
int printSalaries(Employee* list, int length){
	//2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
	int ret = -1;
	int flagExistAny = 0;
	if (list != NULL && length > 0){
		for (int i = 0; i < length; i++){
			if (!list[i].isEmpty){
				flagExistAny = 1;
			}
		}
	}
	if (flagExistAny){
		float acumuladorSalarios = 0;
		int cantidadSalarios = 0;
		float promedioSalarios = 0;
		int cantidadEmpleadosSobrePromedio = 0;

		ret = flagExistAny;
		for (int i = 0; i < length; i++){
			if (!list[i].isEmpty){
				acumuladorSalarios += list[i].salary;
				cantidadSalarios++;
			}
		}
		promedioSalarios = acumuladorSalarios / cantidadSalarios;
		for (int i = 0; i < length; i++){
			if (!list[i].isEmpty){
				if (list[i].salary > promedioSalarios){
					cantidadEmpleadosSobrePromedio++;
				}
			}
		}
		printf("Total de salarios: %6.2f\n", acumuladorSalarios);
		printf("Promedio de salarios: %6.2f\n", promedioSalarios);
		printf("Empleados sobre el promedio: %d\n", cantidadEmpleadosSobrePromedio);
	}
	else {
		ret = 0;
	}
	return ret;
}

int findPlaceInEmployeeArray(Employee employees[], int length )
{
	int ret = -1;
	if (employees != NULL && length > 0)
	{
		for(int i = 0; i < length; i++)
		{
			if (employees[i].isEmpty)
			{
				ret = i;
				break;
			}
		}
	}
	if (ret == -1){
		printf("Empleados esta lleno, no se puede agregar uno nuevo");
	}
	return ret;
}

int editEmployeeById(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	myClearForEclipse(CLEAR_SIZE);
	int ret = -1;
	int index = findEmployeeById(list, len, id);
	if (index >= 0){
		showEditMenu();

		int editOption;
		int nameOk;
		int lastnameOk;
		int salaryOk;
		int sectorOk;

		int optionOk = utn_getNumero(&editOption, "Ingrese una opcion: ", "Error, opcion invalida", 1,4,100);
		if (optionOk)
		{
			if (list != NULL && len > 0 && id > 0 )
			{
				switch(editOption)
				{
				case 1://Pido el nombre
					nameOk = askForString(name, "Ingrese un nombre: ", MAX_STRING_LENGTH);
					if (nameOk)
					{
						strcpy(list[index].name,name);
					}
					break;
				case 2:
					//Pido el apellido
					lastnameOk = askForString(lastName, "Ingrese un nombre: ", MAX_STRING_LENGTH);
					if (lastnameOk)
					{
						strcpy(list[index].lastName,lastName);
					}
					break;
				case 3://Pido el sueldo
					salaryOk = myGetFloat(&salary, "Ingrese un salario: ","Error, ingrese un salario valido",1,9999999,100);
					if (salaryOk)
					{
						list[index].salary = salary;
					}
					break;
				case 4://Pido el sector
					sectorOk = utn_getNumero(&sector, "Ingrese un sector: ","Error, ingrese un sector valido",1,10,100);
					if (sectorOk)
					{
						list[index].sector = sector;
					}
					break;
				}
				ret = 1;
			}
		}
	}
	return ret;
}

