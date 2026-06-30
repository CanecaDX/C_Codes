#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct descritor_grafo{
	int max_vertices;
	int max_arestas;
	struct nodos *vertices;
}grafo;

typedef struct arestas{
	int partida;
	int chegada;
	int peso;
	struct arestas *prox;
}aresta;

typedef struct nodos{
	int chave;
	struct nodos *prox;
	struct arestas *adjacencias;	
}vertice;

grafo *parser(char nome[256]);
grafo *inicializaGrafo(int total);
vertice *criaVertice(int chave);
grafo *insereAresta(grafo *graf, int partida, int chegada, int peso);
vertice *buscaVertice(grafo *graf, int chaveBusca);
void imprimeGrafo(grafo *graf);
