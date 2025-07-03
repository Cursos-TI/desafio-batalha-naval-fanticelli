#include <stdio.h>

int main (){

    //declarando e inicializando a matriz do tabuleiro 10X10.
    //inicializando com 0 (água).
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    }; 

    //primeiro vetor navio vertical.
   tabuleiro[2][5] = 3;
   tabuleiro[3][5] = 3;
   tabuleiro[4][5] = 3;

   //segundo vetor navio horizontal.
   tabuleiro[8][9] = 3;
   tabuleiro[8][8] = 3;
   tabuleiro[8][7] = 3;

    //imprimindo.
    printf("----- Batalha Naval -----\n");
    printf("\n");

    //mostrando as colunas.
    printf("    A B C D E F G H I J\n");

    for (int i = 0; i < 10; i++) {
        printf("%2d ", i); //imprime numero da linha.
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}