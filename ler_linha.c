#include "shell.h"


char *ler_linha(void){
    char *linha = NULL;
    size_t buff = 0;

    if(getline(&linha, &buff, stdin) == -1){
        if(feof(stdin)){
            free(linha);
            exit(EXIT_SUCCESS);
        }
        else{
            free(linha);
            perror("Erro enquanto carregando a linha do stdin\n");
            exit(EXIT_FAILURE);
        }
    }
    return(linha);
}