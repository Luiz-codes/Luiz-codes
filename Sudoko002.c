#include <stdio.h>

#define TAM 9

int sudoku[TAM][TAM];

int verifica_vetor(int vetor[]) {
    int i;
    int freq[10] = {0}; // índices de 1 a 9

    for (i = 0; i < TAM; i++) {
        if (vetor[i] < 1 || vetor[i] > 9)
            return 0;
        if (freq[vetor[i]] != 0)
            return 0;
        freq[vetor[i]] = 1;
    }

    return 1;
}

int verifica_linhas() {
    int i, j;
    int linha[TAM];

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++)
            linha[j] = sudoku[i][j];
        if (!verifica_vetor(linha))
            return 0;
    }
    return 1;
}

int verifica_colunas() {
    int i, j;
    int coluna[TAM];

    for (j = 0; j < TAM; j++) {
        for (i = 0; i < TAM; i++)
            coluna[i] = sudoku[i][j];
        if (!verifica_vetor(coluna))
            return 0;
    }
    return 1;
}

int verifica_blocos() {
    int bloco[TAM];
    int bi, bj, i, j, k;

    for (bi = 0; bi < TAM; bi += 3) {
        for (bj = 0; bj < TAM; bj += 3) {
            k = 0;
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    bloco[k++] = sudoku[bi + i][bj + j];
                }
            }
            if (!verifica_vetor(bloco))
                return 0;
        }
    }
    return 1;
}

int main() {
    int i, j;

    printf("Digite os 81 valores do Sudoku (linha por linha):\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }

    if (verifica_linhas() && verifica_colunas() && verifica_blocos())
        printf("Sudoku valido!\n");
    else
        printf("Sudoku invalido!\n");

    return 0;
}

