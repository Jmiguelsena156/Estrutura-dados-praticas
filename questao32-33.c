// programa 32 e 33
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int TAMANHO = 30;

int index_maior(int *lista, int tam) {
    int maior_index = 0, k;

    for (k = 0; k < tam; k++) {
        if (lista[maior_index] < lista[k]) {
            maior_index = k;
        }
    }

    return maior_index;
}

void imprimir_lista(int lista[], int tam) {
    int k;

    for (k = 0; k < tam; k++) {
        printf("%d ", lista[k]);
    }
    printf("\n");
}

void mover_frente(int *lista, int tam) {
    int k;

    for (k = tam-1; k > 0; k--) {
        int aux = lista[k-1];
        lista[k-1] = lista[k];
        lista[k] = aux;
    }
}

void mover_tras(int *lista, int tam) {
    int k;

    for (k = 0; k < tam-1; k++) {
        int aux = lista[k+1];
        lista[k+1] = lista[k];
        lista[k] = aux;
    }
}

void mover_maior(int *lista, int tam) {
    int maior_index = index_maior(lista, tam), k;

    if (maior_index > tam / 2) {
        for (k = 0; k < maior_index; k++) {
            mover_tras(lista, tam);
        }

        for (k = 0; k < maior_index; k++) {
            mover_frente(lista+1, tam-1);
        }
    } else {
        for (k = tam; k > maior_index; k--) {
            mover_frente(lista, tam);
        }

        for (k = tam-1; k > maior_index; k--) {
            mover_tras(lista+1, tam-1);
        }
    }
}

void mover_pares(int *lista, int tam) {
    int j, i = 0;
    for (j = 0; j < tam; j++) {
        int k;
        if (lista[j] % 2 == 0) {
            for (k = i; k < j; k++) {
                mover_tras(lista+i, tam-i);
            }

            for (k = i; k < j; k++) {
                mover_frente(lista+i+1, tam-i-1);
            }
            i++;
        }
    }
}

int main() {
    int lista[TAMANHO], k;

    srand(time(NULL));
    for (k = 0; k < TAMANHO; k++) {
        lista[k] = (rand() % 100) + 1;
    }

    printf("Lista: ");
    imprimir_lista(lista, TAMANHO);

    mover_maior(lista, TAMANHO);

    printf("Lista: ");
    imprimir_lista(lista, TAMANHO);

    mover_pares(lista, TAMANHO);

    printf("Lista: ");
    imprimir_lista(lista, TAMANHO);

    return 0;
}