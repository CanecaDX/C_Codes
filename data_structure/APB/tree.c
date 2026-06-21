#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

descritorAVL *alocaDesc(void){
 descritorAVL *myTree;
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
		Inorder(raiz->esquerdo);
		Inorder(raiz->direito);
	}
}

void *Posorder(nodo *raiz){
	if(raiz != NULL){
		Inorder(raiz->esquerdo);
		Inorder(raiz->direito);
		printf("%d ", raiz->chave);
	}
}
