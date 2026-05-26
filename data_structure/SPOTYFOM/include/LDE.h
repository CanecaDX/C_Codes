#ifndef LDE_H
#define LDE_H

#include <stdio.h>
#include <stdlib.h>
#include "musica.h"

typedef struct nodoD{
	struct nodoD *prox;
	struct nodoD *ant;
	musica *info;
} nodoD;

typedef struct{
	nodoD *inicio;
	nodoD *fim;
	int tamanho;
} descritorD;

descritorD *criaDescD(void);
nodoD *criaNodoD(void);
void insereD(descritorD *lista, nodoD *novaM, int pos);
nodoD *removerD(descritorD *lista, int pos);
void exibeListaD(descritorD *lista);
nodoD *getD(descritorD *lista, int pos);
nodoD *setD(descritorD *lista, int pos);
nodoD *buscaNomeD(descritorD *lista, char nome[256], int op);
nodoD *buscaCodD(descritorD *lista, int cod);

#endif
