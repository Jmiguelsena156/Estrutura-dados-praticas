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
    char sexo_biologico;
    int idade;
} Pessoa;

int modulo(int num) {
    if (num < 0) {
        return -num;
    }

    return num;
}

Pessoa criar_Pessoa(char *nome, char sexo_biologico, int idade) {
    Pessoa pessoa;
    copiar_string(pessoa.nome, 50, nome);
    pessoa.sexo_biologico = sexo_biologico;
    pessoa.idade = idade;

    return pessoa;
}

Pessoa *M_maior_idade(Pessoa *pessoas, int quant) {
    int k;
    Pessoa *pessoa_maior = NULL;

    for (k = 0; k < quant; k++) {
        if (pessoa_maior == NULL) {
            if (pessoas->sexo_biologico == 'M') {
                pessoa_maior = pessoas;
            }
        } else {
            if (pessoas->sexo_biologico == 'M' && pessoa_maior->idade < pessoas->idade) {
                pessoa_maior = pessoas;
            }
        }
        pessoas++;
    }

    return pessoa_maior;
}

Pessoa *F_maior_idade(Pessoa *pessoas, int quant) {
    int k;
    Pessoa *pessoa_maior = NULL;

    for (k = 0; k < quant; k++) {
        if (pessoa_maior == NULL) {
            if (pessoas->sexo_biologico == 'F') {
                pessoa_maior = pessoas;
            }
        } else {
            if (pessoas->sexo_biologico == 'F' && pessoa_maior->idade < pessoas->idade) {
                pessoa_maior = pessoas;
            }
        }
        pessoas++;
    }

    return pessoa_maior;
}

int media_idade(Pessoa *pessoas, int quant) {
    int k, soma = 0;

    for (k = 0; k < quant; k++) {
        soma += pessoas->idade;
        pessoas++;
    }

    return soma / quant;
}

Pessoa *M_media_idade(Pessoa *pessoas, int quant) {
    int k, media = media_idade(pessoas, quant), diferenca = 100;
    Pessoa *pessoa_proxima = NULL;
    

    for (k = 0; k < quant; k++) {
        if (pessoa_proxima == NULL) {
            if (pessoas->sexo_biologico == 'M') {
                pessoa_proxima = pessoas;
                diferenca = modulo(media - pessoas->idade);
            }
        } else {
            if (pessoas->sexo_biologico == 'M' && modulo(media - pessoas->idade) < diferenca) {
                diferenca = modulo(media - pessoas->idade);
                pessoa_proxima = pessoas;
            }
        }
        pessoas++;
    }

    return pessoa_proxima;
}

Pessoa *F_media_idade(Pessoa *pessoas, int quant) {
    int k, media = media_idade(pessoas, quant), diferenca = 100;
    Pessoa *pessoa_proxima = NULL;
    

    for (k = 0; k < quant; k++) {
        if (pessoa_proxima == NULL) {
            if (pessoas->sexo_biologico == 'F') {
                pessoa_proxima = pessoas;
                diferenca = modulo(media - pessoas->idade);
            }
        } else {
            if (pessoas->sexo_biologico == 'F' && modulo(media - pessoas->idade) < diferenca) {
                diferenca = modulo(media - pessoas->idade);
                pessoa_proxima = pessoas;
            }
        }
        pessoas++;
    }

    return pessoa_proxima;
}

int main() {
    Pessoa grupo[5];
    grupo[0] = criar_Pessoa("Jose Miguel", 'M', 19);
    grupo[1] = criar_Pessoa("Rogerio", 'M', 30);
    grupo[2] = criar_Pessoa("Ana", 'F', 30);
    grupo[3] = criar_Pessoa("Maria", 'F', 56);
    grupo[4] = criar_Pessoa("Ernesto", 'M', 60);

    printf("Homem com maior idade: %s\n", M_maior_idade(grupo, 5)->nome);
    printf("Mulher com maior idade: %s\n", F_maior_idade(grupo, 5)->nome);
    printf("Media: %d\n", media_idade(grupo, 5));
    printf("Homem com idade media: %s\n", M_media_idade(grupo, 5)->nome);
    printf("Mulher com idade media: %s\n", F_media_idade(grupo, 5)->nome);
    return 0;
}