#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "labirinto.h"

int main() {
    printf("Labirinto:\n");
    imprimir_Labirinto();

    Rota *r = Buscar_Saida();

    imprimir_caminho(r->caminhos, r->quant_c);
    deletar_rota(r);
    return 0;
}