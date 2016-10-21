/******************************************************************
*
* Trabajo Practico N 2
*
* \author Ariel Ramirez 1 B TM
*
* *******************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

#define MAX 20

int main()
{

    ePerson personas[MAX];
    char seguir='s';

    // incio las personas
    initializePersons(personas, MAX);

    do
    {

        switch(print_and_get_menu_option())
        {
            case 1:
                setPerson(personas, MAX);
                break;
            case 2:
                deletePerson(personas, MAX);
                break;
            case 3:
                printPersons(personas, MAX);
                break;
            case 4:
                drawGraph(personas, MAX);
                break;
            case 5:
                seguir='n';
                break;
            default:
                printf("\nLa opcion ingresa no es valida!");
        }

        printf("\n");

    } while(seguir=='s');

    return 0;
}