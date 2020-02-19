#include <stdio.h>
#include <stdlib.h>
// ? I need string functions
#include <string.h>

#define MAX_WORDS 23



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
char* get_random_word(){
    srand ( time (0) );
    short random_position = rand() % MAX_WORDS;
    //printf("Random number is: %i\n", random_position);
    return word_collection[random_position];
}


int main(){
    // note como se invoca la funcion
    char* palabra_elegida = get_random_word();
    printf("%s\n",palabra_elegida);
    return 0;
}
