// programa 30 e 31
#include <stdio.h>
const int TAMANHO = 5;

void imprimir_lista(int lista[], int tam) {
    int k;

    for (k = 0; k < tam; k++) {
        printf("%d ", lista[k]);
    }
    printf("\n");
}

void mover_frente(int lista[], int tam) {
    int k;

    for (k = tam-1; k > 0; k--) {
        int aux = lista[k-1];
        lista[k-1] = lista[k];
        lista[k] = aux;
    }
}

void mover_tras(int lista[], int tam) {
    int k;

    for (k = 0; k < tam-1; k++) {
        int aux = lista[k+1];
        lista[k+1] = lista[k];
        lista[k] = aux;
    }
}

int main() {
    int vet[TAMANHO], k;

    for (k = 0; k < TAMANHO; k++) {
        vet[k] = (k+1)*(k+1);
    }

    printf("Lista: ");
    imprimir_lista(vet, TAMANHO);

    mover_frente(vet, TAMANHO);

    printf("Lista movida para frente: ");
    imprimir_lista(vet, TAMANHO);

    mover_tras(vet, TAMANHO);
    mover_tras(vet, TAMANHO);

    printf("Lista movida para tras: ");
    imprimir_lista(vet, TAMANHO);
    return 0;
}