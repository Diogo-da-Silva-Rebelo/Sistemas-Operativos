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

