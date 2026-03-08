#include "shell.h"
#include <unistd.h>


int main(int argc, char *argv[]){
    if (argc > 1){
        if (argc > 2){
            printf("Atenção! Só se pode passar UM arquivo por vez!\n");
            return 0;
        }

        batch(argv[1]);
    }

    if (isatty(STDIN_FILENO) == 1){
        shell_interativo(argc, argv);
    }else{
        shell_nao_interativo();
    }

    return (0);


}