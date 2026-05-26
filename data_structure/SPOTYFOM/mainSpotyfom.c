#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LDE.h"
#include "LSE.h"
#include "fila.h"
#include "pilha.h"
#include "parser.h"
#include "musica.h"

int main(){
	
	//descritores
	descritorS *listaSE = NULL;
	descritorF *fila = NULL;
	
	int op = 1, pos = 0;
	char nome[256];
	nodoS *rem = NULL;
	
	while(op != 0){
		printf("\n");
		printf("\n------------------------------------");
		printf("\n--------------SPOTYFOM--------------");
		printf("\n------------------------------------");
		printf("\n0_ Encerra programa.");
		printf("\n1_ Carregar acervo.");		
		printf("\n2_ Criar playlists.");		
		printf("\n3_ Buscar musica.");
		printf("\n4_ Executar uma musica.");
		printf("\n5_ Impressao de informaçoes de uma musica.");
		printf("\n6_Gerar relatório das playlists.");

		printf("\n------------------------------------");
		printf("\nInforme a ação desejada: ");
		scanf("%d", &op);

		switch(op){
			case 0:
				free(listaSE);
				break;
			case 1:
				listaSE = criaDescS();
				printf("Insira o nome do acervo a ser carregado: ");
				scanf("%s", nome);
				carregaArquivo(nome, listaSE);
				if(listaSE->tamanho == 0){
					printf("A lista está vazia!");
					break;
				}
				//exibeListaS(listaSE);
				break;
			case 2:
				int op2 = 0;
				int qtd_m = 0;
				printf("\n1_Aleatória.");
				printf("\n2_Pessoal.");
				printf("\nDe que forma deseja criar a playlist? ");
				setbuf(stdin, NULL);
				scanf("%d", &op2);
				switch(op2){
					case 1:
							printf("Digite a quantidade de músicas da playlist: ");
							setbuf(stdin, NULL);
							scanf("%d", &qtd_m);
							if(qtd_m > listaSE->tamanho){
								printf("Quantidade inválida!");
								break;	
							}
							fila = randomiza(listaSE, qtd_m);
						break;
					case 2:
						break;
				}
				break;
			case 3:
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
							rem = buscaNomeS(listaSE, nome, bus);
							
							if(rem == NULL){
								break;
							}
							
							printf("\nMúsica com o nome solicitada: ");
							printf("\n |Música:    [%s]", rem->info->titulo);
							printf("\n |Artista:   [%s]", rem->info->artista);
							printf("\n |Letra da música: [%s]", rem->info->letra);
							printf("\n |Código:    [%d]", rem->info->codigo);
							//printf("\n |Execuções: [%d]", rem->info->execucoes);
						break;
					case 2:
							printf("Insira o nome do artista que deseja buscar: ");
							setbuf(stdin, NULL);;
							scanf(" %[^\n]", nome);
							buscaNomeS(listaSE, nome, bus);
						break;
					case 3:
							printf("Insira o código do artista que deseja buscar: ");
							setbuf(stdin, NULL);
							scanf("%d", &pos);
							rem = buscaCodS(listaSE, pos);	
							
							if(rem == NULL){
								break;
							}
							printf("\nMúsica com o codigo solicitado: ");
							printf("\n |Música:    [%s]", rem->info->titulo);
							printf("\n |Artista:   [%s]", rem->info->artista);
							printf("\n |Letra da música: [%s]", rem->info->letra);
							printf("\n |Código:    [%d]", rem->info->codigo);
							//printf("\n |Execuções: [%d]", rem->info->execucoes);
						break;
					case 4:
							printf("Insira a posicao do elemento que deseja buscar: ");
							setbuf(stdin, NULL);
							scanf("%d", &pos);
							rem = getS(listaSE, pos);
							
							if(rem == NULL){
								break;
							}
							printf("\nMúsica da posição solicitada: ");
							printf("\n |Música:    [%s]", rem->info->titulo);
							printf("\n |Artista:   [%s]", rem->info->artista);
							printf("\n |Letra da música: [%s]", rem->info->letra);
							printf("\n |Código:    [%d]", rem->info->codigo);
							//printf("\n |Execuções: [%d]", rem->info->execucoes);
						break;
				}
				break;
			case 4:
				switch(bus){
					case 1:
						break;
					case 2:
						break;
					case 3:

						break;
					case 4:
						break;
				}
				break;
			case 5:
				break;
			case 6:
				if((fila!) || (pilha!)){
					printf("Não existem playlists criadas!");
				}
				int op2 = 0;
				printf("\n1_Aleatória.");
				printf("\n2_Pessoal.");
				printf("\nQual playlist deseja salvar? ");
				setbuf(stdin, NULL);
				scanf("%d", &op2);
					switch(op2){
						case 1:
							salvar_aleat(fila);
							break;
					}	
				break;
		}
	}
	
	return 0;	
}

