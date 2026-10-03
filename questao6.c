#include <stdio.h>

void verificar_tabela(char tab[3][3]) {
    int i, j, situacao = 0;

    for (i = 0; i < 3 && situacao == 0; i++) {
        int X = 0, O = 0;
        for (j = 0; j < 3; j++) {
            if (tab[i][j] == 'X') {
                X++;
            }
            if (tab[i][j] == 'O') {
                O++;
            }
        }

        if (X == 3) {
            situacao = 1;
        }
        if (O == 3) {
            situacao = 2;
        }
    }

    for (j = 0; j < 3 && situacao == 0; j++) {
        int X = 0, O = 0;
        for (i = 0; i < 3; i++) {
            if (tab[i][j] == 'X') {
                X++;
            }
            if (tab[i][j] == 'O') {
                O++;
            }
        }

        if (X == 3) {
            situacao = 1;
        }
        if (O == 3) {
            situacao = 2;
        }
    }

    if (situacao == 0) {
        int X = 0, O = 0;
        for (i = 0; i < 3; i++) {
            if (tab[i][i] == 'X') {
                X++;
            }
            if (tab[i][i] == 'O') {
                O++;
            }
        }

        if (X == 3) {
            situacao = 1;
        }
        if (O == 3) {
            situacao = 2;
        }
    }
    
    if (situacao == 0) {
        int X = 0, O = 0;
        for (i = 0; i < 3; i++) {
            if (tab[i][2-i] == 'X') {
                X++;
            }
            if (tab[i][2-i] == 'O') {
                O++;
            }
        }

        if (X == 3) {
            situacao = 1;
        }
        if (O == 3) {
            situacao = 2;
        }
    }

    for (i = 0; i < 3 && situacao == 0; i++) {
        for (j = 0; j < 3; j++) {
            if (tab[i][j] == '-') {
                situacao = 3;
            }
        }
    }

    switch (situacao) {
        case 1:
            printf("X ganhou!\n");
            break;
        case 2:
            printf("O ganhou!\n");
            break;
        case 3:
            printf("Ainda da para jogar!\n");
            break;
        default:
            printf("Empate!\n");
    }
}

int main() {
    char Tabela[3][3] = {{'O', 'X', 'X'} , {'X', 'O', 'O'}, {'X', 'O', 'X'}};

    verificar_tabela(Tabela);
    return 0;
}