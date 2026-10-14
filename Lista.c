#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista
{
    int valor;
    Lista *prox;
};

Lista *criar_lista() {
    return NULL;
}

Lista *inserir_valor(Lista *lst, int valor) {
    Lista *novo = (Lista *) malloc(sizeof(Lista));

    if (novo != NULL) {
        novo->valor = valor;
        novo->prox = lst;
        return novo;
    }

    fprintf(stderr, "Arquivo Lista não encontrada");
    return lst;
}

void imprimir_lista(Lista *lst) {

    Lista *index;
    for (index = lst; index != NULL; index = index->prox) {
        printf("%d ", index->valor);
    } 
}

void deletar_lista(Lista *lst) {

    Lista *p;
    p = lst;
    while (p != NULL) {
        Lista *q;
        q = p->prox;
        free(p);
        p = q;
    }
}

Lista *calcular_index(Lista *lst, int index) {
    int k = 0;

    Lista *p;
    for (p = lst; p != NULL; p = p->prox) {
        if (k == index) {
            return p;
        }
        k++;
    }

    return NULL;
}

Lista *inserir_valor_index(Lista *lst, int index, int valor) {
    if (index == 0) {
        Lista *novo = (Lista *) malloc(sizeof(Lista));
        novo->prox = lst;
        novo->valor = valor;
        return novo;
    }

    Lista *p = calcular_index(lst, index-1);
    Lista *prox_valor  = p->prox;
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    novo->prox = prox_valor;
    novo->valor = valor;
    p->prox = novo;

    return lst;
}

int Lista_vazia(Lista *lst) {
    return lst == NULL;
}

Lista *remover_valor(Lista *lst, int index) {
    if (Lista_vazia(lst)) {
        return lst;
    }

    if (index == 0) {
        Lista *p = lst->prox;
        free(lst);
        return p;
    }

    Lista *p = calcular_index(lst, index-1);
    
    if (p->prox != NULL) {
        Lista *prox_valor = p->prox->prox;
        free(p->prox);
        p->prox = prox_valor;
    }

    return lst;
}