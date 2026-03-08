output: batch.o dividir_linha.o executar_args.o ler_fluxo.o ler_linha.o main.o novo_processo.o own_cd.o own_env.o own_exit.o own_help.o shell_interativo.o shell_nao_interativo.o
	gcc batch.o dividir_linha.o executar_args.o ler_fluxo.o ler_linha.o main.o novo_processo.o own_cd.o own_env.o own_exit.o own_help.o shell_interativo.o shell_nao_interativo.o -o output

main.o: source/main.c 
	gcc -c source/main.c 

batch.o: source/batch.c source/shell.h
	gcc -c source/batch.c 

dividir_linha.o: source/dividir_linha.c source/shell.h
	gcc -c source/dividir_linha.c 

executar_args.o: source/executar_args.c source/shell.h
	gcc -c source/executar_args.c 

ler_fluxo.o: source/ler_fluxo.c source/shell.h
	gcc -c source/ler_fluxo.c 

ler_linha.o: source/ler_linha.c source/shell.h
	gcc -c source/ler_linha.c 

own_cd.o: source/own_cd.c source/shell.h
	gcc -c source/own_cd.c 

own_env.o: source/own_env.c source/shell.h
	gcc -c source/own_env.c 

own_exit.o: source/own_exit.c source/shell.h
	gcc -c source/own_exit.c 

own_help.o: source/own_help.c source/shell.h
	gcc -c source/own_help.c 

shell_interativo.o: source/shell_interativo.c source/shell.h
	gcc -c source/shell_interativo.c 

shell_nao_interativo.o: source/shell_nao_interativo.c source/shell.h
	gcc -c source/shell_nao_interativo.c 

novo_processo.o: source/novo_processo.c source/shell.h 
	gcc -c source/novo_processo.c

clean:
	rm *.o output 
	