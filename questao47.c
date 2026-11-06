// Questão 47

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Estrutura Ponto (x, y).
typedef struct ponto Ponto;

struct ponto {
    float x;
    float y;
};

// Estrutura Poligono (ponto A1, ponto A2, ..., ponto AN).
typedef struct poligono Poligono;

struct poligono {
    Ponto *pnt;
    Poligono *prox;
};

// Cria e retorna um ponto na memoria.
Ponto *criar_Ponto(float x, float y) {
    Ponto *p = (Ponto *) malloc(sizeof(Ponto));

    if (p == NULL) {
        return NULL;
    }
    p->x = x;
    p->y = y;

    return p;
}

// Deleta o ponto da memoria
void deletar_Ponto(Ponto *ponto) {
    free(ponto);
    ponto = NULL;
}

// Distancia de 2 pontos.
float distancia_Pontos(Ponto *p1, Ponto *p2) {
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

//  Cria um inicio do poligono.
Poligono *criar_Poligono() {
    return NULL;
}

// Poligono é vazio?
int Poligono_vazio(Poligono *plg) {
    return (plg == NULL);
}

// Insere um novo ponto no poligono.
Poligono *Inserir_Ponto(Poligono *plg, float x, float y) {
    Poligono *novo = (Poligono *) malloc(sizeof(Poligono));

    if (novo == NULL) {
        return plg;
    }

    novo->pnt = criar_Ponto(x, y);
    novo->prox = plg;

    return novo;
}

// Deletar o poligono da memória.
void deletar_Poligono(Poligono *plg) {
    Poligono *p = plg;

    while (p != NULL) {
        Poligono *t = p->prox;
        deletar_Ponto(p->pnt);
        free(p);
        p = t;
    }
}

// Calcular perimetro do poligono.
float calcular_perimetro(Poligono *plg) {
    float perimetro = 0;
    Poligono *p = plg;

    if (p != NULL) {
        while (p->prox != NULL) {
            perimetro += distancia_Pontos(p->pnt, p->prox->pnt);
            p = p->prox;
        }

        perimetro += distancia_Pontos(plg->pnt, p->pnt);
    }

    return perimetro;
}

// Calcular maior lado do poligono.
float Maior_Lado(Poligono *plg) {
    float maior = 0;
    Poligono *p = plg;

    if (p != NULL) {
        while (p->prox != NULL) {
            int lado = distancia_Pontos(p->pnt, p->prox->pnt);
            if (lado > maior) {
                maior = lado;
            }
            p = p->prox;
        }

        int lado = distancia_Pontos(plg->pnt, p->pnt);
        if (lado > maior) {
            maior = lado;
        }
    }

    return maior;
}

// Calcular menor lado do poligono.
float Menor_Lado(Poligono *plg) {
    float menor = 0;
    Poligono *p = plg;

    if (p != NULL) {
        while (p->prox != NULL) {
            int lado = distancia_Pontos(p->pnt, p->prox->pnt);
            if (lado < menor || menor == 0) {
                menor = lado;
            }
            p = p->prox;
        }

        int lado = distancia_Pontos(plg->pnt, p->pnt);
        if (lado < menor) {
            menor = lado;
        }
    }

    return menor;
}

// Calcular ponto central do poligono.
Ponto Ponto_Medio(Poligono *plg) {
    Ponto medio;
    Poligono *p = plg;

    int quant = 0;
    medio.x = 0;
    medio.y = 0;

    while (p != NULL) {
        medio.x += p->pnt->x;
        medio.y += p->pnt->y;
        quant++;
        p = p->prox;
    }

    if (quant != 0) {
        medio.x = medio.x / quant;
        medio.y = medio.y / quant;
    }

    return medio;
}

// Calcular a area do Poligono.
float calcular_area(Poligono *plg) {
    float d1 = 0, d2 = 0;
    Poligono *p = plg;

    if (p != NULL) {
        while (p->prox != NULL) {
            d1 += (p->pnt->x * p->prox->pnt->y);
            d2 += (p->pnt->y * p->prox->pnt->x);
            p = p->prox;
        }
        d1 += (p->pnt->x * plg->pnt->y);
        d2 += (p->pnt->y * plg->pnt->x);
    }

    return fabsf(d1 - d2) / 2;
}

int main() {
    Poligono *triangulo = criar_Poligono();

    triangulo = Inserir_Ponto(triangulo, 0, 0);
    triangulo = Inserir_Ponto(triangulo, 0, 3);
    triangulo = Inserir_Ponto(triangulo, 4, 0);

    printf("Dados do triangulo:\n");
    printf("  Perimetro: %.2f;\n", calcular_perimetro(triangulo));
    printf(" Maior Lado: %.2f;\n", Maior_Lado(triangulo));
    printf(" Menor Lado: %.2f;\n", Menor_Lado(triangulo));
    printf(" Area: %.2f;\n", calcular_area(triangulo));

    deletar_Poligono(triangulo);

    Poligono *pentagono = criar_Poligono();

    pentagono = Inserir_Ponto(pentagono, 0, 2);
    pentagono = Inserir_Ponto(pentagono, 0, 5);
    pentagono = Inserir_Ponto(pentagono, 4, 7);
    pentagono = Inserir_Ponto(pentagono, 5, 3.5);
    pentagono = Inserir_Ponto(pentagono, 4, 0);

    printf("\nDados do pentagono:\n");
    printf("  Perimetro: %.2f;\n", calcular_perimetro(pentagono));
    printf(" Maior Lado: %.2f;\n", Maior_Lado(pentagono));
    printf(" Menor Lado: %.2f;\n", Menor_Lado(pentagono));
    printf(" Area: %.2f.\n", calcular_area(pentagono));

    deletar_Poligono(pentagono);
    return 0;
}