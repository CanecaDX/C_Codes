#include <stdio.h>
#include <string.h>

struct Hotel {
	int codigo;
	char nome[100];
	char cidade[50];
	int quartosTotais;
	int quartosDisponiveis;
	float diaria;
} Hotel;
typedef struct Hotel hotel;
hotel hot[100];
int total = 0;

void removeQuartoAlugado(){
	
	FILE *arquivo = fopen("Hoteis.txt", "r");
	if (!arquivo) {
		printf("Erro ao abrir o arquivo para escrita!\n");
		return;
	}
	
	for (int i = 0; i < total; i++) {
			fscanf(arquivo, "%d", &hot[i].quartosDisponiveis);
			hot[i].quartosDisponiveis = hot[i].quartosDisponiveis - 1;
			fprintf(arquivo, "\n%d", hot[i].quartosDisponiveis);
		        
		}
		fclose(arquivo);
		return;

}

void salvarHotel(){
		
	FILE *arquivo = fopen("Hoteis.txt", "a");
	if (!arquivo) {
		printf("Erro ao abrir o arquivo para escrita!\n");
		return;
	}

	for (int i = 0; i < total; i++) {
			fprintf(arquivo, "%d %s %s %d %d %.2f\n",
					hot[i].codigo,
					hot[i].nome,
					hot[i].cidade,
					hot[i].quartosTotais,
					hot[i].quartosDisponiveis,
					hot[i].diaria); 
		        
		}
		fclose(arquivo);
	}

void cadastro(int qtd) {
	int i = 0;

	for(i = total; i<(qtd + total); i++) {
		printf("Insira codigo do hotel: ");
		scanf("%d", &hot[i].codigo);
		printf("Insira nome do hotel: ");
		scanf(" %s", hot[i].nome);
		printf("Insira a cidade do hotel: ");
		scanf(" %s", hot[i].cidade);
		printf("Insira os quartos totais do hotel: ");
		scanf("%d", &hot[i].quartosTotais);
		printf("Insira os quartos disponiveis no hotel: ");
		scanf("%d", &hot[i].quartosDisponiveis);
		printf("Insira o valor da diaria: ");
		scanf("%f", &hot[i].diaria);
	}
	total += qtd;
	salvarHotel();
}

void salvarRelatorio(char data[20], char hotelEscolhido[50]){
	
	FILE *arquivo = fopen("Relatorio.txt", "a");
	
	if (!arquivo) {
		printf("Erro ao abrir o arquivo para escrita!\n");
		return;
	}
	
	fprintf(arquivo, "\nReserva feita no hotel: %s || Para: %s    ", hotelEscolhido, data);
	fclose(arquivo);	 
}

void salvarReserva(char nome[50], int escolhido, char data[20]){
	
	FILE *arquivo2 = fopen("Hoteis.txt", "r");
	if (!arquivo2) {
		printf("Erro ao abrir o arquivo para leitura!\n");
		return;
	}
		
	FILE *arquivo = fopen("Reservas.txt", "a");
	if (!arquivo) {
		printf("Erro ao abrir o arquivo para escrita!\n");
		return;
	}
	
	char hotelEscolhido[50];

	for (int i = 0; i < total; i++) {
		
		if(escolhido == hot[i].codigo){
			fscanf(arquivo2, "%d %s %f %d", &hot[i].codigo, hot[i].nome, &hot[i].diaria, &hot[i].quartosDisponiveis);
			fprintf(arquivo, "%s %s %d %s %.2f\n",
					nome,
					data,
					hot[i].codigo,
					hot[i].nome,
					hot[i].diaria
			);	 
			
			strcpy(hotelEscolhido, hot[i].nome);
			removeQuartoAlugado();
		}
	}

	fclose(arquivo);
	fclose(arquivo2);
	printf("\nReserva feita com sucesso!\n");
	
	salvarRelatorio(data, hotelEscolhido);
}

void reserva(int qtd){
	
	FILE *arquivo = fopen("Hoteis.txt", "r");
	if (!arquivo) {
		printf("Erro ao abrir o arquivo para leitura!\n");
		return;
	}
	
	int i, busca, escolhido, valido = 0;
	char nome[50], data[20];
		
	printf("Insira seu nome: ");
	scanf(" %s", nome);
	printf("Insira a data da reserva: ");
	scanf(" %s", data);
	
	printf("\n");
	
	printf("Hoteis disponiveis;\n");
	for(i=0; i<total; i++) {
		fscanf(arquivo, "%s %d", hot[i].nome, &hot[i].codigo);
		printf("Hotel: %s | Codigo: %d\n", hot[i].nome, hot[i].codigo);

	}
	
	printf("\nEscolha um hotel a partir do codigo: ");
	scanf("%d", &busca);
	
	for(i = 0; i<total; i++){
		if(busca == hot[i].codigo){
			escolhido = hot[i].codigo;
			valido = 1;
			break;
		}
	}		if (!valido){
				printf("Hotel nao encontrado!\n");
				return;
			}
			
	fclose(arquivo);
	salvarReserva(nome, escolhido, data);
}

void relatorio(){
		
	FILE *arquivo = fopen("Relatorio.txt", "r");
	
	if (!arquivo) {
		printf("Erro ao abrir o arquivo para leitura!\n");
		return;
	}	
	
	char linha[200];
	
	while (fgets(linha, sizeof(linha), arquivo)) {
        printf("\n%s", linha);
    }
    
    fclose(arquivo);
			
}

int main() {

	int opcao, i = 1, qtd;

	while(i != 0) {
		printf("\n");
		printf ("\n1 - Cadastrar Hoteis.");
		printf ("\n2 - Reservar quartos.");
		printf ("\n3 - Gerar relatório");
		printf ("\n0 - Encerra programa");
		printf ("\nOpcao? ");
		scanf ("%d", &opcao);

		switch (opcao) {
		case 1:
			printf("\nQuantos hoteis deseja inserir? ");
			scanf("%d", &qtd);
			cadastro(qtd);
			break;
		case 2:
			reserva(qtd);
			break;
		case 3:
			relatorio();
			break;
		case 0:
			printf("Encerrando programa.");
			return 0;
		}
	}
	
	return 0;
}
