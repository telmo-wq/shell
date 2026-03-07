#include "shell.h"


void shell_nao_interativo(void){
    char *linha;
    char **args;
    int status = -1;

    do {
        linha = ler_fluxo();
        args = dividir_linha(linha);
        status = executar_args(args);

        free(linha);
        free(args);

        if (status > 0){
            exit(status);
        }
    } while(status == -1);

}