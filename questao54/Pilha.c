#include <stdio.h>
#include <stdlib.h>
#include "Posicao.h"
#include "Pilha.h"

Rota *criar_rota() {
    Rota *r = (Rota *) malloc(sizeof(Rota));

    r->quant_c = 0;
    r->quant_d = 0;

    return r;
}

void Empilhar_Caminho(Posicao caminhos[], int *pivot, int x, int y) {
    if (*pivot >= MAX_POS) {
        printf("Ultrapassou o limite do vetor.\n");
        exit(1);
    }

    caminhos[*pivot] = criar_posicao(x, y);
    (*pivot)++;
}

void Desempilhar_Caminho(Posicao caminhos[], int *pivot, int *x, int *y) {
    if (*pivot == 0) {
        printf("Pilha vazia.\n");
        exit(1);
    }


    (*pivot)--;
    if( x != NULL && y != NULL) {
       *x = caminhos[*pivot].x;
       *y = caminhos[*pivot].y;
    }
}

void imprimir_caminho(Posicao caminhos[], int tam) {
    int k;
    for (k = 0; k < tam; k++) {
        printf("(%d, %d)", caminhos[k].x, caminhos[k].y);
        if (k != tam-1) {
            printf(" -> ");
        } else {
            printf(".\n");
        }
    }
}

void deletar_rota(Rota *r) {
    free(r);
}