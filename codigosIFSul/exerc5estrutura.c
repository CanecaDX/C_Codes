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
    float divida;
    char data_cadastro[50];	
} Cliente;

typedef struct {
    Pessoa pessoa;
    char produto[50];
    float valor;
} Fornecedor;

int main() {
		Pessoa p1;
		strcpy(p1.nome, "Renato");
		p1.cpf = 98056756009;
		p1.rg = 5113456;
		
		Cliente clientes[10];
	
		for (int i = 0; i < 10; i++) {
				 
		printf("\nDigite o nome da pessoa: ");
		scanf("%f", &clientes[i].divida);
		printf("\nDigite a data do cadastro: ");
		scanf("%s", clientes[i].data_cadastro);
		}

}
