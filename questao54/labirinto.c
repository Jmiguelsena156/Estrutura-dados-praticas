#include <stdio.h>
#include <stdlib.h>
#include "Posicao.h"
#include "Pilha.h"
#include "labirinto.h"

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

void DFS(Rota *r, Posicao inicio, Posicao saida) {
    // Vai retornar a rota com os desvios e o caminho
    int x = inicio.x, y = inicio.y;
    Empilhar_Caminho(r->caminhos, &(r->quant_c), x, y);
    Empilhar_Caminho(r->desvios, &(r->quant_d), x, y);

    // Continua até encontrar a saida ou até todos os caminhos serem testados
    while ((x != saida.x || y != saida.y) && r->quant_c != 0) {
        int passos[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        }, i = 0, moveu = 0;

        while (i < 4 && !moveu) {
            if (
                // Verifica as condições para não escapar da matriz
                (x > 0 || i != 0) &&
                (x < MAX_X-1 || i != 1) &&
                (y > 0 || i != 2) &&
                (y < MAX_Y-1 || i != 3)
            ) {

                int nx = x + passos[i][0];
                int ny = y + passos[i][1];

                if (
                    labirinto[ny][nx] == 0 &&
                    !Buscar_posicao(r->desvios, r->quant_d, nx, ny)
                    ) {

                    x = nx;
                    y = ny;
                    Empilhar_Caminho(r->caminhos, &(r->quant_c), x, y);
                    Empilhar_Caminho(r->desvios, &(r->quant_d), x, y);
                    moveu = 1;

                }
            }

            i++;
        }

        // Voltar no caso de beco sem saida.
        if (!moveu) {
            Desempilhar_Caminho(r->caminhos, &(r->quant_c), NULL, NULL);

            if (r->quant_c != 0) {
                Desempilhar_Caminho(r->caminhos, &(r->quant_c), &x, &y);
                Empilhar_Caminho(r->caminhos, &(r->quant_c), x, y);
            }
        }

    }
}

Rota *Buscar_Saida() {
    Posicao inicio = criar_posicao(pos_inicio[0], pos_inicio[1]);
    Posicao saida = criar_posicao(pos_saida[0], pos_saida[1]);

    Rota *r = criar_rota();

    DFS(r, inicio, saida);

    return r;
}

// Imprime o labirinto
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