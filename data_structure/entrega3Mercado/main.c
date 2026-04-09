// Entrega 3
// 09/04/2026
// Leonardo Manzke, leonardomanzke.aluno@unipampa.edu.br

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "entrega3.h"

int main (){
	
	estoque *est = NULL;
	int prod = 0, opcao = 1, produtosCad = 0, ele = 0, total = 0, set = 0;
	char busca[15];
	
		printf("Quantos produtos serao cadastrados? ");
		scanf("%d", &prod);
		alocaEstoque(&est, prod);
		
		while(opcao != 0){
		printf("\n------------------------------------");
		printf("\n0_ Encerra programa");
		printf("\n1_ Cadastrar produto.");
		printf("\n2_ Vizualizar um produto.");
		printf("\n3_ Vizualziar todos os produtos");
		printf("\n4_ Vizualizar balanço geral de produtos");
		printf("\n5_ Busca por nome.");
		printf("\n6_ Busca por setor.");
		printf("\n7_ Venda.");
		printf("\n8_ Carregar produto por arquivo.");
		printf("\n9_Gerar arquivo de saída do produtos.");
		printf("\n------------------------------------");
		printf("\nInforme a ação desejada: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 0: 
				free(est);
				break;
			case 1:
				cadastraProduto(est, &produtosCad);
				break;
			case 2:
				printf("\nQual elemento da lista deseja vizualizar? ");
				scanf("%d", &ele);
				exibe1Estoque(est, ele, produtosCad);
				break;
			case 3:
				printf("\nExibindo todos os lementos: ");
				exibeTodos(est, produtosCad);
				break;
			case 4:
				total = valorTotal(est, produtosCad) * produtosCad;
				printf("Balanço: %d", total);
				break;
			case 5:
				printf("Insira nome a ser buscado: ");
				scanf("%s", busca);
				buscaNome(est, busca, produtosCad);
				break;
			case 6:
				printf("\n");
				printf("\nInsira o setor que deseja buscar (1 - Frios, 2 - Farinhas, 3 - Pereciveis, 4 - Enlatados): ");
				scanf("%d", &set);
				buscaSetor(est, set, produtosCad);
				break;
			case 7:
				printf("\nQual produto deseja vender? ");
				scanf("%s", busca);
				printf("\nQual a quantidade de produtos vendidos? ");
				scanf("%d", &ele);
				venda(est, busca, ele, produtosCad);
				break;
			case 8:
				printf("Insira o nome do arquivo a ser lido: ");
				scanf("%s", busca);
				carregarArq(est, &produtosCad, busca, prod);
				break;
			case 9:
				printf("Insira o nome do arquivo a ser salvo: ");
				scanf("%s", busca);
				salvarArq(est, produtosCad, busca);
				break;
		}
	}

 return 0;			
}

