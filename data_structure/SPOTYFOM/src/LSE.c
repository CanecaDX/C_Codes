#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LSE.h"

descritorS *criaDescS(void){
	
	descritorS *novoDesc = (descritorS*)malloc (sizeof(descritorS));
	novoDesc->tamanho = 0;
	novoDesc->inicio = NULL;
	
	return novoDesc;			
}

nodoS *criaNodoS(musica *song){
		
	nodoS *novaMusica = (nodoS*)malloc (sizeof(nodoS));
	novaMusica->prox = NULL;
	novaMusica->info = song;
	
	return novaMusica;
}

void insereS(descritorS *lista, nodoS *novaM, int pos){
	//inicio
	if((lista->inicio == NULL) || (pos == 0)){
		novaM->prox = lista->inicio;
		lista->inicio = novaM;
		//novaM->prox = NULL;	
		
		lista->tamanho++;
	} //fim ou meio
	else{
		nodoS *aux = lista->inicio;
		int cont = 0;
		
		if(lista->tamanho < pos){ //insere no final se a posicao for inválida
			while(aux->prox != NULL){
				aux = aux->prox;
			}
			aux->prox = novaM;
			lista->tamanho++;
		}
		else{ //procura posicao e insere
			nodoS *ant = NULL;
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
nodoS *removerS(descritorS *lista, int pos){
	
	if((lista->tamanho == 0) || (pos > lista->tamanho)){
		printf("\nPosicao não existe ou a lista está vazia!");
		return NULL;
	}
	else{//inicio
		if(pos == 0){
			nodoS *aux = lista->inicio;

			lista->inicio = lista->inicio->prox;
			lista->tamanho--;
			return aux;
		}//meio ou fim
		else{
			
			int cont = 0;
			nodoS *ant;
			nodoS *aux = lista->inicio;
			
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

void exibeListaS(descritorS *lista){
	nodoS *aux = lista->inicio;
	
	printf("\n");
	while(aux != NULL){
		printf("\n |Música:    [%s]", aux->info->titulo);
		printf("\n |Artista:   [%s]", aux->info->artista);
		printf("\n |Letra da música: [%s]", aux->info->letra);
		printf("\n |Código:    [%d]", aux->info->codigo);
		//printf("\n |Execuções: [%d]", aux->info->execucoes);
		
		printf("\n");
		aux = aux->prox;
	}
	printf("\n");
}

nodoS *getS(descritorS *lista, int pos){
	
	if((lista->tamanho == 0) || pos > (lista->tamanho)){
		printf("\nPosicao não existe ou a lista está vazia!");	
		return NULL;
	}
	else{
		nodoS *get = lista->inicio;
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

nodoS *setS(descritorS *lista, int pos){
	
	if((lista->tamanho == 0) || pos > (lista->tamanho)){
		printf("\nPosicao não existe ou a lista está vazia!");	
		return NULL;
	}
	
	nodoS *mod = NULL;
	mod = getS(lista, pos);
	
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
	//~ printf("Execuções: ");
	//~ scanf("%d", &mod->info->execucoes);
}

void converteMinuscula(char str[256]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

nodoS *buscaNomeS(descritorS *lista, char nome[256], int op){
	
	char minuscula[256];
	strcpy(minuscula, nome);
	converteMinuscula(minuscula);
	
	if(lista->tamanho == 0){
		printf("\nA lista está vazia!");	
		return NULL;
	}
	else{
		nodoS *aux = lista->inicio;
		
		if(op == 1){
				while(aux != NULL){
					char tituloMin[256];
					strcpy(tituloMin, aux->info->titulo);
					converteMinuscula(tituloMin);
					if(strcmp(minuscula, tituloMin) == 0){
						return aux;
					}
					aux = aux-> prox;
				}
					printf("\nNenhuma musica encontrada! ");
					return NULL;
		}
		else if(op == 2){
				nodoS *aux = lista->inicio;
				int encontrou = 0;
				
				while(aux != NULL){
					char artistaMin[256];
					strcpy(artistaMin, aux->info->artista);
					converteMinuscula(artistaMin);
					if(strcmp(minuscula, artistaMin) == 0){	
						printf("\n");
						printf("\n |Música:    [%s]", aux->info->titulo);
						printf("\n |Artista:   [%s]", aux->info->artista);
						printf("\n |Letra da música: [%s]", aux->info->letra);
						printf("\n |Código:    [%d]", aux->info->codigo);
						//printf("\n |Execuções: [%d]", aux->info->execucoes);
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

nodoS *buscaCodS(descritorS *lista, int cod){
	
	if(lista->tamanho == 0){
		printf("\nA lista está vazia!");	
		return NULL;
	}
	else{
		nodoS *get = lista->inicio;
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

