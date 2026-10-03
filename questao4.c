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

float calcular_media(float vetor[], int tam) {
    int k;
    float soma = 0;

    for (k = 0; k < tam; k++) {
        soma += vetor[0];
    }

    return soma / tam;
}

float calcular_variancia(float vetor[], int tam) {
    float media = calcular_media(vetor, tam), soma = 0;
    int k;

    for (k = 0; k < tam; k++) {
        soma += potencia(vetor[k] - media, 2);
    }

    return soma / tam;
}

float calcular_DP(float vetor[], int tam) {
    return raiz_quadrada(calcular_variancia(vetor, tam));
} 

int main() {
    float vetor[5] = {1, 2, 3, 4, 5};

    float desvio_padrao = calcular_DP(vetor, 5);
    printf("%.2f\n", desvio_padrao);
    return 0;
}