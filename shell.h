#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void shell_interativo(void);
void shell_nao_interativo(void);

char *ler_linha(void);
char **dividir_linha(char *linha);
int executar_args(char **args);

int novo_processo(char **args);

char *ler_fluxo(void);

int own_cd(char **args);
int own_exit(char **args);
int own_env(char **args);
int own_help(char **args);

void executar_pipe(char **args);
#endif