#include <stdio.h>

#define TAM 3

// Verifica se os números estão entre 1 e 9 e sem repetição
int validar_numeros(int matriz[TAM][TAM]) {
    int contagem[10] = {0}; // índice 0 não usado

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            int num = matriz[i][j];
            if (num < 1 || num > 9 || contagem[num] > 0) {
                return 0;
            }
            contagem[num]++;
        }
    }
    return 1;
}

// Verifica se é um quadrado mágico
int eh_quadrado_magico(int matriz[TAM][TAM]) {
    int soma = 0;

    // Soma da primeira linha
    for (int j = 0; j < TAM; j++) {
        soma += matriz[0][j];
    }

    // Verifica linhas
    for (int i = 1; i < TAM; i++) {
        int soma_linha = 0;
        for (int j = 0; j < TAM; j++) {
            soma_linha += matriz[i][j];
        }
        if (soma_linha != soma) return 0;
    }

    // Verifica colunas
    for (int j = 0; j < TAM; j++) {
        int soma_coluna = 0;
        for (int i = 0; i < TAM; i++) {
            soma_coluna += matriz[i][j];
        }
        if (soma_coluna != soma) return 0;
    }

    // Verifica diagonais
    int soma_diag1 = 0;
    for (int i = 0; i < TAM; i++) {
        soma_diag1 += matriz[i][i];
    }
    if (soma_diag1 != soma) return 0;

    int soma_diag2 = 0;
    for (int i = 0; i < TAM; i++) {
        soma_diag2 += matriz[i][TAM - 1 - i];
    }
    if (soma_diag2 != soma) return 0;

    return 1; // É quadrado mágico
}

int main() {
    int matriz[TAM][TAM];

    printf("Digite os 9 números do quadrado 3x3 (valores de 1 a 9, sem repetição):\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    if (!validar_numeros(matriz)) {
        printf("Os números devem ser de 1 a 9, sem repetições.\n");
    } else if (eh_quadrado_magico(matriz)) {
        printf("É um quadrado mágico!\n");
    } else {
        printf("Não é um quadrado mágico.\n");
    }

    return 0;
}
