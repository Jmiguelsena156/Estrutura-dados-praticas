
// Questão 48: Imcompleta
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Tipo abstrato de dado matemático. Exemplo: x⁵+3x⁴-10x²-1.5x+1
typedef struct polinomio Polinomio;

struct polinomio {
    float coeficiente;
    int potencia;
    Polinomio *prox;
};

// Cria o polinomio
Polinomio *criar_polinomio() {
    return NULL;
}

// Insere a próxima potencia de x.
Polinomio *inserir_x(Polinomio *f, float coeficiente) {
    Polinomio *novo = (Polinomio *) malloc(sizeof(Polinomio));

    if (novo == NULL) {
        return f;
    }

    if (f != NULL) {
        novo->potencia = f->potencia+1;
    } else {
        novo->potencia = 0;
    }

    novo->coeficiente = coeficiente;

    novo->prox = f;

    return novo;
}

// Calcula o f(b), para todo b pertencendo aos números reais.
float calcular_fx(Polinomio *f, float x) {
    // Pivot
    Polinomio *p = f;
    float num = 0;

    // Curiosidade: Metodo classico
    // while (p != NULL) {
    //     num += (p->coeficiente * pow(x, p->potencia));
    //     p = p->prox;
    // }

    // Metodo de Horner
    if (p != NULL) {
        num = p->coeficiente;
        while (p->prox != NULL) {
            num = num * x + p->prox->coeficiente;
            p = p->prox;
        }
    }

    return num;
}

// Soma os polinomio. Exemplo: (x²+x+1) + (3x³+x²-x-1) = 3x³+2x²
Polinomio *Somar_polinomios(Polinomio *f1, Polinomio *f2) {
    // Pivot e Terceiro Pivot
    Polinomio *p = f1, *t = f2;
    Polinomio *res = criar_polinomio();
    Polinomio *ultimo = res;

    while (p != NULL && t != NULL) {
        Polinomio *novo = (Polinomio *) malloc(sizeof(Polinomio));
        if (p->potencia == t->potencia) {
            novo->potencia = p->potencia;
            novo->coeficiente = p->coeficiente + t->coeficiente;
            p = p->prox;
            t = t->prox;
        } else if (p->potencia > t->potencia) {
            novo->potencia = p->potencia;
            novo->coeficiente = p->coeficiente;
            p = p->prox;
        } else {
            novo->potencia = t->potencia;
            novo->coeficiente = t->coeficiente;
            t = t->prox;
        }

        if (res == NULL) {
            novo->prox = res;
            res = novo;
            ultimo = novo;
        } else {
            novo->prox = ultimo->prox;
            ultimo->prox = novo;
            ultimo = novo;
        }
    }

    return res;
}

// Multiplica um polinomio por um termo do polinomio.
Polinomio *multiplicar_termo(Polinomio *f1, float coeficiente, int potencia) {
    Polinomio *p = f1;

    if (f1 == NULL) {
        return NULL;
    }

    Polinomio *res = criar_polinomio();
    Polinomio *ultimo = res;

    while (potencia > 0 || p != NULL) {
        Polinomio *novo = (Polinomio *) malloc(sizeof(Polinomio));
        if (p != NULL) {
            novo->potencia = potencia + p->potencia;
            novo->coeficiente = p->coeficiente * coeficiente;
            p = p->prox;
        } else {
            novo->potencia = potencia-1;
            novo->coeficiente = 0;
            potencia--;
        }

        if (res == NULL) {
            novo->prox = res;
            res = novo;
            ultimo = novo;
        } else {
            novo->prox = ultimo->prox;
            ultimo->prox = novo;
            ultimo = novo;
        }
    }

    return res;
}

// Polinomio *multiplicar_polinomios(Polinomio *f1, Polinomio *f2) {
//     Polinomio *p;
// }

// Deleta o polinomio da memoria.
void deletar_polinomio(Polinomio *f) {
    // Pivot
    Polinomio *p = f;

    while (p != NULL) {
        // Terceiro Pivot
        Polinomio *t = p->prox;
        free(p);
        p = t;
    }

    f = NULL;
}

// Imprime o polinomio mais parecido com linguagem matemática
void imprimir_polinomio(Polinomio *f) {
    Polinomio *p;

    for (p = f; p != NULL; p = p->prox) {
        printf("%.2f*(x^%d)", p->coeficiente, p->potencia);

        if (p->potencia != 0) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main()
{
    Polinomio *fx  = criar_polinomio();

    fx = inserir_x(fx, 6);
    fx = inserir_x(fx, -5);
    fx = inserir_x(fx, 1);

    printf("f(x) = ");
    imprimir_polinomio(fx);

    Polinomio *gx = criar_polinomio();

    gx = multiplicar_termo(fx, 3, 1);

    printf("3x * f(x) = ");
    imprimir_polinomio(gx);


    printf("15 * f(5) = %.2f.\n", calcular_fx(gx, 5));
    printf("f(2) = %.2f.\n", calcular_fx(fx, 2));

    deletar_polinomio(fx);
    deletar_polinomio(gx);
    return 0;
}