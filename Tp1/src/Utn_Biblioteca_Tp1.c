/*
 * Utn_Biblioteca_Tp1.c
 *
 *  Created on: 11 abr. 2021
 *      Author: ferna
 */
#include <stdio.h>
#include <stdlib.h>

void mostrarMenu(int primerOperando, int segundoOperando,
		int flagPrimerOperando, int flagSegundoOperando) {
	printf("***Calculadora***\n\n");
	printf("**Ingrese una opcion**\n\n");
	if (flagPrimerOperando) {
		printf("1. Ingresar 1er operando (A=%d)\n", primerOperando);
	} else {
		printf("1. Ingresar 1er operando (A=x)\n");
	}
	if (flagSegundoOperando) {
		printf("2. Ingresar 2do operando (B=%d)\n", segundoOperando);
	} else {
		printf("2. Ingresar 2do operando (B=y)\n");
	}
	printf("3. Calcular todas las operaciones\n");
	printf("\t a) Calcular la suma (A+B)\n");
	printf("\t b) Calcular la resta (A-B)\n");
	printf("\t c) Calcular la division (A/B)\n");
	printf("\t d) Calcular la multiplicacion (A*B)\n");
	printf("\t e) Calcular el factorial (A!)\n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n\n");
}

int tomarRespuesta() {
	int respuesta = -1;
	printf("Opcion: ");
	scanf("%d", &respuesta);
	if (respuesta < 1 || respuesta > 5) {
		respuesta = -1;
	}
	return respuesta;
}

int sumar(int numeroA, int numeroB) {
	return numeroA + numeroB;
}

int restar(int numeroA, int numeroB) {
	return numeroA - numeroB;
}

float dividir(int numeroA, int numeroB) {
	return (float) numeroA / numeroB;
}

int multiplicar(int numeroA, int numeroB) {
	return numeroA * numeroB;
}

long long int calcularFactorial(int numero) {
	int respuesta;
	if (numero == 1) {
		return 1;
	}
	respuesta = numero * calcularFactorial(numero - 1);
	return (respuesta);
}

int resetBanderasCalculos(int *flagDividio, int *flagFactorizoA,
		int *flagFactorizoB, int *flagCalculos) {
	int retorno = 0;
	if (flagCalculos != NULL && flagDividio != NULL && flagFactorizoA != NULL
			&& flagFactorizoB != NULL) {
		retorno = 1;
		*flagCalculos = 0;
		*flagDividio = 0;
		*flagFactorizoA = 0;
		*flagFactorizoB = 0;
	}
	return retorno;

}

int calcularTodo(int primerOperando, int segundoOperando, int *resultadoSuma,
		int *resultadoResta, float *resultadoDivision,
		int *resultadoMultiplicacion, long long int *resultadoFactA,
		long long int *resultadoFactB, int *flagDividio, int *flagFactorizoA,
		int *flagFactorizoB) {
	int retorno = 0;
	if (resultadoSuma != NULL && resultadoResta != NULL
			&& resultadoDivision != NULL && resultadoMultiplicacion != NULL
			&& resultadoFactA != NULL && resultadoFactB != NULL
			&& flagDividio != NULL && flagFactorizoA != NULL
			&& flagFactorizoB != NULL) {
		retorno = 1;
		*resultadoSuma = sumar(primerOperando, segundoOperando);
		*resultadoResta = restar(primerOperando, segundoOperando);
		*resultadoMultiplicacion = multiplicar(primerOperando, segundoOperando);
		//Factoriales solo si es positivo y mayor a 0
		if (primerOperando < 13 && primerOperando > 0) { //el factorial mayor a 12 me desborda la variable long long int
			*resultadoFactA = calcularFactorial(primerOperando);
			*flagFactorizoA = 1;
		} else {
			*flagFactorizoA = 0;
		}
		if (segundoOperando < 13 && segundoOperando > 0) { //el factorial mayor a 12 me desborda la variable long long int
			*resultadoFactB = calcularFactorial(segundoOperando);
			*flagFactorizoB = 1;
		} else {
			*flagFactorizoB = 0;
		}
		//Division solo si el segundo operando es distinto a 0
		if (segundoOperando != 0) {
			*resultadoDivision = dividir(primerOperando, segundoOperando);
			*flagDividio = 1;
		}
	}

	return retorno;
}

