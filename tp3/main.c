/******************************************************************
*
* Trabajo Practico N 3
*
* \author Ariel Ramirez 1 B TM
*
* *******************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

#define MAX 2

int main()
{

    eMovie peliculas[MAX];
    char seguir='s';

    // incio las peliculas
    initializeMovies(peliculas, MAX);

    do
    {

        switch(print_and_get_menu_option_movies())
        {
            case 1:
                addMovie(peliculas, MAX);
                break;
            case 2:
                deleteMovie(peliculas, MAX);
                break;
            case 3:
                editMovie(peliculas, MAX);
                break;
            case 4:
                // createHmtlPage(peliculas, MAX);
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