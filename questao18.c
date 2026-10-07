#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
} Ponto;

Ponto criar_ponto(float x, float y) {
    Ponto ponto;
    ponto.x = x;
    ponto.y = y;

    return ponto;
}

Ponto calcular_ponto_medio(Ponto *pontos, int tam) {
    int k;
    float x = 0, y = 0;

    for (k = 0; k < tam; k++) {
        x += pontos->x;
        y += pontos->y;
        pontos++;
    }

    return criar_ponto(x / tam, y / tam);
}

int main() {
    Ponto *pontos = (Ponto *) malloc(3 * sizeof(Ponto));
    pontos[0] = criar_ponto(1, 2);
    pontos[1] = criar_ponto(5, 3);
    pontos[2] = criar_ponto(2, 4);

    Ponto ptn_medio = calcular_ponto_medio(pontos, 3);

    printf("Ponto medio: x = %.2f, y = %.2f.\n", ptn_medio.x, ptn_medio.y);
    free(pontos);
    return 0;
}