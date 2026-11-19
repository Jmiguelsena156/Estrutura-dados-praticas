#ifndef LISTA_H
#define LISTA_H

// Tipo Estruturado Lista
typedef struct lista Lista;

struct lista
{
    int valor;
    Lista *prox;
};

// Criar o ultimo valor da lista.
Lista *criar_lista();

// Insere um valor inteiro na lista.
Lista *inserir_valor(Lista *lst, int valor);

// Imprime a lista seguindo o encadeamento.
void imprimir_lista(Lista *lst);

// Deleta a lista da memoria.
void deletar_lista(Lista *lst);

// Informa qual valor está a posição index.
Lista *calcular_index(Lista *lst, int index);

// Insere um valor após a posição.
Lista *inserir_valor_index(Lista *lst, int index, int valor);

// Verifica se a lista está vazia.
int Lista_vazia(Lista *lst);

// Remove o valor na posição do endereço.
Lista *remover_valor(Lista *lst, int index);

#endif