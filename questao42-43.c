// Programa 42 e 43
#include <stdio.h>
#include "Lista.h"

int main() {
    Lista *lst;
    lst = criar_lista();
    int num;

    do {
        printf("Informe um numero inteiro: ");
        scanf("%d", &num);

        lst = inserir_valor(lst, num);
    } while (num != 0);

    printf("A lista informada foi: ");
    imprimir_lista(lst);
    printf("\n");

    deletar_lista(lst);
    return 0;
}