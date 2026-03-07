#include "shell.h"

void shell_interativo(int argc, char *argv[]){
    char *linha;
    char **args;
    int status = -1;

    do {
        printf("pluto$ ");
        linha = ler_linha();
        args = dividir_linha(linha);
        if (argc > 1){
            status = batch(argv[1]);
        }else if (argc == 1){
            status = executar_args(args);
        }

        free(linha);
        free(args);

        if (status >= 0){
            exit(status);
        }
    } while (status == -1);
}