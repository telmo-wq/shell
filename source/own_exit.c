#include "shell.h"


int own_exit(char **args){
    if (args[1]){
        return (atoi(args[1]));
    }

    else {
        return 0;
    }
}