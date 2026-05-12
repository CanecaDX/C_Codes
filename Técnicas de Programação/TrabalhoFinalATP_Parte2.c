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

void salvarHotel(){
    FILE *arquivo = fopen("Hoteis.txt", "w");
    if (!arquivo) return;

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

void carregarHoteis(){
    FILE *arquivo = fopen("Hoteis.txt", "r");
    if (!arquivo) return;

    total = 0;

    while (fscanf(arquivo, "%d %s %s %d %d %f",
                  &hot[total].codigo,
                  hot[total].nome,
                  hot[total].cidade,
                  &hot[total].quartosTotais,
                  &hot[total].quartosDisponiveis,
                  &hot[total].diaria) == 6) {
        total++;
    }

    fclose(arquivo);
}

void cadastro(int qtd) {
    carregarHoteis();

    for(int i = total; i < total + qtd; i++) {
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
    if (!arquivo) return;

    fprintf(arquivo, "Reserva feita no hotel: %s || Para: %s\n", hotelEscolhido, data);

    fclose(arquivo);
}

void salvarReserva(char nome[50], int escolhido, char data[20]){
    carregarHoteis();

    FILE *arquivo = fopen("Reservas.txt", "a");
    if (!arquivo) return;

    char hotelEscolhido[50];

    for (int i = 0; i < total; i++) {
        if (hot[i].codigo == escolhido) {

            fprintf(arquivo, "%s %s %d %s %.2f\n",
                    nome,
                    data,
                    hot[i].codigo,
                    hot[i].nome,
                    hot[i].diaria);

            strcpy(hotelEscolhido, hot[i].nome);

            hot[i].quartosDisponiveis--;

            salvarHotel();

            break;
        }
    }

    fclose(arquivo);

    salvarRelatorio(data, hotelEscolhido);
}

void reserva(int qtd){
    carregarHoteis();

    FILE *arquivo = fopen("Hoteis.txt", "r");
    if (!arquivo) return;

    int busca, escolhido, valido = 0;
    char nome[50], data[20];

    printf("Insira seu nome: ");
    scanf(" %s", nome);
    printf("Insira a data da reserva: ");
    scanf(" %s", data);

    printf("\nHoteis disponiveis:\n");

    for(int i = 0; i < total; i++) {
        printf("Hotel: %s | Codigo: %d\n", hot[i].nome, hot[i].codigo);
    }

    printf("\nEscolha um hotel pelo codigo: ");
    scanf("%d", &busca);

    for(int i = 0; i < total; i++){
        if(busca == hot[i].codigo){
            escolhido = hot[i].codigo;
            valido = 1;
            break;
        }
    }

    if (!valido){
        printf("Hotel nao encontrado!\n");
        fclose(arquivo);
        return;
    }

    fclose(arquivo);

    salvarReserva(nome, escolhido, data);
    printf("Reserva feita com sucesso!\n");
}

void relatorio(){
    FILE *arquivo = fopen("Relatorio.txt", "r");
    if (!arquivo) return;

    char linha[200];

    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    fclose(arquivo);
}

void buscaNome(char bus[50]) {

	FILE *arquivo = fopen("Hoteis.txt", "r");

	if (!arquivo) {
		printf("Erro ao abrir o arquivo para leitura!\n");
		return;
	}

	int i, encontrado = 0;

	for(i=0; i<total; i++) {

		   fscanf(arquivo, "%d %s %s %d %d %f\n",
             &hot[i].codigo,
             hot[i].nome,
             hot[i].cidade,
             &hot[i].quartosTotais,
             &hot[i].quartosDisponiveis,
             &hot[i].diaria);

		if(strcmp(bus, hot[i].nome) == 0) {
			printf("Nome: %s \n", hot[i].nome);
            encontrado = 1;
            break;
        }
    }

    if(!encontrado){
        printf("Hotel não encontrado\n");
    }
	
	fclose(arquivo);
}

void buscaCidade(char bus[50]) {

	FILE *arquivo = fopen("Hoteis.txt", "r");

	if (!arquivo) {
		printf("Erro ao abrir o arquivo para leitura!\n");
		return;
	}

	int i, encontrado = 0;

	for(i=0; i<total; i++) {

		   fscanf(arquivo, "%d %s %s %d %d %f\n",
             &hot[i].codigo,
             hot[i].nome,
             hot[i].cidade,
             &hot[i].quartosTotais,
             &hot[i].quartosDisponiveis,
             &hot[i].diaria);

		if(strcmp(bus, hot[i].cidade) == 0) {
			if(!encontrado){
				printf("Hoteis da cidade:\n");
			}
			printf("%s\n", hot[i].nome);
            encontrado = 1;
        }
    }
    if(!encontrado){
        printf("Cidade não encontrada\n");
    }
	
	fclose(arquivo);
}

void buscaValor(int max, int min) {

	FILE *arquivo = fopen("Hoteis.txt", "r");

	if (!arquivo) {
		printf("Erro ao abrir o arquivo para leitura!\n");
		return;
	}
	
	int i, encontrado;

	for(i=0; i<total; i++) {
			
	fscanf(arquivo, "%d %s %s %d %d %f\n", &hot[i].codigo, hot[i].nome, hot[i].cidade, &hot[i].quartosTotais, &hot[i].quartosDisponiveis, &hot[i].diaria);

		if((hot[i].diaria >= min) && (hot[i].diaria <= max)){
			if(!encontrado){
				printf("Hoteis nesta faixa de preco:\n");
			}
			printf("%s\n", hot[i].nome);
            encontrado = 1;
        }
		
    if(!encontrado){
        printf("Hoteis indisponiveis nesta faixa de preco\n");
    }
   }
	
	fclose(arquivo);
}

void ListarHoteis(){

	FILE *arquivo = fopen("Hoteis.txt", "r");

	if (!arquivo) {
		printf("Erro ao abrir o arquivo para leitura!\n");
		return;
	}

	int i;

	for(i=0; i<total; i++) {

		   fscanf(arquivo, "%d %s %s %d %d %f\n",
             &hot[i].codigo,
             hot[i].nome,
             hot[i].cidade,
             &hot[i].quartosTotais,
             &hot[i].quartosDisponiveis,
             &hot[i].diaria);
             
          printf("\nCodigo do hotel: %d | Nome: %s | Cidade %s", hot[i].codigo, hot[i].nome, hot[i].cidade);
        }
	
	fclose(arquivo);
}

int main() {
    int opcao, qtd, min, max;
    char bus[50];

    while(1) {
        printf("\n1 - Cadastrar Hoteis.");
        printf("\n2 - Reservar quartos.");
        printf("\n3 - Gerar relatório");
        printf("\n4 - Procurar Hotel por nome");
        printf("\n5 - Busca hotel por cidade");
        printf("\n6 - Procurar por faixa de preço");
        printf("\n7 - Listar hoteis");
        printf("\n0 - Encerra programa");
        printf("\nOpcao? ");
        scanf ("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Quantos hoteis deseja inserir? ");
                scanf("%d", &qtd);
                cadastro(qtd);
                break;
            case 2:
                reserva(qtd);
                break;
            case 3:
                relatorio();
                break;
            case 4:
				printf("Insira nome do hotel que deseja procurar: ");
				scanf(" %s", bus);
				buscaNome(bus);
				break;
			case 5:
				printf("Insira nome da cidade para listar seus hoteis: ");
				scanf(" %s", bus);
				buscaCidade(bus);
				break;
			case 6:
				printf("Insira o valor maximo e minimo desejado: \n");
				scanf("%d %d", &max, &min);
				buscaValor(max, min);
				break;
			case 7:
				ListarHoteis();
				break;
            case 0:
                return 0;
        }
    }
}
