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

int main (){
	
	estoque *est = NULL;
	int prod = 0, opcao = 1, produtosCad = 0, ele = 0;
	
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
		printf("\n5_ Busca por nome");
		printf("\n6_ Busca por setor");
		printf("\n7_ Venda");
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
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
		}
	}

 return 0;			
}

void alocaEstoque(estoque **est, int prod){
	
	*est = calloc(prod, sizeof(estoque)); 

}
void cadastraProduto(estoque *est, int *pos){
	
	int setorTemp;
	
	printf("Insira o nome do produto: ");
	scanf("%s", est[*pos].nome);
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

