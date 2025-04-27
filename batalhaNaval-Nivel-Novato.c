#include <stdio.h>

// Definição de constantes para facilitar manutenção do código
#define TAMANHO_TABULEIRO 10   // Tamanho do tabuleiro (10x10)
#define TAMANHO_NAVIO 3        // Tamanho fixo dos navios (3 posições)

int main() {
    // Declaração da matriz do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicialização do tabuleiro com 0 (representa água)
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Declaração e inicialização dos navios (valores 3 representam partes do navio)
    int navio_horizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_vertical[TAMANHO_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais para o navio horizontal (linha, coluna)
    int linha_navio_horizontal = 2;
    int coluna_navio_horizontal = 1;

    // Coordenadas iniciais para o navio vertical (linha, coluna)
    int linha_navio_vertical = 5;
    int coluna_navio_vertical = 7;

    // Posicionamento do navio horizontal no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        // Verifica se a posição está dentro do limite de colunas
        if (coluna_navio_horizontal + i < TAMANHO_TABULEIRO) {
            tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] = navio_horizontal[i];
        }
    }

    // Posicionamento do navio vertical no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        // Verifica se a posição está dentro do limite de linhas
        if (linha_navio_vertical + i < TAMANHO_TABULEIRO) {
            // Garante que não haja sobreposição de navios
            if (tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] == 0) {
                tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = navio_vertical[i];
            }
        }
    }

    // Impressão do tabuleiro completo
    printf("Tabuleiro de Batalha Naval:\n\n");

    // Loop para percorrer todas as linhas e colunas
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]); // Exibe valor da posição (0 = água, 3 = navio)
        }
        printf("\n"); // Quebra de linha após cada linha do tabuleiro
    }

    return 0;
}