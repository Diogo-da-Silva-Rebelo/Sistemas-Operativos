#include "exec.h"

/* Implemente um programa semelhante ao anterior que execute o mesmo comando mas agora no contexto
de um processo filho. */

int main(int argc, char** argv) {
    pid_t pid;
    if (( pid == fork()) == 0){
        int ret;
        ret = execlp("ls","-l",NULL);
        if (ret < 0) perror("Something's wrong. ");
    }

    //father's not doing anything.

    return 0;
}