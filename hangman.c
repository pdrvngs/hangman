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
int menu_final(int gano); // opera con el resultado del juego. 1 si gano, 0 si perdio.
void menu_opciones(void);


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
                    "veintitres","python","java","adivinar"
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


void clearscreen()
{
    system("@cls||clear");
}


// Menu function now runs constantly until the user chooses an option
// Problems: Any input apart from integers will set off an infinite loop
int menu(void){
    char nothing[3];
    int choice = 0;
    printf("\033[1;33m");
    printf("--- Menu --- \n"
           "1. Comenzar Juego\n"
           "2. Como Jugar\n"
           "3. Creditos\n"
           "4. Salir del Juego\n");
    printf("\033[0m");

    while(choice != 4) {
        printf("\033[0;33m");
        printf("Ingresar opción: ");
        scanf("%d", &choice);
        printf("\033[0m");
        if (choice == 1) {
            return 1;
        } else if (choice == 2) {
            return 2;
        } else if (choice == 3) {
            return 3;
        } else if (choice == 4) {
            return 4;
        } else if (choice > 4 || choice < 0){
            printf("Select a valid choice\n"); // avoids large integers
        } else {
            printf("Select a valid choice\n");
            fgets(nothing, 3, stdin); // Checks for EOF caused by character input, avoids endless loop crash.
        }
    }
    return 0;
}

int juego(void){
    int tries = 0;
    int aciertos = 0;
    unsigned int length;
    char underscored[50];
    char buscar = ' ';
    char nombre[55];
    char palabra[50];
    const char* random_word = get_random_word();
    char nothing[3];


    // gets random word from word bank, copies it to random_word, gets length
    strcpy(palabra, random_word);
    length = strlen(palabra);
    printf("\033[0;34m");
    printf("Ingrese nombre del jugador: ");
    printf("\033[0m");
    // Double fgets to pick up trailing whitespace due to scanf
    printf("\033[0;34m");
    fgets(nombre, 55, stdin);
    fgets(nombre, 55, stdin);
    printf("\033[0m");
    // Creates a '_' version of the word. We'll be replacing letters in this one.
    for(int i = 0; i < length; i++){
        underscored[i] = '_';
    }

    printf("\n\n");

    // Main body of the function, runs (intentos) times, asking for a letter each time.
    while(tries < intentos && strcmp(underscored, palabra) != 0 && buscar != '0' && aciertos != length) {
        printf("\033[1;36m");
        printf("Jugador: "); fputs(nombre, stdout);
        printf("Intentos: %d de %d\n", tries, intentos);
        printf("Aciertos: %d\n", aciertos);
        printf("Palabra: \n\n");
        printf("\033[0m");

        // Prints underscored.
        for (int i = 0; i < length; i++) {
            printf("%c", underscored[i]);
            printf(" ");
        }
        printf("\n");
        printf("\033[0;35m");
        printf("\nQue letra quiere buscar: ");
        scanf(" %c", &buscar);
        printf("\033[0m");
        // Looks for the same index, compares to random word, if true, replaces underscore with letter.
        for (int i = 0; i < length; i++) {
            if (buscar == palabra[i]) {
                underscored[i] = buscar;
                aciertos++;
                } else {}
        }
        tries++;
        printf("\n");
    } // END OF WHILE

    printf("\n\n");
    // Checks if you guessed or not.
    //menu final ganador, Intentos, nombre, palabra
    if(strcmp(underscored, palabra) == 0 || aciertos == length){
        printf("\033[1;32m");
        printf("      ¡Ganaste!      \n\n");
        printf("Palabra adivinada: "); puts(palabra);
        printf("Jugador:"); fputs(nombre, stdout);
        printf("Intentos: %d de %d\n", tries, intentos);
        printf("Presione ENTER para regresar al menu\n");
        printf("\033[0m");
        fgets(nothing, 3, stdin);
        fgets(nothing, 3, stdin);
        clearscreen();
        return 1;
    } else {

        // menu final perdedor, intentos 10/10, nombre y palabra
        printf("\033[1;31m");
        printf("       Perdiste       \n\n");
        printf("Palabra no adivinada: "); puts(palabra);
        printf("Jugador:"); fputs(nombre, stdout);
        printf("Intentos: %d de %d\n", tries, intentos);
        printf("Presione ENTER para regresar al menu\n");
        printf("\033[0m");
        fgets(nothing, 3, stdin);
        fgets(nothing, 3, stdin);
        clearscreen();
        return 0;}
}


int main(){
    int menu_val = 0;

    while(menu_val != 4) {
        menu_val = menu();
        switch(menu_val) {
            case 1:
                printf("\033[1;34m");
                printf("Comienza el juego\n");
                printf("\033[0m");
                juego();
                break;
            case 2:
                printf("\033[1;34m");
                printf("----------------------------\n");
                printf("Para jugar, seleccione 1 en el menu e ingrese su nombre;\n");
                printf("Esto iniciara el juego y tendras que adivinar la palabra\n");
                printf("Lo unico que debes ingresar es una letra a la vez para adivinar.\n");
                printf("Tendras 10 intentos (sin contar letras correctas) para adivinar\n");
                printf("----------------------------\n\n");
                printf("\033[0m");
                break;
            case 3:
                printf("\033[1;31m");
                printf("==========================================\n");
                printf("Creado por: Luis Venegas y Daniel Cabrera \n");
                printf("==========================================\n\n");
                printf("\033[0m");
                break;
        }
    }
    return 0;
}

