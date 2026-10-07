#include <stdio.h>

typedef struct {
    int i;
    int b;
} Poligono;

Poligono formar_poligono(int interior, int borda) {
    Poligono pol;
    pol.i = interior;
    pol.b = borda;

    return pol;
}

float calcula_area(Poligono poligono) {
    return poligono.i + ((float) poligono.b / 2) - 1;
}

int main() {
    printf("A area de um quadrado de lado 5: %.2f.\n", calcula_area(formar_poligono(16, 20)));
    printf("A area de um quadrado de altura 3 e base 4: %.2f.\n", calcula_area(formar_poligono(3, 8)));
    return 0;
}