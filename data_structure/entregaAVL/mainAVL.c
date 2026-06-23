#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(){
	
descritorAVL *avlTree = NULL;
nodo *novo = NULL;
nodo *rem = NULL;
int chave = 0, op = 1;

while(op != 0){
		printf("\n------------------------------------");
		printf("\n0_ Encerra programa.");
		printf("\n1_ Criar arvore.");
		printf("\n2_ Inserir no.");
		printf("\n3_ Remover no.");
		printf("\n4_ Vizualziar arvore.");
		printf("\n------------------------------------");
		printf("\nInforme a ação desejada: ");
		scanf("%d", &op);

		switch(op){
			case 0:
				printf("Encerrando...");
				break;
			case 1:
				avlTree = alocaDesc();
				printf("\nAVL criada!");
				break;
			case 2:
				if(avlTree == NULL){
					printf("\nA árvore não existe!");
					break;
				}
				
				printf("\nInsira a chave para inserir na arvore: ");
				scanf("%d", &chave);
				novo = criaNodo(chave);
				avlTree->raiz = insereNodo(avlTree->raiz,novo, NULL);
				avlTree->raiz = balanceamento(avlTree->raiz);
				printf("\nValor adicionado com sucesso");
				break;
			case 3:
				if(avlTree == NULL){
					printf("\nA árvore não existe!");
					break;
				}
				else if(avlTree->raiz == NULL){
					printf("\nA árvore está vazia!");
					break;
				}
			
				printf("\nInsira a chave que deseja remover da arvore: ");
				scanf("%d", &chave);
				avlTree->raiz = removeChave(avlTree->raiz, chave);
				printf("\nChave removida: %d", chave);
				printf("\nPre order: ");
				Preorder(avlTree->raiz);
				break;
			case 4:
				if(avlTree == NULL){
					printf("\nA árvore não existe!");
					break;
				}
				else if(avlTree->raiz == NULL){
					printf("\nA árvore está vazia!");
					break;
				}
			
				int op2 = 1;
				printf("\n1_ In Order.");
				printf("\n2_ Pre Order.");
				printf("\n3_ Pos Order.");
				printf("\nQual percurso deseja utilizar? ");
				scanf("%d", &op2);
				switch(op2){
					case 1:	
						Inorder(avlTree->raiz);
						break;
					case 2:
						Preorder(avlTree->raiz);
						break;
					case 3:
						Posorder(avlTree->raiz);
						break;
				}
				break;
		}
	}

return 0;	
}
