// Programa 44
#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

const int TAMANHO = 10;

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
        Lista *p1, *p2, *p, *resultado;

        resultado = criar_lista();

        for (p1 = lst1; p1 != NULL; p1 = p1->prox) {
            resultado = inserir_valor(resultado, 0);
        }

        for (p1 = lst1, p2 = lst2, p = resultado; p != NULL; p1 = p1->prox, p2 = p2->prox, p = p->prox) {
            p->valor = p1->valor + p2->valor;
        }

        return resultado;
    }

    fprintf(stderr, "Erro: A lista tem que ser do mesmo tamanho");
    return NULL;
}

Lista *Subtrair_Lista(Lista *lst1, Lista *lst2) {
    if (tam_Lista(lst1) == tam_Lista(lst2)) {
        Lista *p1, *p2, *p, *resultado;

        resultado = criar_lista();

        for (p1 = lst1; p1 != NULL; p1 = p1->prox) {
            resultado = inserir_valor(resultado, 0);
        }

        for (p1 = lst1, p2 = lst2, p = resultado; p != NULL; p1 = p1->prox, p2 = p2->prox, p = p->prox) {
            p->valor = p1->valor - p2->valor;
        }

        return resultado;
    }

    fprintf(stderr, "Erro: A lista tem que ser do mesmo tamanho");
    return NULL;
}

int produto_escalar(Lista *lst1, Lista *lst2) {
    if (tam_Lista(lst1) == tam_Lista(lst2)) {
        int prod = 0;
        Lista *p1, *p2;

        for (p1 = lst1, p2 = lst2; p1 != NULL; p1 = p1->prox, p2 = p2->prox) {
            prod += p1->valor * p2->valor;
        }

        return prod;
    }

    fprintf(stderr, "Erro: A lista tem que ser do mesmo tamanho");
    return 0;
}

Lista *Concatenar_Simples(Lista *lst1, Lista *lst2) {
    Lista *p, *resultado;

    resultado = criar_lista();

    for (p = lst1; p != NULL; p = p->prox) {
        resultado = inserir_valor(resultado, p->valor);
    }

    for (p = lst2; p != NULL; p = p->prox) {
        resultado = inserir_valor(resultado, p->valor);
    }
    
    return resultado;
}

Lista *Concatenar_Alternada(Lista *lst1, Lista *lst2) {
    Lista *p1, *p2, *resultado;

    resultado = criar_lista();
    p1 = lst1;
    p2 = lst2;

    while (p1 != NULL || p2 != NULL) {
        if (p1 != NULL) {
            resultado = inserir_valor(resultado, p1->valor);
            p1 = p1->prox;
        }
        if (p2 != NULL) {
            resultado = inserir_valor(resultado, p2->valor);
            p2 = p2->prox;
        }
    }

    return resultado;
}

int valor_presente(Lista *lst, int valor) {
    Lista *p = lst;

    while (p != NULL) {
        if (p->valor == valor) {
            return 1;
        }
        p = p->prox;
    }

    return 0;
}

Lista *Uniao_Listas(Lista *lst1, Lista *lst2) {
    Lista *p, *resultado;

    resultado = criar_lista();

    for (p = lst1; p != NULL; p = p->prox) {
        if (!valor_presente(resultado, p->valor)) {
            resultado = inserir_valor(resultado, p->valor);
        }
    }

    for (p = lst2; p != NULL; p = p->prox) {
        if (!valor_presente(resultado, p->valor)) {
            resultado = inserir_valor(resultado, p->valor);
        }
    }
    
    return resultado;
}

Lista *Interseccao_Listas(Lista *lst1, Lista *lst2) {
    Lista *p, *resultado;

    resultado = criar_lista();

    for (p = lst1; p != NULL; p = p->prox) {
        if (!valor_presente(resultado, p->valor) && valor_presente(lst2, p->valor)) {
            resultado = inserir_valor(resultado, p->valor);
        }
    }
    
    return resultado;
}

Lista *Diferenca_Listas(Lista *lst1, Lista *lst2) {
    Lista *p, *resultado;

    resultado = criar_lista();

    for (p = lst1; p != NULL; p = p->prox) {
        if (!valor_presente(resultado, p->valor) && !valor_presente(lst2, p->valor)) {
            resultado = inserir_valor(resultado, p->valor);
        }
    }
    
    return resultado;
}

int main() {
    Lista *lst1, *lst2, *lst3;

    lst1 = criar_lista();
    lst2 = criar_lista();

    int k;
    for (k = 0; k < TAMANHO; k++) {
        lst1 = inserir_valor(lst1, k+3);
        lst2 = inserir_valor(lst2, (k)*(k)+2*(k+1));
    }

    if (!Lista_vazia(lst1) && !Lista_vazia(lst2)) {
        printf("A lista 1 eh: ");
        imprimir_lista(lst1);
        printf("\nA lista 2 eh: ");
        imprimir_lista(lst2);

        lst3 = Somar_Lista(lst1, lst2);

        printf("\nA soma das lista eh: ");
        imprimir_lista(lst3);
        printf("\n");
        deletar_lista(lst3);

        lst3 = Subtrair_Lista(lst1, lst2);

        printf("\nA subtracao das lista eh: ");
        imprimir_lista(lst3);
        printf("\n");

        int prod = produto_escalar(lst1, lst2);

        printf("\nO produto escalar das lista eh: %d.\n", prod);
        deletar_lista(lst3);

        lst3 = Concatenar_Simples(lst1, lst2);

        printf("\nA concatenacao das lista eh: ");
        imprimir_lista(lst3);
        printf("\n");
        deletar_lista(lst3);

        lst3 = Concatenar_Alternada(lst1, lst2);

        printf("\nA concatenacao das lista eh: ");
        imprimir_lista(lst3);
        printf("\n");
        deletar_lista(lst3);

        lst3 = Uniao_Listas(lst1, lst2);

        printf("\nA Uniao das lista eh: ");
        imprimir_lista(lst3);
        printf("\n");
        deletar_lista(lst3);

        lst3 = Interseccao_Listas(lst1, lst2);

        printf("\nA Interseccao das lista eh: ");
        imprimir_lista(lst3);
        printf("\n");
        deletar_lista(lst3);

        lst3 = Diferenca_Listas(lst1, lst2);

        printf("\nA diferença das lista eh: ");
        imprimir_lista(lst3);
        printf("\n");
    }
    
    deletar_lista(lst1);
    deletar_lista(lst2);
    deletar_lista(lst3);
    return 0;
}