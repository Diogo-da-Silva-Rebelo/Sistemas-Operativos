#include "exec.h"

int main(int argc, char** argv) {
    /* Alguns aspetos a ter em conta:
     * -> e se o comando não existir e o exec retornar erro?
     * -> e quando mudamos arg0?
     */

    int ret;
    char * exec_args[] ={"/bin/ls","l",NULL};
    ret = execl("/bin/ls","/bin/ls","-l",NULL);
    printf("ola %d\n", ret);
    perror("reached return");

    /* Existiriam outras formas de chamar o comando -ls
     * -> ret = execlp("/bin/ls","/bin/ls","-l",NULL);
     * -> ret = execv("/bin/ls", exec_args);
     * -> ret = execvp("ls", exec_args)
     */

    return 0;
}