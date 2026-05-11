#include <stdio.h>
#include <stdlib.h>
#include "LCE.h"

int main(){
	
	descritor *lista;
	nodo *novoN;
	int dado, l = 0, pos = 0;
	
	lista = criaDescC();
	while(l < 2){
		printf("\nInsira o numero do elemento a ser inserido: ");
		scanf("%d", &dado);
		novoN = criaNodo(dado);
		
		printf("\nInsira a posicao a ser inserida na lista: ");
		scanf("%d", &pos);
		insere(lista, novoN, pos);
		l++;
	}
	
	exibe(lista);
	
		
	return 0;
}
