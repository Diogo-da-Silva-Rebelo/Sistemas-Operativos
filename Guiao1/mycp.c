#include "files.h"

/* Ex.1: Implemente em C um programa mycp com funcionalidade similar ao comando cp. Varie o tamanho do
 * buffer usado e meça o tempo necessário para copiar um ficheiro de grande dimensão. Não esquecer de
 * criar o ficheiro de origem.*/
int main(int argc, char *argv[]){
    void *buffer = malloc(BUF_SIZE);
    int desc_origin, desc_dest;

    desc_origin = open(argv[1],O_RDONLY);
    desc_dest = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, 0640);


    if (desc_origin == -1) {
        perror("open");
        return -1;
    }
    if (desc_dest == -1){
        perror("open");
        return -1;
    }

    //não esquecer que o valor dos bytes lidos têm de ser atualizados!
    int bytes_read;
    while (bytes_read > 0) {
        bytes_read = read(desc_origin, buffer, bytes_read);
        write(desc_dest, buffer, bytes_read);
    }

    close(desc_origin);
    close(desc_dest);

    return 0;
}