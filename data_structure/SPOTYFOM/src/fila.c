#include "fila.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

descritorF *criaDescF(void){
	
	descritorF *novoDesc = (descritorF*)malloc (sizeof(descritorF));
	novoDesc->head = NULL;
	novoDesc->tail = NULL;
	novoDesc->tamanho = 0;	
	
	return novoDesc;
}

nodoF *criaNodoF(musica *song){
	
	nodoF *novaMusica = (nodoF*)malloc (sizeof(nodoF));	
	novaMusica->prox = NULL;
	novaMusica->info = song;
	
	return novaMusica;
}

void randomiza(descritorF *fila, descritorS *listaSE, int qtd_m){
	
	nodoF *elemento = NULL;
	
	int *selecionadas = (int*)calloc (qtd_m, sizeof(int));
	srand(time(NULL));
	int cont = 0;
	
	while(qtd_m > cont){
		musica *song = (musica*)malloc (sizeof(musica));
		int randon = rand() % listaSE->tamanho;
		
		if(selecionadas[randon] == 0){
			nodoS *aux = listaSE->inicio;
			
			for(int i = 0; i < randon; i++){
				aux = aux->prox;
			}
			
			strcpy(song->artista, aux->info->artista);
			song->codigo = aux->info->codigo;
			strcpy(song->titulo, aux->info->titulo);
			strcpy(song->letra, aux->info->letra);
			
			elemento = criaNodoF(song);
			enqueue(fila, elemento);
			cont++;
		}
	}
	free(selecionadas);
}

void enqueue(descritorF *fila, nodoF *novoE){
	
	if(emptyF(fila) == 1){
		fila->head = novoE;
		fila->tail = novoE;
	}
	else{
		fila->tail->prox = novoE;
		fila->tail = novoE;
	}
	fila->tamanho++;
}

nodoF *dequeue(descritorF *fila, descritorS *listaSE){
	
	nodoF *aux = fila->head;
	nodoS *aux2 = listaSE->inicio;
	
	fila->head = fila->head->prox;
	fila->tamanho--;
	
	if(fila->head == NULL)
		fila->tail = fila->head;
		
	while(aux2 != NULL){
		if(aux2->info->codigo == aux->info->codigo){
			aux2->info->execucoes++;
			return aux;
		}
		aux2 = aux2->prox;
	}
	
	return aux;
}


int emptyF(descritorF *fila){
	if(fila->head ==NULL)
		return 1;
		else
		return 0;
}

void imprimeF(descritorF *fila){
	
	nodoF *first = fila->head;
	
	while(first != NULL){
		printf("\n |Música:    [%s]", first->info->titulo);
		printf("\n |Artista:   [%s]", first->info->artista);
		printf("\n |Letra da música: [%s]", first->info->letra);
		printf("\n |Código:    [%d]", first->info->codigo);
		printf("\n |Execuções: [%d]", first->info->execucoes);
		printf("\n");
		first = first->prox;
	}
	printf("\n");
}

//~ void deletarF(descritorF *fila){
	
	//~ while(emptyF(fila) == 0){
		//~ free(dequeue(fila));
	//~ }
//~ }

int lenghtF(descritorF *fila){
	return fila->tamanho;	
}

void salvar_aleat(descritorF *fila){

	FILE *arquivo = fopen("playlist_aleatoria.txt", "w");
	if (!arquivo) {
		printf("Erro ao abrir o arquivo para escrita!\n");
		return;
	}
	
	nodoF *aux = fila->head;

	fprintf(arquivo, "Playlist Aleatoria: \n\n");
	while(aux != NULL){
		fprintf(arquivo, " |Musica: %s \n |Artista: %s \n |Letra: %s \n |Codigo: %d \n |Execuções: %d\n\n",
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

