#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

#define MAX 100

typedef struct{
    char titulo[100];
    char autor[100];
    int ano;
    int emprestado;
} Livro;

Livro livros[MAX];
int total = 0;

void carregar(){
    FILE *f = fopen("livros.txt","r");
    if (f == NULL) return;
    
    while(fscanf(f, "%[^\n]\n%[^\n]\%d\n%d\n",
         livros[total].titulo,
         livros[total].autor,
         &livros[total].ano,
         &livros[total].emprestado) == 4){
    total++;
    if (total >= MAX) break;
    }
    
    fclose(f);
}

void salvar(){
    FILE *f = fopen("livros.txt", "w");
    for (int i = 0; i < total; i++){
        fprintf(f,"%s\n%s\n%d\n%d\n",
                livros[i].titulo,
                livros[i].autor,
                livros[i].ano,
                livros[i].emprestado);
    }
    fclose(f);
}

void cadastrar(){
    if(total >= MAX){
        printf("Limite de livros atingido.\n");
        return;
    }
    getchar();
    
    printf("Título: ");
    fgets(livros[total].titulo, 100,stdin);
    livros[total].titulo[strcspn(livros[total].titulo, "\n")] = '\0';
    
    printf("Ano: ");
    scanf("%d",&livros[total].ano);
    
    livros[total].emprestado = 0;
    
    total++;
    salvar();
    printf("Livro cadastrado com sucesso!\n");
}

void listar(){
    if(total == 0){
        printf("Nenhum livros cadastrado.\n");
        return;
    }
    
    printf("\n=== Lista de Livros ===\n");
    for(int i = 0; i < total;i++){
         printf("%d) \"%s\" por %s (%d) [%s]\n", 
               i + 1, 
               livros[i].titulo, 
               livros[i].autor, 
               livros[i].ano, 
               livros[i].emprestado ? "Emprestado" : "Disponível");
            
    }
}
 
void buscarPorTitulo(){
    char busca[100];
    int achou = 0;
    
    getchar();
    printf("Digite o título a buscar: ");
    fgets(busca, 100, stdin);
    busca[strcspn(busca, "\n")] = '\0';
    
    for(int i = 0; i < total; i++){
        if(strstr(livros[i].titulo, busca) != NULL){
            printf("Encontrado: \"%s" "por %s (%d) [%s]\n",
                    livros[i].titulo,
                    livros[i].autor,
                    livros[i].ano,
                    livros[i].emprestado ? "Emprestado" : "Disponível");
            achou = 1;        
        }
    }
    if(!achou)
        printf("Livro não encontrado.\n");
}

void emprestarLivro(){
    int indice;
    listar();
    printf("Digite o número do livro a emprestar: ");
    scanf("%d", &indice);
    indice--;
    
    if(indice < 0 || indice >= total){
        printf("Livro inválido.\n");
        return;
    }
    if (livros[indice].emprestado){
        printf("Esse livro já está emprestado.\n");
        return;
        
    }
    
    livros[indice].emprestado = 1;
    salvar();
    printf("Livro emprestado com sucesso.\n");
}
void devolverLivro(){
    int indice;
    listar();
    printf("Digite o número do livro a devolver: ");
    scanf("%d",&indice);
    indice--;
    
    if(indice < 0 || indice >= total){
        printf("Livro inválido.\n");
        return;
    }
    if (!livros[indice].emprestado){
        printf("Esse livro já está disponivél.\n");
        return;
    }
    livros[indice].emprestado = 0;
    salvar();
    printf("Livro devolvido com sucesso!\n");
}

int  menu(){
    int op;
    printf("\n=== MENU ===\n");
    printf("1 - Cadastrar livro\n");
    printf("2 - Listar livros\n");
    printf("3 - Buscar por título\n");
    printf("4 - Emprestar livro\n");
    printf("5 - Devolve livro\n");
    printf("0 - Sair\n");
    printf("Escolher: ");
    scanf("%d", &op);
    return op;
}

int main (){
    carregar();
    int op;
    do{
        op = menu();
        switch(op){
            case 1: cadastrar(); break;
            case 2: listar(); break;
            case 3: buscarPorTitulo(); break;
            case 4: emprestarLivro(); break;
            case 5: devolverLivro(); break;
            case 0: printf("Saindo..."); break;
            default: printf("Opção inválida.\n");
        }
    } while(op != 0);
    
    return 0;
}
