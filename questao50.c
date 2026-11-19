#include <stdio.h>
#include "Pilha.h"

int main() {
    Pilha *p = criar_pilha();
    empilhar(p, 4);
    empilhar(p, 1);
    empilhar(p, 3);
    desempilhar(p);
    empilhar(p, 8);
    desempilhar(p);

    printf("Pilha no final: ");
    while (!pilha_vazia(p)) {
        printf("%d ", desempilhar(p));
    }
    printf("\n");

    deletar_pilha(p);
    return 0;
}