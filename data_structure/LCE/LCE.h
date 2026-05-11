#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dado;
	struct nodo *prox;
}nodo;

typedef struct descritor{
	nodo *inicio;
	int tam;
}descritor;

descritor *criaDescC(void);
nodo *criaNodo(int Ndado);
void insere(descritor *lista, nodo *Ndado, int pos);
void exibe(descritor *lista);

