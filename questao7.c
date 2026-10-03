#include <stdio.h>

void transformar_Cinza(int largura, int altura, int img[altura][largura][3]) {
    int x, y;

    for (x = 0; x < largura; x++) {
        for (y = 0; y < altura; y++) {
            int media = (img[y][x][0] + img[y][x][1] + img[y][x][2]) / 3;

            img[y][x][0] = media;
            img[y][x][1] = media;
            img[y][x][2] = media;
        }
    }
}

int main() {
    return 0;
}