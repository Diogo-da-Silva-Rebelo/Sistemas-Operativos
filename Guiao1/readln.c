#include "files.h"

/*Ex.3: Implemente a leitura de uma linha (i.e. sequência terminada por \n) numa função readln,
 * ou seja, ssize_t readln(int fd, char *line, size_t size);*/
ssize_t myreadln(int fd, char *line, size_t size){
    ssize_t line_read;
    int i=0;

    while (i<size && line[i] != '\n'){
        line_read = read(fd,line,size);
        i+=line_read;
        return line_read;
    }
}

int main(int argc, char *argv[]){


}
