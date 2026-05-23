#include <stdlib.h>
#include <stdio.h>
#include "musica.h"

typedef struct nodoF{
	musica *info;
	struct nodoF *prox;
}nodoF;

typedef struct descritorF{
	nodoF *head;
	nodoF *tail;
	int tamanho;
}descritorF;

descritorF *criaDescF(void);
nodoF *criaNodoF(void);
void enqueue(descritorF *fila, nodoF *novoE);
nodoF *dequeue(descritorF *fila);
int emptyF(descritorF *fila);
void imprimeF(descritorF *fila);
void deletarF(descritorF *fila);
int lenghtF(descritorF *fila);

