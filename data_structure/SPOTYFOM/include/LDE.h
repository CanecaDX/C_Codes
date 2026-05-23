#include <stdio.h>
#include <stdlib.h>
#include "musica.h"

typedef struct nodoD{
	struct nodoD *prox;
	struct nodoD *ant;
	musica *info;
} nodoD;

typedef struct{
	nodo *inicio;
	nodo *fim;
	int tamanho;
} descritorD;

descritorD *criaDescD(void);
nodoD *criaNodoD(void);
void insereD(descritor *lista, nodo *novaM, int pos);
nodoD *removerD(descritor *lista, int pos);
void exibeListaD(descritor *lista);
nodoD *getD(descritor *lista, int pos);
nodoD *setD(descritor *lista, int pos);
nodoD *buscaNomeD(descritor *lista, char nome[256], int op);
nodoD *buscaCodD(descritor *lista, int cod);
