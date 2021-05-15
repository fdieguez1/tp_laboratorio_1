/*
 * ui.h
 *
 */

#ifndef UI_H_HEADER
#define UI_H_HEADER

/** \brief muestra un menu de opciones
 *
 * \param int size tamaño de lineas a mostrar vacias
 * \return void
 *
 */
void myClearForEclipse(int size);

/** \brief muestra un menu de opciones
 *
 * \return void
 *
 */
void showMenu();

/** \brief muestra un menu de opciones para la edicion
 *
 * \return void
 *
 */
void showEditMenu();

/** \brief muestra un menu de opciones para los informes
 *
 * \return void
 *
 */
void informSubMenu();

/** \brief muestra una alerta con opcion de confirmar o cancelar y devuelve la opcion elegida
 *
 * \param alertMsg[] char el mensaje a mostrar
 * \return int devuelve 1 si eligio confirmar, 0 si eligio cualquier otra cosa
 *
 */
int showAlert(char alertMsg[]);

#endif /* UI_H_HEADER */
