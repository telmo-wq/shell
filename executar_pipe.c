#include "shell.h"

void executar_pipe(char **args){
    int cont = 0;
    int fd_in = 0;

    while(args[cont] != NULL){
        int fd[2];

        if (args[cont+1] != NULL){
            pipe(fd);
        }

        pid_t pid = fork();
        if (pid == 0){
            if (fd_in != 0){
                dup2(fd_in, 0);
            }
            if (args[cont+1] != NULL){
                dup2(fd[1], 1);
            }

            if (execvp(args[cont], args) == -1){
                perror("Execução falhou\n");
                exit(1);
            }

        }else {
            wait(NULL);
            if (fd_in != 0){
                close(fd_in);
            }
            if (args[cont+1] != NULL){
                close(fd[1]);
                fd_in = fd[0];
            }
            cont++;
        }



    }
}