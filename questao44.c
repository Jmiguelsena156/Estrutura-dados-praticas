// Programa 44 Não completa
#include <stdio.h>
#include "Lista.h"
#include <stdlib.h>

int tam_Lista(Lista *lst) {
    int tam = 0;
    Lista *p = lst;
    
    while (p != NULL) {
        p = p->prox;
        tam++;
    }

    return tam;
}

Lista *Somar_Lista(Lista *lst1, Lista *lst2) {
    if (tam_Lista(lst1) == tam_Lista(lst2)) {
        Lista *p1, *p2, *resultado = (Lista *) malloc(sizeof(Lista));
        resultado = criar_lista();

        for (p1 = lst1, p2 = lst2; p1 != NULL; p1 = p1->prox, p2 = p2->prox) {
            if (tam_Lista(resultado) == 0) {
                resultado = inserir_valor(resultado, p1->valor+p2->valor);
            } else {
                resultado = inserir_valor_index(resultado, tam_Lista(resultado), p1->valor+p2->valor);
            }
        }

    } else {
        fprintf(stderr, "Erro: A lista tem que ser do mesmo tamanho");
        return NULL;
    }
}

int main() {
    Lista *lst;
    int k;

    for (k = 0; k < 10; k++) {
        lst = inserir_valor(lst, 10-k);
    }


    return 0;
}