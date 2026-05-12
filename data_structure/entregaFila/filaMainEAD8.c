// Atividade EAD 8 - FIla Músicas
// Leonardo Manzke - leonardomanzke.aluno@unipampa.edu.br

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main(){
	
	descritorF *fila = NULL;
	nodoF *elemento = NULL;
	nodoF *rem = NULL;
	int op = 1, t = 0;
	
	while(op != 0){
		printf("\n------------------------------------");
		printf("\n0_ Encerra programa.");
		printf("\n1_ Criar nova fila.");
		printf("\n2_ Inserir nova música na fila (ENQUEUE).");
		printf("\n3_ Remover música da fila (DEQUEUE).");
		printf("\n4_ Vizualziar fila.");
		printf("\n5_ Delete fila.");
		printf("\n6_ Vizualizar tamanho da fila.");
		printf("\n------------------------------------");
		printf("\nInforme a ação desejada: ");
		scanf("%d", &op);

		switch(op){
			case 0:
				printf("Programa encerrado.");
				free(fila);
				free(elemento);
				break;
			case 1:
				fila = criaDesc();
				printf("Fila criada!");
				break;
			case 2:
				if(fila == NULL){
					printf("Fila não existe!");
					break;
				}
				elemento = criaNodo();
				enqueue(fila, elemento);
				printf("\nMúsica inserida na fila.");
				break;
			case 3:
				if(fila->tamanho == 0){
					printf("A fila está vazia!");
					break;
				}
				rem = dequeue(fila);
					
				printf("\nDado removido: ");
				printf("\n |Música:    [%s]", rem->info->titulo);
				printf("\n |Artista:   [%s]", rem->info->artista);
				printf("\n |Letra da música: [%s]", rem->info->letra);
				printf("\n |Código:    [%d]", rem->info->codigo);
				printf("\n |Execuções: [%d]", rem->info->execucoes);
				printf("\n");
				
				break;
			case 4:
			
				if(fila == NULL){
					printf("A fila nao foi criada!");
					break;
				}
				if(fila->head == NULL){
					printf("Nenhum elemento na fila!");
					break;
				}
			
				imprime(fila);
				break;
			case 5:
				if(fila == NULL){
					printf("A fila nao foi criada!");
					break;
				}
				
				deletar(fila);
				printf("Fila deletada.");
				break;
			case 6:
				t = lenght(fila);
				
				printf("Quantidade de elementos na fila: %d", t);
				break;
		}
	}
	
	return 0;	
}


