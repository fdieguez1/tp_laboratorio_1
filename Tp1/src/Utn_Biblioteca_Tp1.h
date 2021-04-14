#ifndef UTN_BIBLIOTECA_H
#define UTN_BIBLIOTECA_H

/** \brief muestra un menu con opciones, si estan cargados operando los reemplaza en las opciones
 *
 * \param int primerOperando valor del primerOperando
 * \param int segundoOperando valor del segundoOperando
 * \param int flagA valor de la bandera del primerOperando
 * \param int flagB valor de la bandera del segundoOperando
 *
 */
void mostrarMenu(int primerOperando, int segundoOperando, int flagA, int flagB);

/** \brief devuelve la opcion ingresada por el usuario, verificando que este en rango
 *
 * \return int opcion ingresada -1: Error, 1-5 opciones
 *
 */
int tomarRespuesta();
/** \brief toma dos numeros enteros y los suma
 *
 * \param int primerEntero primer entero
 * \param int segundoEntero segundo entero
 * \return int devuelve el resultado de la suma
 *
 */
int sumar(int primerEntero, int segundoEntero);

/** \brief toma dos numeros enteros y resta el segundo al primero
 *
 * \param int primerEntero primer entero
 * \param int segundoEntero segundo entero
 * \return int devuelve el resultado de la resta
 *
 */
int restar(int primerEntero, int segundoEntero);

/** \brief toma dos numeros enteros y divide el primero por el segundo
 *
 * \param int primerEntero primer entero
 * \param int segundoEntero segundo entero
 * \return float devuelve el resultado de la division
 *
 */
float dividir(int numeroA, int numeroB);

/** \brief toma dos numeros enteros y multiplica el primero por el segundo
 *
 * \param int primerEntero primer entero
 * \param int segundoEntero segundo entero
 * \return int devuelve el resultado de la multiplicacion
 *
 */
int multiplicar(int numeroA, int numeroB);

/** \brief calcula y devuelve el factorial de un entero dado
 *
 * \param int a entero positivo
 *
 * \return int devuelve el resultado del calculo del factorial
 *
 */
long long int calcularFactorial(int a);

/** \brief ejecuta la opcion elegida por el usuario, guardando en las variables pasadas por memoria los resultados y asigna valores a las flags correspondientes
 *
 * \param int opcion elegida por el usuario
 * \param int primeroOperando: valor del primer operando
 * \param int segundoOperando: valor del segundo operando
 * \param int* flagPrimerOp: ubicacion en memoria de la variable flagPrimerOp
 * \param int* flagSegundoOp: ubicacion en memoria de la variable flagSegundoOp
 * \param int* flagCalculos: ubicacion en memoria de la variable flagCalculos
 * \param int* resultadoSuma: ubicacion en memoria de la variable resultadoSuma
 * \param int* resultadoResta: ubicacion en memoria de la variable resultadoResta
 * \param int* resultadoDivision: ubicacion en memoria de la variable resultadoDivision
 * \param int* restuladoMultiplicacion: ubicacion en memoria de la variable resultadoMultiplicacion
 * \param int* resultadoFactA: ubicacion en memoria de la variable resultadoFactA
 * \param int* resultadoFactB: ubicacion en memoria de la variable resultadoFactb
 * \param int* flagDividio: ubicacion en memoria de la variable flagDividio
 * \param int* flagFactorizoA: ubicacion en memoria de la variable flagFactorizoA
 * \param int* flagFactorizoB: ubicacion en memoria de la variable flagFactorizoB
 *
 * \return int devuelve -1: si hubo error, 1: si el usuario desea salir, 0: si se ejecuto correctamente y se desea continuar
 *
 */

int ejecutarOpcion(int opcion, int *primerOperando, int *segundoOperando,
		int *flagPrimerOp, int *flagSegundoOp, int *flagCalculos,
		int *resultadoSuma, int *resultadoResta, float *resultadoDivision,
		int *resultadoMultiplicacion, long long int *resultadoFactA, long long int *resultadoFactB, int *flagDividio,
		int *flagFactorizoA, int *flagFactorizoB);

/** \brief calcula todas las operaciones matematicas si es posible y asigna valores a las flags correspondientes
 *
 * \param int* flagDividio: ubicacion en memoria de la variable flagDividio
 * \param int* flagFactorizoA: ubicacion en memoria de la variable flagFactorizoA
 * \param int* flagFactorizoB: ubicacion en memoria de la variable flagFactorizoB
 * \param int* flagCalculos: ubicacion en memoria de la variable flagCalculos
 *
 * \return int devuelve 0: si hubo error, 1: si se ejecuto correctamente
 *
 */
int resetBanderasCalculos(int *flagDividio, int *flagFactorizoA,
		int *flagFactorizoB, int *flagCalculos);


/** \brief calcula todas las operaciones matematicas si es posible y asigna valores a las flags correspondientes
 *
 * \param int primeroOperando: valor del primer operando
 * \param int segundoOperando: valor del segundo operando
 * \param int* resultadoSuma: ubicacion en memoria de la variable resultadoSuma
 * \param int* resultadoResta: ubicacion en memoria de la variable resultadoResta
 * \param int* resultadoDivision: ubicacion en memoria de la variable resultadoDivision
 * \param int* restuladoMultiplicacion: ubicacion en memoria de la variable resultadoMultiplicacion
 * \param long long int* resultadoFactA: ubicacion en memoria de la variable resultadoFactA
 * \param long long int* resultadoFactB: ubicacion en memoria de la variable resultadoFactb
 * \param int* flagDividio: ubicacion en memoria de la variable flagDividio
 * \param int* flagFactorizoA: ubicacion en memoria de la variable flagFactorizoA
 * \param int* flagFactorizoB: ubicacion en memoria de la variable flagFactorizoB
 *
 * \return int devuelve -1: si hubo error, 1: si se ejecuto correctamente
 *
 */
int calcularTodo(int primerOperando, int segundoOperando, int *resultadoSuma,
		int *resultadoResta, float *resultadoDivision,
		int *resultadoMultiplicacion, long long int *resultadoFactA,
		long long int *resultadoFactB, int *flagDividio,
		int *flagFactorizoA, int *flagFactorizoB);

/** \brief muestra todos los resultados si corresponde
 *
 * \param int resultadoSuma: valor de la variable resultadoSuma
 * \param int resultadoResta: valor de la variable resultadoResta
 * \param float resultadoDivision: valor de la variable resultadoDivision
 * \param int restuladoMultiplicacion: valor de la variable resultadoMultiplicacion
 * \param long long int resultadoFactA: valor de la variable resultadoFactA
 * \param long long int resultadoFactB: valor de la variable resultadoFactb
 * \param int flagDividio: valor de la variable flagDividio
 * \param int flagFactorizoA: valor de la variable flagFactorizoA
 * \param int flagFactorizoB: valor de la variable flagFactorizoB
 *
 */
void mostrarResultados(int resultadoSuma, int resultadoResta,
		float resultadoDivision, int resultadoMultiplicacion,
		long long int resultadoFactA,
		long long int resultadoFactB, int flagDividio,
		int flagFactorizoA, int flagFactorizoB);
#endif
