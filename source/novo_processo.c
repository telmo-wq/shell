#include "shell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int novo_processo(char **args){
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0){
        //processo filho
        if(execvp(args[0], args) == -1){
            perror("Erro no novo processo: comando não existente\n");
        }
        exit(EXIT_FAILURE);
    }
    else if(pid < 0){
        perror("Erro no novo processo: fork()");
    }
    else {
        //processo pai
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return (-1);
}