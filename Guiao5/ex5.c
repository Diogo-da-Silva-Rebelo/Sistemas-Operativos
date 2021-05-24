#include "pipe.h"

/* Acrescente ao interpretador de comandos proposto nos guiões anteriores a possibilidade de encadear as
entradas e saı́das de programas a executar através de pipes anónimos (operador |). */

/* Esquema com pseudocódigo:
 * for (i=0; i < n_comandos; i++){
 *           if(i=0){
 *           pipe();
 *           switch(fork());
 *
 *           else{ if (i = n_comandos -1 ){
 *
 *                  switch(fork())
 *
 *                  } else{
 *                  pipe();
 *                  switch(fork())
 *                  }
 *                  }
 */

int main() {
    int pipefd[2];
    if(pipe(pipefd) < 0) {
        perror("Erro na criação do pipe!");
        exit(1);
    }


    if(fork() == 0) { // Primeiro filho, irá executar `cat foo.txt` e enviar o
        // seu output para o extremo de escrita do pipe.

        close(pipefd[0]); // Este filho não irá ler do pipe.

        dup2(pipefd[1], STDOUT_FILENO); // O standard output deste filho passa a
        // ser o extremo de escrita do pipe.

        close(pipefd[1]); // Este file descriptor já não é necessário, pois está
        // agora duplicado no STDOUT_FILENO.

        execlp("cat", "cat", "foo.txt", NULL);
        perror("Couldn't start process cat.");
        _exit(1);
    }


    close(pipefd[1]); // Não iremos voltar a escrever no pipe, portanto temos de
    // fechar o extremo de escrita.


    if (fork() == 0) { // Segundo filho, irá executar `wc -l` usando como input
        // o extremo de leitura do pipe.

        dup2(pipefd[0], STDIN_FILENO); // O standard input deste filho passa a
        // ser o extremo de leitura do pipe.

        close(pipefd[0]); // Este file descriptor já não é necessário, pois está
        // agora duplicado no STDIN_FILENO.

        execlp("wc", "wc", "-l", NULL);
        perror("Couldn't start process wc");
        _exit(1);
    }

    close(pipefd[0]); // Também já podemos fechar o extremo de leitura.

    wait(NULL);
    wait(NULL);

    return 0;
}