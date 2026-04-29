#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrega5_LSE.h"

descritor *criaDesc(void){
	
	descritor *novoDesc = (descritor*)malloc (sizeof(descritor));
	novoDesc->tamanho = 0;
	novoDesc->inicio = NULL;
	
	return novoDesc;			
}

nodo *criaNodo(void){
		
	nodo *novaMusica = (nodo*)malloc (sizeof(nodo));
	novaMusica->info = (musica*)malloc(sizeof(musica));
	
	printf("Insira o nome da música: ");
	scanf(" %[^\n]", novaMusica->info->titulo);
	printf("Insira o nome do artista: ");
	scanf(" %[^\n]", novaMusica->info->artista);
	printf("Insira o codigo da música: ");
	scanf("%d", &novaMusica->info->codigo);
	printf("Insira o número de execuções da música: ");
	scanf("%d", &novaMusica->info->execucoes);

	novaMusica->prox = NULL;
	
	return novaMusica;
}

void insere(descritor *lista, nodo *novaM, int pos){
	//inicio
	if((lista->inicio == NULL) || (pos == 0)){
		novaM->prox = lista->inicio;
		lista->inicio = novaM;
		//novaM->prox = NULL;	
		
		lista->tamanho++;
	} //fim ou meio
	else{
		nodo *aux = lista->inicio;
		int cont = 0;
		
		if(lista->tamanho < pos){ //insere no final se a posicao for inválida
			while(aux->prox != NULL){
				aux = aux->prox;
			}
			aux->prox = novaM;
			lista->tamanho++;
		}
		else{
			nodo *ant;
			while(aux != NULL){
				
				ant = aux;
				aux = aux->prox;
				cont++;	
				
				if(cont == pos){
					novaM->prox = aux;
					ant->prox = novaM;
					lista->tamanho++;
				}
			}
		}
	}
}
nodo *remover(descritor *lista, int pos){
	
	if((lista->tamanho == 0) || (pos > lista->tamanho)){
		printf("\nPosicao não existe ou a lista está vazia!");
		return NULL;
	}
	else{//inicio
		if(pos == 0){
			nodo *aux = lista->inicio;
			aux = lista->inicio;
			lista->inicio = lista->inicio->prox;
			lista->tamanho--;
			return aux;
		}//meio ou fim
		else{
			
			int cont = 0;
			nodo *ant;
			nodo *aux = lista->inicio;
			
			while(aux->prox != NULL){
				ant = aux;
				aux = aux->prox;	
				cont++;
				
				if(cont == pos){
					ant->prox = aux->prox;
					lista->tamanho--;
					return aux;
				}
			}
		}
	}
}

void exibeLista(descritor *lista){
	nodo* aux = lista->inicio;
	
	printf("\n");
	while(aux != NULL){
		printf("\n |Música:    [%s]", aux->info->titulo);
		printf("\n |Artista:   [%s]", aux->info->artista);
		printf("\n |Código:    [%d]", aux->info->codigo);
		printf("\n |Execuções: [%d]", aux->info->execucoes);
		
		printf("\n");
		aux = aux->prox;
	}
	printf("\n");
}

nodo *get(descritor *lista, int pos){
	
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

nodo *set(descritor *lista, int pos){
	
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
	printf("Código: ");
	scanf("%d", &mod->info->codigo);
	printf("Execuções:");
	scanf("%d", &mod->info->execucoes);
}

nodo *buscaNome(descritor *lista, char nome[256], int op){
	
	if(lista->tamanho == 0){
		printf("\nA lista está vazia!");	
		return NULL;
	}
	else{
		nodo *aux = lista->inicio;
		
		if(op == 1){
				while(aux->prox != NULL){
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
				
				while(aux->prox != NULL){
					if(strcmp(nome, aux->info->artista) == 0){	
						printf("\n |Música:    [%s]", aux->info->titulo);
						printf("\n |Artista:   [%s]", aux->info->artista);
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

nodo *buscaCod(descritor *lista, int cod){
	
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

