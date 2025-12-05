/*Solicite ao usuário uma string (frase). Conte quantas vogais, consoantes e dígitos numéricos ela
contém.*/

#include <stdio.h>
#include <string.h>

void verifica(char frase[50]){
	
	int vog = 0, conso = 0, num = 0, i = 0;
	
	for(i = 0; i<strlen(frase); i++){
		
        if(frase[i] >= '0' && frase[i] <= '9'){
            num++;
        }
        else if(frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u' ||
                frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U'){
            vog++;
        }
        else if( (frase[i] >= 'A' && frase[i] <= 'Z') ||
                 (frase[i] >= 'a' && frase[i] <= 'z') ){
            conso++;
        }
	}
	
	printf("\nQuantidade de vogais: %d", vog);
	printf("\nQuantidade de consoantes: %d", conso);
	printf("\nQuantidade de numericos: %d", num);
}
	


int main(){
	
	char frase[50];
	
	printf("Insira uma frase: ");
	scanf( "%s", frase);
	
	verifica(frase);
	
	return 0;
}
