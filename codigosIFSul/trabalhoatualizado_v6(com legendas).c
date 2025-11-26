#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
   int valor;
   struct nodo *prox;
   struct nodo *ant;   
}Nodo;

Nodo *inicio = NULL, *fim = NULL;
      
void insere(int elemento){
	Nodo *novo, *aux = inicio;
	
	novo = (Nodo*) malloc (sizeof (Nodo));
	//^Aloca espaço na memória
	novo->valor = elemento;  // |Aponta o ponteiro novo para o valor do elemento
	novo->prox = NULL;		//  |Mostra que o próximo valor em relação ao ponteiro está vazio
	novo->ant = NULL;	   //   |Mostra que o valor anterior em relação ao ponteiro está vazio 

    if (inicio == NULL){ // |Compara se o inicio for nulo(lista vazia
		inicio = novo;	//  |Adiciona o valor novo no inicio
		fim = novo;	   //   |O valor novo será o elemento final também
	}
	else{
		while(aux != NULL && aux->valor < novo->valor){	//|é o criterio para que o ponteiro Aux pare na lista
		aux = aux->prox;							   // |/
	}						   
		if(aux == inicio){		//|Compara se o auxiliar está no inicio da pilha
		novo->prox = inicio;   // |O ponteiro 'prox' aponta para o inicio
		inicio->ant = novo;   //  | O ponteiro anterior do 'inicio' vai apontar para o 'novo'
		inicio = novo;		 //___|parte do codigo responsável por adicionar o menor numero no inicio da pilha
		
		}else if(aux == NULL){ 	//|compara se o ponteiro auxiliar está apontando para um elemento vazio
		novo->ant = fim;	   // |O elemento novo estará apontando para o anterior que será o fim da pilha
		fim->prox = novo;	  //  |Posiciona o elemento 'novo' no fim da pilha
		fim = novo;			 //   |/
		}else {				//____|Parte do codigo responsável por adicionar o maior número no final
			
			novo->ant = aux->ant;   	//|O anterior do elemento 'novo' será igual ao anterior do 'aux'
			novo->prox = aux;      	   // |O próximo do novo ira apontar para o 'aux'
			aux->ant->prox = novo;	  //  |O anterior do aux que aponta para o próximo irá apontar para o novo
			aux->ant = novo;         //   |O anterior do aux apontará para o novo elemento inserido
									//____|Parte do codigo responsável por adicionar um número no meio da pilha (ex: 23 que é menor que 24 e maior que 10)
											//então a pilha vai ficar como: 10, 23, 24
		}
			}
	
}

void remover(int elemento){
	Nodo *aux;
	
	aux = inicio;
	
	while(aux != NULL && aux->valor != elemento){
		aux = aux->prox;	
	}
	
	if (aux == NULL)
		printf("Elemento nao esta na lista...\n");
	
	else{
		if (aux == inicio && aux == fim){
				inicio = fim = NULL;
		}
		
		else if (aux == inicio){
			inicio = inicio->prox;
			inicio->ant = NULL;
		}
		
		else if (aux == fim){
			fim = fim->ant;
			fim->prox = NULL;
		}
		
		printf("Elemento %d removido!", aux->valor);
		free(aux);	
	}
}

void mostra_inicio (){
	Nodo *aux = inicio;
	
    printf("\n");
	printf("NULL <-- "); 
	while (aux != NULL){
		if ((aux == inicio && aux->prox == NULL) || aux == fim)
			printf ("%d --> ", aux->valor);
		else
			printf ("%d <--> ", aux->valor);	
		aux = aux->prox;
	}
	printf("NULL "); 
	printf("\n");
}

void mostra_fim (){
	Nodo *aux = fim;
	
    printf("\n"); 
	printf("NULL <-- "); 
	while (aux != NULL){
		if ((aux == fim && aux->ant == NULL) || aux == inicio)
			printf ("%d --> ", aux->valor);
		else
			printf ("%d <--> ", aux->valor);	
		aux = aux->ant;
	}
	printf("NULL "); 
	printf("\n");
}


