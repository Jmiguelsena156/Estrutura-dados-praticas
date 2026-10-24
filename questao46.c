// Questão 46
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copiar_string(char *string1, char *string2) {
    int k;
    for (k = 0; string2[k] != '\0'; k++) {
        string1[k] = string2[k];
    }
    string1[k] = '\0';
}

int strings_iguais(char *string1, char *string2) {
    int k;
    for (k = 0; string1[k] != '\0' && string2[k] != '\0'; k++) {
        if (string1[k] != string2[k]) {
            return 0;
        }
    }

    if (string1[k] != string2[k]) {
        return 0;
    }

    return 1;
}

typedef struct lista_alunos Lista_Alunos;

struct lista_alunos {
    char Matricula[11];
    Lista_Alunos *prox;
};

typedef struct lista_turmas Lista_Turmas;

struct lista_turmas {
    char nome_turma[51];
    int tam_turmas;
    Lista_Alunos *turma;
    Lista_Turmas *prox;
};

Lista_Alunos *criar_aluno() {
    return NULL;
}

Lista_Alunos *inserir_aluno(Lista_Alunos *lst) {
    Lista_Alunos *aluno = (Lista_Alunos *) malloc(sizeof(Lista_Alunos));

    if (aluno == NULL) {
        printf("Nao eh possivel colocar mais alunos.\n");
        return lst;
    }
    aluno->prox = lst;

    int k;
    for (k = 0; k < 11; k++) {
        aluno->Matricula[k] = (rand() % 10) + '0';
    }

    return aluno;
}

Lista_Turmas *criar_turma() {
    return NULL;
}

Lista_Turmas *inserir_turma(Lista_Turmas *lst, int quant_alunos, char *nome) {
    Lista_Turmas *turma_nova = (Lista_Turmas *) malloc(sizeof(Lista_Turmas));

    if (turma_nova == NULL) {
        return lst;
    }

    turma_nova->turma = criar_aluno();
    copiar_string(turma_nova->nome_turma, nome);
    turma_nova->tam_turmas = quant_alunos;

    int k;
    for (k = 0; k < quant_alunos; k++) {
        turma_nova->turma = inserir_aluno(turma_nova->turma);
    }

    turma_nova->prox = lst;

    return turma_nova;
}

void deletar_Alunos(Lista_Alunos *lst) {
    Lista_Alunos *p = lst;

    while (p != NULL) {
        Lista_Alunos *t = p->prox;
        free(p);
        p = t;
    }

}

void deletar_Turmas(Lista_Turmas *lst) {
    Lista_Turmas *p = lst;

    while (p != NULL) {
        Lista_Turmas *t = p->prox;
        deletar_Alunos(p->turma);
        free(p);
        p = t;
    }

}

void imprimir_Turmas(Lista_Turmas *lst) {
    Lista_Turmas *p;

    for (p = lst; p != NULL; p = p->prox) {
        printf("* %s - possui %d alunos.\n", p->nome_turma, p->tam_turmas);
    }
}

Lista_Turmas *procurar_turma(Lista_Turmas *escola, char *nome_turma) {
    Lista_Turmas *p = escola;

    while (p != NULL && !strings_iguais(p->nome_turma, nome_turma)) {
        p = p->prox;
    }

    if (p == NULL) {
        return NULL;
    }

    return p;
}

Lista_Turmas *remover_alunos(Lista_Turmas* escola, char *nome_turma, int quant_alunos) {
    Lista_Turmas *turma = procurar_turma(escola, nome_turma);
    turma->tam_turmas -= quant_alunos;
    Lista_Alunos *p = turma->turma;

    while (p != NULL && quant_alunos != 0) {
        Lista_Alunos *t = p->prox;
        free(p);
        p = t;
        quant_alunos--;
    }
    turma->turma = p;

    return escola;
}

Lista_Turmas *adicionar_alunos(Lista_Turmas* escola, char *nome_turma, int quant_alunos) {
    Lista_Turmas *turma = procurar_turma(escola, nome_turma);
    turma->tam_turmas += quant_alunos;
    Lista_Alunos *p = turma->turma;

    while (quant_alunos != 0) {
        p = inserir_aluno(p);
        quant_alunos--;
    }
    turma->turma = p;

    return escola;
}

int main() {
    srand(time(NULL));
    Lista_Turmas *Escola_IFPB = criar_turma();

    // Mes 1
    Escola_IFPB = inserir_turma(Escola_IFPB, 30, "ADS - periodo 2");
    Escola_IFPB = inserir_turma(Escola_IFPB, 25, "BECA - periodo 3");

    // Mes 2;
    Escola_IFPB = remover_alunos(Escola_IFPB, "BECA - periodo 3", 25/2);
    Escola_IFPB = adicionar_alunos(Escola_IFPB, "BECA - periodo 3", 25/2 + 3);

    // Mes 3:
    Escola_IFPB = inserir_turma(Escola_IFPB, 40, "BEC - periodo 1");
    imprimir_Turmas(Escola_IFPB);
    deletar_Turmas(Escola_IFPB);
    return 0;
}