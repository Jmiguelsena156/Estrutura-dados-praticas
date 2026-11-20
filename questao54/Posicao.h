#ifndef POSICAO_H
#define POSICAO_H

// TAD posição
typedef struct posicao {
    int x;
    int y;
} Posicao;

// Cria Posicao do labirinto
Posicao criar_posicao(int x, int y);

// Buscar posicao na lista
int Buscar_posicao(Posicao caminhos[], int tam, int x, int y);

#endif