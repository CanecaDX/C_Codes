#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

int main(){
	
	grafo *graf = NULL;
	char nome[256];
	printf("\nInsira o nome do arquivo: ");
	scanf(" %255[^\n]", nome);
	graf = parser(nome);
	imprimeGrafo(graf);

	return 0;	
}

