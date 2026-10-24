// Questão 45
#include <stdio.h>
#include <stdlib.h>

void copiar_string(char *copia, char *original) {
    int k;

    for (k = 0; original[k] != '\0'; k++) {
        copia[k] = original[k];
    }
    copia[k] = '\0';
}

int strings_iguais(char *str1, char *str2) {
    int k;

    for (k = 0; str2[k] != '\0' && str1[k] != '\0'; k++) {
        if (str1[k] != str2[k]) {
            return 0;
        }
    }

    return 1;
}

typedef struct {
    char *nome;
    int idade;
    char sexo;
} Pessoa;

typedef struct lista_pessoas Lista_Pessoas;

struct lista_pessoas {
    Pessoa *info;
    Lista_Pessoas *prox;
};

Lista_Pessoas *criar_lst() {
    return NULL;
}

Lista_Pessoas *inserir_pessoa(Lista_Pessoas *lst, char *nome, int idade, char sexo) {
    Lista_Pessoas *individuo = (Lista_Pessoas *) malloc(sizeof(Lista_Pessoas));

    if (individuo == NULL) {
        fprintf(stderr, "Nao existe espaco de memoria na maquina.");
        return NULL;
    }

    individuo->info = (Pessoa *) malloc(sizeof(Pessoa));
    if (individuo->info == NULL) {
        free(individuo);
        fprintf(stderr, "Nao existe espaco de memoria na maquina.");
        return NULL;
    }

    individuo->info->nome = (char *) malloc(sizeof(char) * 100);
    if (individuo->info->nome == NULL) {
        free(individuo->info);
        free(individuo);
        fprintf(stderr, "Nao existe espaco de memoria na maquina.");
        return NULL;
    }

    copiar_string(individuo->info->nome, nome);
    individuo->info->sexo = sexo;
    individuo->info->idade = idade;

    individuo->prox = lst;

    return individuo;
}

void imprimir_lst(Lista_Pessoas *lst) {
    Lista_Pessoas *p;

    for (p = lst; p != NULL; p = p->prox) {
        if (p->info->sexo == 'M') {
            printf("- O hospede tem nome %s e ele tem %d anos.\n", p->info->nome, p->info->idade);
        } else {
            printf("- A hospede tem nome %s e ela tem %d anos.\n", p->info->nome, p->info->idade);
        }
    }
}

void deletar_lista(Lista_Pessoas *lst) {
    Lista_Pessoas *pivot = lst;

    while (pivot != NULL) {
        Lista_Pessoas *proximo = pivot->prox;
        free(pivot->info->nome);
        free(pivot->info);
        free(pivot);

        pivot = proximo;
    }

}

Lista_Pessoas *deletar_pessoa_index(Lista_Pessoas *lst, int index) {
    Lista_Pessoas *ant = NULL;
    Lista_Pessoas *p = lst;

    while (p != NULL && index != 0) {
        ant = p;
        p = p->prox;
        index--;
    }

    if (p == NULL) {
        return lst;
    }

    if (ant == NULL) {
        lst = p->prox;
    } else {
        ant->prox = p->prox;
    }
    free(p->info->nome);
    free(p->info);
    free(p);

    return lst;
}

int lista_vazia(Lista_Pessoas *lst) {
    return (lst == NULL);
}

int tamanho_lst(Lista_Pessoas *lst) {
    Lista_Pessoas *p;
    int cont = 0;

    for (p = lst; p != NULL; p = p->prox) {
        cont++;
    }

    return cont;
}

Lista_Pessoas *deletar_pessoa_sexo(Lista_Pessoas *lst, char sexo) {
    Lista_Pessoas *ant = NULL;
    Lista_Pessoas *p = lst;

    while (p != NULL && p->info->sexo != sexo) {
        ant = p;
        p = p->prox;
    }

    if (p == NULL) {
        return lst;
    }

    if (ant == NULL) {
        lst = p->prox;
    } else {
        ant->prox = p->prox;
    }
    free(p->info->nome);
    free(p->info);
    free(p);

    return lst;
}

int main() {
    Lista_Pessoas *Hospedes;

    Hospedes = criar_lst();
    // Dia 1
    Hospedes = inserir_pessoa(Hospedes, "Jose Miguel", 19, 'M');
    Hospedes = inserir_pessoa(Hospedes, "Maria Luisa", 38, 'F');
    Hospedes = inserir_pessoa(Hospedes, "Carlinhos", 22, 'M');
    printf("Dia 1:\n");
    imprimir_lst(Hospedes);

    // Dia 2
    Hospedes = deletar_pessoa_sexo(Hospedes, 'M');
    printf("Dia 2:\n");
    imprimir_lst(Hospedes);

    // Dia 3
    Hospedes = inserir_pessoa(Hospedes, "Yasmim Deques", 20, 'F');
    Hospedes = inserir_pessoa(Hospedes, "Fatima De Silva", 67, 'F');
    printf("Dia 3:\n");
    imprimir_lst(Hospedes);

    // Dia 4
    if (!lista_vazia(Hospedes)) Hospedes = deletar_pessoa_index(Hospedes, tamanho_lst(Hospedes)-1);

    printf("Dia 4:\n");
    imprimir_lst(Hospedes);

    deletar_lista(Hospedes);
    return 0;
}