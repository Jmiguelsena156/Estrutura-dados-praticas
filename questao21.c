#include <stdio.h>
#include <stdlib.h>

typedef struct ilha Ilha;

struct ilha {
    char nome[50];
    Ilha *entrada;
    Ilha *saida;
};

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

Ilha criar_ilha(char *nome, Ilha *entrada, Ilha *saida) {
    Ilha ilha1;
    copiar_string(ilha1.nome, sizeof(ilha1.nome), nome);
    ilha1.entrada = entrada;
    ilha1.saida = saida;

    return ilha1;
}

int seguir_caminho(Ilha *inicial, char (*trajeto)[50], int quant) {
    int k;
    Ilha *caminho;
    caminho = inicial->saida;

    for (k = 0; k < quant; k++) {
        if (!strings_iguais(caminho->nome, sizeof(caminho->nome), trajeto[k])) {
            return 0;
        }

        caminho = caminho->saida;
    }

    return 1;
}

int main() {
    Ilha *arquipelago = (Ilha *) malloc(5 * sizeof(Ilha));
    arquipelago[0] = criar_ilha("Ilha do Raftler", arquipelago+2, arquipelago+1);
    arquipelago[1] = criar_ilha("Ilha Sandieses", arquipelago, arquipelago+4);
    arquipelago[2] = criar_ilha("Ilha Porlarco", arquipelago+3, arquipelago);
    arquipelago[3] = criar_ilha("Ilha Vertrenes", arquipelago+4, arquipelago+2);
    arquipelago[4] = criar_ilha("Ilha do Yascot", arquipelago+1, arquipelago+3);

    char trajeto1[4][50] = {"Ilha Porlarco" ,"Ilha do Raftler", "Ilha Sandieses", "Ilha do Yascot"};

    if (seguir_caminho(arquipelago+3 , trajeto1, 4)) {
        printf("Eh possivel seguir caminho 1.\n");
    } else {
        printf("Nao eh possivel seguir caminho 1.\n");
    }

    char trajeto2[4][50] = {"Ilha Vertrenes" ,"Ilha Porlarco", "Ilha do Raftler", "Ilha Vertrenes"};

    if (seguir_caminho(arquipelago+4 , trajeto2, 4)) {
        printf("Eh possivel seguir caminho 2.\n");
    } else {
        printf("Nao eh possivel seguir caminho 2.\n");
    }

    free(arquipelago);
    return 0;
}