#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Matriz para representar o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Representação dos navios com valor 3
    int navio[TAMANHO_NAVIO] = {3, 3, 3};

    // -------------------------------
    // POSICIONAMENTO DOS NAVIOS
    // -------------------------------

    // Navio 1: Horizontal (linha 1, colunas 2-4)
    int l1 = 1, c1 = 2;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (c1 + i < TAMANHO_TABULEIRO && tabuleiro[l1][c1 + i] == 0) {
            tabuleiro[l1][c1 + i] = navio[i];
        }
    }

    // Navio 2: Vertical (coluna 7, linhas 5-7)
    int l2 = 5, c2 = 7;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (l2 + i < TAMANHO_TABULEIRO && tabuleiro[l2 + i][c2] == 0) {
            tabuleiro[l2 + i][c2] = navio[i];
        }
    }

    // Navio 3: Diagonal principal (↘) — posições (3,3), (4,4), (5,5)
    int l3 = 3, c3 = 3;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (l3 + i < TAMANHO_TABULEIRO && c3 + i < TAMANHO_TABULEIRO &&
            tabuleiro[l3 + i][c3 + i] == 0) {
            tabuleiro[l3 + i][c3 + i] = navio[i];
        }
    }

    // Navio 4: Diagonal secundária (↙) — posições (2,6), (3,5), (4,4)
    int l4 = 2, c4 = 6;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (l4 + i < TAMANHO_TABULEIRO && c4 - i >= 0 &&
            tabuleiro[l4 + i][c4 - i] == 0) {
            tabuleiro[l4 + i][c4 - i] = navio[i];
        }
    }

    // -------------------------------
    // EXIBIÇÃO DO TABULEIRO
    // -------------------------------

    printf("Tabuleiro de Batalha Naval:\n\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            // Imprime com espaçamento para visualização alinhada
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }

    return 0;
}