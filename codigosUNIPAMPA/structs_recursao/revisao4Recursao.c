/* Escreva uma função que recebe um número inteiro positivo N como parâmetro, a mesma deve
retornar a soma de todos os números inteiros entre 1 e N (inclusive). Faça um programa que recebe
um número e imprime a soma de todos os números entre 1 e N utilizando, para isso, a função
definida.*/

#include <stdio.h>

void contagem(int num){
	
	int i = 1, soma = 0;
	
	for(i = 1; i <= num; i++){
		printf("\nContando: %d", i);
		soma += i;
	}
	
	printf("\nSoma de todos os números até %d: %d", num, soma);
	
}

int main(){
	
	int num;
	
	printf("Insira um numero: ");
	scanf("%d", &num);
	
	contagem(num);
	
	return 0;
}
