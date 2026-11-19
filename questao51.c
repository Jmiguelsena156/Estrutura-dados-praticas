#include <stdio.h>
#include "Pilha.h"

// Empilha número em sêquencia, de quant à 1.
void empilhar_sequencia(Pilha *plh, int quant) {
    int k;
    for (k = quant; k >= 1; k--) {
        empilhar(plh, k);
    }
}

// Imprime as torres de Hanoi.
void imprimir_Torres(Pilha *torre1, Pilha *torre2, Pilha *torre3) {
    printf("Torres Resultados: \n");
    printf("Torre 1: ");
    imprimir_lista(torre1->prim);
    printf("\n");
    printf("Torre 2: ");
    imprimir_lista(torre2->prim);
    printf("\n");
    printf("Torre 3: ");
    imprimir_lista(torre3->prim);
    printf("\n\n");
}

// Coloca os números do p1 para p3, sem colocar o maior em cima e só usando funções de pilhas
void TorreDeHanoi(int num, Pilha *Origem, Pilha *Destino, Pilha *Auxiliar) {
    if (num != 0) {
        TorreDeHanoi(num-1, Origem, Auxiliar, Destino);
        empilhar(Destino, desempilhar(Origem));
        TorreDeHanoi(num-1, Auxiliar, Destino, Origem);
    }
}

int main() {
    int pinos = 5;
    Pilha *p1 = criar_pilha(), *p2 = criar_pilha(), *p3 = criar_pilha();

    empilhar_sequencia(p1, pinos);

    imprimir_Torres(p1, p2, p3);
    TorreDeHanoi(pinos, p1, p2, p3);
    imprimir_Torres(p1, p2, p3);
    TorreDeHanoi(pinos, p2, p3, p1);
    imprimir_Torres(p1, p2, p3);

    deletar_pilha(p1);
    deletar_pilha(p2);
    deletar_pilha(p3);
    return  0;
}