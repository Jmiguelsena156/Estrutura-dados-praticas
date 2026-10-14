#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista
{
    int valor;
    Lista *prox;
};

Lista *criar_lista();

Lista *inserir_valor(Lista *lst, int valor);

void imprimir_lista(Lista *lst);

void deletar_lista(Lista *lst);

Lista *calcular_index(Lista *lst, int index);

Lista *inserir_valor_index(Lista *lst, int index, int valor);

int Lista_vazia(Lista *lst);

Lista *remover_valor(Lista *lst, int index);

#endif