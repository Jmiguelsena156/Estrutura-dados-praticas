#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Pilha.h"

void Adicao(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("A pilha esta vazia.\n");
        exit(1);
    } else {
        int res = desempilhar(p);

        if (pilha_vazia(p)) {
            printf("A pilha precisa ter mais de 1 valor.\n");
        } else {
            res += desempilhar(p);
        }
        empilhar(p, res);
    }
}

void Subtracao(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("A pilha esta vazia.\n");
        exit(1);
    } else {
        int res = desempilhar(p);

        if (pilha_vazia(p)) {
            printf("A pilha precisa ter mais de 1 valor.\n");
        } else {
            res = desempilhar(p) - res;
        }
        empilhar(p, res);
    }
}

void Multiplicacao(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("A pilha esta vazia.\n");
        exit(1);
    } else {
        int res = desempilhar(p);

        if (pilha_vazia(p)) {
            printf("A pilha precisa ter mais de 1 valor.\n");
        } else {
            res *= desempilhar(p);
        }
        empilhar(p, res);
    }
}

void Divisao(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("A pilha esta vazia.\n");
        exit(1);
    } else {
        int res = desempilhar(p);

        if (pilha_vazia(p)) {
            printf("A pilha precisa ter mais de 1 valor.\n");
        } else {
            res = desempilhar(p) / res;
        }
        empilhar(p, res);
    }
}

void Resto(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("A pilha esta vazia.\n");
        exit(1);
    } else {
        int res = desempilhar(p);

        if (pilha_vazia(p)) {
            printf("A pilha precisa ter mais de 1 valor.\n");
        } else {
            res = desempilhar(p) % res;
        }
        empilhar(p, res);
    }
}

void Potenciacao(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("A pilha esta vazia.\n");
        exit(1);
    } else {
        int res = desempilhar(p);

        if (pilha_vazia(p)) {
            printf("A pilha precisa ter mais de 1 valor.\n");
        } else {
            res = (int) pow(desempilhar(p), res);
        }
        empilhar(p, res);
    }
}

int main() {
    printf("expressao: (2*3+5)*2 - (pow(2, 3) / 2).\n");
    Pilha *p = criar_pilha();

    empilhar(p, 2);
    empilhar(p, 3);
    Multiplicacao(p);
    empilhar(p, 5);
    Adicao(p);
    empilhar(p, 2);
    Multiplicacao(p);
    empilhar(p, 2);
    empilhar(p, 3);
    Potenciacao(p);
    empilhar(p, 2);
    Divisao(p);
    Subtracao(p);

    printf("Resultado: %d.\n", desempilhar(p));
    deletar_pilha(p);
    return 0;
}