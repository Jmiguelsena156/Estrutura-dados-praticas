#ifndef PILHA_H
#define PILHA_H

// Tamanho da Pilha
#define MAX_POS 50

// Bibliotecas usadas
#include "Posicao.h"

// Tipo de Estrutura de Pilha de caminhos
typedef struct rota Rota;

struct rota {
    Posicao caminhos[MAX_POS];
    Posicao desvios[MAX_POS];
    int quant_c;
    int quant_d;
};

// Criar TAD rota
Rota *criar_rota();

// Empilhar caminho
void Empilhar_Caminho(Posicao caminhos[], int *pivot, int x, int y);

// Desempilhar caminho
void Desempilhar_Caminho(Posicao caminhos[], int *pivot, int *x, int *y);

// Imprime o caminho até o fim.
void imprimir_caminho(Posicao caminhos[], int tam);

// Deleta Rota da Memória
void deletar_rota(Rota *r);

#endif