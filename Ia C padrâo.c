#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define MAX_USUARIOS 100

struct DadosUsuarios {
    char nome[MAX_USUARIOS][100]; // Ajustado para um tamanho razo�vel
    int idade[MAX_USUARIOS];
    float altura[MAX_USUARIOS];
    int diaNascimento[MAX_USUARIOS];
    int mesNascimento[MAX_USUARIOS];
    int anoNascimento[MAX_USUARIOS];
    char sexo[MAX_USUARIOS][20];
    char estadoCivil[MAX_USUARIOS][20];
    char curso[MAX_USUARIOS][50];
    char matricula[MAX_USUARIOS][20];
    char endereco[MAX_USUARIOS][100];
    char materias[MAX_USUARIOS][200];
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    int numUsuarios;
    int i;

    printf("Digite o n�mero de usu�rios que deseja cadastrar (m�ximo %d): ", MAX_USUARIOS);
    scanf("%d", &numUsuarios);
    getchar(); // Limpar o buffer do teclado

    if (numUsuarios > MAX_USUARIOS || numUsuarios <= 0) {
        printf("N�mero de usu�rios inv�lido.\n");
        return 1;
    }

    struct DadosUsuarios usuarios;

    for (i = 0; i < numUsuarios; i++) {
        printf("\n======== Dados do usu�rio %d =========\n", i + 1);

        printf("Nome: ");
        scanf("%99[^\n]", usuarios.nome[i]);
        getchar();

        printf("Idade: ");
        scanf("%d", &usuarios.idade[i]);
        getchar();

        printf("Altura: ");
        scanf("%f", &usuarios.altura[i]);
        getchar();

        printf("Data de Nascimento (dd mm aaaa): ");
        scanf("%d %d %d", &usuarios.diaNascimento[i], &usuarios.mesNascimento[i], &usuarios.anoNascimento[i]);
        getchar();

        printf("Sexo: ");
        scanf("%19[^\n]", usuarios.sexo[i]);
        getchar();

        printf("Estado Civil: ");
        scanf("%19[^\n]", usuarios.estadoCivil[i]);
        getchar();

        printf("Curso: ");
        scanf("%49[^\n]", usuarios.curso[i]);
        getchar();

        printf("Matr�cula: ");
        scanf("%19[^\n]", usuarios.matricula[i]);
        getchar();

        printf("Endere�o: ");
        scanf("%99[^\n]", usuarios.endereco[i]);
        getchar();

        printf("Mat�rias: ");
        scanf("%199[^\n]", usuarios.materias[i]);
        getchar();
    }

    // Imprimir os dados dos usu�rios
    printf("\n======== Dados dos Usu�rios Cadastrados =========\n");
    for (i = 0; i < numUsuarios; i++) {
        printf("\n-------- Usu�rio %d --------\n", i + 1);
        printf("Nome: %s\n", usuarios.nome[i]);
        printf("Idade: %d\n", usuarios.idade[i]);
        printf("Altura: %.2f\n", usuarios.altura[i]);
        printf("Data de Nascimento: %02d/%02d/%04d\n", usuarios.diaNascimento[i], usuarios.mesNascimento[i], usuarios.anoNascimento[i]);
        printf("Sexo: %s\n", usuarios.sexo[i]);
        printf("Estado Civil: %s\n", usuarios.estadoCivil[i]);
        printf("Curso: %s\n", usuarios.curso[i]);
        printf("Matr�cula: %s\n", usuarios.matricula[i]);
        printf("Endere�o: %s\n", usuarios.endereco[i]);
        printf("Mat�rias: %s\n", usuarios.materias[i]);
    }

    return 0;
}
