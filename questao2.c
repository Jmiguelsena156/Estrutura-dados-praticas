#include <stdio.h>

int contar_div(int num) {
    int k, cont = 0;

    for (k = 1; k <= num; k++) {
        if (num % k == 0) {
            cont++;
        }
    }

    return cont;
}

int eh_primo(int num) {
    return contar_div(num) == 2;
}

int soma_primos(int M, int N) {
    if (M > N) {
        return 0;
    }

    if (eh_primo(M)) {
        return M + soma_primos(M+1, N);
    }

    return soma_primos(M+1, N);

}

int main() {

    printf("%d\n", soma_primos(2, 10));
    return 0;
}