#include "shell.h"
#include <unistd.h>


int main(int argc, char *argv[]){
    if (argc > 1){
        batch(argv[1]);
    }

    if (isatty(STDIN_FILENO) == 1){
        shell_interativo(argc, argv);
    }else{
        shell_nao_interativo();
    }

    return (0);


}