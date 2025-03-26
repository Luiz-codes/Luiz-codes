#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char nome[50];
    int idade;
} Pessoa;

void cadastrar();
void listar();
void alterar();
void deletar();
int buscarPorID(int id);

FILE *arquivo;

int main() {
    int opcao;
    
    do {
        printf("\n=== MENU ===\n");
        printf("1 - Cadastrar Pessoa\n");
        printf("2 - Listar Pessoas\n");
        printf("3 - Alterar Pessoa\n");
        printf("4 - Deletar Pessoa\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: cadastrar(); break;
            case 2: listar(); break;
            case 3: alterar(); break;
            case 4: deletar(); break;
            case 5: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while(opcao != 5);
    
    return 0;
}

void cadastrar() {
    Pessoa p;
    arquivo = fopen("dados.dat", "ab");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    printf("ID: ");
    scanf("%d", &p.id);
    printf("Nome: ");
    scanf(" %[^\n]", p.nome);
    printf("Idade: ");
    scanf("%d", &p.idade);
    
    fwrite(&p, sizeof(Pessoa), 1, arquivo);
    fclose(arquivo);
    
    printf("Cadastro realizado com sucesso!\n");
}

void listar() {
    Pessoa p;
    arquivo = fopen("dados.dat", "rb");
    
    if (arquivo == NULL) {
        printf("Nenhum dado cadastrado.\n");
        return;
    }
    
    printf("\n=== Lista de Pessoas ===\n");
    while (fread(&p, sizeof(Pessoa), 1, arquivo)) {
        printf("ID: %d | Nome: %s | Idade: %d\n", p.id, p.nome, p.idade);
    }
    
    fclose(arquivo);
}

void alterar() {
    Pessoa p;
    int id, encontrado = 0;
    
    printf("Digite o ID da pessoa a ser alterada: ");
    scanf("%d", &id);
    
    FILE *temp = fopen("temp.dat", "wb");
    arquivo = fopen("dados.dat", "rb");
    
    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }
    
    while (fread(&p, sizeof(Pessoa), 1, arquivo)) {
        if (p.id == id) {
            printf("Novo Nome: ");
            scanf(" %[^\n]", p.nome);
            printf("Nova Idade: ");
            scanf("%d", &p.idade);
            encontrado = 1;
        }
        fwrite(&p, sizeof(Pessoa), 1, temp);
    }
    
    fclose(arquivo);
    fclose(temp);
    
    remove("dados.dat");
    rename("temp.dat", "dados.dat");
    
    if (encontrado)
        printf("Dados alterados com sucesso!\n");
    else
        printf("ID nao encontrado.\n");
}

void deletar() {
    Pessoa p;
    int id, encontrado = 0;
    
    printf("Digite o ID da pessoa a ser deletada: ");
    scanf("%d", &id);
    
    FILE *temp = fopen("temp.dat", "wb");
    arquivo = fopen("dados.dat", "rb");
    
    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }
    
    while (fread(&p, sizeof(Pessoa), 1, arquivo)) {
        if (p.id != id) {
            fwrite(&p, sizeof(Pessoa), 1, temp);
        } else {
            encontrado = 1;
        }
    }
    
    fclose(arquivo);
    fclose(temp);
    
    remove("dados.dat");
    rename("temp.dat", "dados.dat");
    
    if (encontrado)
        printf("Pessoa deletada com sucesso!\n");
    else
        printf("ID nao encontrado.\n");
}
