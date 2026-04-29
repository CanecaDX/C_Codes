#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char titulo[256];
	char artista[256];
	//char letra[256];
	int codigo;
	int execucoes;
} musica;

typedef struct nodo{
	struct nodo *prox;
	musica *info;
} nodo;

typedef struct{
	nodo *inicio;
	int tamanho;
} descritor;

descritor *criaDesc(void);
nodo *criaNodo(void);
void insere(descritor *lista, nodo *novaM, int pos);
nodo *remover(descritor *lista, int pos);
void exibeLista(descritor *lista);
nodo *get(descritor *lista, int pos);
nodo *set(descritor *lista, int pos);
nodo *buscaNome(descritor *lista, char nome[256], int op);
nodo *buscaCod(descritor *lista, int cod);
//void consulta();
