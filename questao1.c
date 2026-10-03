#include <stdio.h>

float modulo(float num) {
    if (num < 0) {
        return -num;
    }

    return num;
}

float potencia(float base, int expoente) {

    if (expoente < 0) {
        return 1 / potencia(base, -expoente);
    }

    if (expoente > 0) {
        return base * potencia(base, expoente-1);
    }

    return 1;
}

// Isso não é por recursão, mas consegui fazer...
float raiz_quadrada(int num) {
    if (num <= 1) {
        return num;
    }

    float aproximacao = 0.00001, soma = 0;
    int expoente = -1;
    
    do {
        if (potencia((soma + potencia(2, expoente)) * num, 2) <= num) {
            soma += potencia(2, expoente);
        }
        expoente--;

    } while (modulo(potencia(soma * num, 2) - num) > aproximacao);

    printf("\n");
    return num * soma;
}

int main() {
    printf("%.5f\n", raiz_quadrada(5));
    return 0;
}