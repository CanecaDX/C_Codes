#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "entrega3.h"

void alocaEstoque(estoque **est, int prod){
	
	*est = calloc(prod, sizeof(estoque)); 
}

void cadastraProduto(estoque *est, int *pos){
	
	int setorTemp;
	
	printf("Insira o nome do produto: ");
	scanf(" %[^\n]", est[*pos].nome);
	printf("1 - Frios\n");
	printf("2 - Farinhas\n");
	printf("3 - Pereciveis\n");
	printf("4 - Enlatados\n");	 
	printf("\nSelecione o setor do produto: ");
	scanf("%d", &setorTemp);
	if(setorTemp > 4){
		printf("Código inválido");
		free(est);
		return;
	}
	est[*pos].set = (Setor)setorTemp;
	printf("\nInsira a quantidade deste produto: ");
	scanf("%d", &est[*pos].qtd);
	printf("\nInsira o preço deste produto: ");
	scanf("%f", &est[*pos].valor);
	
	(*pos)++;
}

void exibe(estoque est){
	
		printf("\nNome: %s", est.nome);
			
		printf("\nSetor: ");
			 switch(est.set){
				case 1:
					printf("Frios");
					break;
				case 2:
					printf("Farinhas");
					break;
				case 3:
					printf("Pereciveis");
					break;
				case 4:
					printf("Enlatados");
					break;
				}
		printf("\nQuantidade: %d", est.qtd);
		printf("\nPreço: %.2f", est.valor);
}

void exibe1Estoque(estoque *est, int ele, int pos){
	
	int i = 0;
	
	if(ele < 0 || ele > pos){
		printf("Produto não econtrado!");
		return;
	}
	else{
		for(i = 0; i<pos; i++){
			 if(i == (ele-1)){
				 exibe(est[i]);
			 }
		} 
	}
}

void exibeTodos(estoque *est, int pos){
	
	int i = 0;
	
		for(i = 0; i<pos; i++){
			printf("\n");
			exibe(est[i]);
		}
}

int valorTotal(estoque *est, int produtosCad){
	
	if(produtosCad <= 0) return 0;
	return est[produtosCad-1].qtd + valorTotal(est, produtosCad - 1);
		
}

void buscaNome(estoque *est, char nomeProd[15], int produtosCad){
	
	int i;

	for(i = 0; i<produtosCad; i++){
		if(strcmp(nomeProd, est[i].nome) == 0){
			printf("\nProduto solicitado: ");
			exibe(est[i]);
		}
		else{
			printf("\nEsse produto não existe no estoque!");
			return;
		}
	}
}

void buscaSetor(estoque *est, int set, int produtosCad){
	
	int i;

	printf("\nProdutos solicitados: ");
	for(i = 0; i<produtosCad; i++){
		printf("\n");
		if(est[i].set == set){
			exibe(est[i]);
		}
		else{
			printf("\nEsse produto não existe no estoque!");
			return;
		}
	}	
}

void venda(estoque *est, char busca[15], int ele, int produtosCad){
	
	int i = 0;
	
	printf("\nValor decrementado do total do produto.");
	for(i = 0; i<produtosCad; i++){
		if(strcmp(est[i].nome, busca) == 0){
			est[i].qtd -= ele;
		}
	}
	return;
}

void carregarArq(estoque *est, int *pos, char *nomeArq, int prod){
	
	int setorTemp = 0;
	
	FILE *arq = fopen(nomeArq, "r");
	
	if(!arq){
		printf("Erro ao abrir o arquivo!");
		return;
	}
	
	while(*pos < prod && fscanf(arq, "%s %d %d %f", est[*pos].nome, &setorTemp, &est[*pos].qtd, &est[*pos].valor) == 4){
		est[*pos].set = (Setor)setorTemp;
		(*pos)++;
	}
	
	fclose(arq);
	
}

void salvarArq(estoque *est, int pos, char *nomeArq){
	
	int i = 0;
	
	FILE *arq = fopen(nomeArq, "w");
	
	if(!arq){
		printf("Erro ao abrir o arquivo!");
		return;
	}
	
	for(i = 0; i < pos; i++){
		fprintf(arq, "%s %d %d %.2f", est[i].nome, est[i].set, est[i].qtd, est[i].valor);
	}
	
	fclose(arq);
	
}
