#include <stdio.h>
#include <stdlib.h>
// I need string functions, strcpy
// https://www.programiz.com/c-programming/library-function/string.h
#include <string.h>
#include <time.h>

// Macros https://gcc.gnu.org/onlinedocs/cpp/Object-like-Macros.html#Object-like-Macros
// este macro dictara la cantidad maxima de palabras que habra en nuestro banco de palabras
#define MAX_WORDS 23



// # FUNCTION PROTOTYPES
// defina aqui todos los prototipos de funciones que vaya a implementar.
const char* get_random_word(void);
int menu(void);
int juego(void);
int menu_final(void); // opera con el resultado del juego. 1 si gano, 0 si perdio.


// Global variables
// este sera nuestro banco de palabras, por favor agregue, quite, modifique las palabras que quiera
// puede agregar hasta un maximo de MAX_WORDS palabras, si desea agregar mas de 23 palabras
// modifique MAX_WORDS a la cantidad que se ajuste a sus necesidades.
// ! NO AGREGUE PALABRAS QUE CONTENGAN NUMEROS
// ? este es un arreglo de strings, un arreglo de punteros ;)
const char *word_collection[MAX_WORDS]= {
                    "ferrari","porsche","marroquin","libertad","cerveza",
                    "justicia","supercalifragilisticoespiralidoso","superheroe","circuito",
                    "arduino","concatenar","facil","palabra","lamborghini",
                    "banco","macroeconomia","destruccion","universidad","herigonza",
                    "veintitres","python","java","adiviniar"
                    };

int intentos = 10;
/*
 ? function get_random_word(), no recibe argumentos porque trabajara con la variable global word_collection (banco de palabras)
 ? y devolvera una palabra aleatoria del banco de palabras
 */
const char* get_random_word(void){
    // seed the random generator.
    srand ( time (0) );
    // obtain a 0 < randon number < MAX_WORDS
    int random_position = rand() % MAX_WORDS;
    //printf("Random number is: %i\n", random_position);
    return word_collection[random_position];
}


// Menu function now runs constantly until the user chooses an option
// Problems: Any input apart from integers will set off an infinite loop
int menu(void){
    int choice = 0;
    printf("--- Menu --- \n"
           "1. Comenzar Juego\n"
           "2. Como Jugar\n"
           "3. Creditos\n"
           "4. Salir del Juego\n");

    while(choice != 4) {
        scanf("%d", &choice);
        if (choice == 1) {
            return 1;
        } else if (choice == 2) {
            return 2;
        } else if (choice == 3) {
            return 3;
        } else if (choice == 4) {
            return 4;
        } else {printf("Select a valid choice\n");}
    }
    return 0;
}

void buscar_letra(char palabra[], char buscar){
    int length = strlen(palabra);
    printf("Encontrando: %s %c\n", palabra, buscar);
    for (int i=0;i < length; i++){
        if (buscar == palabra[i]){
            palabra[i]='x';
            printf("Found char: \'%c\' in palabra: \'%s\'  position: %d \ncrossing it out ...\n\n\n",buscar, palabra, i);
        }
        else {
            
        }
    }
}

int juego(void){
    /* Esta funcion pregunta por el nombre del jugador y manejara el juego.
     "Ingrese su Nombre"
     Jugador:
     Intentos:
     Palabra:

     _ _ _ _ _ _ _ _

     retorna 1 si gana (letra por letra o de una)
     retorna 0 si pierde, ingresa 0

     */
    char nombre[55];

    printf("Como lo deberia llamar? ");

    //fseek(stdin,0,SEEK_END); This works, but not recommended

    // Recommended solution, double fgets, one picks up the trailing whitespace/newline caused by scanf
    // Using fgets because just gets is dangerous (for some reason)
    fgets(nombre, 55, stdin);
    fgets(nombre, 55, stdin);

    puts(nombre);


    return 0;
}


int menu_final(void){
    // dependiendo en el resultado de juego devuelve la pantalla de derrota o de victoria
    return 0;
}


int main(){
    // note como se invoca la funcion, la funcion se invoca de esta manera y se guarda en una variable
    const char* palabra_elegida = get_random_word();
    printf("%s\n",palabra_elegida);


    int menu_val = 0;
    while(menu_val != 4) {
        menu_val = menu();
        switch(menu_val) {
            case 1:
                printf("Comienza el juego\n");
                juego(); // corre el juego cuando es igual a 1
                break;
            case 2:
                printf("----------------------------\n");
                printf("Para jugar, seleccione 1 en el menu e ingrese su nombre;\n");
                printf("Esto iniciara el juego y tendras que adivinar la palabra\n");
                printf("Lo unico que debes ingresar es una letra a la vez para adivinar.\n");
                printf("Tendras 10 intentos (esto incluye letras correctas) para adivinar\n");
                printf("----------------------------\n\n");
                break;
            case 3:
                printf("==========================================\n");
                printf("Creado por: Luis Venegas y Daniel Cabrera \n");
                printf("==========================================\n\n");
                break;
        }
    }






    // comparemos 2 strings. puede remover estas lineas.
    // char str1[] = "abcd", str2[] = "abcd", str3[]="abCd";
    // printf("strcmp(str1, str2) = %d\n", strcmp(str1,str2));
    // printf("strcmp(str1, str2) = %d\n", strcmp(str1,str3));

    return 0;
}
