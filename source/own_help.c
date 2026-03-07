#include "shell.h"


int own_help(char **args){
    char *lista_builtin_func[] = {
        "cd",
        "env",
        "help",
        "exit"
    };
    long unsigned int i = 0;

    (void)(**args);

    printf("\n ----- help shell -----\n");
    printf("Digite um comando e seus argumentos, então dê enter\n");
    printf("Comandos builtin:\n");
    for (; i < sizeof(lista_builtin_func) / sizeof(char *); i++){
        printf(" -> %s\n", lista_builtin_func[i]);
    }
    printf("Use o comando principal para informações sobre outros programas\n");
    return (-1);

}