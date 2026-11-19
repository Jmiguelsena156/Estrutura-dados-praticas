#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Pilha.h"

Pilha *criar_pilha() {
    Pilha *plh = (Pilha *) malloc(sizeof(Pilha));

    if (plh != NULL) {
        plh->prim = criar_lista();
        return plh;
    }

    return NULL;
}

void empilhar(Pilha *plh, int valor) {
    plh->prim = inserir_valor(plh->prim, valor);
}

int desempilhar(Pilha *plh) {
     if (pilha_vazia(plh)) {
        printf("A pilha esta vazia.\n");
        return 0;
    }
    int valor = plh->prim->valor;
    plh->prim = remover_valor(plh->prim, 0);
    return valor;
}

int pilha_vazia(Pilha *plh) {
    return Lista_vazia(plh->prim);
}

void deletar_pilha(Pilha *plh) {
    deletar_lista(plh->prim);
    plh->prim = NULL;

    free(plh);
}