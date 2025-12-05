/*6: Alterando Valores em Vetor de Structs com Ponteiros
Crie uma struct Produto com os campos nome e preco.
Cadastre 3 produtos. Depois, crie uma função atualizarPreco() que receba um ponteiro para
struct e aumente o preço em 10%.
Use ponteiros para passar cada produto para a função e mostrar os preços atualizados.*/

#include <stdio.h>
#include <string.h>

struct produto{
	
	char nome[50];
	float preco;
};
typedef struct produto prod;
prod pro[100];


void cadastro(){
	
	int i;
	
	for(i = 0; i<3; i++){
		printf("Nome do produto: ");
		scanf(" %s", pro[i].nome);
		printf("Preco do produto: ");
		scanf("%f", &pro[i].preco);
	}
	
	return;
}

void atualizarPreco(prod *p){
	p->preco = p->preco * 1.10;
	
	return;
}

int main(){
	
	
	int opcao, i;
	int j = 1; 
	
	cadastro();
	
    while(j != 0){
		printf("\nDeseja atualizar os precos? (Digite 1 para sim || Digite 0 para não) ");
		scanf ("%d", &opcao);
		
		switch (opcao){
			case 1:
				for(i = 0; i < 3; i++){
					atualizarPreco(&pro[i]);  
				}
				printf("\nPreços atualizados!\n");
				break;

			case 0:
				j = 0;  
				break;
		}
	}
				
	    for(i = 0; i < 3; i++) {
        printf("Produto: %s | Preco atualizado: %.2f\n", pro[i].nome, pro[i].preco);
    }

	return 0;
}
