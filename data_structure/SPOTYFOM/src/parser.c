#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

void carregaArquivo(char nome[256], descritorS *listaSE){

	char line[512];
	int i, cont = 0;
	
	FILE *acervo = fopen(nome, "r");
	if (!acervo) {
		perror("Erro ao abrir o arquivo !\n");
		return;
	}
	
	char lim[512];
	fgets(lim, sizeof(lim), acervo);
	int numMusicas = atoi(lim);
	
	 for (i = 0; i < numMusicas; i++) {
		if (fgets(line, sizeof(line), acervo) != NULL){    
            musica *song = (musica*)malloc (sizeof(musica));
            nodoS *elemento = NULL;
            
            line[strcspn(line, "\n\r")] = '\0';
            char copia[512];
			strcpy(copia, line);
            
			strcpy(song->artista, strtok(copia, ";"));
			song->codigo = atoi(strtok(NULL, ";"));
			strcpy(song->titulo, strtok(NULL, ";"));
			strcpy(song->letra, strtok(NULL, ";"));
			cont++;

			elemento = criaNodoS(song);
			insereS(listaSE, elemento, cont);
		} 	
    }
    
    printf("Acervo carregado com sucesso!");
	fclose(acervo);
}

void carregaBackup(char nome[256], descritorS *listaSE){

	char line[512];
	int i, cont = 0;
	
	FILE *acervo = fopen(nome, "r");
	if (!acervo) {
		perror("Erro ao abrir o arquivo !\n");
		return;
	}
	
	char lim[512];
	fgets(lim, sizeof(lim), acervo);
	int numMusicas = atoi(lim);
	
	 for (i = 0; i < numMusicas; i++) {
		if (fgets(line, sizeof(line), acervo) != NULL){    
            musica *song = (musica*)malloc (sizeof(musica));
            nodoS *elemento = NULL;
            
            line[strcspn(line, "\n\r")] = '\0';
            char copia[512];
			strcpy(copia, line);
            
			strcpy(song->artista, strtok(copia, ";"));
			song->codigo = atoi(strtok(NULL, ";"));
			strcpy(song->titulo, strtok(NULL, ";"));
			strcpy(song->letra, strtok(NULL, ";"));
			song->execucoes = atoi(strtok(NULL, ";"));
			cont++;

			elemento = criaNodoS(song);
			insereS(listaSE, elemento, cont);
		} 	
    }
    
    printf("Acervo carregado com sucesso!");
	fclose(acervo);
}

void salvar_acervo(descritorS *listaSE, char nome[256]){
	
	FILE *acervo = fopen(nome, "r");
	if (!acervo) {
		perror("Erro ao abrir o arquivo !\n");
		return;
	}
	
	char lim[512];
	fgets(lim, sizeof(lim), acervo);
	int numMusicas = atoi(lim);
	fclose(acervo);

	FILE *arquivo = fopen("acervoBackup.txt", "w");
	if (!arquivo) {
		printf("Erro ao abrir o arquivo para escrita!\n");
		return;
	}
	
	nodoS *aux = listaSE->inicio;

	fprintf(arquivo, "%d \n", numMusicas);
	while(aux != NULL){
		fprintf(arquivo, "%s;%d;%s;%s;%d\n",
				aux->info->artista,
				aux->info->codigo,
		        aux->info->titulo,    
		        aux->info->letra,	         
		        aux->info->execucoes
		);
		aux = aux->prox;
	}

	fclose(arquivo);
	printf("Acervo salvo com sucesso!\n");
}

