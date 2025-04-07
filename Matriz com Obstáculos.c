#include <stdio.h>

#define MAX 50

typedef struct {
    int x, y, passos;
} Nodo;

int matriz[MAX][MAX];
int visitado[MAX][MAX];
Nodo fila[MAX * MAX];
int frente = 0, tras = 0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void enfileirar(int x, int y, int passos) {
    fila[tras].x = x;
    fila[tras].y = y;
    fila[tras].passos = passos;
    tras++;
}

Nodo desenfileirar() {
    return fila[frente++];
}

int esta_vazia() {
    return frente == tras;
}

int dentro_da_matriz(int x, int y, int n) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

int bfs(int n) {
    enfileirar(0, 0, 0);
    visitado[0][0] = 1;

    while (!esta_vazia()) {
        Nodo atual = desenfileirar();

        if (atual.x == n - 1 && atual.y == n - 1) {
            return atual.passos;
        }

        for (int i = 0; i < 4; i++) {
            int novoX = atual.x + dx[i];
            int novoY = atual.y + dy[i];

            if (dentro_da_matriz(novoX, novoY, n) &&
                !visitado[novoX][novoY] &&
                matriz[novoX][novoY] == 0) {

                visitado[novoX][novoY] = 1;
                enfileirar(novoX, novoY, atual.passos + 1);
            }
        }
    }

    return -1;
}

int main() {
    int n;
    printf("Digite o tamanho da matriz (ate %d): ", MAX);
    scanf("%d", &n);

    printf("Digite a matriz (0 = livre, 1 = obstaculo):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matriz[i][j]);

    if (matriz[0][0] == 1 || matriz[n - 1][n - 1] == 1) {
        printf("Impossível sair: inicio ou fim bloqueado.\n");
        return 0;
    }

    int resultado = bfs(n);

    if (resultado == -1)
        printf("Nao ha caminho possivel ate o destino.\n");
    else
        printf("Menor caminho encontrado: %d passos\n", resultado);

    return 0;
}

