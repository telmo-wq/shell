#include "shell.h"
#include <string.h>


int executar_args(char **args){
    char *lista_builtin[] = {
        "cd",
        "env",
        "help",
        "exit"
    };
    int (*builtin_func[])(char **) = {
        &own_cd,
        &own_env,
        &own_help,
        &own_exit
    };
    int i = 0;

    if (args[0] == NULL){
        return -1;
    }
    for (; i < sizeof(lista_builtin) / sizeof(char *); i++){
        if (strcmp(args[0], lista_builtin[i]) == 0){
            return ((*builtin_func[i])(args));
        }
    }
    return (novo_processo(args));

}