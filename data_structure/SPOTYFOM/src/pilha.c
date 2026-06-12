#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

descritorP *criaDescP(void){
	
	descritorP *pilha = (descritorP*)malloc (sizeof(descritorP));
	pilha->top = NULL;
	pilha->tamanho = 0;
	
	return pilha;
}

nodoP *criaNodoP(musica *song){
	
	nodoP *novaMusica = (nodoP*)malloc (sizeof(nodoP));
	novaMusica->prox = NULL;
	novaMusica->info = song;
	
	return novaMusica;
}

void inserePessoal(descritorP *pilha, descritorS *listaSE, int cod){
	
	nodoP *elemento = NULL;
	nodoS *aux = listaSE->inicio;
	
	while(aux != NULL){
		musica *song = (musica*)malloc (sizeof(musica));
		if(aux->info->codigo == cod){
			
			strcpy(song->artista, aux->info->artista);
			song->codigo = aux->info->codigo;
			strcpy(song->titulo, aux->info->titulo);
			strcpy(song->letra, aux->info->letra);
			
			elemento = criaNodoP(song);
			push(pilha, elemento);
			return;
		}
		aux = aux->prox;
	}
}

void push(descritorP *pilha, nodoP *novoE){
	novoE->prox = pilha->top;
	pilha->top = novoE;
	pilha->tamanho++;
}

nodoP *pop(descritorP *pilha, descritorS *listaSE){
	
	nodoP *aux = pilha->top;
	nodoS *aux2 = listaSE->inicio;
	
	pilha->top = pilha->top->prox;
	pilha->tamanho--;
	
	while(aux2 != NULL){
		if(aux2->info->codigo == aux->info->codigo){
			aux2->info->execucoes++;
			return aux;
		}
		aux2 = aux2->prox;
	}
	
	return aux;
}

int emptyP(descritorP *pilha){
	if(pilha->top == NULL)
		return 1;
		else
		return 0;
}

nodoP *top(descritorP *pilha){
	return pilha->top;
}

void imprimeP(descritorP *pilha){
	
	nodoP *topo = top(pilha);
	
	while(topo !=NULL){
		printf("\n |Música:    [%s]", topo->info->titulo);
		printf("\n |Artista:   [%s]", topo->info->artista);
		printf("\n |Letra da música: [%s]", topo->info->letra);
		printf("\n |Código:    [%d]", topo->info->codigo);
		//printf("\n |Execuções: [%d]", topo->info->execucoes);
		printf("\n");
		topo = topo->prox;
	}
	printf("\n");
}

void salvar_pessoal(descritorP *pilha, char nome[256]){

	FILE *arquivo = fopen(nome, "w");
	if (!arquivo) {
		perror("Erro ao abrir o arquivo para escrita!\n");
		return;
	}
	
	nodoP *aux = top(pilha);

	fprintf(arquivo, "%s: \n\n", nome);
	while(aux != NULL){
		fprintf(arquivo, "|Musica: %s \n |Artista: %s \n |Letra: %s \n |Codigo: %d \n |Execuções: %d\n\n",
		        aux->info->titulo,
		        aux->info->artista,
		        aux->info->letra,	        
		        aux->info->codigo,
		        aux->info->execucoes
		);
		aux = aux->prox;
	}

	fclose(arquivo);
	printf("Musicas salvas com sucesso!\n");
}
