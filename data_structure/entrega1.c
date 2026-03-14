#include <stdio.h>
#include <stdlib.h>

int criaMatriz(int m, int n);
//void leiaMatriz(int mat, int m, int n)
//int somaMatriz(int **mat, int m, int n)
//int * colunaMat(int **mat, int m, int n, int ncoluna
//void liberaMatriz(int **mat, int ncoluna)
//void imprimeMatriz(int **mat, int m, int n)
//void imprimeVet (int *vet, int n)

int main(){
	
	int opcao, m, n, i = 0;

	while(i == 0) {
		printf ("\n1 - Criar matriz.");
		printf ("\n2 - Ler elementos da matriz.");
		printf ("\n3 - Soma dos elementos da matriz");
		printf ("\n4 - Retornar elmentos de uma coluna X");
		printf("\n5 - Encerra programa.");
		printf ("\nOpcao? ");
		scanf ("%d", &opcao);

		switch (opcao) {
		case 1:
			printf("\nQuantos numeros deseja inserir na linha? ");
			scanf("%d", &m);
			printf("\nQuantos numeros deseja inserir na coluna? ");
			scanf("%d", &n);
			criaMatriz(m, n);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
			printf("Encerrando programa.");
			return 0;
		}
	}
	
	return 0;			
}
	
int criaMatriz(int m, int n){
	
	int i, j;
	
	int **matriz = (int **)malloc(m * sizeof(int*));
	
	for(i = 0; i < m; i++){
			matriz[i] = (int *)malloc(n * sizeof(int));
	}
	
	printf("\nDigite os valores da matriz:\n");
    for (int i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("matriz[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    printf("\nMatriz digitada:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}


