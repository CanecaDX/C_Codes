#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int cpf;
    int rg;
} Pessoa;

typedef struct {
    Pessoa pessoa;
    double divida;
    char data_cadastro[50];
} Cliente;

typedef struct {
    Pessoa pessoa;
    char produto[50];
    float valor;
} Fornecedor;

int main() {
    
		Cliente clientes[3];

		for (int i = 0; i < 3; i++) {
			
        printf("\nDigite o nome da pessoa: ");
        scanf("%s", clientes[i].pessoa.nome);
        
        printf("\nDigite o cpf da pessoa: ");
        scanf("%d", &clientes[i].pessoa.cpf);
        
        printf("\nDigite o rg da pessoa: ");
        scanf("%d", &clientes[i].pessoa.rg);
        
        printf("\nDigite a divida: ");
        scanf("%lf", &clientes[i].divida);
        
        printf("\nDigite a data do cadastro: ");
        scanf("%s", clientes[i].data_cadastro);
        
        printf("\nNome da pessoa: %s", clientes[i].pessoa.nome);
			printf("\nCPF da pessoa: %d", clientes[i].pessoa.cpf);
				printf("\nRG da pessoa: %d", clientes[i].pessoa.rg);
					printf("\nDivida da pessoa: %.2f", clientes[i].divida);
						printf("\nData do cadastro: %s\n", clientes[i].data_cadastro);
    }
    
    	Fornecedor fornecedores[3];

		for (int i = 0; i < 3; i++) {
      
        printf("\nDigite o nome do produto: ");
        scanf("%s", fornecedores[i].produto);
        
        printf("\nDigite o valor do produto: ");
        scanf("%f", &fornecedores[i].valor);
        
           printf("\nNome do produto: %s", fornecedores[i].produto);
			printf("\nValor do produto: %.2f\n", fornecedores[i].valor);
    }

    return 0;
}
