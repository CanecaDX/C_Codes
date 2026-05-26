#include "pilha.h"

descritorP *criaDescP(void){
	
	descritorP *pilha = (descritorP*)malloc (sizeof(descritorP));
	pilha->top = NULL;
	pilha->tamanho = 0;
}

nodoP *criaNodoP(void){
	
	nodoP *novaMusica = (nodoP*)malloc (sizeof(nodoP));
	novaMusica->info = (musica*)malloc (sizeof(nodoP));
	
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
}

void push(descritorP *pilha, nodoP *novoE){
	novoE->prox = pilha->top;
	pilha->top = novoE;
	pilha->tamanho++;
}

nodoP *pop(descritorP *pilha){
	
	nodoP *aux = pilha->top;
	
	pilha->top = pilha->top->prox;
	pilha->tamanho--;
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
		printf("\n |Execuções: [%d]", topo->info->execucoes);
		printf("\n");
		topo = topo->prox;
	}
	printf("\n");
}
