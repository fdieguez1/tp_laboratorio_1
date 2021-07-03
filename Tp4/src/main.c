/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

typedef struct
{
    int id;
    char nombre[20];
    int edad;
    char sexo;
} ePersona;

void mostrarPersona(ePersona* persona);
void mostrarPersonas(LinkedList* lista);
int esMasculino(void* persona);
int esFemenino(void* persona);
int mayorDeEdad(void* persona);
int esJorge(void* persona);

int compararNombres(void* persona1, void* persona2);
int compararEdad(void* persona1, void* persona2);

int main(void)
{
    srand(time(NULL));
    // rand() % (max-min+1) + min
    // min 18
    // max 65

    LinkedList* lista = ll_newLinkedList();

    ePersona p1 = {123, "Jorge", 16, 'm'};
    ePersona p2 = {323, "Mario", 20, 'm'};
    ePersona p3 = {135, "Marta", 17, 'f'};
    ePersona p4 = {124, "Miguel", 19, 'm'};
    ePersona p5 = {122, "Ana", 23, 'f'};
    ePersona p6 = {121, "Jenni", 25, 'f'};

    ll_add(lista, &p1);
    ll_add(lista, &p2);
    ll_add(lista, &p3);
    ll_add(lista, &p4);
    ll_add(lista, &p5);


    printf("\n--ll_len lista tamanio: %d\n", ll_len(lista));

    printf("\nLista Inicial: \n");
    mostrarPersonas(lista);

    printf("\n--ll_add: \n");
    ll_add(lista, &p6);
    printf("\nlista tamanio: %d\n", ll_len(lista));
    mostrarPersonas(lista);

    printf("\n--ll_get Segunda persona: \n");
    mostrarPersona((ePersona*) ll_get(lista,1));

    printf("\n--ll_set Cuarta persona: \n");
    ePersona p7 = {111, "Pepe", 20, 'm'};
    ll_set(lista, 3, &p7);
    mostrarPersonas(lista);

    printf("\n--ll_remove Cuarta persona: \n");
    ll_remove(lista, 3);
    mostrarPersonas(lista);

    printf("\n--ll_indexOf Ana: \n");
    printf("Indice Ana: %d\n",ll_indexOf(lista, &p5));

    printf("\n--ll_isEmpty: \n");
    if(ll_isEmpty(lista))
    {
        printf("Lista vacia\n");
    }
    else
    {
        printf("Lista con valores\n");
    }

    printf("\n--ll_Push en segundo lugar \n");
    ePersona p8 = {999, "Esteban", 14, 'm'};
    ll_push(lista, 1, &p8);
    mostrarPersonas(lista);

    printf("\n--ll_Pop segundo lugar \n");
    ePersona* auxPersona = ll_pop(lista, 1);
    mostrarPersonas(lista);
    printf("--Extraido: \n");
    mostrarPersona(auxPersona);

    printf("\nll_filter Lista Filtrada (mayor de edad): \n");
    LinkedList* mayores = ll_filter(lista, mayorDeEdad);
    mostrarPersonas(mayores);

    printf("\n--ll_Contains Lista inicial -> Jorge: \n");
    if (ll_contains(lista, &p1))
    {
        printf("Lo contiene\n");
    }
    else
    {
        printf("No lo contiene\n");
    }

    printf("\n--ll_Contains Mayores -> Lista inicial: \n");
    if (ll_containsAll(lista, mayores))
    {
        printf("Contiene todos\n");
    }
    else
    {
        printf("No contiene todos\n");
    }

    printf("\n--ll_sublist:\n");
    LinkedList* lista2 = ll_subList(lista, 1,3);
    if (!ll_isEmpty(lista2))
    {
        printf("Lista copiada, del indice 1 al indice 2\n");
        printf("Lista 2:\n");
        mostrarPersonas(lista2);
    }

    printf("\n--ll_clone:\n");
    LinkedList* lista3 = ll_clone(lista);
    if (!ll_isEmpty(lista3))
    {
        printf("Lista clonada a partir de la lista inicial\n");
        printf("Lista 3:\n");
        mostrarPersonas(lista3);
    }

    printf("\nll_sort Lista ordenada (edad, ASC): \n");
    ll_sort(lista, compararEdad,1);
    mostrarPersonas(lista);

    printf("\nll_sort Lista ordenada (nombre, ASC): \n");
    ll_sort(lista, compararNombres,1);
    mostrarPersonas(lista);

    printf("\nll_sort Lista ordenada (nombre, DESC): \n");
    ll_sort(lista, compararNombres,0);
    mostrarPersonas(lista);

     printf("\nll_sort Lista ordenada (edad, DESC): \n");
     ll_sort(lista, compararEdad,0);
    mostrarPersonas(lista);


    printf("\n--ll_clear lista inicial: \n");
    ll_clear(lista);
    mostrarPersonas(lista);

    printf("\n--ll_deleteLinkedList lista inicial: \n");
    if(ll_deleteLinkedList(lista) == 0)
    {
        printf("\nlista Eliminada \n");
    }


    /*startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
    startTesting(3);  // getNode - test_getNode
    startTesting(4);  // addNode - test_addNode
    startTesting(5);  // ll_add
    startTesting(6);  // ll_get
    startTesting(7);  // ll_set
    startTesting(8);  // ll_remove
    startTesting(9);  // ll_clear
    startTesting(10); // ll_deleteLinkedList
    startTesting(11); // ll_indexOf
    startTesting(12); // ll_isEmpty
    startTesting(13); // ll_push
    startTesting(14); // ll_pop
    startTesting(15); // ll_contains
    startTesting(16); // ll_containsAll
    startTesting(17); // ll_subList
    startTesting(18); // ll_clone
    startTesting(19); // ll_sort*/


    return 0;
}

