#include "shell.h"


int own_env(char **args){
    int i = 0;
    (void)(**args);
    extern char **environ;

    while(environ[i]){
        write(STDOUT_FILENO, environ[i], strlen(environ[i]));
        write(STDIN_FILENO, "\n", 1);
        i++;
    }

    return (-1);
}