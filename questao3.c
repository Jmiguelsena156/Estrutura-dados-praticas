#include <stdio.h>

int combinacao(int n, int p) {
    if (n < p || p < 0) {
        return  0;
    }

    if (n == p || p == 0) {
        return 1;
    }

    return combinacao(n-1, p-1) + combinacao(n-1, p);
}

void expandir(int expoente) {
    int k;

    printf("(a+b)^%d =", expoente);
    for (k = 0; k <= expoente; k++) {
        if (combinacao(expoente, k) != 1) {
            printf(" %d *", combinacao(expoente, k));
        }

        if (expoente-k != 0) {
            printf(" a^%d ", expoente-k);
        }

        if (expoente-k != 0 && k != 0) {
            printf("*");
        }

        if (k != 0) {
            printf(" b^%d ", k);
        }

        if (k != expoente) {
            printf("+");
        }
    }
    printf("\n");
}

int main() {
    expandir(2);
    expandir(5);
    return 0;
}