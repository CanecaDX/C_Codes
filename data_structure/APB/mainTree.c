#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
	
descritorTree *tree = NULL;
tree = alocaDesc();
int chave = 0, op = 1, rem = 0;

while(op != 0){
		printf("\n------------------------------------");
		printf("\n0_ Encerra programa.");
		printf("\n1_ Inserir no.");
		printf("\n2_ Remover no.");
		printf("\n3_ Vizualziar arvore (InOrder).");
		printf("\n4_ Vizualziar arvore (PreOrder).");
		printf("\n5_ Vizualziar arvore (PosOrder).");
		printf("\n------------------------------------");
		printf("\nInforme a ação desejada: ");
		scanf("%d", &op);

		switch(op){
			case 0:
				printf("Encerrando...");
				break;
			case 1:
				if(tree == NULL){
					printf("A arvore não existe");
					break;
				}
				
				printf("\nInsira a chave para inserir na arvore: ");
				scanf("%d", &chave);
				nodo *novo = criaNodo(chave);
				tree->raiz = insereNodo(tree->raiz,novo,tree->raiz);
				printf("\nraiz com valor %d\n", tree->raiz->chave);
				break;
			case 2:
				if(tree == NULL){
					printf("A arvore não existe");
					break;
				}
				
				printf("\nInsira a chave para remover da arvore: ");
				scanf("%d", &rem);
				tree->raiz = removeNodo(tree->raiz, rem);
				printf("\nElemento removido: %d\n", rem);
				break;
			case 3:
				if(tree == NULL){
					printf("A arvore não existe");
					break;
				}
				
				Inorder(tree->raiz);
				break;
			case 4:
				if(tree == NULL){
					printf("A arvore não existe");
					break;
				}
				
				Preorder(tree->raiz);
				break;
			case 5:
				if(tree == NULL){
					printf("A arvore não existe");
					break;
				}
				Posorder(tree->raiz);
				break;
		}
	}

return 0;	
}
