#include "fila.h"

descritorF *criaDesc(void){
	
	descritorF *novoDesc = (descritorF*)malloc (sizeof(descritorF));
	novoDesc->head = NULL;
	novoDesc->tail = NULL;
	novoDesc->tamanho = 0;	
	
	return novoDesc;
}

nodoF *criaNodo(void){
	
	nodoF *novaMusica = (nodoF*)malloc (sizeof(nodoF));
	novaMusica->info = (musica*)malloc (sizeof(musica));
	
	printf("Insira o nome da música: ");
	scanf(" %[^\n]", novaMusica->info->titulo);
	printf("Insira o nome do artista: ");
	scanf(" %[^\n]", novaMusica->info->artista);
	printf("Insira a letra da música: ");
	scanf(" %[^\n]", novaMusica->info->letra);
	printf("Insira o codigo da música: ");
	scanf("%d", &novaMusica->info->codigo);
	printf("Insira o número de execuções da música: ");
	scanf("%d", &novaMusica->info->execucoes);
	
	novaMusica->prox = NULL;
	
	return novaMusica;
}

void enqueue(descritorF *fila, nodoF *novoE){
	
	if(empty(fila) == 1){
		fila->head = novoE;
		fila->tail = novoE;
	}
	else{
		fila->tail->prox = novoE;
		fila->tail = novoE;
	}
	fila->tamanho++;
}

nodoF *dequeue(descritorF *fila){
	
	nodoF *aux = fila->head;
	
	fila->head = fila->head->prox;
	fila->tamanho--;
	
	if(fila->head == NULL)
		fila->tail = fila->head;
		
	return aux;
}


int empty(descritorF *fila){
	if(fila->head ==NULL)
		return 1;
		else
		return 0;
}

void imprime(descritorF *fila){
	
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

void deletar(descritorF *fila){
	
	while(empty(fila) == 0){
		free(dequeue(fila));
	}
}

int lenght(descritorF *fila){
	return fila->tamanho;	
}
