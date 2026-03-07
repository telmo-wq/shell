#include "shell.h"


char *ler_fluxo(void){
    int bufsize = 1024;
    int i = 0;
    char* linha = malloc(sizeof(char) * bufsize);
    int caractere;

    if (linha == NULL){
        fprintf(stderr, "Erro de alocação no ler_fluxo\n");
        exit(EXIT_FAILURE);
    }
    while(1){
        caractere = getchar();
        if (caractere == EOF){
            free(linha);
            exit(EXIT_SUCCESS);
        }

        else if (caractere == '\n'){
            linha[i] = '\0';
            return linha;
        }
        else {
            linha[i] = caractere;
        }
        i++;
        bufsize += bufsize;
        linha = realloc(linha, bufsize);
        if (linha == NULL){
            fprintf(stderr, "Erro de realocação em ler_fluxo\n");
            exit(EXIT_FAILURE);
        }
    }
}