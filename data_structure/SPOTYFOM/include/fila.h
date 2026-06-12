#ifndef fila_H
#define fila_H

#include <stdlib.h>
#include <stdio.h>
#include "musica.h"
#include "LSE.h"

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
nodoF *criaNodoF(musica *song);
void randomiza(descritorF *fila, descritorS *listaSE, int qtd_m);
void enqueue(descritorF *fila, nodoF *novoE);
nodoF *dequeue(descritorF *fila, descritorS *listaSE);
int emptyF(descritorF *fila);
void imprimeF(descritorF *fila);
//void deletarF(descritorF *fila);
int lenghtF(descritorF *fila);
void salvar_aleat(descritorF *fila);

#endif
