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

Lista *lst_insere(Lista *lst, int valor) {
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    if (novo != NULL) {
        novo->valor = valor;
        novo->prox = lst;
        
        return novo;
    }
    fprintf(stderr, "Erro: Memoria esta cheia!");
    return lst;
}

void lst_imprime(Lista *lst) {
    Lista *p;
    for (p = lst; p != NULL; p = p->prox) {
        printf("%d ", p->valor);
    } 
}

int lst_vazia(Lista *lst) {
    return lst == NULL;
}

Lista* lst_busca(Lista *lst, int valor) {
    Lista *p;

    for (p = lst; p != NULL; p = p->prox) {
        if (p->valor == valor) {
            return p;
        }
    }

    printf("Valor nao encontrado!");
    return NULL;
}

Lista *lst_retira(Lista *lst, int valor) {
    Lista *ant= NULL;
    Lista *p = lst;

    while (p != NULL && p->valor != valor) {
        ant = p;
        p = p->prox;
    }

    if (p == NULL) {
        return lst;
    }

    if (ant != NULL) {
        lst = p->prox;
    } else {
        ant->prox = p->prox;
    }

    free(p);
    return lst;
}

Lista *lst_inserir_ordenado(Lista *lst, int valor) {
    Lista *novo;
    Lista *ant= NULL;
    Lista *p = lst;

    while (p != NULL && p->valor < valor) {
        ant = p;
        p = p->prox;
    }

    novo = (Lista *) malloc(sizeof(Lista));
    novo->valor = valor;

    if (ant != NULL) {
        novo->prox = lst;
        lst = novo;
    } else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    return lst;
}