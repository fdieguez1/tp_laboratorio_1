/*
 * iu.c
 *
 */
#include <stdio.h>
#define CLEAR_SIZE 2

void myClearForEclipse(int size){
	for (int i = 0; i < size; i++){
		printf("\n");
	}
}

void showMenu()
{
	//system("cls");
	myClearForEclipse(CLEAR_SIZE);
    printf("\n--- Gestion ---\n\n");
    printf("1-ALTAS\n");
    printf("2-MODIFICAR\n");
    printf("3-BAJA\n");
    printf("4-INFORMAR\n");
    printf("5-SALIR\n");
}
void showEditMenu(){
	printf("1-MODIFICAR NOMBRE\n");
	printf("2-MODIFICAR APELLIDO\n");
	printf("3-MODIFICAR SALARIO\n");
	printf("4-MODIFICAR SECTOR\n");
}

void informSubMenu(){
	myClearForEclipse(CLEAR_SIZE);
    printf("1-Listado de empleados por apellido y sector\n");
    printf("2-Total y promedio de salarios, empleados con salario sobre el promedio\n");
}

int showAlert(char alertMsg[])
{
    int ret = 0;
    char input;
    printf("\n\nAVISO\n%s\n", alertMsg);
    printf("Si: S \t No: N \n\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%c", &input);
    if (input == 's' || input == 'S')
    {
        ret = 1;
    }
    return ret;
}
