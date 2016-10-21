//Prototipos


float sumar(float a, float b);
float restar(float a, float b);
float dividir(float a, float b);
float multiplicar(float a, float b);
long int factorial(int x);

int esNumerico(char str[]);
int chek_menu_opt(int a);
int getVal(char mensaje[]);

int esAlfaNumerico(char str[]);

float getFloat(char mensaje[]);
float getInt(char mensaje[]);

int all_operations(float x, float z);

void clean_stdin(void);

int getStrings(char mensaje[],char input[]);
void getString(char mensaje[],char input[]);
int esSoloLetras(char str[]);

// Funciones tp2

typedef struct
{
    char name[25];
    int age;
    float dni;
    int status;
} ePerson;


typedef struct
{
    char title[30];
    char category[50];
    int duration;
    int rating;
    char description[150];
    char link_to_img[150];
    int status;
    int id;
} eMovie;


int print_and_get_menu_option();

void initializePersons(ePerson personas[], int len);

int findFree(ePerson personas[], int len);

int findByDni(ePerson personas[], int len, float dni);

void printPersons(ePerson personas[], int len);

void setPerson(ePerson personas[], int len);

void deletePerson(ePerson personas[], int len);

void drawGraph(ePerson personas[], int len);