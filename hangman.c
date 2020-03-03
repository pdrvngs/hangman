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

int buscar_letra(char palabra[]){
    int tries = 0;
    char underscored[50];
    int length = strlen(palabra);
    char buscar = ' ';
    char nombre[55];

    printf("Como lo deberia llamar? ");
    // Double fgets to pick up trailing whitespace due to scanf
    fgets(nombre, 55, stdin);
    fgets(nombre, 55, stdin);


    // Creates a '_' version of the word. We'll be replacing letters in this one.
    for(int i = 0; i < length; i++){
        underscored[i] = '_';
    }

    /* Prints out underscored version
    for(int i = 0; i < length; i++){
        printf("%c", underscored[i]);
        printf(" ");
    } */

    printf("\n");

    // Main body of the function, runs (intentos) times, asking for a letter each time.
    while(tries < intentos && strcmp(underscored, palabra) != 0) {
        printf("Jugador: "); puts(nombre);
        printf("Intentos: %d de %d\n", tries, intentos);
        printf("Palabra: \n");

        // Prints underscored.
        for (int i = 0; i < length; i++) {
            printf("%c", underscored[i]);
            printf(" ");
        }
        printf("\n");

        printf("\nQue letra quiere buscar: ");
        scanf(" %c", &buscar);

        // Looks for the same index, compares to random word, if true, replaces underscore with letter.
        for (int i = 0; i < length; i++) {
            if (buscar == palabra[i]) {
                underscored[i] = buscar;
                } else {}
        }

        tries++;
        printf("\n");
    } // END OF WHILE

    // Checks if you guessed or not.
    if(strcmp(underscored, palabra) == 0){
        puts(palabra);
        return 1;
    } else {return 0;}
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


    //fseek(stdin,0,SEEK_END); This works, but not recommended

    // Recommended solution, double fgets, one picks up the trailing whitespace/newline caused by scanf
    // Using fgets because just gets is dangerous (for some reason)


    char random_word[50];
    strcpy(random_word, get_random_word());
    buscar_letra(random_word);
    printf("\n");


    return 0;
}


int menu_final(void){
    // dependiendo en el resultado de juego devuelve la pantalla de derrota o de victoria
    return 0;
}


int main(){
    // note como se invoca la funcion, la funcion se invoca de esta manera y se guarda en una variable
    const char* palabra_elegida = get_random_word();
    //printf("%s\n",palabra_elegida);


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
    return 0;
}
