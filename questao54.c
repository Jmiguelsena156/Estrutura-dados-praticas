#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Pilha.h"

// Tamanho do Labirinto
#define MAX_X 7
#define MAX_Y 7

const int labirinto[MAX_Y][MAX_X] = {
    {1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 0, 0, 1},
    {1, 0, 0, 1, 0, 1, 1},
    {1, 1, 1, 1, 0, 1, 1},
};
const int pos_inicio[2] = {1, 1};
const int pos_saida[2] = {4, 6};

// Não consegui resolver ainda. Estou pensando em mudar pilha para pilha de index.
void DFS(Pilha *p, int inicio[2], int saida[2], int *estado) {
    // Direções: baixo (0), cima (1), esquerda (2), direita (3)
    // estado: 1 achou a saida, 0 não revelado, -1 não achou saida

    

}

Pilha *encontrar_saida() {
    int inicio[2], saida[2];
    // Copia o inicio da constante
    inicio[0] = pos_inicio[0];
    inicio[1] = pos_inicio[1];

    // Copia a saida da constante
    saida[0] = pos_saida[0];
    saida[1] = pos_saida[1];

    Pilha *caminho = criar_pilha();
    int estado = 0;
    DFS(caminho, inicio, saida, &estado);

    return caminho;
} 

void imprimir_Labirinto() {
    int i, j;

    for (i = 0; i < MAX_Y*2; i++) {
        for (j = 0; j < MAX_X; j++) {
            if (labirinto[i/2][j] == 0) {
                printf("   ");
            } else {
                printf("###");
            }
        }
        printf("\n");
    }
}

void imprimir_caminho(Pilha *caminho) {
    Lista *passo;

    for (passo = caminho->prim; passo != NULL; passo = passo->prox) {
        switch (passo->valor) {
            case 0:
                printf("Ande para baixo\n");
                break;
            case 1:
                printf("Ande para cima\n");
                break;
            case 2:
                printf("Ande para esquerda\n");
                break;
            case 3:
                printf("Ande para direita\n");
                break;
            default:
                break;
        }
    }
    printf("Chegou ao seu destino.\n");
}

int main() {
    printf("Labirinto:\n");
    imprimir_Labirinto();

    Pilha *caminho = encontrar_saida();
    imprimir_caminho(caminho);
    return 0;
}