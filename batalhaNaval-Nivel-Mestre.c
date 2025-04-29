#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HABILIDADE 5
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

// Função para imprimir o tabuleiro com números
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para aplicar a habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna) {
    int offset = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTab = origemLinha - offset + i;
            int colunaTab = origemColuna - offset + j;

            if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == AGUA) {
                    tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                }
            }
        }
    }
}

// Função para criar a matriz de habilidade "cone"
void criarCone(int cone[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            cone[i][j] = (j >= 2 - i && j <= 2 + i && i <= 2) ? 1 : 0;
        }
    }
}

// Função para criar a matriz de habilidade "cruz"
void criarCruz(int cruz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            cruz[i][j] = (i == 2 || j == 2) ? 1 : 0;
        }
    }
}

// Função para criar a matriz de habilidade "octaedro"
void criarOctaedro(int octaedro[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            octaedro[i][j] = (abs(i - 2) + abs(j - 2) <= 2) ? 1 : 0;
        }
    }
}

// Função para reiniciar o tabuleiro com água e navios
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;

    // Navio horizontal
    for (int i = 0; i < 3; i++) {
        tabuleiro[1][2 + i] = NAVIO;
    }

    // Navio vertical
    for (int i = 0; i < 3; i++) {
        tabuleiro[5 + i][7] = NAVIO;
    }

    // Diagonal principal
    for (int i = 0; i < 3; i++) {
        tabuleiro[3 + i][3 + i] = NAVIO;
    }

    // Diagonal secundária
    for (int i = 0; i < 3; i++) {
        tabuleiro[2 + i][6 - i] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];

    // --------------------
    // Habilidade: CONE
    // --------------------
    inicializarTabuleiro(tabuleiro);
    criarCone(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 2, 2);
    printf("Tabuleiro com habilidade CONE em (2,2):\n");
    imprimirTabuleiro(tabuleiro);

    // --------------------
    // Habilidade: CRUZ
    // --------------------
    inicializarTabuleiro(tabuleiro);
    criarCruz(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 7, 3);
    printf("Tabuleiro com habilidade CRUZ em (7,3):\n");
    imprimirTabuleiro(tabuleiro);

    // --------------------
    // Habilidade: OCTAEDRO
    // --------------------
    inicializarTabuleiro(tabuleiro);
    criarOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 5, 5);
    printf("Tabuleiro com habilidade OCTAEDRO em (5,5):\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}