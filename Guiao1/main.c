#include "files.h"

// Implementação do comando nl
int main(){

/* Observações:
 * -> Vamos ler do terminal (stdin);
 * -> Funções read definidas retornam um número de bytes lidos!
 * -> 1. Pretende-se esperar que o utilizador escreva;
 * -> 2. Imprimir a linha em questão e dar enter;
 * -> 3. Imprimir a linha, um ponto seguido do que o utilizador escreveu e dar um enter;
 * -> 4. Fazer isto até que o utilizador queria sair.*/

    void *line_buffer = malloc(BUF_SIZE);
    int bytes_read;

    int i=0;
    while ((bytes_read = myreadln2(0,line_buffer,BUF_SIZE)) > 0) {
        char line_number[LINE_SIZE];
        sprintf(line_number,"%*d ", 5, i++);
        write(STDOUT_FILENO, line_number, strlen(line_number));
        write(STDOUT_FILENO,line_buffer,bytes_read);
    }

return 0;
}
