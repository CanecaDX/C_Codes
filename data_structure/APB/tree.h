#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int chave;
	struct nodo *pai;
	struct nodo *esquerdo;
	struct nodo *direito;
}nodo;


typedef struct{
	int tamanho;
	nodo *raiz;
}descritorTree;

descritorAVL *alocaDesc(void);
nodo *criaNodo(int chave);
nodo *insereNodo(nodo *atual, nodo *novoNodo, nodo *pai);
void *Inorder(nodo *raiz);
void *Preorder(nodo *raiz);
void *Posorder(nodo *raiz);
