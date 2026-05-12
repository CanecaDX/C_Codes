#include <stdlib.h>
#include <stdio.h>

typedef struct{
	char titulo[256];
	char artista[256];
	char letra[256];
	int codigo;
	int execucoes;
} musica;

typedef struct nodoF{
	musica *info;
	struct nodoF *prox;
}nodoF;

typedef struct descritorF{
	nodoF *head;
	nodoF *tail;
	int tamanho;
}descritorF;

descritorF *criaDesc(void);
nodoF *criaNodo(void);
void enqueue(descritorF *fila, nodoF *novoE);
nodoF *dequeue(descritorF *fila);
int empty(descritorF *fila);
void imprime(descritorF *fila);
void deletar(descritorF *fila);
int lenght(descritorF *fila);

