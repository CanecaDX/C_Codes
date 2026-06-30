#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

descritorTree *alocaDesc(void){
 descritorTree *myTree;
 myTree = (descritorTree*)malloc(sizeof(descritorTree));
 myTree->tamanho = 0;
 myTree->raiz = NULL;
 return myTree;	
}

nodo *criaNodo(int chave){
	nodo *novoNodo;
	novoNodo = (nodo*) malloc(sizeof(nodo));
	novoNodo->chave = chave;
	novoNodo->esquerdo=NULL;
	novoNodo->direito=NULL;
	novoNodo->pai=NULL;	
	return novoNodo;
}

nodo *insereNodo(nodo *atual, nodo *novoNodo, nodo *pai){
	if(atual == NULL){
		novoNodo->pai = pai;
		return novoNodo;
	}
	if(novoNodo->chave  > atual->chave)
		atual->direito = insereNodo(atual->direito, novoNodo, atual);
	else
		atual->esquerdo = insereNodo(atual->esquerdo,novoNodo, atual);
	return atual;	
}

nodo *removeNodo(nodo *atual, int chave){ //quatro casos: sem filhos, um filho(direito ou esquerdo) e dois filhos
	
	if(atual == NULL)
		 return NULL;
		 
	if(atual->chave == chave){
		printf("\nNodo encontrado!");
		
		if((atual->direito == NULL) && (atual->esquerdo == NULL)){ //folha
			printf(" (Removendo nó folha)\n");
			free(atual);
			return NULL;
		}	
		else{
			if(atual->direito == NULL){ //apenas filho esquerdo
				printf(" (Removendo nó com 1 filho (esquerdo))\n");
				nodo *temp = atual->esquerdo;
				atual->esquerdo->pai = atual->pai;
				free(atual);
				return temp;
			}
			else if(atual->esquerdo == NULL){ //apenas filho direito
				printf(" (Removendo nó com 1 filho (direito))\n");
				//nodo *temp = atual->direito;
				atual->direito->pai = atual->pai;
				atual->pai->direito = atual->direito;
				return atual;
			}
			else if((atual->direito != NULL) && (atual->esquerdo != NULL)){ //dois filhos (achar sucessor)
				printf(" (Removendo nó com 2 filhos)\n");
				nodo *sucessor = atual->direito;
				while(sucessor->esquerdo != NULL){
					sucessor = sucessor->esquerdo;
				}
				atual->chave = sucessor->chave;
				atual->direito = removeNodo(atual->direito, sucessor->chave);
				if(atual->direito != NULL)
					  atual->direito->pai = atual;
			}
		}
		return atual;	
	}
	 else{
		if(chave > atual->chave)
				atual->direito = removeNodo(atual->direito, chave);
		else
				atual->esquerdo = removeNodo(atual->esquerdo, chave);
	 }
	return atual;
}

void *Inorder(nodo *raiz){
	if(raiz != NULL){
		Inorder(raiz->esquerdo);
		printf("%d ", raiz->chave);
		Inorder(raiz->direito);
	}
}

void *Preorder(nodo *raiz){
	if(raiz != NULL){
		printf("%d ", raiz->chave);
		Preorder(raiz->esquerdo);
		Preorder(raiz->direito);
	}
}

void *Posorder(nodo *raiz){
	if(raiz != NULL){
		Posorder(raiz->esquerdo);
		Posorder(raiz->direito);
		printf("%d ", raiz->chave);
	}
}
