#include <stdio.h>
#include <stdlib.h>
#include "LCE.h"

descritor *criaDescC(void){
	
	descritor *novoDesc = (descritor*)malloc (sizeof(descritor));	
	novoDesc->tam = 0;
	novoDesc->inicio = NULL;

	return novoDesc;	
	
}

nodo *criaNodo(int Ndado){
	
	nodo *novoN = (nodo*)malloc (sizeof(nodo));
	novoN->prox = NULL;
	novoN->dado = Ndado;
	
	return novoN;
}

void insere(descritor *lista, nodo *novoN , int pos){
	
	if(lista == NULL){
		printf("\nA lista não existe.");
	}
	else{
			//insere no incio
			if(lista->inicio == NULL || pos == 0){
				novoN->prox = lista->inicio;
				lista->inicio = novoN;
			
			
				if(novoN->prox == NULL){
					novoN->prox = novoN;
				}
				else{
					//atualizar o último para apontar para o novo início
					nodo *aux = lista->inicio;
					while(aux->prox != lista->inicio){ 
						aux = aux->prox;
					}
					aux->prox = novoN;
				}
				lista->tam++;
			}else{
			
				nodo *aux = lista->inicio;
				int cont = 0;
				
				if(lista->tam < pos){ //insere no final se a posicao for inválida
					while(aux->prox != lista->inicio){
						aux = aux->prox;
					}
				aux->prox = novoN;
				novoN->prox = lista->inicio;
				lista->tam++;
				}
				
				else{ //busca e insere na posicao
					
					nodo *ant;
					
					while(aux != NULL){
						ant = aux;
						aux = aux->prox;
						cont++;
						
						if(pos == cont){
							novoN->prox = aux;
							ant->prox = novoN;
							lista->tam++;
						}
					}		
				}
		  }
	}
}
	
void exibe(descritor *lista){
	nodo* aux = lista->inicio;
	int cont = lista->tam;
	
	printf("Teste");
	printf("\n");
	printf("Dados: ");
	while(cont != 0){
		printf("[%d] --> ", aux->dado);
		cont--;
		aux = aux->prox;
	}
}
