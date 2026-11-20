#include "Posicao.h"

// Cria Posicao do labirinto
Posicao criar_posicao(int x, int y) {
    Posicao pos;
    pos.x = x;
    pos.y = y;
    return pos;
}


// Buscar posicao na lista
int Buscar_posicao(Posicao caminhos[], int tam, int x, int y) {
    int k;
    for (k = 0; k < tam; k++) {
        if (caminhos[k].x == x && caminhos[k].y == y) {
            return 1;
        }
    }

    return 0;
}