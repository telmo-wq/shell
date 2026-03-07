#include "shell.h"


int own_cd(char **args){
    if (args[1] == NULL){
        fprintf(stderr, "argumento esperado para \"cd\"\n");
    }
    else {
        if (chdir(args[1]) != 0){
            perror("error em own_cd.c: mudando dir\n");
        }
    }
    return (-1);
}