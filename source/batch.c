#include "shell.h"


void batch(char *argv){
    FILE *arquivo;
    arquivo = fopen(argv, "r");
    char comando[100];

    while (fgets(comando, 100, arquivo) != NULL){
        comando[strcspn(comando, "\n")] = '\0';
        printf("%s\n", comando);

    }
    rewind(arquivo);

    while(fgets(comando, 100, arquivo) !=NULL){
        comando[strcspn(comando, "\n")] = '\0';
        if (strcmp(comando, "exit") == 0){
            break;
        }
        char *arg[100];

        char *token = strtok(comando, " ");
        int cont = 0;

        while(token != NULL && cont < 100){
            arg[cont] = token;
            token = strtok(NULL, " ");
            cont++;
        }
        arg[cont] = NULL;

        if (strcmp(arg[0], "cd") == 0){
            if (chdir(arg[1]) != 0){
                printf("Não foi possível localizar o diretório\n");
            }else {
                char diretorio_destino[1000];
                getcwd(diretorio_destino, sizeof(diretorio_destino));
                printf("%s\n", diretorio_destino);
            }
        }else {
            pid_t pid;

            pid = fork();

            if (pid == 0){
                //processo filho
                if(execvp(arg[0], arg) == -1){
                    perror("Erro no novo processo: processo_filho");
                }
                exit(EXIT_FAILURE);
            }
            else if(pid < 0){
                perror("Erro no novo processo: fork()");
            }
            else {
                //processo pai
                wait(NULL);
            }
        }

    }
    fclose(arquivo);

}