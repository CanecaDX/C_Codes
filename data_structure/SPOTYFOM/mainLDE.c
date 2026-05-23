#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LDE.h"
#include "LSE.h"
#include "fila.h"
#include "pilha.h"
#include "musica.h"

int main(){
	
	int op = 1
	
	while(op != 0){
		printf("\n--------------SPOTYFOM--------------");
		printf("\n------------------------------------");
		printf("\n0_ Encerra programa.");
		printf("\n1_ Carregar acervo.");
		printf("\n2_ Executar uma musica.");
		printf("\n3_ Buscar musica.");
		printf("\n4_ Impressao de informaçoes de uma musica.");
		printf("\n5_ Criar playlists.");
		//printf("\n6_ Remover música.");
		printf("\n------------------------------------");
		printf("\nInforme a ação desejada: ");
		scanf("%d", &op);

		switch(op){
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				switch(bus){
					case 1:
						break;
					case 2:
						break;
					case 3:

						break;
					case 4:
						break;
				}
				break;
			case 4:
				switch(bus){
					case 1:
						break;
					case 2:
						break;
					case 3:

						break;
					case 4:
						break;
				}
				break;
			case 5:
				break;
		}
	}
	
	return 0;	
}
