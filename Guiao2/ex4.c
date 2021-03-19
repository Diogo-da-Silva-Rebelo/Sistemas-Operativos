#include "process.h"

/* Implemente um programa que crie dez processos filhos que deverão executar em concorrência. O pai
deverá esperar pelo fim da execução de todos os seus filhos, imprimindo os respectivos códigos de saı́da. */
int main(int argc, char* argv[]) {
    int i;
    int status;

    for (i = 1; i < 11; i++) {
        pid_t pid;
        if ((pid = fork()) == 0) {
            //printf("%d\n", i);
            _exit(i);
        }
    }
    pid_t terminated_pid = wait(&status);
    printf("[pai] process %d exited. exit code: %d\n", terminated_pid, WEXITSTATUS(status));
    return 0;
}