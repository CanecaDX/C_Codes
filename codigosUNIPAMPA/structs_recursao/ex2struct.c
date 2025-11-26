/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

struct bandas{
    char nome[50];
    char tipo[50];
    int num;
}; 

void exibe(int esc, struct bandas vet[5]){
    int i = 0;
    if(esc == 1){
        for(i=0; i<1; i++){
            printf("\nNome da banda: %s", vet[i].nome);
            printf("\nTipo da banda: %s", vet[i].tipo);
            printf("\nNúmero de integrantes: %d", vet[i].num);
        }
    }else if(esc == 2){
        for(i=1; i<2; i++){
            printf("\nNome da banda: %s", vet[i].nome);
            printf("\nTipo da banda: %s", vet[i].tipo);
            printf("\nNúmero de integrantes: %d", vet[i].num);
        }
    }else if(esc == 3){
        for(i=2; i<3; i++){
            printf("\nNome da banda: %s", vet[i].nome);
            printf("\nTipo da banda: %s", vet[i].tipo);
            printf("\nNúmero de integrantes: %d", vet[i].num);
        }
    }else if(esc == 2){
        for(i=3; i<4; i++){
            printf("\nNome da banda: %s", vet[i].nome);
            printf("\nTipo da banda: %s", vet[i].tipo);
            printf("\nNúmero de integrantes: %d", vet[i].num);
        }
    }else if(esc == 2){
        for(i=4; i<5; i++){
            printf("\nNome da banda: %s", vet[i].nome);
            printf("\nTipo da banda: %s", vet[i].tipo);
            printf("\nNúmero de inegrantes %d", vet[i].num);
        }
    }
}

int main()
{
    int i, esc;
    struct bandas vet[5];
    
    for(i = 0; i<5; i++){
        printf("\nInsira o nome da banda: ");
        scanf(" %s", &vet[i].nome);
        printf("Insira o tipo da banda: ");
        scanf(" %s", &vet[i].tipo);
        printf("Insira o numero de integrantes da banda: ");
        scanf(" %d", &vet[i].num);
    }
    
    printf("Insira um numero para exibir a posicao no ranking: ");
    scanf("%d", &esc);
    exibe(esc, vet);

    return 0;
}