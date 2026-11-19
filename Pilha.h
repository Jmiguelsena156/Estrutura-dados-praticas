/* 
- Pilha com valores inteiros
*/
#ifndef PILHA_H
#define PILHA_H

// Bibliotecas usadas
#include "Lista.h"

// Tipo Abstrato de Dado: PILHA.
typedef struct pilha Pilha;

struct pilha {
    Lista *prim;
};

// Cria uma pilha
Pilha *criar_pilha();

// Adiciona elemento na pilha
void empilhar(Pilha *plh, int valor);

// Tira ultimo valor da pilha.
int desempilhar(Pilha *plh);

// Verifica se a pilha está vazia
int pilha_vazia(Pilha *plh);

void deletar_pilha(Pilha *plh);

#endif