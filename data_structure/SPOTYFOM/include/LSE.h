#ifndef LSE_H
#define LSE_H

#include <stdio.h>
#include <stdlib.h>
#include "musica.h"

typedef struct nodoS{
	struct nodoS *prox;
	musica *info;
} nodoS;

typedef struct descritorS{
	nodoS *inicio;
	int tamanho;
} descritorS;

descritorS *criaDescS(void);
nodoS *criaNodoS(musica *mus);
void insereS(descritorS *lista, nodoS *novaM, int pos);
nodoS *removerS(descritorS *lista, int pos);
void exibeListaS(descritorS *lista);
nodoS *getS(descritorS *lista, int pos);
nodoS *setS(descritorS *lista, int pos);
nodoS *buscaNomeS(descritorS *lista, char nomeB[256], int op);
nodoS *buscaCodS(descritorS *lista, int cod);

#endif
