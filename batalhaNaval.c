#include <stdio.h>
#include <stdbool.h>

// Tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Valores para representar água e navios
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se uma posição é válida
bool posicaoValida(int linha, int coluna) {
    return linha >= 0 && linha < TAMANHO_TABULEIRO && 
           coluna >= 0 && coluna < TAMANHO_TABULEIRO;
}

// Função para verificar se é possível posicionar um navio
bool podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                         int linha, int coluna, bool horizontal) {
    // Verifica todas as posições que o navio ocuparia
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linhaAtual = horizontal ? linha : linha + i;
        int colunaAtual = horizontal ? coluna + i : coluna;
        
        if (!posicaoValida(linhaAtual, colunaAtual) || 
            tabuleiro[linhaAtual][colunaAtual] != AGUA) {
            return false;
        }
    }
    return true;
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                     int linha, int coluna, bool horizontal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linhaAtual = horizontal ? linha : linha + i;
        int colunaAtual = horizontal ? coluna + i : coluna;
        tabuleiro[linhaAtual][colunaAtual] = NAVIO;
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro de Batalha Naval:\n\n");
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j); // Imprime números das colunas
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i); // Imprime número da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Inicializa o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);
    
    // Coordenadas dos navios (definidas no código)
    // Navio horizontal: linha 2, coluna 3
    int linhaHorizontal = 2, colunaHorizontal = 3;
    // Navio vertical: linha 5, coluna 7
    int linhaVertical = 5, colunaVertical = 7;
    
    // Verifica e posiciona o navio horizontal
    if (podePosicionarNavio(tabuleiro, linhaHorizontal, colunaHorizontal, true)) {
        posicionarNavio(tabuleiro, linhaHorizontal, colunaHorizontal, true);
        printf("Navio horizontal posicionado com sucesso!\n");
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal nas coordenadas (%d, %d)\n", 
               linhaHorizontal, colunaHorizontal);
        return 1;
    }
    
    // Verifica e posiciona o navio vertical
    if (podePosicionarNavio(tabuleiro, linhaVertical, colunaVertical, false)) {
        posicionarNavio(tabuleiro, linhaVertical, colunaVertical, false);
        printf("Navio vertical posicionado com sucesso!\n");
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical nas coordenadas (%d, %d)\n", 
               linhaVertical, colunaVertical);
        return 1;
    }
    
    // Imprime o tabuleiro
    imprimirTabuleiro(tabuleiro);
    
    return 0;
}