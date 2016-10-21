/******************************************************************
*
* Biblioteca de Funciones
*
* \author Ariel Ramirez 1 B TM
*
* *******************************************************************/

//Funciones
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"


// Constantes
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))
#define MAXVAL 50
float total;
float nro;

/**
 * \brief Suma dos valores
 * \param float numero
 * \param float numero
 * \return retorna la suma de los 2 valores recibidos
 *
 */
float sumar(float a, float b ){
    total=a+b;
    return total;
}

/**
 * \brief Resta dos valores
 * \param float numero
 * \param float numero
 * \return retorna la resta de los 2 valores recibidos
 *
 */
float restar(float a, float b){
    total=a-b;
    return total;
}

/**
 * \brief Divide dos valores
 * \param float numero
 * \param float numero
 * \return retorna la suma de los 2 valores recibidos
 *
 */
float dividir(float a , float b){
    if(b==0)
        printf("error zero division");
    total = a/b;
    return total;
}

/**
 * \brief Multiplica dos valores
 * \param float numero
 * \param float numero
 * \return retorna la suma de los 2 valores recibidos
 *
 */
float multiplicar(float a, float b){
    total=a*b;
    return total;
}

/**
 * \brief Factorial de un numero
 * \param int numero
 * \return retorna el factorial de un numero entero
 */
 long int factorial(int x){
    int i;
    long int fac = 1;
    for (i=2; i<=x; i=i+1)
    {
        fac=fac*i;
    }

     return (fac);
}

/**
 * \brief Pedir al usuario que ingrese un valor
 * \return retorna el valor ingresado
 *
 */
float pedirNum(){
    float val;
    printf("ingresar numero:");
    scanf("%f",&val);
    return val;
}


