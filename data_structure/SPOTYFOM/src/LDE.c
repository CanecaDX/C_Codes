#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LDE.h"

descritorD *criaDescD(void){
	
	descritorD *novoDesc = (descritor*)malloc (sizeof(descritor));
	novoDesc->tamanho = 0;
	novoDesc->inicio = NULL;
	novoDesc->fim = NULL;
	
	return novoDesc;			
}

nodo *criaNodo(void){
		
	nodoD *novaMusica = (nodoD*)malloc (sizeof(nodoD));
	novaMusica->info = (musica*)malloc(sizeof(musica));
	
	printf("Insira o nome da música: ");
	scanf(" %[^\n]", novaMusica->info->titulo);
	printf("Insira o nome do artista: ");
	scanf(" %[^\n]", novaMusica->info->artista);
	printf("Insira a letra da música: ");
	scanf(" %[^\n]", novaMusica->info->letra);
	printf("Insira o codigo da música: ");
	scanf("%d", &novaMusica->info->codigo);
	printf("Insira o número de execuções da música: ");
	scanf("%d", &novaMusica->info->execucoes);

	novaMusica->prox = NULL;
	novaMusica->ant = NULL;
	
	return novaMusica;
}

void insere(descritorD *lista, nodoD *novaM, int pos){
	//inicio
	if((lista->inicio == NULL) || (pos == 0)){
		novaM->prox = lista->inicio;
		
		if(lista->inicio != NULL){
			lista>inicio->ant = novaM;
		}
		lista->inicio = novaM;
		
		if(lista->tamanho = 0)
			lista->fim = novaM;
		
		lista->tamanho++;
		return;
	} //fim ou meio
	else{
		
		int cont = 0;
		
		if(lista->tamanho <= pos){ //insere no final se a posicao for inválida
			nodo *aux = lista->fim;

			aux->prox = novaM;		
			novaM->ant = aux;
			lista->tamanho++;
			lista->fim = novaM;
		}
		else{ //insere no meio
			nodo *aux = lista->inicio;
			while(aux->prox != NULL){
				aux = aux->prox;
				cont++;	
				
				if(cont == pos){
					novaM->prox = aux;
					novaM->ant = aux->ant;
					aux->ant->prox = novaM;
					aux->ant = novaM;
					lista->tamanho++;
				}
			}
		}
	}
}
nodoD *remover(descritorD *lista, int pos){
	
	if((lista->tamanho == 0) || (pos > lista->tamanho)){
		printf("\nPosicao não existe ou a lista está vazia!");
		return NULL; 
	}
	else{//inicio
		nodo *aux = lista->inicio;
		if(pos == 0){
			lista->inicio = aux->prox;
			if(lista->inicio != NULL){
					lista->inicio->ant = NULL;
			}
			if(lista->inicio == NULL){
					lista->fim = NULL;
			}
			lista->tamanho--;
			return aux;
		}//meio ou fim
		else{
			
			int cont = 0;
			nodo *aux = lista->inicio;
			
			while(aux != NULL){
				if(cont == pos){
					aux->ant->prox = aux->prox;
					
					if(aux->prox != NULL){
							aux->prox->ant = aux->ant;
					}
					if(aux->prox == NULL){
						lista->fim = aux->ant;
					}
					lista->tamanho--;
					return aux;
				}
				aux = aux->prox;	
				cont++;
			}
		}
	}
}

void exibeLista(descritorD *lista){
	nodo* aux = lista->inicio;
	
	printf("\n");
	while(aux != NULL){
		printf("\n |Música:    [%s]", aux->info->titulo);
		printf("\n |Artista:   [%s]", aux->info->artista);
		printf("\n |Letra da música: [%s]", aux->info->letra);
		printf("\n |Código:    [%d]", aux->info->codigo);
		printf("\n |Execuções: [%d]", aux->info->execucoes);
		
		printf("\n");
		aux = aux->prox;
	}
	printf("\n");
}

nodoD *get(descritorD *lista, int pos){
	
	if((lista->tamanho == 0) || pos > (lista->tamanho)){
		printf("\nPosicao não existe ou a lista está vazia!");	
		return NULL;
	}
	else{
		nodo *get = lista->inicio;
		int cont = 0;
		
		if(pos == 0){
			get = lista->inicio;
			return get; 
		}
		else{
			while(get->prox != NULL){
				get = get->prox;
				cont++;
				
				if(cont == pos){
					return get;
				}
			}			
				printf("\nNenhuma musica encontrada na posicao! ");
				return NULL;
		}	
	}
}

nodoD *set(descritorD *lista, int pos){
	
	if((lista->tamanho == 0) || pos > (lista->tamanho)){
		printf("\nPosicao não existe ou a lista está vazia!");	
		return NULL;
	}
	
	nodo *mod = NULL;
	mod = get(lista, pos);
	
	if(mod == NULL){
		printf("Algo deu errado.");
		return;
	}
	
	printf("Modifique os dados da música: ");
	printf("\nNome: ");
	scanf(" %[^\n]", mod->info->titulo);
	printf("Artista: ");
	scanf(" %[^\n]", mod->info->artista);
	printf("Letra: ");
	scanf(" %[^\n]", mod->info->letra);
	printf("Código: ");
	scanf("%d", &mod->info->codigo);
	printf("Execuções: ");
	scanf("%d", &mod->info->execucoes);
}

nodoD *buscaNome(descritorD *lista, char nome[256], int op){
	
	if(lista->tamanho == 0){
		printf("\nA lista está vazia!");	
		return NULL;
	}
	else{
		nodo *aux = lista->inicio;
		
		if(op == 1){
				while(aux != NULL){
					if(strcmp(nome, aux->info->titulo) == 0){
						return aux;
					}
					aux = aux-> prox;
				}
					printf("\nNenhuma musica encontrada! ");
					return NULL;
		}
		else if(op == 2){
				nodo *aux = lista->inicio;
				int encontrou = 0;
				
				while(aux != NULL){
					if(strcmp(nome, aux->info->artista) == 0){	
						printf("\n |Música:    [%s]", aux->info->titulo);
						printf("\n |Artista:   [%s]", aux->info->artista);
						printf("\n |Letra da música: [%s]", aux->info->letra);
						printf("\n |Código:    [%d]", aux->info->codigo);
						printf("\n |Execuções: [%d]", aux->info->execucoes);
						encontrou = 1;
					}
					aux = aux-> prox;
			}
				if(!encontrou){
					printf("\nNenhuma musica do artista encontrada! ");
					return NULL;
				}
				else{
					return NULL;	
				}
		}
	}
}

nodoD *buscaCod(descritorD *lista, int cod){
	
	if(lista->tamanho == 0){
		printf("\nA lista está vazia!");	
		return NULL;
	}
	else{
		nodo *get = lista->inicio;
		int encontrado = 0;
		
			while(get != NULL){	
				if(cod == get->info->codigo){
					return get;
				}				
				get = get->prox;
			}
					printf("\nCódigo não encontrado!");
					return NULL;			
	}
}


