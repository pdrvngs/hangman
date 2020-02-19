#include <stdio.h>
#include <stdlib.h>
// I need string functions, strcpy
#include <string.h>
#include <time.h>

// Macros https://gcc.gnu.org/onlinedocs/cpp/Object-like-Macros.html#Object-like-Macros
// este macro dictara la cantidad maxima de palabras que habra en nuestro banco de palabras
#define MAX_WORDS 23



// # FUNCTION PROTOTYPES
// defina aqui todos los prototipos de funciones que vaya a implementar.
const char* get_random_word(void);




// Global variables
// este sera nuestro banco de palabras, por favor agregue, quite, modifique las palabras que quiera
// puede agregar hasta un maximo de MAX_WORDS palabras, si desea agregar mas de 23 palabras
// modifique MAX_WORDS a la cantidad que se ajuste a sus necesidades.
// ? este es un arreglo de strings, un arreglo de punteros ;)
const char *word_collection[MAX_WORDS]= {
                    "este","es","un","banco","de",
                    "palabras","sientase","en","libertad",
                    "de","agregar","la","cantidad","de",
                    "palabras","que","usted","desee","hasta",
                    "un","maximo","de","MAX_WORDS"
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


/*
Insert your code here
*/

int main(){
    // note como se invoca la funcion, la funcion se invoca de esta manera y se guarda en una variable
    const char* palabra_elegida = get_random_word();
    printf("%s\n",palabra_elegida);

    /*
        Insert your code here
    */
    return 0;
}
