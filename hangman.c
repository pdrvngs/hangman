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
// Improvements: Functional, but not elegant.
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
            return 0;
        } else {printf("Select a valid choice\n");}
    }
    return 0;
}

/*
Insert your code here
*/

int main(){
    // note como se invoca la funcion, la funcion se invoca de esta manera y se guarda en una variable
    const char* palabra_elegida = get_random_word();
    printf("%s\n",palabra_elegida);


    // Currently the menu works as intended once. Have tried calling menu() and main()
    // after each case, but it causes a slight bug in which the menu starts acting
    // weird and not choosing the inputed option.
    switch(menu())
    {
        case 1:
            printf("Comienza el juego\n");
            break;
        case 2:
            printf("Instrucciones de como jugar, opcion de regresar\n");
            break;
        case 3:
            printf("ABOUT page\n");
            break;
        case 4:
            break;

    }

    // previous attempt at a recurring menu. Hasn't worked, trying switch/case instead.
    //while (menu() != 4) {
    //    int choice = menu();
    //    if (choice == 1) {
    //        printf("1\n");
    //    } else if (choice == 2){
    //        printf("2\n");
    //    } else if (choice == 3){
    //        printf("3\n");
    //    }
    //}


    // comparemos 2 strings. puede remover estas lineas.
    // char str1[] = "abcd", str2[] = "abcd", str3[]="abCd";
    // printf("strcmp(str1, str2) = %d\n", strcmp(str1,str2));
    // printf("strcmp(str1, str2) = %d\n", strcmp(str1,str3));

    /*
        Insert your code here
    */
    return 0;
}
