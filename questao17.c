#include <stdio.h>

typedef struct {
    float coeficiente;
    float valor;
} Icognita;

typedef struct {
    int possui_valores;
    Icognita x;
    Icognita y;
    Icognita z;
    float resultado;
} Equacao;

Equacao criar_equacao(float co_x, float co_y, float co_z, float res) {
    Equacao eq;
    eq.x.coeficiente = co_x;
    eq.y.coeficiente = co_y;
    eq.z.coeficiente = co_z;
    eq.resultado = res;

    return eq;
}

void Imprimir_Equacao(Equacao equacao) {
    printf("%.2fx + %.2fy + %.2fz = %.2f\n", equacao.x.coeficiente, equacao.y.coeficiente, equacao.z.coeficiente, equacao.resultado);
}

void Imprimir_Sistema(Equacao eq1, Equacao eq2, Equacao eq3) {
    Imprimir_Equacao(eq1);
    Imprimir_Equacao(eq2);
    Imprimir_Equacao(eq3);
}

float determinante_matriz3(float mat[3][3]) {
    int i, j;
    float res = 0;

    for (i = 0; i < 3; i++) {
        float prod = 1;
        for (j = 0; j < 3; j++) {
            prod *= mat[j][(i+j)%3];
        }
        res += prod;
    }

    for (i = 0; i < 3; i++) {
        float prod = 1;
        for (j = 0; j < 3; j++) {
            prod *= mat[2-j][(i+j)%3];
        }
        res -= prod;
    }


    return res;
}

void Resolver(Equacao *eq1, Equacao *eq2, Equacao *eq3) {
    float Dx[3][3] = {{eq1->resultado ,eq1->y.coeficiente, eq1->z.coeficiente}, {eq2->resultado ,eq2->y.coeficiente, eq2->z.coeficiente}, {eq3->resultado ,eq3->y.coeficiente, eq3->z.coeficiente}};
    float Dy[3][3] = {{eq1->x.coeficiente, eq1->resultado, eq1->z.coeficiente}, {eq2->x.coeficiente, eq2->resultado, eq2->z.coeficiente}, {eq3->x.coeficiente, eq3->resultado, eq3->z.coeficiente}};
    float Dz[3][3] = {{eq1->x.coeficiente ,eq1->y.coeficiente, eq1->resultado}, {eq2->x.coeficiente ,eq2->y.coeficiente, eq2->resultado}, {eq3->x.coeficiente ,eq3->y.coeficiente, eq3->resultado}};
    float D[3][3] = {{eq1->x.coeficiente ,eq1->y.coeficiente, eq1->z.coeficiente}, {eq2->x.coeficiente ,eq2->y.coeficiente, eq2->z.coeficiente}, {eq3->x.coeficiente ,eq3->y.coeficiente, eq3->z.coeficiente}};

    float DetX = determinante_matriz3(Dx);
    float DetY = determinante_matriz3(Dy);
    float DetZ = determinante_matriz3(Dz);
    float Det = determinante_matriz3(D);

    if (Det != 0) {
        eq1->x.valor = eq2->x.valor = eq3->x.valor = DetX / Det;
        eq1->y.valor = eq2->y.valor = eq3->y.valor = DetY / Det;
        eq1->z.valor = eq2->z.valor = eq3->z.valor = DetZ / Det;
        eq1->possui_valores = eq2->possui_valores = eq3->possui_valores = 1;
    }

}

int main() {
    Equacao eq1 = criar_equacao(1, 1, 1, 6);
    Equacao eq2 = criar_equacao(1, 2, 2, 9);
    Equacao eq3 = criar_equacao(2, 1, 3, 11);

    Resolver(&eq1, &eq2, &eq3);

    printf("Solucao do sistema de equacoes: ");
    Imprimir_Sistema(eq1, eq2, eq3);

    if (eq1.possui_valores) {
        printf("\nx = %.2f, y = %.2f, z = %.2f.\n", eq1.x.valor, eq1.y.valor, eq1.z.valor);
    }
    return 0;
}