#include <stdio.h>

#define N 5

int labirinto[N][N] = {
    {1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1}
};

int caminho[N][N];

// Verifica se a posição é válida
int ehValido(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && labirinto[x][y] == 1);
}

// Função recursiva para resolver o labirinto
int resolverLabirinto(int x, int y) {
    if (x == N - 1 && y == N - 1) {
        caminho[x][y] = 1;
        return 1;
    }

    if (ehValido(x, y)) {
        caminho[x][y] = 1;

        // Move para a direita
        if (resolverLabirinto(x, y + 1)) {
            return 1;
        }

        // Move para baixo
        if (resolverLabirinto(x + 1, y)) {
            return 1;
        }

        // Backtrack: desfaz a marcação
        caminho[x][y] = 0;
    }

    return 0;
}

// Imprime o caminho encontrado
void imprimirCaminho() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (caminho[i][j] == 1) {
                printf("* ");
            } else if (labirinto[i][j] == 0) {
                printf("0 ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    int i, j;

    // Inicializa a matriz caminho com 0
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            caminho[i][j] = 0;
        }
    }

    if (resolverLabirinto(0, 0)) {
        printf("Caminho encontrado:\n\n");
        imprimirCaminho();
    } else {
        printf("Nenhum caminho possível.\n");
    }

    return 0;
}


