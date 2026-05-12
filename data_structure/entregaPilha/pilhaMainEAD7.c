// Atividade EAD 7 - Pilha Músicas
// Leonardo Manzke - leonardomanzke.aluno@unipampa.edu.br

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main(){
	
	descritorP *pilha = NULL;
	nodoP *elemento = NULL;
	nodoP *rem = NULL;
	int op = 1, v = 0;
	
	while(op != 0){
		printf("\n------------------------------------");
		printf("\n0_ Encerra programa.");
		printf("\n1_ Criar nova pilha.");
		printf("\n2_ Inserir nova música na pilha (PUSH).");
		printf("\n3_ Remover música da pilha (POP).");
		printf("\n4_ Vizualziar pilha.");
		printf("\n5_ Empty");
		printf("\n------------------------------------");
		printf("\nInforme a ação desejada: ");
		scanf("%d", &op);

		switch(op){
			case 0:
				printf("Programa encerrado.");
				free(pilha);
				free(elemento);
				break;
			case 1:
				pilha = criaDesc();
				printf("Pilha criada!");
				break;
			case 2:
				if(pilha == NULL){
					printf("Pilha não existe!");
					break;
				}
				elemento = criaNodo();
				push(pilha, elemento);
				printf("Música inserida na pilha.");
				break;
			case 3:
				if(pilha->tamanho == 0){
					printf("A pilha está vazia!");
					break;
				}
				rem = pop(pilha);
					
				printf("\nDado removido: ");
				printf("\n |Música:    [%s]", rem->info->titulo);
				printf("\n |Artista:   [%s]", rem->info->artista);
				printf("\n |Letra da música: [%s]", rem->info->letra);
				printf("\n |Código:    [%d]", rem->info->codigo);
				printf("\n |Execuções: [%d]", rem->info->execucoes);
				printf("\n");
				
				break;
			case 4:
				imprime(pilha);
				break;
			case 5:
				if(pilha == NULL){
					printf("A pilha nao foi criada!");
					break;
				}
				
				v = vazia(pilha);
				
				if(v)
					printf("A pilha esta vazia");
					else
					printf("A pilha nao esta vazia");
				break;
		}
	}
	
	return 0;	
}

