#include "files.h"

/*Ex.3: Implemente a leitura de uma linha (i.e. sequência terminada por \n) numa função readln,
 * ou seja, ssize_t readln(int fd, char *line, size_t size);*/
ssize_t myreadln(int fd, char *line, size_t size){

    ssize_t i = 0;

    //-1, pois já sabemos que termina em \n, logo, não queremos ler esse.
    while (i < size - 1){
        ssize_t line_read = read(fd,&line[i],1); //leitura de 1 careter
        if (line_read < 1) break;
        if (line[i++] == '\n') break;
    }
    line[i] = 0;
    return i;
}
/*Ex.4: Melhoramento da implementação da função readln, evitando ler um
 * carater de cada vez.*/
ssize_t myreadln2(int fd, char* line, size_t size) {
    ssize_t bytes_read = read(fd, line, size);
    if (!bytes_read) return 0;
    //definir tamanho da linha
    size_t length_line = strcspn(line, "\n") + 1; //retorna o tamanho entre o primeiro elemento de str1 e str2
    if (bytes_read < length_line) length_line = bytes_read;
    line[length_line] = 0;

    lseek(fd, length_line, SEEK_CUR);
    return length_line;
}

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

    int i = 1;
    while ((bytes_read = myreadln2(0,line_buffer,BUF_SIZE)) > 0) {
        char line_number[LINE_SIZE];
        sprintf(line_number,"%*d ", 5, i++);
        write(STDOUT_FILENO, line_number, strlen(line_number));
        write(STDOUT_FILENO, line_buffer, bytes_read);
    }

    return 0;
}


