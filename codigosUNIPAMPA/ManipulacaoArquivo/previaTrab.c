/*Controle de Estoque com Struct e Arquivo Texto*/

#include <stdio.h>

struct Produto {
	int id;
	char nome[100];
	int qtd;
	float preco;
};
typedef struct Produto est;
est esto[100];
int total = 0;

//CADASTRO
void cadastro(int qtd) {
	int i = 0;

	for(i = total; i<(qtd + total); i++) {
		printf("Insira id do produto: ");
		scanf("%d", &esto[i].id);
		printf("Insira nome do produto: ");
		scanf(" %s", esto[i].nome);
		printf("Insira a quantidade do produto: ");
		scanf("%d", &esto[i].qtd);
		printf("Insira o preco do produto: ");
		scanf("%f", &esto[i].preco);
	}
	total += qtd;

}

//SALVA EM TXT
void salvar() {

	FILE *arquivo = fopen("estoque.txt", "w");
	if (!arquivo) {
		printf("Erro ao abrir o arquivo para escrita!\n");
		return;
	}

	for (int i = 0; i < total; i++) {
		fprintf(arquivo, "%d %s %d %.2f\n",
		        esto[i].id,
		        esto[i].nome,
		        esto[i].qtd,
		        esto[i].preco
		       );
	}

	fclose(arquivo);
	printf("Dados salvos com sucesso!\n");
}

void ler(int qtd) {

	FILE *arquivo = fopen("estoque.txt", "r");
	if (!arquivo) {
		printf("Erro ao abrir o arquivo para escrita!\n");
		return;
	}

	int i;

	for(i=0; i<total; i++) {

		fscanf(arquivo, "%d %s %d %f", &esto[i].id, esto[i].nome, &esto[i].qtd, &esto[i].preco);
		printf("Codigo: %d | Nome: %s | Quantidade: %d | Preco: R$ %.2f\n", esto[i].id, esto[i].nome, esto[i].qtd, esto[i].preco);

	}
	
	fclose(arquivo);

}

void busca(int bus, int qtd) {

	FILE *arquivo = fopen("estoque.txt", "r");

	if (!arquivo) {
		printf("Erro ao abrir o arquivo para escrita!\n");
		return;
	}

	int i;

	for(i=0; i<total; i++) {

		fscanf(arquivo, "%d %s %d %f", &esto[i].id, esto[i].nome, &esto[i].qtd, &esto[i].preco);

		if(bus == esto[i].id) {
			printf("Codigo: %d | Nome: %s | Quantidade: %d | Preco: R$ %.2f\n", esto[i].id, esto[i].nome, esto[i].qtd, esto[i].preco);
		}
	}
	
	fclose(arquivo);
}

void ValorTotal(int qtd){
    FILE *arquivo = fopen("estoque.txt", "r");

	if (!arquivo) {
		printf("Erro ao abrir o arquivo para escrita!\n");
		return;
	}
	
	float valorT;
	int i;
	
	
    for(i=0; i<total; i++) {

		fscanf(arquivo, "%d %f", &esto[i].qtd, &esto[i].preco);

		valorT = valorT + (esto[i].preco * esto[i].qtd);
	}
	
	printf("Valor total no estoque: %.2f", valorT);
	
	fclose(arquivo);
    
}

int main() {

	int opcao, i = 1, qtd, bus;

	while(i != 0) {
		printf ("\n1 - Adicionar novo produto.");
		printf ("\n2 - Salvar.");
		printf ("\n3 - Ler");
		printf ("\n4 - Buscar por codigo");
		printf("\n5 - Calcular valor final.");
		printf ("\n0 - Encerra programa");
		printf ("\nOpcao? ");
		scanf ("%d", &opcao);

		switch (opcao) {
		case 1:
			printf("\nQuantos produtos deseja inserir? ");
			scanf("%d", &qtd);
			cadastro(qtd);
			break;
		case 2:
			salvar();
			break;
		case 3:
			ler(qtd);
			break;
		case 4:
            printf("\nQual codigo deseja buscar? ");
			scanf("%d", &bus);
			busca(bus, qtd);
			break;
		case 5:
			ValorTotal(qtd);
			break;
		case 0:
			printf("Encerrando programa.");
			return 0;
		}
	}


	return 0;
}
