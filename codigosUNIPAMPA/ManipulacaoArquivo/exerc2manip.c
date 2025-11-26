/*2 - Ler números inteiros e armazená-los no arquivo (numeros.txt). Ler o arquivo
numeros.txt) e armazenar no arquivo (pares.txt) os valores pares e no (impares.txt) os
ímpares */

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	FILE *arq, *imp, *par;
	arq = fopen("numeros.txt", "w");
	int i = 1, valor;
	
	if (arq == NULL){
		printf("Erro ao abrir arquivo: ");
		return 0;
	};
	
	while(i == 1){
		printf("Insira números inteiros: ");
		scanf("%d", &valor);
		fprintf(arq, "%d\n", valor);
		printf("\nDeseja continuar? (1 - SIM || 0 - NAO): ");
		scanf("%d", &i);
	}
	
	fclose(arq);
	
	arq = fopen("numeros.txt", "r");
	par = fopen("pares.txt", "w");
	imp = fopen("impar.txt", "w");
	
    if (arq == NULL || par == NULL || imp == NULL) {
        printf("Erro ao abrir um dos arquivos.\n");
        return 0;
    }
    
    while(fscanf(arq, "%d", &valor) != EOF){
		if((valor % 2) == 0){
			fprintf(par, "%d\n", valor);
		}else{
			fprintf(imp, "%d\n", valor);
		 }
	}
	
	fclose(par);
	fclose(imp);
	
	return 0;
}
