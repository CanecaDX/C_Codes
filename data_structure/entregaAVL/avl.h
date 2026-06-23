#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int chave;
	int rot;
	struct nodo *pai;
	struct nodo *esquerdo;
	struct nodo *direito;
}nodo;


typedef struct{
	int altura;
	nodo *raiz;
}descritorAVL;

descritorAVL *alocaDesc(void);
nodo *criaNodo(int chave);
nodo *insereNodo(nodo *atual, nodo *novoNodo, nodo *pai);
nodo *removeChave(nodo *atual, int chave);
int Maior(int a, int b);
int altura(nodo *raiz);
nodo *balanceamento(nodo *raiz);
void *Inorder(nodo *raiz);
void *Preorder(nodo *raiz);
void *Posorder(nodo *raiz);
