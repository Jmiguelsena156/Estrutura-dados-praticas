#include <stdio.h>

void copiar_string(char *copia, int tam, char *original) {
    int k;

    for (k = 0; k < tam && original[k] != '\0'; k++) {
        copia[k] = original[k];
    }
    copia[k] = '\0';
}

typedef struct {
    char nome[50];
    float peso;
    float altura;
} Pessoa;

Pessoa criar_Pessoa(char *nome, float altura, float peso) {
    Pessoa pessoa;
    copiar_string(pessoa.nome, sizeof(pessoa.nome), nome);
    pessoa.peso = peso;
    pessoa.altura = altura;

    return pessoa;
}

void imprimir_imc(Pessoa *pessoas, int quant) {
    int k;

    for (k = 0; k < quant; k++) {
        printf("Nome: %s\n", pessoas->nome);
        float IMC = (pessoas->peso / (pessoas->altura * pessoas->altura));

        if (IMC >= 24.9) {
            printf("Dado: imc de %.2f eh caso de obesidade.\n", IMC);
        } else if (IMC >= 18.5) {
            printf("Dado: imc de %.2f eh caso normal.\n", IMC);
        } else {
            printf("Dado: imc de %.2f eh caso de desnutricao alimentar.\n", IMC);
        }
        pessoas++;
    }
}

int main() {
    Pessoa grupo[5];
    grupo[0] = criar_Pessoa("Jose Miguel", 1.8, 70.0);
    grupo[1] = criar_Pessoa("Rogerio", 1.7, 73.0);
    grupo[2] = criar_Pessoa("Ana", 1.5, 42.0);
    grupo[3] = criar_Pessoa("Maria", 1.5, 56.0);
    grupo[4] = criar_Pessoa("Ernesto", 1.7, 80.0);

    imprimir_imc(grupo, 5);
    return 0;
}