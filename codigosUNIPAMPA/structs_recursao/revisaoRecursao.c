/*Escreva uma função que calcula e retorna o valor do dobro de um número recebido por parâmetro.
Faça um programa que recebe um número e calcula e mostra o valor do seu dobro utilizando a
função definida.*/

#include <stdio.h>

int dobro(int num){
	int numDobro;
	
	numDobro = num * 2;
	
	return numDobro;
}

int main(){
	
	int num, numDobro;
	
	printf("Insira um numero: ");
	scanf("%d", &num);
	
	numDobro = dobro(num);
	
	printf("\nDobro do numero inserido: %d", numDobro);
	
	return 0;	
}
