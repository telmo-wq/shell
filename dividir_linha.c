#include "shell.h"
#define TOK_DELIM " \t\r\n\a"



char **dividir_linha(char *linha){
    int buff = 64;
    int i = 0;
    char **tokens = malloc(buff * sizeof(char *));
    char *token;

    if (!tokens){
        fprintf(stderr, "Erro de alocação em dividir_linha\n");
        exit(EXIT_FAILURE);
    }
    token = strtok(linha, TOK_DELIM);
    while(token != NULL){
        if (token[0] == '#'){
            break;
        }
        tokens[i] = token;
        i++;
        if (i >= buff){
            buff += buff;
            tokens = realloc(tokens, buff * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "Erro de realocação em dividir_linha\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, TOK_DELIM);
    }
    tokens[i] = NULL;
    return tokens;

}