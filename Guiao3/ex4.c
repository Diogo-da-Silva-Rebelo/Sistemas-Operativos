#include "exec.h"

/* Implemente um programa que execute o programa da questão anterior com uma qualquer lista de argu-
mentos. Mantendo o nome do ficheiro que corresponde o programa executável, experimente alterar o
primeiro elemento da lista de argumentos (índice zero do argv). */

int main(void){
    char buf[1024];
    size_t i = 1;
    char* args[1024];

    strcpy(args[0],"./ex3");
    while (fgets(buf, 1024, stdin)) {
        buf[strcspn(buf,"\n\r")] = 0;
        strcpy(args[i+1],strdup(buf));
    }

    (args[i]) = NULL;
    execv("./ex3",args);

    return 0;
}
