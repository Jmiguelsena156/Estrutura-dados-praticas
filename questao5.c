#include <stdio.h>

int eh_maior(int a, int b) {
    return (a > b);
}

int contar_zeros(int vet[], int tam) {
    int k, cont = 0;

    for (k = 0; k < tam; k++) {
        if (vet[k] == 0) {
            cont++;
        }
    }

    return cont;
}

// Consegui pensar numa logica, mas ainda nao funciona :(
int passear(int vetor[], int tam, int index) {
    int vetor_copia[tam], k, dir = 0, esq = 0;

    for (k = 0; k < tam; k++) {
        vetor_copia[k] = vetor[k];
    }
    vetor_copia[index]--;

    if (index == 0) {
        if (vetor_copia[index+1] == 0) {
            return contar_zeros(vetor_copia, tam);
        } else {
            dir = passear(vetor_copia, tam, index+1);
        }
    }

    if (index == tam-1) {
        if (vetor_copia[index-1] == 0) {
            return contar_zeros(vetor_copia, tam);
        } else {
            esq = passear(vetor_copia, tam, index-1);
        }
    }

    if (index != 0 && index != tam-1) {
        if (vetor_copia[index-1] == 0 && vetor_copia[index+1] == 0) {
            return contar_zeros(vetor_copia, tam);
        } else {
            dir = passear(vetor_copia, tam, index+1);
            esq = passear(vetor_copia, tam, index-1);
        }
    }

    if (eh_maior(dir, esq)) {
        if (index < tam) {
            vetor[index]--;
        }

        return dir;
    } else {
        if (index >= 0) {
            vetor[index]--;
        }

        return esq;
    }

}

int main() {
    int vetor[4] = {3, 3, 1, 1};
    printf("%d\n", passear(vetor, 4, 0));
    return 0;
}