void procura_valor(){
	if(inicio == NULL || inicio == fim){ //verifica se a lista esta vazia
		printf("não vai rolar\n");
		}
		
		else{
			int v1; //define as variáveis >:3
			Nodo *a1; //define um ponteiro
			
			a1 = inicio;  //posiciona os dois ponteiros no inicio
			
			printf("Informe o valor que deseja procurar: ");
			scanf("%d", &v1);  //recebe o valor da posição do p1
	
			int posicao = 1;
			while(a1 != NULL){ //verifica se o ponteiro não atingiu o final da lista.
			if (a1->valor == v1){
			printf ("Valor %d esta na posicao %d\n", v1, posicao);
			return;
			}
				a1 = a1->prox; //percorre o ponteiro pela lista até chegar no valor indicado pelo usuario
				posicao++; //atualiza a posicao que o ponteiro aponta
			}			//assim podemos saber a posicao correta quando acharmos o valor
			
			if(a1 == NULL)
            printf("Valor nao encontrado\n");
        }

		
	}


void procura_posicao(){
	if(inicio == NULL || inicio == fim){ //verifica se a lista esta vazia
		printf("não vai rolar\n");
		}
		
		else{
			int p1; //define as variáveis >:3
			Nodo *a1; //define um ponteiro
			
			a1 = inicio;  //posiciona os dois ponteiros no inicio
			
			printf("Informe a posicao que deseja procurar: ");
			scanf("%d", &p1);  //recebe o valor da posição do p1
	
			
			for(int i = 0; i < p1-1; i++){	//O "-1" é para que o a1 não caia no número da frente pois um vetor começa pelo 0
			a1 = a1->prox;//^Percorre o a2 pela lista até chegar no valor indicado pelo usuario
			}		  
			
			 if(a1 != NULL){ //verifica se o ponteiro não atingiu o final da lista.
			 printf("a posicao contem o valor: %d\n", a1->valor);  //mostra o valor encontrado na posição desejada.
			 }
			
			 else
			 printf("Valor não encontrado");

		}
	}
	
	

void remover_n_maior(){
	if(inicio == NULL || inicio == fim){ //verifica se a lista esta vazia
	printf("não vai rolar\n");
	}
	
	Nodo *aux = fim;
	int n;
	
	printf("Digite o n-esimo maior que deseja remover: ");
	scanf("%d", &n);
	
	while(n-1 > 0 && aux != NULL){	//O "-1" é para que o a1 não caia no número da frente pois um vetor começa pelo 0
	aux = aux->ant; //Percorre o aux pela lista até chegar no valor indicado pelo usuario
	n--;
}
	if(aux == NULL){
	printf("ELemento não encontrado");
	}
	
	remover(aux->valor);

	}

void remover_n_menor(){
	Nodo *aux = inicio; //Variáveis >:3
	int n; //Variáveis >:3
	
	printf("Digite o n-esimo menor numero a ser removido: "); //coluna de texto que pede para inserir as informações
	scanf("%d", &n); //lê as informações enviadas

	if(aux != NULL){
	for(int k = 0; k < n-1; k++){
	//O "-1" é para que o k não caia no número da frente pois um vetor começa pelo 0
		
	aux = aux->prox;
	}//percorre o vetor segundo o for, para apagar o n-esimo menor numero
	
	remover(aux->valor);
	//remove o numero em que o ponteiro aux está
		}
	else if(aux == NULL){	
			printf("\nO numero indicado não existe!");
		}
	}

