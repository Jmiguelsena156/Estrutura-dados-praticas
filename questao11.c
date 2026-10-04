#include <stdio.h>
#include <stdlib.h>
const int ORDEM = 3;

void criar_matriz(int *mat, int ordem) {
    int k;
    for (k = 0; k < ordem*ordem; k++) {
        mat[k] = k+1;
    }
}

int *criar_vetor(int tam) {
    int *vet;
    vet = (int *) malloc(tam * sizeof(int));

    return vet;
}

void liberar_memoria(int *vet) {
    if (vet != NULL) {
        free(vet);
    }
}

int *ter_diagonal(int *matriz, int ordem) {
    int *diagonal = criar_vetor(ordem);
    int i;

    if (diagonal != NULL) {
        for (i = 0; i < ordem; i++) {
            diagonal[i] = matriz[ordem*i+i];
        }

        return diagonal;
    }

    return NULL;
}

int main() {
    int matriz[ORDEM][ORDEM];
    criar_matriz(*matriz, ORDEM);

    int *diagonal = ter_diagonal(*matriz, ORDEM);

    if (diagonal != NULL) {
        int k;
        printf("Diagonal eh: ");
        for (k = 0; k < ORDEM; k++) {
            printf("%d ", diagonal[k]);
        }
        printf("\n");
    }
    liberar_memoria(diagonal);
    return 0;
}