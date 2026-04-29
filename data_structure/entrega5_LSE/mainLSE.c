#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrega5_LSE.h"

int main(){
	
	descritor *lista = NULL;
	nodo *elemento = NULL;
	nodo *rem = NULL;
	int pos, op = 1;
	char nome[256];
	
	while(op != 0){
		printf("\n------------------------------------");
		printf("\n0_ Encerra programa.");
		printf("\n1_ Criar nova lista.");
		printf("\n2_ Inserir nova música.");
		printf("\n3_ Vizualziar lista.");
		printf("\n4_ Modificar uma música.");
		printf("\n5_ Buscar música.");
		printf("\n6_ Remover música.");
		printf("\n------------------------------------");
		printf("\nInforme a ação desejada: ");
		scanf("%d", &op);

		switch(op){
			case 0:
				printf("Programa encerrado.");
				free(lista);
				free(elemento);
				break;
			case 1:
				lista = criaDesc();
				printf("Lista criada!");
				break;
			case 2:
				if(lista == NULL){
					printf("Lista não existe!");
					return 1;
				}
				elemento = criaNodo();
				printf("Que posicao deseja inserir na lista? ");
				setbuf(stdin, NULL);
				scanf("%d", &pos);
				insere(lista, elemento, pos);
				printf("Música inserida na lista.");
				break;
			case 3:
				if(lista->tamanho == 0){
					printf("A lista está vazia!");
					break;
				}
				exibeLista(lista);
				break;
			case 4:
				printf("Insira a posicao do elemento que deseja modificar: ");
				setbuf(stdin, NULL);
				scanf("%d", &pos);
				set(lista, pos);
				break;
			case 5:
				int bus = 0;
				printf("\n1_Nome");
				printf("\n2_Artista");
				printf("\n3_Código");
				printf("\n4_Posicao");
				printf("\nDe que forma deseja realizar a busca? ");
				setbuf(stdin, NULL);
				scanf("%d", &bus);
				switch(bus){
					case 1:
							printf("\nInsira o nome da musica que deseja buscar: ");
							setbuf(stdin, NULL);
							scanf(" %[^\n]", nome);
							rem = buscaNome(lista, nome, bus);
							
							if(rem == NULL){
								break;
							}
							
							printf("\nMúsica com o nome solicitada: ");
							printf("\n |Música:    [%s]", rem->info->titulo);
							printf("\n |Artista:   [%s]", rem->info->artista);
							printf("\n |Código:    [%d]", rem->info->codigo);
							printf("\n |Execuções: [%d]", rem->info->execucoes);
						break;
					case 2:
							printf("Insira o nome do artista que deseja buscar: ");
							setbuf(stdin, NULL);;
							scanf(" %[^\n]", nome);
							buscaNome(lista, nome, bus);
						break;
					case 3:
							printf("Insira o código do artista que deseja buscar: ");
							setbuf(stdin, NULL);
							scanf("%d", &pos);
							rem = buscaCod(lista, pos);	
							
							if(rem == NULL){
								break;
							}
							printf("\nMúsica com o codigo solicitado: ");
							printf("\n |Música:    [%s]", rem->info->titulo);
							printf("\n |Artista:   [%s]", rem->info->artista);
							printf("\n |Código:    [%d]", rem->info->codigo);
							printf("\n |Execuções: [%d]", rem->info->execucoes);

						break;
					case 4:
							printf("Insira a posicao do elemento que deseja buscar: ");
							setbuf(stdin, NULL);
							scanf("%d", &pos);
							rem = get(lista, pos);
							
							if(rem == NULL){
								break;
							}
							printf("\nMúsica da posição solicitada: ");
							printf("\n |Música:    [%s]", rem->info->titulo);
							printf("\n |Artista:   [%s]", rem->info->artista);
							printf("\n |Código:    [%d]", rem->info->codigo);
							printf("\n |Execuções: [%d]", rem->info->execucoes);
						break;
				}
				break;
			case 6:
				printf("Insira a posicao que deseja remover da lista: ");
				setbuf(stdin, NULL);
				scanf("%d", &pos);
				rem = remover(lista, pos);
				
				printf("\nDado removido: ");
				printf("\n |Música:    [%s]", rem->info->titulo);
				printf("\n |Artista:   [%s]", rem->info->artista);
				printf("\n |Código:    [%d]", rem->info->codigo);
				printf("\n |Execuções: [%d]", rem->info->execucoes);
		}
	}
	
	return 0;	
}
