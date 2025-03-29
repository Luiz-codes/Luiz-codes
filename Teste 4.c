#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100

// Estrutura para armazenar os dados de um aluno
struct DadosAluno {
    char curso[100];
    char turma[100];
    char unidadeCurricular[1000];
    char nome[100];
    char matricula[100];
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;
    char endereco[100];
    char telefone[100];
    float notas[3];
    float media;
    char condicaoFinal[100];
};

// Função para exibir os dados de um aluno
void exibirAluno(struct DadosAluno aluno) {
    printf("\n-------- Aluno --------\n");
    printf("Curso: %s", aluno.curso);
    printf("Turma: %s", aluno.turma);
    printf("Unidade Curricular: %s", aluno.unidadeCurricular);
    printf("Nome: %s", aluno.nome);
    printf("Matrícula: %s", aluno.matricula);
    printf("Data de Nascimento: %02d/%02d/%04d\n",
           aluno.diaNascimento, aluno.mesNascimento, aluno.anoNascimento);
    printf("Endereço: %s", aluno.endereco);
    printf("Telefone: %s", aluno.telefone);
    printf("Notas: %.2f, %.2f, %.2f\n", aluno.notas[0], aluno.notas[1], aluno.notas[2]);
    printf("Média: %.2f\n", aluno.media);
    printf("Condição Final: %s\n", aluno.condicaoFinal);
}

// Função para alterar os dados de um aluno
void alterarAluno(struct DadosAluno *aluno) {
    printf("Digite os novos dados para o aluno %s:\n", aluno->nome);

    printf("Curso: ");
    fgets(aluno->curso, sizeof(aluno->curso), stdin);

    printf("Turma: ");
    fgets(aluno->turma, sizeof(aluno->turma), stdin);

    printf("Unidade Curricular: ");
    fgets(aluno->unidadeCurricular, sizeof(aluno->unidadeCurricular), stdin);

    printf("Nome: ");
    fgets(aluno->nome, sizeof(aluno->nome), stdin);

    printf("Matrícula: ");
    fgets(aluno->matricula, sizeof(aluno->matricula), stdin);

    // Remover o \n no final da matrícula
    aluno->matricula[strcspn(aluno->matricula, "\n")] = '\0';

    printf("Data de Nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &aluno->diaNascimento, &aluno->mesNascimento, &aluno->anoNascimento);
    getchar();

    printf("Endereço: ");
    fgets(aluno->endereco, sizeof(aluno->endereco), stdin);

    printf("Telefone: ");
    fgets(aluno->telefone, sizeof(aluno->telefone), stdin);

    aluno->media = 0;
     int i;
    for ( i = 0; i < 3; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &aluno->notas[i]);
        getchar();
        aluno->media += aluno->notas[i];
    }
    aluno->media /= 3;

    if (aluno->media >= 7.0) {
        snprintf(aluno->condicaoFinal, sizeof(aluno->condicaoFinal), "Aprovado");
    } else if (aluno->media >= 5.0) {
        snprintf(aluno->condicaoFinal, sizeof(aluno->condicaoFinal), "Recuperação");
    } else {
        snprintf(aluno->condicaoFinal, sizeof(aluno->condicaoFinal), "Reprovado");
    }
}

// Função para deletar um aluno
void deletarAluno(struct DadosAluno alunos[], int *numAlunos, int index) {
	int i;
    for ( i = index; i < (*numAlunos) - 1; i++) {
        alunos[i] = alunos[i + 1];
    }
    (*numAlunos)--;
    printf("Aluno deletado com sucesso.\n");
}

