/*Escreva uma função que retorna 1 se o número recebido por parâmetro é positivo, e 0 caso
contrário. Faça um programa que recebe um número e imprime se o número é positivo ou negativo
utilizando, para isso, a função definida.*/

#include <stdio.h>

int verifica(int num){
	int resu;
	
	if(num > 0){
		resu = 1;	
	}else{
		resu = 0;	
	}
	
	return resu;
}

int main(){
	
	int num, resu;
	
	printf("Insira um numero para verficacao: ");
	scanf("%d", &num);
	resu = verifica(num);
	
	printf("Resultado: %d", resu);
}
