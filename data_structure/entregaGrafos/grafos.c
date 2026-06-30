#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

grafo *parser(char nome[256]){
	char line[512];
	int i;
	
	FILE *arq = fopen(nome, "r");
	if (!arq) {
		perror("Erro ao abrir o arquivo !\n");
		return NULL;
	}

	char totalL[256];
	fgets(totalL, sizeof(totalL), arq);
	int total = atoi(totalL);
	printf("\nTotal de nodos: %d", total);
	grafo *graf = NULL;
	graf = inicializaGrafo(total);

	 for (i = 0; i < total; i++) {
		if (fgets(line, sizeof(line), arq) != NULL){    
            
            line[strcspn(line, "\n\r")] = '\0'; //pega a linha até o limitador          
			int partida = atoi(strtok(line, " "));
			int chegada = atoi(strtok(NULL, " "));
			int peso = atoi(strtok(NULL, " ")); 

			graf = insereAresta(graf,partida,chegada,peso);
		} 	
    }
    
    printf("\nGrafo carregado com sucesso!");
	fclose(arq);
	return graf;
}

grafo *inicializaGrafo(int total){
	grafo *novoGrafo = (grafo*)malloc (sizeof(grafo));
	novoGrafo->max_vertices = total;
	novoGrafo->max_arestas = 0;
	novoGrafo->vertices = NULL;
	int i;
	
	//cria a lista encadeada de nodos
	for(i = 0; i < total; i++){
		vertice *novoVertice = criaVertice(i+1);
		if(novoGrafo->vertices == NULL){
			novoGrafo->vertices = novoVertice;
		}
		else{
			vertice *temp = novoGrafo->vertices;
			while(temp->prox!=NULL){
					temp = temp->prox;
			}
			temp->prox = novoVertice;
		}
	}
	return novoGrafo;
}

vertice *criaVertice(int chave){
	vertice *novoVertice  = (vertice*) malloc(sizeof(vertice));
	novoVertice->chave = chave;
	novoVertice->prox = NULL;
	novoVertice->adjacencias = NULL;
	return novoVertice;
}

grafo *insereAresta(grafo *graf, int partida, int chegada, int peso){
	 vertice *verticeSaida = buscaVertice(graf, partida);
	 
	 aresta *arest = (aresta*)malloc (sizeof(aresta));
	 arest->chegada = chegada;
	 arest->partida = partida;
	 arest->peso = peso;
	 
	if(verticeSaida->adjacencias == NULL)
		verticeSaida->adjacencias = arest;
	else{
		aresta *tempAdj = verticeSaida->adjacencias;
		while(tempAdj->prox != NULL){
			tempAdj = tempAdj->prox;
		}	
		tempAdj->prox = arest;	
	}
	return graf;	 
}

vertice *buscaVertice(grafo *graf, int chaveBusca){
	vertice *temp = graf->vertices;
	while(temp != NULL){
		if(temp->chave == chaveBusca)
			return temp;
		temp = temp->prox;
	}
	return NULL;	
}


void imprimeGrafo(grafo *graf){
	vertice *nodoGrafo = graf->vertices;
	printf("\n========GRAFO LISTA=============\n");
		while(nodoGrafo != NULL){
			printf("Nodo %d -",nodoGrafo->chave);
			aresta *adjacenciaNodo = nodoGrafo->adjacencias;
				while(adjacenciaNodo != NULL){
					printf("[ ->%d (peso %d)] ",adjacenciaNodo->chegada, adjacenciaNodo->peso);
					adjacenciaNodo = adjacenciaNodo->prox;
				}	
				printf("\n");
				nodoGrafo = nodoGrafo->prox;
		}
	printf("=====================\n");
}
