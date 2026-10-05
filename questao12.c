#include <stdio.h>
#include <stdlib.h>

const int LINHA1 = 2, N = 3, COLUNA2 = 2;

int *criar_vetor(int tam) {
    int *vet = (int *) malloc(tam * sizeof(int));

    if (vet != NULL) {
        return vet;
    }

    return NULL;
}

int **criar_matriz(int linhas, int colunas) {
    int **mat = (int **) malloc(linhas * sizeof(int *));
    int k;

    for (k = 0; k < linhas; k++) {
        mat[k] = criar_vetor(colunas);
    }

    return mat;
}

void liberar_memoria(int **matriz, int linhas) {
    int k;
    
    for (k = 0; k < linhas; k++) {
        if (matriz[k] != NULL) {
            free(matriz[k]);
        }
    }

    if (matriz != NULL) {
        free(matriz);
    }
}

void preencher_matriz(int **matriz, int linhas, int colunas) {
    int i, j;

    for (i = 0; i < linhas; i++) {
        printf("\nInforme %d numeros inteiros: ", colunas);
        for (j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void informar_matriz(int **matriz, int linhas, int colunas) {
    int i, j;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int **multiplicar_matrizes(int **matriz1, int **matriz2, int l1, int n, int c2) {
    int **prod = criar_matriz(l1, c2);
    int k, i, j;

    for (i = 0; i < l1; i++) {
        for (j = 0; j < c2; j++) {
            prod[i][j] = 0;
            for (k = 0; k < n; k++) {
                prod[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    
    return prod;
}

int main() {
    int **matriz1 = criar_matriz(LINHA1, N);

    preencher_matriz(matriz1, LINHA1, N);

    printf("Matriz 1:\n");
    informar_matriz(matriz1, LINHA1, N);

    int **matriz2 = criar_matriz(N, COLUNA2);

    preencher_matriz(matriz2, N, COLUNA2);

    printf("Matriz 2:\n");
    informar_matriz(matriz2, N, COLUNA2);

    int **produto = multiplicar_matrizes(matriz1, matriz2, LINHA1, N, COLUNA2);

    printf("Produto Matricial =\n");
    informar_matriz(produto, LINHA1, COLUNA2);

    liberar_memoria(matriz1, LINHA1);
    liberar_memoria(matriz2, N);
    liberar_memoria(produto, LINHA1);
    return 0;
}