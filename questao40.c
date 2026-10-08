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
    
    return 0;
}