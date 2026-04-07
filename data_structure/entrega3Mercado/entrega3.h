#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum{Frios = 1, Farinhas, Pereciveis, Enlatados}Setor; 

typedef struct{
	char nome[15];
	Setor set;
	int qtd;
	float valor;	
}estoque;

void alocaEstoque(estoque **est, int prod);
void cadastraProduto(estoque *est, int *pos);
void exibe(estoque est);
void exibe1Estoque(estoque *est, int ele, int pos);
void exibeTodos(estoque *est, int pos);
int valorTotal(estoque *est, int produtosCad);
void buscaNome(estoque *est, char nomeProd[15], int produtosCad);
void buscaSetor(estoque *est, int set, int produtosCad);
void venda(estoque *est, char busca[15], int ele, int produtosCad);
