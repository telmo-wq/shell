#include "shell.h"


int batch(char *argv){
    FILE *arquivo;
    arquivo = fopen(argv, "r");
    char comando[100];

    while (fgets(comando, 100, arquivo) != NULL){
        comando[strcspn(comando, "\n")] = '\0';
        printf("%s\n", comando);

    }
    rewind(arquivo);

    while(fgets(comando, 100, arquivo) !=NULL){
        comando[strcspn(comando, "\n")] = '\0';
        if (strcmp(comando, "exit") == 0){
            break;
        }
        char **args_comando = dividir_linha(comando);
        int status = executar_args(args_comando);

        return status;
    }
    fclose(arquivo);

}