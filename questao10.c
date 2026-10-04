#include <stdio.h>
#include <stdlib.h>
const int LINHAS = 3, COLUNAS = 3;

void criar_matriz(int *mat, int l, int c) {
    int k;
    for (k = 0; k < l*c; k++) {
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

int *somar_linhas(int *matriz, int linhas, int colunas) {
    int *soma = criar_vetor(linhas);
    int i, j;

    if (soma != NULL) {
        for (i = 0; i < linhas; i++) {
            soma[i] = 0;
            for (j = 0; j < colunas; j++) {
                soma[i] += matriz[i*colunas+j];
            }
        }

        return soma;
    }

    return NULL;
}

int main() {
    int matriz[LINHAS][COLUNAS];
    criar_matriz(*matriz, LINHAS, COLUNAS);

    int *soma = somar_linhas(*matriz, LINHAS, COLUNAS);

    if (soma != NULL) {
        int k;
        for (k = 0; k < LINHAS; k++) {
            printf("soma linha %d: %d \n", k, soma[k]);
        }
    }

    liberar_memoria(soma);
    return 0;
}