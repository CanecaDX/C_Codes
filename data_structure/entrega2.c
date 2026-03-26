// Lista 2
// 26/03/26
// Leonardo Manzke, leonardomanzke.aluno@unipampa.edu.br

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
void exibeStruct(bandas *listaB, int numBandas);
void exibeUma(bandas listaB);
void exibeRanking(bandas *listaB, int numRank, int numBandas);
void exibeGenero(bandas *listaB, int tipo, int numBandas);
void nomeFav(bandas *listaB, char nomeBanda[50], int numBandas);

int main (){
	
	bandas *listaB = NULL;
	int numRank = 0, tipo = 0, opcao = 1, numBandas = 0;
	char nomeBanda[50];
	
		while(opcao != 0){
		printf("\n------------------------------------");
		printf("\n0_ Encerra programa");
		printf("\n1_ Inserir bandas.");
		printf("\n2_ Mostrar bandas.");
		printf("\n3_ Mostrar banda por genero");
		printf("\n4_ Mostrar bandas por ranking");
		printf("\n5_ Mostrar bandas pelo nome");
		printf("\n------------------------------------");
		printf("\nInforme a ação desejada: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 0: 
				printf("\nEncerrando programa");
				free(listaB);
			break;
			case 1:
				printf("Quantas bandas deseja inserir? ");
				scanf("%d", &numBandas);
				listaB = preencheStruct(listaB, numBandas);
			break;
			case 2:
				exibeStruct(listaB, numBandas);
			break;
			case 3:
				printf("\n");
				printf("\nInsira o genero que deseja buscar (1 - rock, 2 - metal, 3 - mpb, 4 - pagode, 5 - sertanejo, 6 - nu metal, 7 - eletronica): ");
				scanf("%d", &tipo);
				exibeGenero(listaB, tipo, numBandas);
			break;
			case 4:
				printf("\nInsira a posicao do ranking (1 a 5): ");
				scanf("%d", &numRank);
				exibeRanking(listaB, numRank, numBandas);
			break;
			case 5:
				printf("Insira o nome da banda que deseja buscar: ");
				scanf("%s", nomeBanda);
				nomeFav(listaB, nomeBanda, numBandas);
			break;
		}
	}

 return 0;			
}

bandas *preencheStruct(bandas *p, int numBandas){
	
	int i = 0;
	p = (bandas*)malloc(numBandas * sizeof(bandas));
	
	for(i = 0; i<numBandas; i++){
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

void exibeStruct(bandas *listaB, int numBandas){
	
	int i = 0;
	
	for(i = 0; i < numBandas; i++){
		exibeUma(listaB[i]);
	}
}

void exibeUma(bandas listaB){

	 printf("\n");
	 printf("\nNome da banda: %s", listaB.nome);
	 printf("\nGenero da banda: ");
	 switch(listaB.tipo){
				case 1:
					printf("Rock");
					break;
				case 2:
					printf("Metal");
					break;
				case 3:
					printf("MPB");
					break;
				case 4:
					printf("Pagode");
					break;
				case 5:
					printf("Sertanejo");
					break;
				case 6:
					printf("Nu Metal");
					break;
				case 7:
					printf("Eletronica");
					break;
				}
	 printf("\nNúmero de integrantes da banda: %d", listaB.integrantes);
	 printf("\nRanking da banda (top 5): %d", listaB.ranking);
}

void exibeRanking(bandas *listaB, int numRank, int numBandas){
	
	int i = 0;
	
	for(i = 0; i<numBandas; i++){
		 if(listaB[i].ranking == numRank){
			 exibeUma(listaB[i]);
		 }
	}
}

void exibeGenero(bandas *listaB, int tipo, int numBandas){
	
	int i = 0;
	
	printf("\nBandas com este genero na lista:");
	for(i = 0; i<numBandas; i++){
		 if(listaB[i].tipo == tipo){
			 exibeUma(listaB[i]);
		 }
	}
}

void nomeFav(bandas *listaB, char nomeBanda[50], int numBandas){
	
	int i;

	for(i = 0; i<numBandas; i++){
		if(strcmp(nomeBanda, listaB[i].nome) == 0 && listaB[i].ranking < 5){
			printf("\nEssa banda esta no seu top 5!");
			exibeUma(listaB[i]);
		}
		else{
			printf("\nEssa banda nao esta no seu top 5!");
		}
	}
	
}
