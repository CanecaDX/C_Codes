#include <stdlib.h>
#include <stdio.h>

typedef struct{
	char titulo[256];
	char artista[256];
	char letra[256];
	int codigo;
	int execucoes;
} musica;

typedef struct nodoP{
	musica *info;
	struct nodoP *prox;
}nodoP;

typedef struct descritorP{
	struct nodoP *top;
	int tamanho;
}descritorP;

descritorP *criaDesc(void);
nodoP *criaNodo(void);
void push(descritorP *pilha, nodoP *novoE);
nodoP *pop(descritorP *pilha);
int vazia(descritorP *pilha);
void imprime(descritorP *pilha);
nodoP *top(descritorP *pilha);
