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

float raiz_quadrada(float num) {
    if (num <= 0 && num == 1.0) {
        return num;
    }

    if (num < 1) {
        return 1 / raiz_quadrada(1 / num);
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

typedef struct {
    int x;
    int y;
} Ponto;

Ponto criar_ponto(int x, int y) {
    Ponto ponto;
    ponto.x = x;
    ponto.y = y;

    return ponto;
}

float distancia_euclidiana(Ponto p1, Ponto p2) {
    return raiz_quadrada(potencia(p1.x - p2.x, 2) + potencia(p1.y - p2.y, 2));
}

int main() {
    Ponto A = criar_ponto(6, -1), B = criar_ponto(9, -5);

    float d = distancia_euclidiana(A, B);
    printf("A distancia de A e B eh %.2f\n", d);
    return 0;
}