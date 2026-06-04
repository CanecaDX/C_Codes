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
	descritorF *fila = NULL; //aleatoria
	descritorP *pilha = NULL; //pessoal
	
	int op = 1, pos = 0;
	char nome[256];
	
	//nodos
	nodoS *rem = NULL;
	nodoF *remF = NULL;
	
	while(op != 0){
		printf("\n");
		printf("\n|------------------------------------|");
		printf("\n|--------------SPOTYFOM--------------|");
		printf("\n|------------------------------------|");
		printf("\n0_ Encerra programa.");
		printf("\n1_ Carregar acervo.");		
		printf("\n2_ Criar playlists.");		
		printf("\n3_ Buscar musica.");
		printf("\n4_ Executar uma playlist.");
		printf("\n5_ Impressão.");
		printf("\n6_Gerar relatórios");

		printf("\n-------------------------------------");
		printf("\nInforme a ação desejada: ");
		scanf("%d", &op);

		switch(op){
			case 0:
				free(listaSE);
				free(fila);
				free(pilha);
				free(rem);
				printf("Encerrando...");
				break;
			case 1:
				printf("\n1_Acervo inicial.");
				printf("\n2_Backup.");
				printf("\nQual tipo de arquivo deseja carregar? ");
				scanf("%d", &op);
				switch(op){
					case 1:
						listaSE = criaDescS();
						printf("\nInsira o nome do acervo a ser carregado: ");
						scanf("%s", nome);
						carregaArquivo(nome, listaSE);
						if(listaSE->tamanho == 0){
						printf("\nA lista está vazia!");
						}
						break;
					case 2:
						listaSE = criaDescS();
						printf("\nInsira o nome do backupt a ser carregado: ");
						scanf("%s", nome);
						carregaBackup(nome, listaSE);
						if(listaSE->tamanho == 0){
						printf("\nA lista está vazia!");
						}
						break;
				}
				break;
			case 2:
				if(listaSE == NULL){
					printf("A lista está vazia ou não existe!");
					break;
				}
				
				printf("\n");
				printf("\n|------------------------------------|");
				printf("\n|--------------PLAYLISTS-------------|");
				printf("\n|------------------------------------|");
				printf("\n1_Aleatória.");
				printf("\n2_Pessoal.");
				printf("\nDe que forma deseja criar a playlist? ");
				setbuf(stdin, NULL);
				scanf("%d", &op);
				switch(op){
					case 1:
						int qtd_m = 0;
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
						int cod = 1;
						exibeListaS(listaSE);
						pilha = criaDescP();
							
						printf("\nDigite 0 para parar de inserir músicas.\n");
						while(cod != 0){
							printf("\nDigite os codigos das músicas que deseja inserir na playlist: ");
							setbuf(stdin, NULL);
							scanf("%d", &cod);
							inserePessoal(&pilha, listaSE, cod);
						}
						printf("\nPlaylist criada!\n");
						imprimeP(pilha);
						break;
				}
				break;
			case 3:
				if(listaSE == NULL){
					printf("A lista está vazia ou não existe!");
					break;
				}
				
				printf("\n|------------------------------------|");
				printf("\n|---------------BUSCAR---------------|");
				printf("\n|------------------------------------|");
				int bus = 0;
				char nomeB[256];
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
						scanf(" %[^\n]", nomeB);
						rem = buscaNomeS(listaSE, nomeB, bus);
							
						if(rem == NULL){
							break;
						}
							
						printf("\nMúsica com o nome solicitada: ");
						printf("\n |Música:    [%s]", rem->info->titulo);
						printf("\n |Artista:   [%s]", rem->info->artista);
						printf("\n |Letra da música: [%s]", rem->info->letra);
						printf("\n |Código:    [%d]", rem->info->codigo);
						printf("\n |Execuções: [%d]", rem->info->execucoes);
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
						printf("\n |Execuções: [%d]", rem->info->execucoes);
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
						printf("\n |Execuções: [%d]", rem->info->execucoes);
						break;
				}
				break;
			case 4:
				if(listaSE == NULL){
					printf("A lista está vazia ou não existe!");
					break;
				}
				
				printf("\n|------------------------------------|");
				printf("\n|--------------EXECUTAR--------------|");
				printf("\n|------------------------------------|");
				printf("\n1_Aleatória.");
				printf("\n2_Pessoal.");
				printf("\nQual playlist deseja exsecutar? ");
				setbuf(stdin, NULL);
				scanf("%d", &op);
				switch(op){
					case 1:
						if(!fila){
						printf("\nA playlist não existe.");
						break;
						}
						else if(fila->tamanho == 0){
							printf("\nA playlist está vazia!");
							break;
						}
					
						printf("\n1_Uma por uma.");
						printf("\n2_Todas.");
						printf("\nDe que forma deseja executar? ");
						scanf("%d", &op);
						switch(op){
							case 1:
								int cond = 1;
								printf("\ninsira 0 para parar de executar e 1 para continuar executando.\n");
								while(cond != 0){
									printf("\n|: ");
									scanf("%d", &cond); 
									dequeue(fila, listaSE);
								}
								break;
							case 2:
								int tam = 0;
								cond = 0;
								tam = fila->tamanho;
								while(cond < tam){
									dequeue(fila, listaSE);
									cond++;
								}
								break;
						}
						break;
					case 2:
						printf("\n1_Uma por uma.");
						printf("\n2_Todas.");
						printf("\nDe que forma deseja executar? ");
						scanf("%d", &op);
						switch(op){
							case 1:
								if(!pilha){
								printf("\nA playlist não existe.");
								break;
								}
								else if(pilha->tamanho == 0){
									printf("\nA playlist está vazia!");
									break;
								}
								int cond2 = 1;
								printf("\ninsira 0 para parar de executar e 1 para continuar executando.\n");
								while(cond2 != 0){
								printf("\n|: ");
								scanf("%d", &cond2); 
								pop(pilha, listaSE);
								}
								break;
							case 2:
								int tam2 = 0, cond3 = 0;
								tam2 = pilha->tamanho;
								while(cond3 < tam2){
									pop(pilha, listaSE);
									cond3++;
								}
								break;
						}
						break;
				}
				break;
			case 5:
				if(listaSE == NULL){
					printf("A lista está vazia ou não existe!");
					break;
				}
				
				printf("\n|------------------------------------|");
				printf("\n|--------------EXIBIÇÃO--------------|");
				printf("\n|------------------------------------|");
				printf("\n1_Acervo completo.");
				printf("\n2_Playlist aleatoria.");
				printf("\n3_Playlist pessoal.");
				printf("\nO que gostaria de exibir? ");
				scanf("%d", &op);
				switch(op){
					case 1:
						exibeListaS(listaSE);
						break;
					case 2:
						if(!fila){
							printf("\nA playlist não existe.");
							break;
						}
						else if(fila->tamanho == 0){
							printf("\nA playlist está vazia!");
							break;
						}
						imprimeF(fila);
						break;
					case 3:
						if(!pilha){
							printf("\nA playlist não existe.");
							break;
						}
						else if(pilha->tamanho == 0){
							printf("\nA playlist está vazia!");
							break;
						}
						imprimeP(pilha);
						break;
				}
				break;
			case 6:
				if(listaSE == NULL){
					printf("A lista está vazia ou não existe!");
					break;
				}
				
				printf("\n|------------------------------------|");
				printf("\n|-------------RELATÓRIOS-------------|");
				printf("\n|------------------------------------|");
				printf("\n1_Playlist Aleatória.");
				printf("\n2_Playlist Pessoal.");
				printf("\n3_Acervo completo.");
				printf("\nO que deseja salvar? ");
				setbuf(stdin, NULL);
				scanf("%d", &op);
					switch(op){
						case 1:
							if(!fila){
								printf("A playlist não existe");
							break;
							}
							salvar_aleat(fila);
							break;
						case 2:
							if(!pilha){
								printf("A playlist não existe");
							break;
							}
							char nomePlay[256];
								printf("Insira o nome da playlist: ");
								scanf(" %[^\n]", nomePlay);
								salvar_pessoal(pilha, nomePlay);
							break;
						case 3:
							salvar_acervo(listaSE, nome);
							break;
					}	
			}
	}
	return 0;	
}

