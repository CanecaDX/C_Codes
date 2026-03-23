#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum{
	rock = 1 ,
	metal,
	mpb,
	pagode,
	sertanejo,
	numetal,
	eletronica
} genero;

typedef struct bandas{
	char nome[20];
	genero tipo;
	int integrantes;
	int ranking;
} bandas;

bandas* preencheStruct();
void exibeStruct(bandas *listaB);
void exibeUma(bandas listaB);
void exibeRanking(bandas *listaB, int numRank);
void exibeGenero(bandas *listaB, int tipo);

int main (){
	
	
	bandas *listaB = NULL;
	int numRank = 0, tipo;
	
	listaB = preencheStruct();
	exibeStruct(listaB);
	
	printf("Insira um numero de 1 a 5: ");
	scanf("%d", &numRank);
	
	exibeRanking(listaB, numRank);
	
	printf("\nInsira o genero que deseja buscar: ");
	scanf("%d", &tipo);

 return 0;			
}

bandas* preencheStruct(){
	
	int i = 0;
	bandas *p = (bandas*)malloc(3 * sizeof(bandas));
	
	for(i = 0; i<3; i++){
	 printf("\nInsira dados da %d° banda: ", i+1);
	 printf("\nInsira o nome da banda: ");
	 scanf("%s", p[i].nome);
	 printf("\n1 - ROCK\n");
	 printf("2 - METAL\n");
	 printf("3 - MPB\n");
	 printf("4 - PAGODE\n");
	 printf("5 - SERTANEJO\n");
	 printf("6 - NU METAL\n");
	 printf("7 - ELETRONICA\n");	 
	 printf("\nEscolha o genero da banda: ");
	 scanf("%d", &p[i].tipo);
	 printf("Insira o número de integrantes da banda: ");
	 scanf("%d", &p[i].integrantes);
	 printf("Insira o ranking da banda (top 5): ");
	 scanf("%d", &p[i].ranking);
	}
	
 return p;
}

void exibeStruct(bandas *listaB){
	
	int i = 0;
	
	for(i = 0; i<4; i++){
		exibeUma(listaB[i]);
	}
}

void exibeUma(bandas listaB){

	 printf("\n");
	 printf("\nNome da banda: %s", listaB.nome);
	 printf("\nGenero da banda: ");
	 switch(listaB.tipo){
				case 1:
					printf("Metal\n");
					break;
				case 2:
					printf("Rock\n");
					break;
				case 3:
					printf("MPB\n");
					break;
				case 4:
					printf("Pagode\n");
					break;
				case 5:
					printf("Sertanejo\n");
					break;
				case 6:
					printf("Nu Metal\n");
					break;
				case 7:
					printf("Eletronica\n");
					break;
				}
	 printf("\nNúmero de integrantes da banda: %d", listaB.integrantes);
	 printf("\nRanking da banda (top 5): %d", listaB.ranking);
}

void exibeRanking(bandas *listaB, int numRank){
	
	int i = 0;
	
	for(i = 0; i<4; i++){
		 if(listaB[i].ranking == numRank){
			 exibeUma(listaB[i]);
		 }
	}
}

void exibeGenero(bandas *listaB, int tipo){
	
	int i = 0;
	
	for(i = 0; i<4; i++){
		 if(listaB[i].tipo == tipo){
			 exibeUma(listaB[i]);
		 }
	}
}
