#include "shell.h"

void shell_interativo(void){
    char *linha;
    char **args;
    int status = -1;

    do {
        printf("simple_prompt$ ");
        linha = ler_linha();
        args = dividir_linha(linha);
        status = executar_args(args);

        free(linha);
        free(args);

        if (status >= 0){
            exit(status);
        }
    } while (status == -1);
}