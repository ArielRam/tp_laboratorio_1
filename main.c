/******************************************************************
* Trabajo Practico Numero 1 Laboratorio/Programacion 1
*
* Enunciado:
* Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
*	1.Ingresar 1er operando (A=x)
*	2.Ingresar 2do operando (B=y)
*	3.Calcular la suma (A+B)*
*	4.Calcular la resta (A-B)
*	5.Calcular la division (A/B)
*	6.Calcular la multiplicacion (A*B)
*	7.Calcular el factorial (A!)
*	8.Calcular todas las operaciones
*	9.Salir
*
* Aspectos a tener en cuenta:
*   - Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
*		que contenga las funciones para realizar las 4 operaciones. 
*
*	- En el menú deberán aparecer los valores actuales cargados en los operandos A y B 
*       (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)

*	- Deberán contemplarse los casos de error (división por cero, etc)
*
*	- Documentar todas las funciones
*
* Version: 1.0 2016-09-09
* Autor: Ariel Ramirez 1 B Turno Manana
* 
* *******************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "funciones.h"

#define MAX 50


int main()
{
	char input[MAX] ;
	int length;
   	char seguir='s';
   	int opcion=0;
   	int opcion1=0;
   	float valor1=0,valor2=0;
   	float resultado;
   	int flagOpA = 0;
   	int flagOpB = 0;
   	long int resultadof;

   	while(tolower(seguir) == 's')
   	{

       	printf("1- Ingresar 1er operando (A=%.2f)\n",valor1);
       	printf("2- Ingresar 2do operando (B=%.2f)\n",valor2);
       	printf("3- Calcular la suma (A+B)\n");
       	printf("4- Calcular la resta (A-B)\n");
       	printf("5- Calcular la division (A/B)\n");
       	printf("6- Calcular la multiplicacion (A*B)\n");
       	printf("7- Calcular el factorial (A!)\n");
       	printf("8- Calcular todas las operacione\n");
       	printf("9- Salir\n");

       	fflush(stdin);
       	scanf("%s",input);
       	// Lo parseo directamente a int, si recibo vienen letras se convierten a cero
       	// evito comprobaciones. y pasa directo al default de case.
        sscanf(input,"%d",&opcion);


       	switch(opcion)
       	{
       	case 1:
        //op1   	
           	valor1 = getFloat("Ingrese el valor A :");
           	if (valor1 != 0)
           		flagOpA = 1;
           	break;
       	case 2:
        //op2
        	valor2 = getFloat("Ingrese el valor B :");
           	if (valor2 != 0)
           		flagOpB = 1;
           	break;
       	case 3:
       	//Suma
       		if (flagOpA && flagOpB)
       		{
           		resultado = sumar(valor1,valor2);
           		printf("el resultado de la suma es %.2f \n",resultado);
       		}else{
       			printf("A y B son requeridos para operar \n");
       		}
           	break;
       	case 4:
       	//resta
       		if (flagOpA && flagOpB)
       		{
           		resultado = restar(valor1,valor2);
           		printf("el resultado de la resta es %.2f \n",resultado);
       		}else{
       			printf("A y B son requeridos para operar \n");
       		}
           	break;
       	case 5:
       	//Division
       		if (flagOpA && flagOpB)
       		{
           		resultado = dividir(valor1,valor2);
           		printf("el resultado de la division es %.2f \n",resultado);
       		}else if (flagOpA && !flagOpB)
       		{
           		printf("Error! division por cero. \n");
       		}else{
       			printf("A y B son requeridos para operar \n");
       		}
           	break;
       	case 6:
       	// multiplicacion
       		if (flagOpA && flagOpB)
       		{
           		resultado = multiplicar(valor1,valor2);
           		printf("el resultado de la multiplicacion es %.2f \n",resultado);
       		}else{
       			printf("A y B son requeridos para operar \n");
       		}
           	break;
       	case 7:
       	// Factorial
       		if (flagOpA)
       		{
           		resultadof = factorial((int)valor1);
       			printf("\n El resultado del factorial es %.ld (Si A es un valor decimal se calcular el factorial de la parte entera)\n",resultadof);
       		}else{
       			printf("A es querido para esta operacion \n");
       		}
          	break;
       	case 8:
       	// Todas las operaciones
       		if (flagOpA && flagOpB){
               	all_operations(valor1, valor2);
       		}else{
       			printf(" A y B son requeridos para operar \n" );
       		}
           break;
        default:
        	printf("La opcion ingresa no es una opcion valida del menu \n" );
        	break;
       	}
		opcion = 0;
		printf("\n Desea seguir ? ");
		fflush(stdin);
		clean_stdin();
		scanf("%c",&seguir);
   }

   	printf("Bye \n");
   	return 0;
}
