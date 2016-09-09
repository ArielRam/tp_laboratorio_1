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
   	int resultado1;

   	while(seguir == 's')
   	{

       	printf("1- Ingresar 1er operando (A=%.2f)\n",&valor1);
       	printf("2- Ingresar 2do operando (B=%.2f)\n",&valor2);
       	printf("3- Calcular la suma (A+B)\n");
       	printf("4- Calcular la resta (A-B)\n");
       	printf("5- Calcular la division (A/B)\n");
       	printf("6- Calcular la multiplicacion (A*B)\n");
       	printf("7- Calcular el factorial (A!)\n");
       	printf("8- Calcular todas las operacione\n");
       	printf("9- Salir\n");


       	scanf("%s",input);
       	//Valido que la opcion ingresada se un numero
       	//de lo contrario cae el default del switch
       	if (esNumerico(input))
        	sscanf(input,"%d",&opcion);


       	switch(opcion)
       	{
       	case 1:
           	valor1 = getFloat("Por ingrese el valor A :");
           	break;
       	case 2:
        	valor2 = getFloat("Por ingrese el valor B :");
           	break;
       	case 3:
           	resultado = sumar(valor1,valor2);
           	printf("el resultado de la suma es %.2f \n",resultado);
           	break;
       	case 4:
           	resultado = restar(valor1,valor2);
           	printf("el resultado de la suma es %.2f \n",resultado);
           	break;
       	case 5:
           	resultado = dividir(valor1,valor2);
           	printf("el resultado de la suma es %.2f \n",resultado);
           	break;
       	case 6:
           	resultado = multiplicar(valor1,valor2);
           	printf("el resultado de la suma es %.2f \n",resultado);
           	break;
       	case 7:
           	printf("ingrese un numero entero");
           	scanf("%d",&opcion1);
           	resultado1 = factorial(opcion1);

           	printf("\nel resultado del factorial es %.d \n",resultado1);
          	break;
       	case 8:
//                all_operations();
           break;
        default:
        	printf("La opcion ingresa no es una opcion valida del menu \n" );
        	break;
       }

       printf("\ndesea seguir ? ");
       fflush(stdin);
       clean_stdin();
       scanf("%c",&seguir);
   }
   return 0;
}
