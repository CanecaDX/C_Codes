/*Sistema de Gerenciamento de Funcionários com Arquivo Binário*/

#include <stdio.h>

struct Funcionario {
    int id;
    char nome[100];
    char cargo[100];
    float salario;
};
typedef struct Funcionario funcio;

funcio fun[100];
int total = 0;

// CARREGA ARQUIVO 
void carregarArquivo() {
    FILE *arquivo = fopen("funcionarios.bin", "rb");
    if (!arquivo) return;

    total = fread(fun, sizeof(funcio), 100, arquivo);
    fclose(arquivo);
}

// GRAVA ARQUIVO
void salvarArquivo() {
    FILE *arquivo = fopen("funcionarios.bin", "wb");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    fwrite(fun, sizeof(funcio), total, arquivo);
    fclose(arquivo);

    printf("Dados salvos com sucesso!\n");
}

// CADASTRO
void cadastro(int qtd) {
    for(int i = total; i < total + qtd; i++) {
        printf("Insira id do funcionario: ");
        scanf("%d", &fun[i].id);

        printf("Insira nome do funcionario: ");
        scanf(" %s", fun[i].nome);

        printf("Insira o cargo do funcionario: ");
        scanf(" %s", fun[i].cargo);

        printf("Insira o salario do funcionario: ");
        scanf("%f", &fun[i].salario);
    }

    total += qtd;
    salvarArquivo();
}

// LISTAR
void listar() {
    if (total == 0) {
        printf("Nenhum funcionario cadastrado.\n");
        return;
    }

    for(int i = 0; i < total; i++) {
        printf("ID: %d | Nome: %s | Cargo: %s | Salario: R$ %.2f\n",
               fun[i].id, fun[i].nome, fun[i].cargo, fun[i].salario);
    }
}

// BUSCA
void busca(int bus) {

    int encontrado = 0;

    for(int i = 0; i < total; i++) {
        if(bus == fun[i].id) {
            printf("ID: %d | Nome: %s | Cargo: %s | Salario: R$ %.2f\n",
                   fun[i].id, fun[i].nome, fun[i].cargo, fun[i].salario);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado){
        printf("Funcionario nao encontrado!\n");
    }
}

void modifica(int bus){
	
	int encontrado = 0;
	
	for(int i = 0; i < total; i++) {
        if(bus == fun[i].id) {
            printf("Atualize o cargo: ");
            scanf(" %s", fun[i].cargo);
			printf("Atualize o salario: ");
			scanf("%f", &fun[i].salario);
            encontrado = 1;
            break;
        }
    }
    
    if (encontrado){
        salvarArquivo();
	}
	else{
		printf("Funcionario nao encontrado!\n");
	}
}
// ================= REMOVER =================
void removerFuncionario(int bus) {

    FILE *arquivoOrig = fopen("funcionarios.bin", "rb");
    if (!arquivoOrig) {
        printf("Erro ao abrir arquivo original!\n");
        return;
    }

    FILE *temp = fopen("temp.bin", "wb");
    if (!temp) {
        printf("Erro ao abrir arquivo temporario!\n");
        fclose(arquivoOrig);
        return;
    }

    funcio f;
    int removido = 0;

    // Lê funcionário por funcionário e grava somente quem NÃO será removido
    while (fread(&f, sizeof(funcio), 1, arquivoOrig) == 1) {
        if (f.id != bus) {
            fwrite(&f, sizeof(funcio), 1, temp);
        } else {
            removido = 1;
        }
    }

    fclose(arquivoOrig);
    fclose(temp);

    // Substitui arquivo original pelo temporário
    remove("funcionarios.bin");
    rename("temp.bin", "funcionarios.bin");

    // Recarrega tudo na memória
    carregarArquivo();

    if (removido)
        printf("Funcionario removido com sucesso!\n");
    else
        printf("Funcionario nao encontrado!\n");        
}

void remover(int bus) {

    FILE *arquivoOrig = fopen("funcionarios.bin", "rb");
    if (!arquivoOrig) {
        printf("Erro ao abrir arquivo original!\n");
        return;
    }

    FILE *temp = fopen("temp.bin", "wb");
    if (!temp) {
        printf("Erro ao abrir arquivo temporario!\n");
        fclose(arquivoOrig);
        return;
    }

    funcio f;
    int removido = 0;

    // Lê funcionário por funcionário e grava somente quem NÃO será removido
    while (fread(&f, sizeof(funcio), 1, arquivoOrig) == 1) {
        if (f.id != bus) {
            fwrite(&f, sizeof(funcio), 1, temp);
        } else {
            removido = 1;
        }
    }

    fclose(arquivoOrig);
    fclose(temp);

    // Substitui arquivo original pelo temporário
    remove("funcionarios.bin");
    rename("temp.bin", "funcionarios.bin");

    // Recarrega tudo na memória
    carregarArquivo();

    if (removido)
        printf("Funcionario removido com sucesso!\n");
    else
        printf("Funcionario nao encontrado!\n");
}

int main() {

    carregarArquivo(); // carrega dados ao iniciar

    int opcao, qtd, bus, i = 1;

    while(i != 0) {
        printf("\n1 - Cadastrar novo funcionario.");
        printf("\n2 - Listar todos os funcionarios.");
        printf("\n3 - Buscar por id");
        printf("\n4 - Alterar dados de um funcionario");
        printf("\n5 - Remover funcionario");
        printf("\n0 - Encerra programa");
        printf("\nOpcao? ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\nQuantos funcionarios deseja inserir? ");
            scanf("%d", &qtd);
            cadastro(qtd);
            break;

        case 2:
            listar();
            break;

        case 3:
            printf("Insira id do funcionario a ser buscado: ");
            scanf("%d", &bus);
            busca(bus);
            break;
		case 4:
			printf("Insira id do funcionario a ser alterado: ");
			scanf("%d", &bus);
			modifica(bus);
			break;
		case 5:
			printf("Insira id do funcionarido a ser removido: ");
			scanf("%d", &bus);
			remover(bus);
			break;
        case 0:
            printf("Encerrando programa.\n");
            return 0;

        default:
            printf("Opcao invalida.\n");
        }
    }

    return 0;
}




