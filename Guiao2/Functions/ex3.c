#include "process.h"
/* Implemente um programa que crie dez processos filhos que deverão executar sequencialmente. Para este
efeito, os filhos podem imprimir o seu PID e o do seu pai, e finalmente, terminarem a sua execução com
um valor de saı́da igual ao seu número de ordem (e.g.: primeiro filho criado termina com o valor 1). O
pai deverá imprimir o código de saı́da de cada um dos seus filhos. */
int main(int argc, char* argv[]){
    int i;
    int status;

    for (i=1; i<11; i++){
        pid_t pid;
        if((pid = fork()) == 0) {
            pid_t child_pid = getpid();
            pid_t father_pid = getppid();
            printf("[filho] O PID do processo filho é %d.\nO pid do processo pai é %d.\n", child_pid, father_pid);
            printf("%d\n\n", i);
            _exit(i);
        }
        else {
            int terminated_pid = wait(&status);
            printf("[pai] process %d exited. exit code: %d.\n\n", terminated_pid, WEXITSTATUS(status));
        }
    }
    return 0;
}