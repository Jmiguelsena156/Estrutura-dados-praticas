// Programa 41
#include <stdio.h>
#include "Lista.h"

int main() {
    Lista *lst;
    lst = criar_lista();
    lst = inserir_valor(lst, 10);
    lst = inserir_valor(lst, 15);
    lst = inserir_valor(lst, 4);
    lst = inserir_valor(lst, 30);

    printf("Lista encadeada: ");
    imprimir_lista(lst);
    printf("\n");

    lst = inserir_valor_index(lst, 0, 12);
    lst = inserir_valor_index(lst, 2, 50);

    printf("Lista encadeada: ");
    imprimir_lista(lst);
    printf("\n");

    lst = remover_valor(lst, 4);
    
    printf("Lista encadeada: ");
    imprimir_lista(lst);
    printf("\n");

    deletar_lista(lst);
    return 0;
}