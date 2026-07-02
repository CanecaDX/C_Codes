#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

int main(){
	
	grafo *graf = NULL;
	int chave = 0, op = 1;
	char nome[256];
	
	while(op != 0){
			printf("\n------------------------------------");
			printf("\n0_ Encerra programa.");
			printf("\n1_ Criar grafo.");
			printf("\n2_ Vizualizar grafo.");
			printf("\n3_ Busca por profundidade.");
			printf("\n4_ Busca por amplitude.");
			printf("\n------------------------------------");
			printf("\nInforme a ação desejada: ");
			scanf("%d", &op);

			switch(op){
				case 0:
					printf("Programa encerrado.");
					break;
				case 1:
					printf("\nInsira o nome do arquivo: ");
					scanf(" %255[^\n]", nome);
					graf = parser(nome);
					break;
				case 2:
					imprimeGrafo(graf);
					break;
				case 3:
					int n = graf->max_vertices;
					int *visitado = calloc(n + 1, sizeof(int));
					printf("Insira a chave que deseja buscar: ");
					scanf("%d", &chave);
					printf("\nPROFUNDIDADE\n");
					buscaProfundidade(graf, chave, visitado);
					free(visitado);
					break;
				case 4:
					int n2 = graf->max_vertices;
					int *visitado2 = calloc(n2 + 1, sizeof(int));
					printf("Insira a chave que deseja buscar: ");
					scanf("%d", &chave);
					printf("\nAMPLITUDE\n");
					buscaAmplitude(graf, chave, visitado2);
					free(visitado2);
					break;
			}
		}
	
	return 0;	
}



