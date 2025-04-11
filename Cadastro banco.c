#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX__CONTAS 100

typedef struct{
    int numero;
    char titular[100];
    float saldo;
} Conta;

Conta contas[MAX__CONTAS];
int totalContas = 0;

void salvarContas(){
    FILE *f = fopen("contas.txt","w");
    if(!f){
        printf("Erro ao salvar as contas.\n");
        return;
    }
    for (int i = 0; i < totalContas; i++){
        fprintf(f, "%d\n%s\n%.2f\n", contas[i].numero, contas[i].titular, contas[i].saldo);
    }
    
    fclose(f);
    
}
void carregarContas(){
    FILE *f =fopen("contas.txt","r");
    if (!f) return;
    
    while(fscanf(f, "%d\n%[^\n]\%f\n", &contas{totalContas}.numero, contas[totalContas].titular,&contas[totalContas].saldo) == 3){
        totalContas++;
        if (totalContas >= MAX__CONTAS) break;
    }
    
    fclose(f);
}

void cadastrar(){
    if (total >= MAX){
        printf("Limite de cadastro atigindo.\n");
        return;
    }
    
    printf("Nome: ");
    getchar();
    fgets(pessoas[total].nome, 100, stdin);
    pessoas[total].nome[strcspn(pessoas[total].nome, "\n")] = '\0';
    
    printf("Idade: ");
    scanf("%d", &pessoas[total].idade);
    
    printf("CPF: ");
    scanf("%14s",pessoas[total].idade);
    
    total++;
    salvarDados();
    printf("Cadastro relizado com sucesso!\n");
}

void listar(){
    if(total == 0){
        printf("Nunhum cadastro encontrado.\n");
        return;
    }
    printf("=== Lista de Pessoas Cadastradas ===\n");
    for(int i = 0; i < total; i++){
        printf("%d) %s | %d anos | CPF: %s\n", i + 1, pessoas[i].nome, pessoas{i].idade, pessoas[i].cpf);
    }
}
void buscarPorNome(){
    char nomeBusca[100];
    int achou = 0;
    
    printf("Digite o nome a buscar: ");
    getchar();
    fgets(nomeBusca, 100, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
    
    for(int i = 0; i < total; i++){
        if(strstr(pessoas[i].nome, nomeBusca) != NULL){
            printf("Encontrado: %s | %d anos | CPF: %s\n", pessoas[i].nome, pessoas[i].idade,pessoas[i].cpf);
            achou = 1;
        }
    }
    
    if(!achou){
        printf("Nenhum nome encontrado.\n");
   }
}

void ordenarPorIdade(){
    Pessoa temp;
    for (int i = 0; i < total - 1; i++){
        for(int j = i + 1; j < total; j++){
            if(pessoas[i].idade > pessoas[j].idade){
                temp = pessoas[i];
                pesssoas [i] = pessoas[j];
                pessoas[j] = temp;
            }
        }
    }
    printf("Lista ordenada por idade com sucesso.\n");
}

int menu(){
    int opcao;
    printf("\n=== MENU ===\n");
    printf("1 - Cadastrar pessoa\n");
    printf("2 - Listar todos \n");
    printf("3 - Buscar por nome\n");
    printf("4 - Ordenar por idade\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    return opcao;
}
int main(){
    carregarDados();
    
    int op;
    do{
        op = menu();
        switch (op){
            case 1: cadastrar();break;
            case 2:listar();break;
            case 3: buscarPorNome();break;
            case 3: ordenarPorIdade();break;
            case 0: printf("Saindo...\n");break;
            default: printf("Opção inválida.\n");
        }
    } while (op != 0);
    
    return 0;
}
