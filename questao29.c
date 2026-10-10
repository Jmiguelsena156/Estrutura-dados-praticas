// programa 29
#include <stdio.h>
#include <stdlib.h>

const char NAIPES[4][10] = {"Espadas", "Copas", "Ouros", "Paus"};
const char VALOR[13][10] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valete", "Dama", "Rei"};


void copiar_string(char *copia, int tam, const char *original) {
    int k;

    for (k = 0; k < tam && original[k] != '\0'; k++) {
        copia[k] = original[k];
    }
    copia[k] = '\0';
}

int strings_iguais(char *str1, int tam, const char *str2) {
    int k;

    for (k = 0; k < tam && str1[k] != '\0'; k++) {
        if (str1[k] != str2[k]) {
            return 0;
        }
    }

    return 1;
}

typedef struct {
    char Valor[10];
    char Naipe[10];
} Baralho;

Baralho *criar_baralho() {
    Baralho *baralho = (Baralho *) malloc(52 * sizeof(Baralho));
    Baralho *index;
    index = baralho;
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            copiar_string(index->Naipe, 10, NAIPES[i]);
            copiar_string(index->Valor, 10, VALOR[j]);
            index++;
        }
    }

    return baralho;
}

Baralho *buscar_carta(Baralho *cartas, char *Valor, char *Naipe) {
    int naipe_index = 0, valor_index = 0;
    while (!strings_iguais(cartas[naipe_index].Naipe, 10, Naipe) && naipe_index < 4) {
        naipe_index++;
    }

    while (!strings_iguais(cartas[valor_index].Valor, 10, Valor) && valor_index < 13) {
        valor_index++;
    }

    if (naipe_index > 4 || valor_index > 13) {
        return NULL;
    }
    
    return cartas+(naipe_index*13)+valor_index;
}

int main() {

    Baralho *cartas = NULL;
    cartas = criar_baralho();


    printf("%ld\n", buscar_carta(cartas, "As", "Ouros") - cartas);
    printf("%ld\n", buscar_carta(cartas, "8", "Espadas")- cartas);
    printf("%ld\n", buscar_carta(cartas, "Rei", "Copas") - cartas);

    free(cartas);
    return 0;
}