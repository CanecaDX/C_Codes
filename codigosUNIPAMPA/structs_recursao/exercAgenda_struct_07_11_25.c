#include <stdio.h>
#include <string.h>

struct endereco{
    char rua[30];
    int numero;
    int cep;
    char cidade[30];
    char estado[30];
    char pais[10];
};
typedef struct endereco End;

struct telefone{
    int ddd;
    int numero;
};
typedef struct telefone Tel;

struct aniversario{
    int dia;
    int mes;
    int ano;
};

struct dados{
    char nome[40];
    char email[40];
    End endereco1;
    Tel telefone1;
    struct aniversario data;
    char obs[30];
};
typedef struct dados DADOS;
DADOS contatos[100];
int total = 0;

void insere(int qtd){
    int i = 0;
    
    for(i = 0; i<qtd; i++){
        printf("Insira nome do contato: ");
        scanf(" %s", contatos[i].nome);
        printf("\nInsira email do contato: ");
        scanf(" %s", contatos[i].email);
        printf("\nInsira os dados de endereco do contato: ");
            printf("\nInserir rua: ");
            scanf(" %s", contatos[i].endereco1.rua);
            printf("Inserir numero: ");
            scanf("%d", &contatos[i].endereco1.numero);
            printf("Inserir CEP: ");
            scanf("%d", &contatos[i].endereco1.cep);
            printf("Inserir cidade: ");
            scanf(" %s", contatos[i].endereco1.cidade);
            printf("Inserir estado: ");
            scanf(" %s", contatos[i].endereco1.estado);
            printf("Inserir pais: ");
            scanf(" %s", contatos[i].endereco1.pais);
        printf("Insira dados de telefone do contato: ");
            printf("\nDDD: ");
            scanf("%d", &contatos[i].telefone1.ddd);
            printf("Numero do contato: ");
            scanf("%d", &contatos[i].telefone1.numero);
        printf("\nInsira data de nascimento do contato: ");
            printf("\nDia: ");
            scanf("%d", &contatos[i].data.dia);
            printf("Mes: ");
            scanf("%d", &contatos[i].data.mes);
            printf("Ano: ");
            scanf("%d", &contatos[i].data.ano);
    }
    total += qtd;
    printf("\n contato(s) adicionado(s).\n");
}

void buscarNome(){
    char busca[40];
    int i;
    
    printf("Digite o primeiro nome: ");
    scanf("%s", busca);
    
    for(i = 0; i < total; i++){
            if(strcmp(contatos[i].nome, busca) == 0){
            printf("\nNome: %s | Email: %s\n", contatos[i].nome, contatos[i].email);
            }   
            else{
                printf("\nNenhum contato encontrado.\n");
            }
    }
     
}

void buscarMes(){
    int mes;
    int i;
    
    printf("Insira o mes de aniversario que deseja buscar (1-12): ");
    scanf("%d", &mes);
    
        for(i = 0; i < total; i++){
            if(contatos[i].data.mes == mes){
            printf("\nNome: %s | Email: %s\n", contatos[i].nome, contatos[i].email);
            }   
            else{
                printf("\nNenhum contato encontrado.\n");
            }
        }
    
}

void buscarMes_Dia(){
    
    int mes, dia;
    int i;
    
    printf("Insira o mes de aniversario que deseja buscar (1-12): ");
    scanf("%d", &mes);
    printf("Insira o dia de aniversario que deseja buscar (1-31): ");
    scanf("%d", &dia);
    
        for(i = 0; i < total; i++){
            if(contatos[i].data.mes == mes && contatos[i].data.dia == dia){
            printf("\nNome: %s | Email: %s\n", contatos[i].nome, contatos[i].email);
            }   
            else{
                printf("\nNenhum contato encontrado.\n");
            }
        }
}

void remover(){
    char busca[40];
    int i, j;
    printf("Nome do contato a remover: ");
    scanf("%s", busca);

    for(i = 0; i < total; i++){
        if(strcmp(contatos[i].nome, busca) == 0){
            for(j = i; j < total - 1; j++){
                contatos[j] = contatos[j+1];
            }
            total--;
            printf("\nContato removido.\n");
            return;
        }
    }
    printf("\nContato não encontrado.\n");
} 

void imprimeTudo(){
    int i;
    if(total == 0){
        printf("\nNão há contatos salvos.\n");
        return;
    }
    for(i = 0; i < total; i++){
        printf("\nContato %d\n", i+1);
        printf("Nome: %s\nEmail: %s\nTelefone: (%d) %d\nAniversário: %d/%d/%d\n",
        contatos[i].nome, contatos[i].email,
        contatos[i].telefone1.ddd, contatos[i].telefone1.numero,
        contatos[i].data.dia, contatos[i].data.mes, contatos[i].data.ano);
    }
}

int main()
{
   int opcao, i = 1, qtd;
   
    while(i != 0){
		printf ("\n1 - Adicionar novo contato na agenda.");
		printf ("\n2 - Buscar a partir do primeiro nome.");
		printf ("\n3 - Buscar por mes de aniversario");
		printf ("\n4 - Busca por dia e mes de aniversario");
		printf("\n5 - Insere apenas um contato");
		printf("\n6 - Retira pessoa");
		printf("\n7 - Imprime todos os dados");
		printf ("\n0 - Encerra programa");
		printf ("\nOpcao? ");
		scanf ("%d", &opcao);
		
		switch (opcao){
			case 1:
			    printf("\nQuantos contatos deseja inserir? ");
			    scanf("%d", &qtd);
				insere(qtd);
				break;
			case 2:
			    buscarNome();
			    break;
			case 3:
			    buscarMes();
			    break;
			case 4:
			    buscarMes_Dia();
			    break;
			case 5:
			    insere(1);
			    break;
			case 6:
			    remover();
			    break;
			case 7:
			    imprimeTudo();
			    break;
			case 0:
			    printf("Encerrando programa.");
			    return 0;
	    }
    }

    return 0;
}
