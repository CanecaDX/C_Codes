#include <stdio.h>
#include <stdlib.h>
#include "musica.h"

typedef struct nodoS{
	struct nodo *prox;
	musica *info;
} nodoS;

typedef struct descritorS{
	nodoS *inicio;
	int tamanho;
} descritorS;

descritorS *criaDescS(void);
nodoS *criaNodoS(void);
void insereS(descritor *lista, nodo *novaM, int pos);
nodoS *removerS(descritor *lista, int pos);
void exibeListaS(descritor *lista);
nodoS *getS(descritor *lista, int pos);
nodoS *setS(descritor *lista, int pos);
nodoS *buscaNomeS(descritor *lista, char nome[256], int op);
nodoS *buscaCodS(descritor *lista, int cod);
