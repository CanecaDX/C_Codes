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
	novoNodo = calloc(1, sizeof(nodo));
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
	else{
			if(novoNodo->chave  > atual->chave){
				atual->direito = insereNodo(atual->direito, novoNodo, atual);
			}
			else{
				atual->esquerdo = insereNodo(atual->esquerdo,novoNodo, atual);
			}
	}
	return atual;	
}

nodo *removeChave(nodo *atual, int chave){
	
	if(atual == NULL)
		return NULL;
	
	if(atual->chave == chave){
		printf("\nChave encontrada!");
		if((atual->direito == NULL) && (atual->esquerdo == NULL)){ //folha
			printf(" (Sem filhos (folha))\n");
			free(atual);
			return NULL;
		}
		else{
			if(atual->direito == NULL){ //apenas filho esquerdo
				printf(" (Apenas filho esquerdo\n)");
				nodo *temp = atual->esquerdo;
				temp->pai = atual->pai;
				free(atual);
				return temp;
			}
			else if(atual->esquerdo == NULL){ //apenas filho direito
				printf(" (Apenas filho direito\n)");
				nodo *temp = atual->direito;
				temp->pai = atual->pai;
				free(atual);
				return temp;
			}	
			else if((atual->direito != NULL) && (atual->esquerdo != NULL)){ //dois filhos
				printf(" (Removendo nó com 2 filhos)\n");
                
                // encontra o sucessor
                nodo *sucessor = atual->direito;
                while(sucessor->esquerdo != NULL){
                    sucessor = sucessor->esquerdo;
                }
                
                //substitui a chave
                atual->chave = sucessor->chave;
                
                //remove o sucessor recursivamente
                atual->direito = removeChave(atual->direito, sucessor->chave);
                if(atual->direito != NULL)
                    atual->direito->pai = atual;
			}
		}
		atual = balanceamento(atual); 
		return atual;
	}
	else{
		if(chave > atual->chave){
			atual->direito = removeChave(atual->direito, chave);
		}
		else{
			atual->esquerdo = removeChave(atual->esquerdo, chave);
		}	
	}
	atual = balanceamento(atual); 
	return atual;
}

int Maior(int a, int b){
    return (a>b) ? a : b;
}

int altura(nodo *raiz){
   if(raiz == NULL){
        return 0;
   }
   else{
        return 1 + Maior(altura(raiz->esquerdo), altura(raiz->direito));
    }
}

nodo *balanceamento(nodo *raiz){
	nodo *aux = NULL, *aux2 = NULL;
	
	if(raiz != NULL){
		raiz->esquerdo = balanceamento(raiz->esquerdo);
		raiz->direito = balanceamento(raiz->direito);
		raiz->rot = altura(raiz->esquerdo) - altura(raiz->direito);
		if((raiz->rot == 2) || (raiz->rot == -2)){
			printf("\nPre order: ");
			Preorder(raiz);
			
			if((raiz->rot > 0) && (raiz->esquerdo->rot > 0)){ //rot_dir
				if(raiz->pai != NULL)
					raiz->pai->rot--;
				printf("\nRotação a direita do nó %d\n", raiz->chave);
				aux = raiz->esquerdo;
				raiz->esquerdo = aux->direito;
				if(aux->direito != NULL)
					aux->direito->pai = raiz;
				aux->direito = raiz;
				aux->pai = raiz->pai;
				raiz->pai = aux;
				raiz = aux;
				raiz->rot = altura(raiz->esquerdo) - altura(raiz->direito);
			}
			else{
				if((raiz->rot < 0) && (raiz->direito->rot < 0)){ //rot_esq
					if(raiz->pai != NULL)
						raiz->pai->rot--;
					printf("\nRotação a esquerda do nó %d\n", raiz->chave);
					aux = raiz->direito;
					raiz->direito = aux->esquerdo;
					if(aux->esquerdo != NULL)
						aux->esquerdo->pai = raiz;
					aux->esquerdo = raiz;
					aux->pai = raiz->pai;
					raiz->pai = aux;
					raiz = aux;
					raiz->rot = altura(raiz->esquerdo) - altura(raiz->direito);
				}
				else{
				//falta ajustar os pais
                    if((raiz->rot > 0)&&(raiz->esquerdo->rot < 0)){ //rot_dupla_dir
						if(raiz->pai != NULL)
							raiz->pai->rot--;
						printf("\nRotação dupla a direita do nó %d\n", raiz->chave);
                        aux = raiz->esquerdo;
                        aux2 = aux->direito;
                        aux->direito = aux2->esquerdo;
                        aux2->esquerdo = aux;
                        raiz->esquerdo = aux2->direito;
                        aux2->direito = raiz;
                        if(aux2->rot == -1){
                            raiz->rot = 1;
                        }
                        else{
                            raiz->rot = 0;
                        }
                        if(aux2->rot == 1){
                            aux->rot = -1;
                        }
                        else{
                            aux->rot = 0;
                        }
                        raiz = aux2;
                   }
                   else{
					   if((raiz->rot < 0)&&(raiz->direito->rot > 0)){ //rot_dupla_esq
							if(raiz->pai != NULL)
								raiz->pai->rot++;
							printf("\nRotação dupla a esquerda do nó %d\n", raiz->chave);
                            aux = raiz->direito;
                            aux2 = aux->esquerdo;
                            aux->esquerdo = aux2->direito;
                            aux2->direito = aux;
                            raiz->direito = aux2->esquerdo;
                            aux2->esquerdo = raiz;
                            if(aux2->rot == -1){
                                raiz->rot = 1;
                            }
                            else{
                                raiz->rot = 0;
                            }
                            if(aux2->rot == 1){
                                aux->rot = -1;
                            }
                            else{
                                aux->rot = 0;
                            }
                            raiz = aux2;   
                      }
				   }
				}
			}
		}
		return raiz;
	}
		return NULL;
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
		printf("\n|%d| ", raiz->chave);
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
