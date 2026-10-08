#include <stdio.h>
#include <stdlib.h>

typedef struct divisor Divisor;

struct divisor {
    int num;
    Divisor *divisor1;
    Divisor *divisor2;
};

int calcular_divisor2(int num) {
    int k;

    for (k = 2; k < num; k++) {
        if (num % k == 0) {
            return num / k;
        }
    }

    return 1;
}

Divisor *criar_num_divisores(int num) {
    Divisor *div1 = (Divisor *) malloc(sizeof(Divisor));
    div1->num = num;

    if (num != 1) {
        div1->divisor1 = div1;
        div1->divisor2 = criar_num_divisores(calcular_divisor2(div1->num));
    } else {
        div1->divisor1 = div1;
        div1->divisor2 = div1;
    }

    return div1;
}

void Liberar_memoria(Divisor *dvs) {
    if (dvs->num != 1) {
        Liberar_memoria(dvs->divisor2);
    }
    free(dvs);
}

int main() {
    Divisor *num1 = criar_num_divisores(120);

    printf("O 4 divisor maior de 120 eh %d.\n", num1->divisor2->divisor2->divisor2->num);

    Divisor *num2 = criar_num_divisores(625);

    printf("O 4 divisor maior de 625 eh %d.\n", num2->divisor2->divisor2->divisor2->num);

    Liberar_memoria(num1);
    Liberar_memoria(num2);
    return 0;
}