#include <stdio.h>

typedef struct {
    float Real;
    float Img;
} Complexo;

Complexo criar_num_complexo(float Real, float Img) {
    Complexo num;
    num.Real = Real;
    num.Img = Img;
    return num;
}

void imprimir_complexo(Complexo num) {
    printf("(%.2f + %.2fi)", num.Real, num.Img);
}

Complexo soma_complexa(Complexo num1, Complexo num2) {
    Complexo resultado;
    resultado.Real = num1.Real + num2.Real;
    resultado.Img = num1.Img + num2.Img;

    return resultado;
}

Complexo diferenca_complexa(Complexo num1, Complexo num2) {
    Complexo resultado;
    resultado.Real = num1.Real - num2.Real;
    resultado.Img = num1.Img - num2.Img;

    return resultado;
}

Complexo produto_complexo(Complexo num1, Complexo num2) {
    Complexo resultado;
    resultado.Real = num1.Real * num2.Real - num1.Img * num2.Img;
    resultado.Img = num1.Real * num2.Img + num2.Real * num1.Img;

    return resultado;
}

Complexo conjugado(Complexo num) {
    num.Img = -num.Img;

    return num;
}

Complexo divisao_complexo(Complexo num1, Complexo num2) {
    Complexo resultado;
    num1 = produto_complexo(num1, conjugado(num2));
    num2 = produto_complexo(num2, conjugado(num2));

    resultado.Real = num1.Real / num2.Real;
    resultado.Img = num1.Img / num2.Real;

    return resultado;
}

Complexo potencia(Complexo base, int expoente) {
    Complexo num1;
    num1.Real = 1;
    num1.Img = 0;

    if (expoente == 0) {
        return num1;
    }

    if (expoente < 0) {
        return potencia(divisao_complexo(num1, base), -expoente);
    }

    return produto_complexo(base, potencia(base, expoente-1));

}

int main() {
    Complexo num1 = criar_num_complexo(2, 2);
    Complexo num2 = criar_num_complexo(10, 5);
    Complexo num3 = criar_num_complexo(0, 1);

    imprimir_complexo(num1);
    printf(" + ");
    imprimir_complexo(num2);
    printf(" = ");
    imprimir_complexo(soma_complexa(num1, num2));
    printf("\n");

    imprimir_complexo(num2);
    printf(" - ");
    imprimir_complexo(num1);
    printf(" = ");
    imprimir_complexo(diferenca_complexa(num2, num1));
    printf("\n");

    imprimir_complexo(num2);
    printf(" * ");
    imprimir_complexo(num3);
    printf(" = ");
    imprimir_complexo(produto_complexo(num2, num3));
    printf("\n");

    imprimir_complexo(num2);
    printf(" / ");
    imprimir_complexo(num1);
    printf(" = ");
    imprimir_complexo(divisao_complexo(num2, num1));
    printf("\n");

    imprimir_complexo(num2);
    printf(" ** 4 = ");
    imprimir_complexo(potencia(num2, 4));
    printf("\n");

    return 0;
}