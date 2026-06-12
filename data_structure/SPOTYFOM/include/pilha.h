#ifndef pilha_H
#define pilha_H

#include <stdlib.h>
#include <stdio.h>
#include "musica.h"
#include "LSE.h"

typedef struct nodoP{
	musica *info;
	struct nodoP *prox;
}nodoP;

typedef struct descritorP{
	struct nodoP *top;
	int tamanho;
}descritorP;

descritorP *criaDescP(void);
nodoP *criaNodoP(musica *song);
void inserePessoal(descritorP *pilha, descritorS *listaSE, int cod);
void push(descritorP *pilha, nodoP *novoE);
nodoP *pop(descritorP *pilha, descritorS *listaSE);
int emptyP(descritorP *pilha);
void imprimeP(descritorP *pilha);
nodoP *top(descritorP *pilha);
void salvar_pessoal(descritorP *pilha, char nome[256]);

#endif
