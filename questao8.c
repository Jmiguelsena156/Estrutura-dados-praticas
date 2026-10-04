#include <stdio.h>

void ordenar_variaveis(int *num1, int *num2, int *num3) {
    if (*num1 > *num2) {
        int aux = *num1;
        *num1 = *num2;
        *num2 = aux;
    }

    if (*num1 > *num3) {
        int aux = *num1;
        *num1 = *num3;
        *num3 = aux;
    }

    if (*num2 > *num3) {
        int aux = *num2;
        *num2 = *num3;
        *num3 = aux;
    }
}

int main() {
    int a = 7, b = 2, c = 10;
    ordenar_variaveis(&a, &b, &c);

    printf("%d %d %d\n", a, b, c);
    return 0;
}