// programa 23
#include <stdio.h>
#include <stdlib.h>

void copiar_string(char *copia, int tam, char *original) {
    int k;

    for (k = 0; k < tam && original[k] != '\0'; k++) {
        copia[k] = original[k];
    }
    copia[k] = '\0';
}

int strings_iguais(char *str1, int tam, char *str2) {
    int k;

    for (k = 0; k < tam && str1[k] != '\0'; k++) {
        if (str1[k] != str2[k]) {
            return 0;
        }
    }

    return 1;
}

typedef struct pessoa Pessoa;

struct pessoa {
    char nome[100];
    int idade;

    int qtd_irmaos;
    Pessoa *irmaos;
};

Pessoa criar_pessoa(char *nome, int idade, Pessoa *irmaos, int quant) {
    Pessoa irmao;
    copiar_string(irmao.nome, 100, nome);
    irmao.idade = idade;
    irmao.qtd_irmaos = quant;
    irmao.irmaos = irmaos;

    return irmao;
}

Pessoa *irmao_mais_velho(Pessoa *irmao) {
    int maior_idade = irmao->irmaos->idade, k = 0;
    Pessoa *index, *mais_velho = irmao->irmaos;

    for (index = irmao->irmaos; k < irmao->qtd_irmaos; index++) {
        if (maior_idade < index->idade) {
            mais_velho = index;
            maior_idade = mais_velho->idade;
        }
        k++;
    }

    return mais_velho;
}

int main() {
    Pessoa *Joao = (Pessoa *) malloc(5 * sizeof(Pessoa));;

    Joao[0] = criar_pessoa("Joao da Silva", 17, Joao, 5);
    Joao[1] = criar_pessoa("Joao Guilherme", 13, Joao, 5);
    Joao[2] = criar_pessoa("Joao Miguel", 20, Joao, 5);
    Joao[3] = criar_pessoa("Joao Costa", 23, Joao, 5);
    Joao[4] = criar_pessoa("Joaozinho", 7, Joao, 5);

    printf("%s.\n", irmao_mais_velho(Joao+4)->nome);
    free(Joao);
    return 0;
}