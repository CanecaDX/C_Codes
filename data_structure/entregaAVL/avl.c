#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

descritorAVL *alocaDesc(void){
 descritorAVL *avlTree;
 avlTree = (descritorAVL*)malloc(sizeof(descritorAVL));
 avlTree->altura = 0;
 avlTree->raiz = NULL;
 return avlTree;	
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
		printf("\nInserção concluída! (pai)");

	}
	if(novoNodo->chave  > atual->chave){
		novoNodo->rot--;
		atual->direito = insereNodo(atual->direito, novoNodo, atual);
		printf("\nInserção concluída!");

	}
	else{
		novoNodo->rot++;
		atual->esquerdo = insereNodo(atual->esquerdo,novoNodo, atual);
		printf("\nInserção concluída!");

	}
	
	return atual;	
}

nodo *balanceamento(nodo *raiz){
	nodo *aux = NULL, *aux2 = NULL;
	
	if(raiz != NULL){
		raiz->esquerdo = balanceamento(raiz->esquerdo);
		raiz->direito = balanceamento(raiz->direito);
		if((raiz->rot == 2) || (raiz->rot == -2)){
			printf("Pre order: ");
			Preorder(raiz);
			
			if((raiz->rot>0)&&(raiz->esquerdo->rot>0)){ //rot_dir
				if(raiz->pai != NULL)
					raiz->pai->rot--;
				printf("Rotação a direita do nó %d\n", raiz->chave);
				aux = raiz->direito;
				raiz->esquerdo = aux->direito;
				if(aux->direito != NULL)
					aux->direito->pai = raiz;
				aux->direito = raiz;
				aux->pai = raiz->pai;
				raiz->rot = 0;
				raiz = aux;
			}
		}
	}
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
