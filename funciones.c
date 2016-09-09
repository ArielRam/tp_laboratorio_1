#include <stdio.h>
#include <stdlib.h>

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
            printf("\nfac = %ld i = %d",fac,i);
            fac=fac*i;
            printf("\nfac = %ld i = %d",fac,i);
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
        if(str[i] == '.') continue;
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
 * \brief Verifica si el valor recibido se encuentra comprendido dentro de las opciones del menu
 *  de la calculadora
 * \param int 
 * \return 1 solo si el el valor esta comprendido dentro de las opciones
 *
 */
int chek_menu_opt(int a){
    if (a >= 1 && a <= 9)
        return 1;

    return 0;
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
        printf("es numero\n");
        sscanf(input,"%f",&auxiliar);
    }
    else{
        printf("El valor ingresado es invalido \n");
        return 0;
    }
    printf("%f", auxiliar);
    return auxiliar;
}