void mostrarResultados(int resultadoSuma, int resultadoResta,
		float resultadoDivision, int resultadoMultiplicacion,
		long long int resultadoFactA, long long int resultadoFactB,
		int flagDividio, int flagFactorizoA, int flagFactorizoB) {

	printf("**Resultados**\n\n");
	printf("a) El resultado de A+B es: %d \n", resultadoSuma);
	printf("b) El resultado de A-B es: %d \n", resultadoResta);
	if (flagDividio) {
		printf("c) El resultado de A/B es: %.2f \n", resultadoDivision);
	} else {
		printf("c) No es posible dividir por cero\n");
	}
	printf("d) El resultado de A*B es: %d \n", resultadoMultiplicacion);
	if (flagFactorizoA) {
		printf("e) El factorial de A es: %I64d \n", resultadoFactA);
	} else {
		printf("e) No se pudo calcular el factorial de A\n");
	}
	if (flagFactorizoB) {
		printf("e) El factorial de B es: %I64d \n", resultadoFactB);
	} else {
		printf("e) No se pudo calcular el factorial de B\n");
	}

	system("pause");

}

int ejecutarOpcion(int opcion, int *primerOperando, int *segundoOperando,
		int *flagPrimerOp, int *flagSegundoOp, int *flagCalculos,
		int *resultadoSuma, int *resultadoResta, float *resultadoDivision,
		int *resultadoMultiplicacion, long long int *resultadoFactA,
		long long int *resultadoFactB, int *flagDividio, int *flagFactorizoA,
		int *flagFactorizoB) {
	int retorno = -1;
	if (opcion > 0 && opcion < 6 && primerOperando != NULL && segundoOperando != NULL
			&& flagPrimerOp != NULL && flagSegundoOp != NULL && flagCalculos != NULL && resultadoSuma != NULL && resultadoResta != NULL
			&& resultadoDivision != NULL && resultadoMultiplicacion != NULL
			&& resultadoFactA != NULL && resultadoFactB != NULL) {
		switch (opcion) {
		case 1: /*Estamento vacio para ignorar el error "a label can only be part of a statement and a declaration is not a statement"*/
			;
			//1. Ingresar 1er operando (A=x)
			int primerIngreso;
			printf("Ingrese el primer operando: ");
			if (scanf("%d", &primerIngreso)) {
				*primerOperando = primerIngreso;
				retorno = 0;
				*flagPrimerOp = 1;
				resetBanderasCalculos(flagDividio, flagFactorizoA, flagFactorizoB, flagCalculos);
			} else {
				printf("Error al cargar el primer operando\n");
			}
			break;
		case 2: /*Estamento vacio para ignorar el error mencionado previamente*/
			;
			//2. Ingresar 2do operando (B=y)
			int segundoIngreso;
			printf("Ingrese el segundo operando: ");
			if (scanf("%d", &segundoIngreso)) {
				*segundoOperando = segundoIngreso;
				retorno = 0;
				*flagSegundoOp = 1;
				resetBanderasCalculos(flagDividio, flagFactorizoA, flagFactorizoB, flagCalculos);
			} else {
				printf("Error al cargar el segundo operando\n");
			}
			break;
		case 3:
			//3. Calcular todas las operaciones
			if (*flagPrimerOp && *flagSegundoOp) {
				int calculoOk = calcularTodo(*primerOperando, *segundoOperando,
						resultadoSuma, resultadoResta, resultadoDivision,
						resultadoMultiplicacion, resultadoFactA, resultadoFactB,
						flagDividio, flagFactorizoA, flagFactorizoB);
				if (calculoOk) {
					printf("Calculos OK \n\n");
					retorno = 0;
					*flagCalculos = 1;
				} else {
					printf("Error en calculos \n\n");
					retorno = -1;
				}
			} else {
				printf(
						"Error: Debe cargar ambos operandos antes de realizar los calculos\n");
			}
			break;
		case 4:
			//4. Informar resultados
			if (*flagCalculos == 1) {
				mostrarResultados(*resultadoSuma, *resultadoResta,
						*resultadoDivision, *resultadoMultiplicacion,
						*resultadoFactA, *resultadoFactB, *flagDividio,
						*flagFactorizoA, *flagFactorizoB);
				retorno = 0;
			} else {
				printf(
						"Error: Debe calcular los resultados antes de mostrar los mismos\n");
			}
			break;

		case 5:
			//Salir
			printf("Realmente desea salir? s/n\n");
			char salir = 'n';
			fflush(stdin);
			scanf("%c", &salir);
			if (salir == 's') {
				retorno = 1;
			} else {
				retorno = 0;
			}
			break;
		}

	} else {
		retorno = -1;
	}
	return retorno;
}

