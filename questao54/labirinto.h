#ifndef LABIRINTO_H
#define LABIRINTO_H

// Bibliotecas usadas.
#include "Posicao.h"
#include "Pilha.h"

// Tamanho do Labirinto.
#define MAX_X 7
#define MAX_Y 7

// Labirinto em Matriz.
extern const int labirinto[MAX_Y][MAX_X];

// Inicio e Fim do labirinto.
extern const int pos_inicio[2];
extern const int pos_saida[2];

// Algoritmo Busca em Profundidade (Depth-First Search)
void DFS(Rota *r, Posicao inicio, Posicao saida);

// Criar o caminho para o final.
Rota *Buscar_Saida();

// Imprime o labirinto
void imprimir_Labirinto();

#endif