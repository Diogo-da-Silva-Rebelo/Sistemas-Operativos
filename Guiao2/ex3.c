#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int i;
    int status;

    for (i=0; i<3; i++){
        int pid = fork();
        if(pid==0){
            printf("%d\n", i);
            _exit(i);
        }
        else {
            pid_t terminated_pid = wait(&status);
            printf("[pai] process %d exited. exit code: %d\n", terminated_pid, WEXITSTATUS(status));
        }
    }
    return 0;
}