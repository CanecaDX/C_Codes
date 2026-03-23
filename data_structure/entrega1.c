// Lista 1
// 17/03/2026
// Leonardo Manzke (leonardomanzke.aluno@unipampa.edu.br)

#include <stdio.h>
#include <stdlib.h>

int** criaMatriz(int m, int n);
void leiaMatriz(int **mat, int m, int n);
int somaMatriz(int **mat, int m, int n);
int * colunaMat(int **mat, int m, int n, int ncoluna);
void liberaMatriz(int **mat, int *vet);
void imprimeMatriz(int **mat, int m, int n);
void imprimeVet (int *vet, int n);

int main(){
	
	int opcao, m, n, i = 0, soma = 0, ncoluna = 0;
	int **mat = NULL;
	int *vet = NULL;

	while(i == 0) {
		printf("\n");
		printf ("\n1 - Criar matriz.");
		printf ("\n2 - Ler elementos da matriz.");
		printf ("\n3 - Soma dos elementos da matriz");
		printf ("\n4 - Retornar elmentos de uma coluna X");
		printf("\n0 - Encerra programa.");
		printf ("\nOpcao? ");
		scanf ("%d", &opcao);

		switch (opcao) {
		case 1:
			liberaMatriz(mat, vet);
			printf("\nQuantos numeros deseja inserir na linha? ");
			scanf("%d", &m);
			printf("\nQuantos numeros deseja inserir na coluna? ");
			scanf("%d", &n);
			mat = criaMatriz(m, n);
			break;
		case 2:
			if(mat != NULL) {
				leiaMatriz(mat, m, n);
			}
			break;
		case 3:
			soma = somaMatriz(mat, m, n);
			printf("\nResultado da soma da matriz: %d", soma);
			break;
		case 4:
			printf("\nQual coluna deseja vizualizar? ");
			scanf("%d", &ncoluna);
			vet = colunaMat(mat, m, n , ncoluna);
			if(vet != NULL) {
				imprimeVet(vet, m);
			} else {
				printf("\nNenhuma coluna selecionads (case 4)");
			}
			break;
		case 0:
			printf("\nEncerrando programa.");
			return 0;
		}
	}
	
	return 0;			
}

void liberaMatriz(int **mat, int *vet) {
	 
	 
	if(mat != NULL) {
		free(mat);
	}
		
	if(vet != NULL){
		free(vet);
	}
}
	
int** criaMatriz(int m, int n){
	
	int i;
	
	int **mat = (int **)malloc(m * sizeof(int*));
	for(i = 0; i < m; i++){
			mat[i] = (int *)malloc(n * sizeof(int));
	}
    
    return mat;
}


void leiaMatriz(int **mat, int m, int n){
	
	int i, j;
	
	printf("\nDigite os valores da matriz:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("matriz[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
	
	imprimeMatriz(mat, m, n);
	
}

int somaMatriz(int **mat, int m, int n){
	
	int i, j, soma = 0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
           soma += mat[i][j];
        }
    }
    
    return soma;
}

int* colunaMat(int **mat, int m, int n, int ncoluna){
	
	int i;
	
	int *vet = (int *)malloc(m * sizeof(int));
	
        for (i = 0; i < m; i++) {
            vet[i] = mat[i][ncoluna];
        }
   
	return vet;
}

void imprimeVet(int *vet, int n){
	
	int i;
	
	  for (i = 0; i < n; i++) {
            printf("%d\n", vet[i]);
      }
}

void imprimeMatriz(int **mat, int m, int n) { 
	
	int i, j;
	
	printf("\nMatriz digitada:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

}


