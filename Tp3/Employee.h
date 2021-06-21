#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;


/** \brief Genera un nuevo empleado vacio inicializado en 0
 *
 * \return Employee*
 *
 */
Employee* employee_new();
/** \brief Genera un nuevo empleado con parametros string
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
/** \brief Genera un nuevo empleado
 *
 * \param id int
 * \param nombre char*
 * \param horas int
 * \param sueldo int
 * \return Employee*
 *
 */
Employee* newEmployeeParam(int id, char* nombre, int horas, int sueldo);
/** \brief Elimina un empleado
 *
 * \param this Employee*
 * \return int
 *
 */
int employee_delete(Employee* this);

//getters
/** \brief Get by id
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id);
/** \brief Get by nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre);
/** \brief  get horas trabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief Get by sueldo
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

//setters
/** \brief Set id
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id);

/** \brief Set nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief set horas trabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


/** \brief setea el sueldo de un empleado
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Muestra un solo empleado
 *
 * \param this Employee*
 * \return int
 *
 */
int mostrarEmpleado(Employee* this);

/** \brief Ordena comparando id
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int employee_cmpId(void* a, void* b);

/** \brief Ordena comparando horas
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int employee_cmpHours(void* a, void* b);

/** \brief Ordena comparando sueldos
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int employee_cmpSalary(void* a, void* b);

/** \brief Ordena comparando nombres
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int employee_cmpName(void* a, void* b);

#endif // employee_H_INCLUDED
