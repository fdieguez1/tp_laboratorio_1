/*
 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
 1. Ingresar 1er operando (A=x)
 2. Ingresar 2do operando (B=y)
 3. Calcular todas las operaciones
 a) Calcular la suma (A+B)
 b) Calcular la resta (A-B)
 c) Calcular la division (A/B)
 d) Calcular la multiplicacion (A*B)
 e) Calcular el factorial (A!)
 4. Informar resultados
 a) “El resultado de A+B es: r”
 b) “El resultado de A-B es: r”
 c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 d) “El resultado de A*B es: r”
 e) “El factorial de A es: r1 y El factorial de B es: r2”
 5. Salir
 • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
 que contenga las funciones para realizar las cinco operaciones.
 • En el menú deberán aparecer los valores actuales cargados en los operandos A y B
 (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
 • Deberán contemplarse los casos de error (división por cero, etc)
 • Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>
#include "Utn_Biblioteca_Tp1.h"

int main(void) {
	setbuf(stdout, NULL);
	int flagPrimerOp = 0;
	int flagSegundoOp = 0;
	int flagCalculos = 0;
	int primerOperando = 0; //Inicializado para evitar warning de "may be used uninitialized"
	int segundoOperando = 0; //Inicializado para evitar warning de "may be used uninitialized"
	int resultadoSuma;
	int resultadoResta;
	float resultadoDivision;
	int resultadoMultiplicacion;
	long long int resultadoFactA;
	long long int resultadoFactB;

	int flagDivido;
	int flagFactA;
	int flagFactB;
	int retornoEjecucion = 0;

	while (retornoEjecucion <= 0) {
		mostrarMenu(primerOperando, segundoOperando, flagPrimerOp,
				flagSegundoOp);
		int opcion = tomarRespuesta();
		if (opcion != -1) {
			if (retornoEjecucion == 0) {
				retornoEjecucion = ejecutarOpcion(opcion, &primerOperando,
						&segundoOperando, &flagPrimerOp, &flagSegundoOp,
						&flagCalculos, &resultadoSuma, &resultadoResta,
						&resultadoDivision, &resultadoMultiplicacion,
						&resultadoFactA, &resultadoFactB, &flagDivido,
						&flagFactA, &flagFactB);
			} else {
				printf("\nNo se pudo procesar la opcion, intente nuevamente\n");
			}
			system("pause");
		} else {
			printf(
					"Error, ingrese un rango valido para las opciones, del 1 al 5\n");
		}
	}
	printf("Programa finalizado\n");

	return EXIT_SUCCESS;
}

