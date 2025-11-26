#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
   int valor;
   struct nodo *prox;
   struct nodo *ant;
}Nodo;

Nodo *inicio = NULL, *fim = NULL;
 
void insere(int elemento); 
void remover(int elemento);
void mostra(); 
      
void insere(int elemento){
	Nodo *novo;

	novo = (Nodo*) malloc (sizeof (Nodo));
	novo->valor = elemento;
	novo->prox = NULL;
	novo->ant = NULL;
	
    if (inicio == NULL){
		inicio = novo;
	}
	else{
		fim->prox = novo;
		novo->ant = fim;
	}
	
	fim = novo;
}

void remover(int elemento){
	Nodo *aux1, *aux2;
	
	aux1 = aux2 = inicio;
	
	while(aux1 != NULL && aux1->valor != elemento){
		aux2 = aux1;
		aux1 = aux1->prox;	
	}
	
	if (aux1 == NULL)
		printf("Elemento nao esta na lista...\n");
	
	else{
		if (aux1 == inicio && aux1 == fim){
			inicio = inicio->prox;
			fim = NULL;
		}
		
		else if (aux1 == inicio){
			inicio = inicio->prox;
			inicio->ant = NULL;
		}
		
		else if (aux1 == fim){
			fim = aux2;
			aux2->prox = NULL;
		}
		
		else{
				aux1->prox->ant = aux2;
				aux2->prox = aux1->prox;
		}
			
		printf("Elemento %d removido!", aux1->valor);
		free(aux1);	
	}
}

void mostra(){
	Nodo *aux = inicio;
	
    printf("\n"); 
	while (aux != NULL){
		printf ("%d --> ", aux->valor);
		aux = aux->prox;
	}
	printf("\n");
}

void mostra_fim(){
	Nodo *aux = fim;
	
    printf("\n"); 
	while (aux != NULL){
		printf ("%d --> ", aux->valor);
		aux = aux->ant;
	}
	printf("\n");
}

int main(void) {
   int elemento;
   int opcao;
   
   do{
		printf ("\n1 - Insere elemento na lista");
		printf ("\n2 - Retira elemento da lista");
		printf ("\n3 - Mostrar lista");
		printf ("\n4 - Mostrar Fim");
		printf ("\n0 - Encerra programa");
		printf ("\nOpcao? ");
		scanf ("%d", &opcao);
		
		switch (opcao){
			case 1:
				printf ("\nInforme valor a ser inserido: ");
				scanf ("%d", &elemento);
				insere(elemento);
				mostra();
				break;
			case 2:
				if (inicio != NULL){
					printf ("\nInforme valor a ser removido: ");
					scanf ("%d", &elemento);
					remover(elemento);
					mostra();
				}
				else
					printf("Lista vazia...\n");
				break;
			case 3:
				mostra();
				break;	
			case 4:
				mostra_fim();
				break;
			}
	}while(opcao != 0);
}
