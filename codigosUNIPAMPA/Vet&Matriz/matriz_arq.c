/* 
   3 - Escreva um programa que armazene números primos numa matriz. 
   5 - Retome o exercício 3, porém armazene-o num arquivo
*/

#include <stdio.h>

int main(){
	
	FILE *arq;
	int i = 0, j = 0, i2 = 0;
	int matriz[4][4], primo = 0, priS;
	
	arq = fopen("matriz.txt", "w");
	
	for(i = 0; i<4; i++){
		for(j = 0; j < 4; j++){
			printf("Insira os números da matriz: ");
			scanf("%d", &primo);
				
			if(primo < 2){
				priS = 0;
			}else{
				priS = 1;
				for (i2 = 2; i2 < primo; i2++) {
					if (primo % i2 == 0) { 
						priS = 0;
						break;
					}
				}
			 }
			 
			 if(priS == 1){
				 matriz[i][j] = primo;
			 }
			 else{
				 matriz[i][j] = 0;
			 }
		}
	}
		
	    printf("\nMatriz resultante:\n");
    	for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				printf(" %d", matriz[i][j]);
				fprintf(arq, " %d", matriz[i][j]);
			}
			printf(" \n");
			fprintf(arq, "\n");
		}
		
		fclose(arq);
	
	return 0;
}
