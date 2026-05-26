#ifndef pilha_H
#define pilha_H

#include <stdlib.h>
#include <stdio.h>
#include "musica.h"

typedef struct nodoP{
	musica *info;
	struct nodoP *prox;
}nodoP;

typedef struct descritorP{
	struct nodoP *top;
	int tamanho;
}descritorP;

descritorP *criaDescP(void);
nodoP *criaNodoP(void);
void push(descritorP *pilha, nodoP *novoE);
nodoP *pop(descritorP *pilha);
int emptyP(descritorP *pilha);
void imprimeP(descritorP *pilha);
nodoP *top(descritorP *pilha);

#endif