void troca_posicao(){
	if(inicio == NULL || inicio == fim){
		printf("não vai rolar\n");
		}
		
		else{
			int p1, p2; //define as variáveis >:3
			Nodo *a1, *a2; //define um ponteiro
			
			a1 = a2 = inicio;  //posiciona os dois ponteiros no inicio
			
			printf("Informe a primeira posicao que deseja trocar: ");
			scanf("%d", &p1);  //recebe o valor da posição do p1
			
			printf("Informe a segunda posicao que deseja trocar: ");
			scanf("%d", &p2);  //recebe o valor da posição do p2
			
		
			for(int i = 0; i < p1-1; i++){
			//O "-1" é para que o a1 não caia no número da frente pois um vetor começa pelo 0
			a1 = a1->prox;
			//^Percorre o a1 pela lista até chegar no valor indicado pelo usuario
			}
			for(int i = 0; i < p2-1; i++){	
			//O "-1" é para que o a1 não caia no número da frente pois um vetor começa pelo 0
			a2 = a2->prox;	
			//^Percorre o a2 pela lista até chegar no valor indicado pelo usuario	
		}
		int aux = a1->valor;
		//insere o valor da posição de a1 no aux
		a1->valor = a2->valor;
		//determina que o o valor de a1 é igual o de a2
		a2->valor = aux;
		//insere o valor de aux na posição de a2
		}
	}

void mostra_tamanho(){
	if(inicio == NULL || inicio == fim){
	printf("não vai rolar\n");
	}
	
	int posicao = 0;
	Nodo *aux = inicio;	
	
		while(aux != NULL){ //verifica se o ponteiro não atingiu o final da lista.
		aux = aux->prox;
		posicao++;
	}
		printf ("A lista tem %d elementos\n", posicao);
	
}

void limpar_lst(){
		Nodo *aux = inicio;

	printf("\nLimpando lista...");
	
	

	if(inicio == NULL || inicio == fim){
	//Compara se a tabela está vazia 
		printf("\nA lista já está vazia!\n");
		}
		else{
		//se a tabela não estiver vazia, o codigo abaixo vai ser executado >:3
		while(aux != NULL){
			//compara enquanto o ponteiro auxiliar for diferente de Null(não estiver vazio)
			aux=aux->prox;
			//Percorre a Lista
			if(aux != NULL)
			//compara se o auxiliar é diferente de null
				remover(aux->ant->valor);
				//remove o valor anterior ao auxiliar
				else if(aux == NULL)
				//compara se aux é igual a null
				remover(fim->valor);
				//remove o valor final da tabela ^v^
		}
	}
}

int main(void){
   int elemento;
   int opcao;
   
   do{
		printf ("\n1  - Insere elemento na lista");
		printf ("\n2  - Procurar um valor na lista por valor");
		printf ("\n3  - Procurar elemento por posicao");
		printf ("\n4  - Retira elemento da lista");
		printf ("\n5  - Remover n-esimo maior elemento da lista");
		printf ("\n6  - Remover n-esimo menor elemento da lista");
		printf ("\n7  - Trocar a posicaoo de dois elementos da lista");
		printf ("\n8  - Mostrar o tamanho da lista");
		printf ("\n9  - Mostrar a lista do inicio ao fim");
		printf ("\n10 - Mostrar a lista do fim ao inicio");
		printf ("\n11 - Limpar a lista");
		printf ("\n0  - Encerra programa");
		printf ("\nOpcao? ");
		scanf ("%d", &opcao);
		
		switch (opcao){
			case 0:
				printf("Encerrando o programa...\n");
				break;
			case 1:
				printf ("\nInforme valor a ser inserido: ");
				scanf ("%d", &elemento);
				insere(elemento);
				mostra_inicio();
				break;
				case 2:
					procura_valor();
				break;
				case 3:
				procura_posicao();
				break;
			case 4:
				if (inicio != NULL){
					printf("\nInforme valor a ser removido: ");
					scanf ("%d", &elemento);
					remover(elemento);
					if (inicio != NULL)
						mostra_inicio();
					}
				else
					printf("Lista vazia...\n");
				break;	
				case 5: 
					remover_n_maior();
				break;		
				case 6:
					remover_n_menor();
					break;
				case 7:
					troca_posicao();
					break;
				case 8:
					mostra_tamanho();
				break;
				case 9:
				if (inicio != NULL){
					mostra_inicio();
					}
				else
					printf("Lista vazia...\n");
				break;
				case 10:
					if (inicio != NULL){
						mostra_fim();
				}else{
					printf("Lista vazia...\n");
					}
					
				break;
				case 11:
					limpar_lst();
					break;
			default:
				printf("Opcao invalida!\n");
				break;	
			}
	}while(opcao != 0);
}
