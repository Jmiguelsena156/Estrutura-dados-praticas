// programa 28
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int TAMANHO = 50;

void preencher_aleatorio(int *vet, int tam) {
    int k;

    for (k = 0; k < tam; k++) {
        vet[k] = (rand() % 50) + 1;
    }
}

void imprimir_vetor(int *vet, int tam) {
    int k;

    for (k = 0; k < tam; k++) {
        printf("%d ", vet[k]);
    }
}

void trocar_valores(int *vet, int tam, int M, int N) {
    if (M < tam && N < tam && M >= 0 && N >= 0) {
        int aux = vet[M];
        vet[M] = vet[N];
        vet[N] = aux;
    }
}

int main() {
    srand(time(NULL));
    int *vet = (int *) malloc(TAMANHO * sizeof(int));

    preencher_aleatorio(vet, TAMANHO);

    printf("Vetor formado foi: ");
    imprimir_vetor(vet, TAMANHO);
    printf("\n");

    trocar_valores(vet, TAMANHO, 23, 11);

    printf("O novo vetor eh: ");
    imprimir_vetor(vet, TAMANHO);
    printf("\n");
    free(vet);
    return 0;
}