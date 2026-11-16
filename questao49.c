#include <stdio.h>
#include "Lista.h"

Lista *ordenar_lista(Lista *lst, int tam) {
    if (tam == 0) {
        return lst;
    }

    Lista *vet[tam];

    Lista *p;
    int i = 0, j = 0;
    for (p = lst; p != NULL; p = p->prox) {
        vet[i] = p;
        i++;
    }

    for (i = 0; i < tam-1; i++) {
        for (j = 0; j < tam-i-1; j++) {
            if (vet[j]->valor > vet[j+1]->valor) {
                Lista *aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }

    vet[tam-1]->prox = NULL;
    for (j = tam-2; j >= 0; j--) {
        vet[j]->prox = vet[j+1];
    }

    return vet[0];
}

int main() {
    Lista *lista1;
    int tam = 0;

    lista1 = inserir_valor(lista1, 1);
    tam++;
    lista1 = inserir_valor(lista1, 5);
    tam++;
    lista1 = inserir_valor(lista1, 4);
    tam++;
    lista1 = inserir_valor(lista1, 8);
    tam++;
    lista1 = inserir_valor(lista1, 2);
    tam++;
    lista1 = inserir_valor(lista1, 10);
    tam++;
    lista1 = inserir_valor(lista1, 3);
    tam++;
    lista1 = inserir_valor(lista1, 7);
    tam++;
    lista1 = inserir_valor(lista1, 6);
    tam++;
    lista1 = inserir_valor(lista1, 9);
    tam++;

    printf("Lista Normal: ");
    imprimir_lista(lista1);
    printf("\n");

    lista1 = ordenar_lista(lista1, tam);

    printf("Lista Ordenada: ");
    imprimir_lista(lista1);
    printf("\n");
    deletar_lista(lista1);
    return 0;
}