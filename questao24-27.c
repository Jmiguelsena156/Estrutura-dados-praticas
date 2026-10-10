// programa 24, 25, 26 e 27
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int TAMANHO = 50;

void preencher_ordenado(int *vet, int tam) {
    int k;
    vet[0] = rand() % 3;

    for (k = 1; k < tam; k++) {
        vet[k] = vet[k-1] + (rand() % 3) + 1;
    }
}

void imprimir_vetor(int *vet, int tam) {
    int k;

    for (k = 0; k < tam; k++) {
        printf("%d ", vet[k]);
    }
}

int enesimo_maior(int *vet, int tam, int N) {
    if (N <= tam && N > 0) {
        return vet[tam - N];
    }

    return 0;
}

int enesimo_menor(int *vet, int tam, int N) {
    if (N <= tam && N > 0) {
        return vet[N-1];
    }

    return 0;
}

int mediana(int *vet, int tam) {
    if (tam % 2 == 0) {
        return (vet[tam/2] + vet[(tam/2)-1]) / 2;
    }

    return vet[(tam-1)/2];
}

int *buscar_elemento(int *vet, int tam, int N) {
    if (tam == 1) {
        if (vet[0] == N) {
            return vet;
        }

        return NULL;
    }

    int pivot, inicio = 0, final = tam-1;

    do {
        pivot = (final+inicio) / 2;
        if (vet[pivot] == N) {
            return vet+pivot;
        } else if (vet[pivot] > N) {
            final = pivot-1;
        } else {
            inicio = pivot+1;
        }

    } while (inicio <= final);

    return NULL;
}

int main() {
    srand(time(NULL));
    int *vet = (int *) malloc(TAMANHO * sizeof(int));

    preencher_ordenado(vet, TAMANHO);

    printf("Vetor formado foi: ");
    imprimir_vetor(vet, TAMANHO);
    printf("\n");

    printf("O maior numero: %d,\nO quarto maior numero: %d,\n", enesimo_maior(vet, TAMANHO, 1), enesimo_maior(vet, TAMANHO, 4));
    printf("O menor numero: %d,\nO vigesimo quinto menor numero: %d,\n", enesimo_menor(vet, TAMANHO, 1), enesimo_menor(vet, TAMANHO, 25));

    printf("A mediana do vetor eh %d,\n", mediana(vet, TAMANHO));

    printf("O endereco do primeiro elemento: %p,\n", buscar_elemento(vet, 50, vet[0]));
    printf("O endereco do quarto elemento: %p,\n", buscar_elemento(vet, 50, vet[4]));
    printf("O endereco do 25 elemento: %p,\n", buscar_elemento(vet, 50, vet[25]));
    printf("O endereco do ultimo elemento: %p.\n", buscar_elemento(vet, 50, vet[TAMANHO-1]));


    free(vet);
    return 0;
}