#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "Employee.h"

/** \brief Busca un empleado especifico por su id
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int
 *
 */
int findEmployee(LinkedList* pArrayListEmployee, int id);

/** \brief Busca el proximo id
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int getNextId(LinkedList* pArrayListEmployee);
/** \brief buscar un indice en la lista
 *
 * \param pArrayListEmployee LinkedList*
 * \param int* pIndice
 * \return int
 *
 */
int findPlace(LinkedList* pArrayListEmployee, int* pIndice);
/** \brief Busca el mayor id de los empleados que estan cargados
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int*
 * \return int
 *
 */
int getBiggestId(LinkedList* pArrayListEmployee, int* id);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id);

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(LinkedList* pArrayListEmployee);

#endif // CONTROLLER_H_INCLUDED
