#include <stdio.h>

// O codigo funciona só que a lógica é forçada a funcionar
int *encontrar_numero(int *vet, int tam, int num) {
    int *pivot;
    pivot = vet + tam/2;

    if (*pivot == num) {
        return pivot;
    }

    if (tam == 1 && vet[0] != num && vet[1] != num) {
        return NULL;
    }

    if (*pivot > num) {
        if (tam / 2 > 0) {
            return encontrar_numero(vet, tam/2, num);
        } else {
            return encontrar_numero(vet, 1, num);
        }
    }

    if (tam / 2 > 0) {
        return encontrar_numero(pivot, tam/2, num);
    } else {
        return encontrar_numero(pivot+1, 1, num);
    }
}

int main() {
    int vet1[6] = {2, 4, 5, 6, 10, 12};
    int *p;
    p = encontrar_numero(vet1, 6, 5);
    printf("%p %p\n", vet1, p);

    return 0;
}