/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[])
{
   int i=0;
    while(str[i] != '\0')
    {
        //Agrego este pequeno parche a fines practicos de validar un float
        if(str[i] == '.') {i++;continue;}
        if(str[i] < '0' || str[i] > '9')
           return 0;
        i++;
    }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

/**
* \brief Vacia el buffer de la entrada estandar
*/
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * valida que la opcion ingresada retornando 0 si es invalida
 * y avisando al usuario
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    char input[MAXVAL] ;
    float auxiliar;
    printf("%s",mensaje);
    scanf("%s",input);

    if (esNumerico(input)){
        sscanf(input,"%f",&auxiliar);
    }
    else{
        // printf("El valor ingresado es invalido \n");
        return 0;
    }

    return auxiliar;
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * valida que la opcion ingresada retornando 0 si es invalida
 * y avisando al usuario
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getInt(char mensaje[])
{
    char input[MAXVAL] ;
    int auxiliar;
    printf("%s",mensaje);
    scanf("%s",input);

    if (esNumerico(input)){
        sscanf(input,"%d",&auxiliar);
    }
    else{
        // printf("El valor ingresado es invalido \n");
        return 0;
    }

    return auxiliar;
}

/**
 * \brief Ejecutar todas las operaciones de la calculadora
 * \param valor1 valor A
 * \param valor2 valor B
 * \return Imprime en pantalla el resultados de todas las operaciones.
 *
 */

 int all_operations(float x, float z){
 	float aux = 0;
 	long int auxf = 0;


 	aux = sumar(x,z);
 	printf("El resultado de la suma es : %.2f \n",aux );
 	aux = restar(x,z);
 	printf("El resultado de la resta es : %.2f \n",aux );
 	aux = multiplicar(x,z);
 	printf("El resultado de la multiplicacion es : %.2f \n",aux );
 	aux = dividir(x,z);
 	printf("El resultado de la division es : %.2f \n",aux );
 	auxf = factorial((int)x);
 	printf("El resultado de la factorial es : %.ld \n (Si A es un valor decimal se calcular el factorial de la parte entera)",auxf );

 	return 1;
 }

 /**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

 /**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

 /**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStrings(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}



/*Funciones TP 2*/


/** \brief Imprime el menu de opciones
 *
 * \return la opcion elegida
 *
 */
int print_and_get_menu_option()
{
    int opcion=0;

    printf("*******************\n");
    printf("******* MENU ******\n");
    printf("*******************\n");
    printf("\n\n");
    printf("Por favor ingrese una opcion\n\n");
    printf("1. Agregar persona\n");
    printf("2. Borrar persona\n");
    printf("3. Imprimir lista ordenada por nombre\n");
    printf("4. Imprimir grafico de edades\n");
    printf("5. Salir\n");
    printf("\n\n");

    printf("Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

/** \brief Inicializa posiciones del estado en 0
 *
 * \param personas array de estructura personas[] ePerson
 * \param len tamaño del array 
 * \return void
 *
 */
void initializePersons(ePerson personas[], int len)
{
    int i;

    for(i=0; i<len; i++)
        personas[i].status=0;
}

/** \brief Encontrar una posicion libre
 *
 * \param personas array de estructura ePerson
 * \param len int tamaño del array 
 * \return posicion libre 0 -1 int
 *
 */
int findFree(ePerson personas[], int len)
{
    int idx=-1;
    int i;

    for(i=0; i<len; i++)
    {
        if(personas[i].status==0)
        {
            idx=i;
            break;
        }
    }

    return idx;
}

/** \brief Busca DNI
 *
 * \param personas array de estructura ePerson
 * \param len int tamaño del array
 * \param dni dni float
 * \return posicion del dni or -1 int
 *
 */
int findByDni(ePerson personas[], int len, float dni)
{
    int idx=-1;
    int i;

    for(i=0; i<len; i++)
    {
        if(personas[i].dni==dni)
        {
            idx=i;
            break;
        }
    }

    return idx;
}

/** \brief Imprime la lista de Personas ordenada por nombre
 *
 * \param personas array de estructura ePerson
 * \param len int tamaño del array
 * \return void
 *
 */
void printPersons(ePerson personas[], int len)
{
    int i,j;

    for(i=0; i<len-1; i++)
    {
        if(personas[i].status==0) continue;
        for(j=i+1; j<len; j++)
        {
            if(personas[j].status==0) continue;

            if(strcmp(personas[i].name, personas[j].name)==1)
            {
                ePerson auxiliar=personas[i];
                personas[i]=personas[j];
                personas[j]=auxiliar;
            }
        }
    }

    printf("\nNOMBRE\tEDAD\tDNI\n\n");

    for(i=0; i<len; i++)
    {
        if(personas[i].status==1)
            printf("%s\t%d\t%.0f\n", personas[i].name, personas[i].age, personas[i].dni);
    }
}

/** \brief alta de persona persona
 *
 * \param personas array de estructura ePerson
 * \param len int tamaño del array
 * \return void
 *
 */
void setPerson(ePerson personas[], int len)
{
    int freeP=0;
    int findDni=0;
    int ageAux;
    int aux = 0;
    float dniAux=0;

    freeP=findFree(personas, len);

    if(freeP==-1)
        printf("\nNo hay lugar disponible!!!");
    else
    {
        dniAux = getFloat("\nIngrese DNI: ");
        // fflush(stdin);
		clean_stdin();

		if (dniAux == 0){
            printf("\nEl DNI ingresado  es invalido");
            return;
		}
			

        findDni=findByDni(personas, len, dniAux);

        if(findDni!=-1 && personas[findDni].status==1)
            printf("\nPersona registrada actualmente");
        else
        {

            while(aux == 0)
            {
            	aux = getStrings("Ingrese nombre: ",personas[freeP].name);
            
	            if (aux == 0)
		            printf("\nNombre invalido! ingrese solo letras por favor. \n");
            }            

            ageAux = getInt("Ingrese edad: ");
            
            if (ageAux == 0)
	            printf("\nEdad Invalida! \n");


            while(ageAux < 1 || ageAux > 100)
            {
            	ageAux = getInt("Ingrese una edad valida (Entre 1 y 100): ");
            
	            if (ageAux == 0)
		            printf("\nEdad Invalida! \n");
            }
			
			personas[freeP].age = ageAux;
            personas[freeP].dni=dniAux;

            personas[freeP].status=1;
            printf("\nLa carga ha sido exitosa!\n\n");
        }
    }
}

/** \brief dar de baja una persona
 *
 * \param $personas array de estructura ePerson
 * \param len int tamaño del array
 * \return void
 *
 */
void deletePerson(ePerson personas[], int len)
{
    float dniAux=0;
    int idx=0;
    int confirm=0;

    dniAux = getFloat("\nIngrese DNI: ");
    // fflush(stdin);
	clean_stdin();

	if (dniAux == 0){
        printf("\nEl ingresado DNI es invalido");
        return;
	}

    idx = findByDni(personas, len, dniAux);

    if(idx == -1)
       printf("\nEl DNI ingresado no existe");
    else
    {
        printf("\nNOMBRE  EDAD  DNI");
        printf("\n\n");
        printf("%s - %d - %.0f", personas[idx].name, personas[idx].age, personas[idx].dni);
        
        printf("\n\n");

        printf("Esta seguro que desea eliminar esta persona?");
        printf("\n\n");
        printf("1. Si\n");
        printf("2. No\n");
        printf("\nOpcion: ");
		clean_stdin();
        // fflush(stdin);
        scanf("%d", &confirm);

        if (confirm == 1)
           	printf("\nSe elimino correctamente!");
        else
        	return;
    }
}

/** \brief Grafico de edades
 * Este metodo fue presentado en clase por el profesor
 * 
 * \param personas array de estructura ePerson
 * \param len int tamaño del array
 * \return void
 */
void drawGraph(ePerson personas[], int len)
{
    int menor18=0;
    int entre19Y35=0;
    int mayor35=0;
    int i;
    int j;
    int mayorCantidad=0;

    for(i = 0; i < len; i++)
    {
        if(personas[i].status==1)
        {
            if(personas[i].age<=18)
            {
                menor18++;
            }
            else if(personas[i].age>=19 && personas[i].age<=35)
            {
                entre19Y35++;
            }
            else if(personas[i].age>35)
            {
                mayor35++;
            }
        }
    }

    if(menor18>entre19Y35)
    {
        if(menor18>mayor35)
        {
            mayorCantidad=menor18;
        }
    }
    else
    {
        if(entre19Y35>=mayor35)
        {
            mayorCantidad=entre19Y35;
        }
        else
        {
            mayorCantidad=mayor35;
        }
    }

    char matriz[mayorCantidad][3];

    for(i=0; i<mayorCantidad; i++)
    {
        for(j=0; j<3; j++)
        {
            switch(j)
            {
            case 0:
                if(menor18>i)
                {
                    matriz[i][j]='*';
                }
                else
                {

                    matriz[i][j]=' ';
                }
                break;
            case 1:
                if(entre19Y35>i)
                {
                    matriz[i][j]='*';
                }
                else
                {

                    matriz[i][j]=' ';
                }
                break;
            case 2:
                if(mayor35>i)
                {
                    matriz[i][j]='*';
                }
                else
                {

                    matriz[i][j]=' ';
                }
                break;
            }
        }
    }

    printf("\n\n");

    for(i=mayorCantidad-1; i>=0; i--)
    {
        printf("%c      %c      %c      \n",matriz[i][0],matriz[i][1],matriz[i][2]);
    }

    printf("\n<18  18-35  >35");

}