// Função para consultar um aluno pelo número da matrícula
int consultarAluno(struct DadosAluno alunos[], int numAlunos, char matricula[]) {
	int i;
    for ( i = 0; i < numAlunos; i++) {
        if (strcmp(alunos[i].matricula, matricula) == 0) {
            exibirAluno(alunos[i]);
            return i;
        }
    }
    printf("Aluno não encontrado.\n");
    return -1;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int numAlunos = 0, i, j;
    int opcao, index;
    char matricula[100];

    struct DadosAluno alunos[MAX_ALUNOS];

    do {
        printf("\n======== MENU PRINCIPAL ========\n");
        printf("1. Cadastro de Novos Alunos\n");
        printf("2. Consultar Aluno\n");
        printf("3. Alterar Dados do Aluno\n");
        printf("4. Deletar Aluno\n");
        printf("5. Exibir Todos os Alunos\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer

        switch (opcao) {
            case 1: {
                printf("Digite o número de alunos que deseja cadastrar (máximo %d): ", MAX_ALUNOS);
                scanf("%d", &numAlunos);
                getchar(); // Limpar o buffer

                if (numAlunos > MAX_ALUNOS || numAlunos <= 0) {
                    printf("Número de alunos inválido.\n");
                    break;
                }

                for (i = 0; i < numAlunos; i++) {
                    printf("\n======== Cadastro do Aluno %d ========\n", i + 1);

                    printf("Curso: ");
                    fgets(alunos[i].curso, sizeof(alunos[i].curso), stdin);

                    printf("Turma: ");
                    fgets(alunos[i].turma, sizeof(alunos[i].turma), stdin);

                    printf("Unidade Curricular: ");
                    fgets(alunos[i].unidadeCurricular, sizeof(alunos[i].unidadeCurricular), stdin);

                    printf("Nome: ");
                    fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

                    printf("Matrícula: ");
                    fgets(alunos[i].matricula, sizeof(alunos[i].matricula), stdin);

                    // Remover o \n no final da matrícula
                    alunos[i].matricula[strcspn(alunos[i].matricula, "\n")] = '\0';

                    printf("Data de Nascimento (dd mm aaaa): ");
                    scanf("%d %d %d", &alunos[i].diaNascimento, &alunos[i].mesNascimento, &alunos[i].anoNascimento);
                    getchar();

                    printf("Endereço: ");
                    fgets(alunos[i].endereco, sizeof(alunos[i].endereco), stdin);

                    printf("Telefone: ");
                    fgets(alunos[i].telefone, sizeof(alunos[i].telefone), stdin);

                    alunos[i].media = 0;
                    for (j = 0; j < 3; j++) {
                        printf("Nota %d: ", j + 1);
                        scanf("%f", &alunos[i].notas[j]);
                        getchar();
                        alunos[i].media += alunos[i].notas[j];
                    }
                    alunos[i].media /= 3;

                    if (alunos[i].media >= 7.0) {
                        snprintf(alunos[i].condicaoFinal, sizeof(alunos[i].condicaoFinal), "Aprovado");
                    } else if (alunos[i].media >= 5.0) {
                        snprintf(alunos[i].condicaoFinal, sizeof(alunos[i].condicaoFinal), "Recuperação");
                    } else {
                        snprintf(alunos[i].condicaoFinal, sizeof(alunos[i].condicaoFinal), "Reprovado");
                    }
                }
                break;
            }
            case 2:
                printf("Digite a matrícula do aluno para consulta: ");
                fgets(matricula, sizeof(matricula), stdin);
                matricula[strcspn(matricula, "\n")] = '\0'; // Remover o \n
                consultarAluno(alunos, numAlunos, matricula);
                break;
            case 3:
                printf("Digite a matrícula do aluno para alteração: ");
                fgets(matricula, sizeof(matricula), stdin);
                matricula[strcspn(matricula, "\n")] = '\0'; // Remover o \n
                index = consultarAluno(alunos, numAlunos, matricula);
                if (index != -1) {
                    alterarAluno(&alunos[index]);
                }
                break;
            case 4:
                printf("Digite a matrícula do aluno para deletação: ");
                fgets(matricula, sizeof(matricula), stdin);
                matricula[strcspn(matricula, "\n")] = '\0'; // Remover o \n
                index = consultarAluno(alunos, numAlunos, matricula);
                if (index != -1) {
                    deletarAluno(alunos, &numAlunos, index);
                }
                break;
            case 5:
                printf("\n======== Dados dos Alunos Cadastrados ========\n");
                for (i = 0; i < numAlunos; i++) {
                    exibirAluno(alunos[i]);
                }
                break;
            case 6:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}