void mostrarPersonas(LinkedList* lista)
{
    if(lista != NULL)
    {
        if (!ll_isEmpty(lista))
        {
            printf("\nId      Nombre Edad Sexo \n");
            for (int i = 0; i < ll_len(lista); i++)
            {
                mostrarPersona((ePersona*) ll_get(lista,i));
            }
        }
        else
        {
            printf("\nLista vacia \n");
        }
        printf("\n");
    }
}
void mostrarPersona(ePersona* persona)
{
    printf("%3d %10s %4d %1c\n", persona->id, persona->nombre, persona->edad, persona->sexo);
}

int esMasculino(void* persona)
{
    int ok = 0;
    ePersona* auxPersona = NULL;
    if (persona != NULL)
    {
        auxPersona = (ePersona*) persona;
        if (auxPersona->sexo == 'm' || auxPersona->sexo == 'M')
        {
            ok = 1;
        }
    }
    return ok;
}
int esFemenino(void* persona)
{
    int ok = 0;
    ePersona* auxPersona = NULL;
    if (persona != NULL)
    {
        auxPersona = (ePersona*) persona;
        if (auxPersona->sexo == 'f' || auxPersona->sexo == 'F')
        {
            ok = 1;
        }
    }
    return ok;
}
int mayorDeEdad(void* persona)
{
    int ok = 0;
    ePersona* auxPersona = NULL;
    if (persona != NULL)
    {
        auxPersona = (ePersona*) persona;
        if (auxPersona->edad > 17)
        {
            ok = 1;
        }
    }
    return ok;
}
int esJorge(void* persona)
{
    int ok = 0;
    ePersona* auxPersona = NULL;
    if (persona != NULL)
    {
        auxPersona = (ePersona*) persona;
        if (strcmp(auxPersona->nombre, "Jorge") == 0)
        {
            ok = 1;
        }
    }
    return ok;
}

int compararNombres(void* persona1, void* persona2)
{
    if (persona1 != NULL && persona2 != NULL)
    {
        char nombre1[20];
        strcpy(nombre1,((ePersona*)persona1)->nombre);
        char nombre2[20];
        strcpy(nombre2,((ePersona*)persona2)->nombre);
        return (strcmp(nombre1, nombre2));
    }
}
int compararEdad(void* persona1, void* persona2)
{
    int ret= 0;
    ePersona* auxiliar = NULL;
    ePersona* auxiliar2 = NULL;
    if(persona1 != NULL && persona2 != NULL)
    {
        auxiliar = (ePersona*) persona1;
        auxiliar2 = (ePersona*)persona2;
        if(auxiliar->edad > auxiliar2->edad)
        {
            ret = 1;
        }
        else if(auxiliar->edad < auxiliar2->edad)
        {
            ret = -1;
        }
    }
    return ret;
}




























