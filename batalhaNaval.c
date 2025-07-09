#include <stdio.h>
#include <stdlib.h> //para o uso do system("");
#include <ctype.h>  // Para uso e toupper().

//definições globais.
#define LINHA 10
#define COLUNA 10
#define TAM_HABILIDADE 5

//funções.
void limparTela() {
    system("clear");
}

void mostrarTabuleiro(int tabuleiro[LINHA][COLUNA]){
    printf("        Batalha Naval \n");
    printf("     A B C D E F G H I J\n");
    printf("   -----------------------\n");

    for (int i = 0; i < LINHA; i++) {

        //mostrando linha.
        printf("%2d |", i); 

        for (int j = 0; j < COLUNA; j++) {
            // Imprime o caractere correspondente ao valor.
            if (tabuleiro[i][j] == 0) {
                printf(" ~"); //Modifica a aparencia da água. 
            } else if (tabuleiro[i][j] == 3){
                printf(" n"); //modifica o navio.
            } else if (tabuleiro[i][j] == 7){
                printf(" *");
            } else {
                printf(" %d", tabuleiro[i][j]); // Outros valores.
            }
        }
        printf("\n");
    }
    printf("\n");
}

void coordenadas(int* escolhaLinha, char* escolhaLetra){
    // Loop para entrada válida.
    while (scanf(" %c%d", escolhaLetra, escolhaLinha) != 2) {
        printf("Formato invalido! Tente novamente!! ");
        // Limpa o buffer de entrada.
        while(getchar() != '\n');
    }
}

void aplicarHabilidade(int tabuleiro[LINHA][COLUNA], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
int ondeLinha, int ondeColuna, int origemLinha, int origemColuna){
    for (int i = 0; i < TAM_HABILIDADE; i++){
        for (int j = 0; j < TAM_HABILIDADE; j++){
            if (habilidade[i][j] == 1){
                int linhaTabuleiro = ondeLinha + i - origemLinha;

                int colunaTabuleiro = ondeColuna + j - origemColuna;

                if (linhaTabuleiro >= 0 && linhaTabuleiro < LINHA &&
                colunaTabuleiro >= 0 && colunaTabuleiro < COLUNA){
                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0 ||
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] == 3){
                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 7;
                    }
                }
                
            }
            
        }
    }
    
}

int main (){
    //declarando e inicializando a matriz.
    int tabuleiro[LINHA][COLUNA] = {0}; 

    //primeiro vetor navio vertical.
    tabuleiro[2][5] = 3;
    tabuleiro[3][5] = 3;
    tabuleiro[4][5] = 3;

    //segundo vetor navio horizontal. 
    tabuleiro[8][9] = 3;
    tabuleiro[8][8] = 3;
    tabuleiro[8][7] = 3;

    //primeiro navio diagonal. 
    tabuleiro[0][0] = 3;
    tabuleiro[1][1] = 3;
    tabuleiro[2][2] = 3;

    //segundo navio diagonal.
    tabuleiro[9][0] = 3;
    tabuleiro[8][1] = 3;
    tabuleiro[7][2] = 3;

    //matriz da habilidade cone.
    //origem [0][2]
    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    //matriz habilidade cruz.
    //origem [2][2]
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    //matriz octaedro.
    //origem [2][2]
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    //loop para as escolhas.
    while (1){
        limparTela();
        mostrarTabuleiro(tabuleiro);

        //menu.
        printf(" Escolha qual habilidade usar:\n");
        printf(" 1. Cone\n");
        printf(" 2. Cruz\n");
        printf(" 3. Octaedro\n");
        printf(" 0. sair\n");

        printf(" --> ");

        int escolhaHab;
        scanf(" %d", &escolhaHab);

        if (escolhaHab == 0) {
            printf("Saindo do jogo...\n");
            break; //encerra o programa.
        }

        // verificação.
        if (escolhaHab < 1 || escolhaHab > 3) {
            printf("Opcao invalida. \nPressione Enter para tentar novamente...");
            while(getchar() != '\n'); // Limpa buffer de input.
            getchar();
            continue; // Pula para a proxima volta do loop.
        }

        //limpa tela e reescreve o tabuleiro.
        limparTela();
        mostrarTabuleiro(tabuleiro);
        printf(" Escolha a posiçãopara usar a habilidade: (Ex: c8):\n");

        printf(" --> ");
      
        int escolhaLinha;
        char escolhaLetra; //letra referenciando a coluna.
        
        coordenadas(&escolhaLinha, &escolhaLetra); 
        int ondeColuna = toupper(escolhaLetra) - 'A';

        switch (escolhaHab){

            //cone - origem [0][2]
        case 1:
            aplicarHabilidade(tabuleiro, cone, escolhaLinha, ondeColuna, 0, 2);
        break;

        //cruz - origem [2][2]
        case 2:
            aplicarHabilidade(tabuleiro, cruz, escolhaLinha, ondeColuna, 2, 2);
        break;

        //octaedro - origem [2][2]
        case 3:
            aplicarHabilidade(tabuleiro, octaedro, escolhaLinha, ondeColuna, 2, 2);

        break;
        }
    }
    return 0;
}

