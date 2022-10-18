#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
  srand(time(NULL));
  int vida1 = 10, vida2 = 10;
  char matriz[7][10];
  char vetor[28];
  for (int linha = 0; linha < 7; linha++) {
    for (int coluna = 0; coluna < 10; coluna++) {
      matriz[linha][coluna] = ' ';
    }
  }
  // Vetor TRAJETO------------------------------------------------------
  vetor[0] = 'P';
  vetor[1] = 'B';
  vetor[2] = 'R';
  vetor[3] = 'G';
  vetor[4] = 'B';
  vetor[5] = 'A';
  vetor[6] = 'B';
  vetor[7] = 'Y';
  vetor[8] = 'B';
  vetor[9] = 'R';

  vetor[10] = 'G';
  vetor[11] = 'P';
  vetor[12] = 'A';
  vetor[13] = 'B';
  vetor[14] = 'B';
  vetor[15] = 'R';

  vetor[16] = 'G';
  vetor[17] = 'B';
  vetor[18] = 'Y';
  vetor[19] = 'B';
  vetor[20] = 'R';
  vetor[21] = 'V';
  vetor[22] = 'B';
  vetor[23] = 'A';
  vetor[24] = 'R';

  vetor[25] = 'Y';
  vetor[26] = 'G';
  vetor[27] = 'P';

  int px1 = 0, py1 = 0, px2 = 0, py2 = 0;
  int J1 = 0, J2 = 0;
  int Vencedor = 0;
  int vivo1 = 1, vivo2 = 1;
  int GameContinue = 1;

  // SORTEO DO PRIMEIRO JOGADOR
  int vez1, vez2;
  int z = rand() % 2;
  if ( z== 1) {
    vez1 = 1;
    vez2 = 0;
  } else {
    vez1 = 0;
    vez2 = 1;
  }

  // INICIO DE FATO DO JOGO
  while (GameContinue) {
    // Matrz MAPA---------------------------------------------------------------
    matriz[0][0] = 'P';
    matriz[0][1] = 'B';
    matriz[0][2] = 'R';
    matriz[0][3] = 'G';
    matriz[0][4] = 'B';
    matriz[0][5] = 'A';
    matriz[0][6] = 'B';
    matriz[0][7] = 'Y';
    matriz[0][8] = 'B';
    matriz[0][9] = 'R';

    matriz[1][9] = 'G';
    matriz[2][9] = 'P';
    matriz[3][9] = 'A';
    matriz[4][9] = 'B';
    matriz[5][9] = 'B';
    matriz[6][9] = 'R';

    matriz[6][0] = 'R';
    matriz[6][1] = 'A';
    matriz[6][2] = 'B';
    matriz[6][3] = 'V';
    matriz[6][4] = 'R';
    matriz[6][5] = 'B';
    matriz[6][6] = 'Y';
    matriz[6][7] = 'B';
    matriz[6][8] = 'G';

    matriz[3][0] = 'P';
    matriz[4][0] = 'G';
    matriz[5][0] = 'Y';

    //  & = '1' e '2' na matriz que apenas é a imagem
    matriz[py1][px1] = '1';
    if (matriz[py2][px2] == '1') {
      matriz[py2][px2] = '&';
    } else {
      matriz[py2][px2] = '2';
    }

    system("clear");
    for (int linha = 0; linha < 7; linha++) {
      for (int coluna = 0; coluna < 10; coluna++) {
        printf("%c ", matriz[linha][coluna]);
      }
      printf("\n");
    }
    printf("VidaJ1: %i\nVidaJ2: %i\nPosicaoJ1: %i\nPosicaoJ2: %i\n", vida1,
           vida2, J1 + 1, J2 + 1);

    // regras DO JOGO
    // CHECA VENCEDOR DO JOGO
    if (J1 >= 27) {
      J1 = 27;
      Vencedor = 1;
      GameContinue = 0;
      break;
    } else if (J2 >= 27) {
      J2 = 27;
      Vencedor = 2;
      GameContinue = 0;
      break;
    } else if (!vivo1 && !vivo2) {
      GameContinue = 0;
      Vencedor = 0;
      break;
    }

    // JOGADOR 1---------------------------------------------------------
    if (vez1 && vivo1) {
      printf("\n\nVez do Jogador 1");
      getchar();
      int d1 = 1 + rand() % 6;
      int posicaoFutura = d1 + J1;
      J1 = posicaoFutura;
      // ASSOCIAÇÃO POSIÇÃO INT COM MATRIZ
      if (J1 < 10) {
        py1 = 0;
        px1 = J1; // TAMANHO COLUNA 0 ATE 9
      } else if (J1 < 16) {
        py1 = (J1 - 9); // TAMANHO LINHA 2 ATE 6
        px1 = 9;
      } else if (J1 < 25) {
        py1 = 6;
        px1 = (-J1 + 24); // ao contrario TAMANHO COLUNA 8 ATE 0
        // -16 + 24 = 8 até -24 + 24 = 0
      } else if (J1 < 27) {
        py1 = (-J1 + 30); // ao contrario TAMANHO LINHA 5 ATÉ 3
        px1 = 0;
        // -25 + 30 = 5 até -26 + 30 = 4
      } else {
        // POSIÇÃO DE FIM DE JOGO
        py1 = 3;
        px1 = 0;
      }

      if (vetor[posicaoFutura] == 'P' && J1 != 27 && J1 != 0) {
        J1 = 0;
        px1 = 0, py1 = 0;
      } else if (vetor[posicaoFutura] == 'R') {
        vida1 -= 3;
      } else if (vetor[posicaoFutura] == 'G' && vida1 < 10) {
        vida1++;
      } else if (vetor[posicaoFutura] == 'Y') {
        vez1 = 0;
      } else if (vetor[posicaoFutura] == 'A') {
        vez2 = 0;
      }
    } else if (vez1 == 0) {
      vez1 = 1;
    }
    // P -PRETO B- BRANCO R- VERMELHO G-VERDE B-BRANCO Y-AMARELO A-AZUL

    // CHECA VENCEDOR DO JOGO
    if (J1 >= 27) {
      J1 = 27;
      Vencedor = 1;
      GameContinue = 0;
      break;
    }
    // Checa Morte de Jogador
    if (vida1 < 1) {
      vivo1 = 0;
    }

    // atualiza matriz para depois imprimir

    matriz[0][0] = 'P';
    matriz[0][1] = 'B';
    matriz[0][2] = 'R';
    matriz[0][3] = 'G';
    matriz[0][4] = 'B';
    matriz[0][5] = 'A';
    matriz[0][6] = 'B';
    matriz[0][7] = 'Y';
    matriz[0][8] = 'B';
    matriz[0][9] = 'R';

    matriz[1][9] = 'G';
    matriz[2][9] = 'P';
    matriz[3][9] = 'A';
    matriz[4][9] = 'B';
    matriz[5][9] = 'B';
    matriz[6][9] = 'R';

    matriz[6][0] = 'R';
    matriz[6][1] = 'A';
    matriz[6][2] = 'B';
    matriz[6][3] = 'V';
    matriz[6][4] = 'R';
    matriz[6][5] = 'B';
    matriz[6][6] = 'Y';
    matriz[6][7] = 'B';
    matriz[6][8] = 'G';

    matriz[3][0] = 'P';
    matriz[4][0] = 'G';
    matriz[5][0] = 'Y';

    matriz[py1][px1] = '1';
    if (matriz[py2][px2] == '1') {
      matriz[py2][px2] = '&';
    } else {
      matriz[py2][px2] = '2';
    }

    system("clear");
    for (int linha = 0; linha < 7; linha++) {
      for (int coluna = 0; coluna < 10; coluna++) {
        printf("%c ", matriz[linha][coluna]);
      }
      printf("\n");
    }
    printf("VidaJ1: %i\nVidaJ2: %i\nPosicaoJ1: %i\nPosicaoJ2: %i\n", vida1,
           vida2, J1 + 1, J2 + 1);
    // JOGADOR 2--------------------------------------------------------------
    if (vez2 && vivo2) {
      printf("\n\nVez do Jogador 2");
      getchar();
      int d2 = 1 + rand() % 6;
      int posicaoFutura = d2 + J2;
      J2 = posicaoFutura;

      // ASSOCIAÇÃO POSIÇÃO INT COM MATRIZ
      if (J2 < 10) {
        py2 = 0;
        px2 = J2; // TAMANHO COLUNA 0 ATE 9
      } else if (J2 < 16) {
        py2 = (J2 - 9); // TAMANHO LINHA 2 ATE 6
        px2 = 9;
      } else if (J2 < 25) {
        py2 = 6;
        px2 = (24 - J2); // ao contrario TAMANHO COLUNA 9 ATE 0
      } else if (J2 < 27) {
        py2 = (30 - J2); // ao contrario TAMANHO LINHA 5 ATÉ 3
        px2 = 0;
      } else {
        // POSIÇÃO DE FIM DE JOGO
        py2 = 3;
        px2 = 0;
      }

      if (vetor[posicaoFutura] == 'P' && J2 != 27 && J2 != 0) {
        J2 = 0;
        px2 = 0, py2 = 0;
      } else if (vetor[posicaoFutura] == 'R') {
        vida2 -= 3;
      } else if (vetor[posicaoFutura] == 'G' && vida2 < 10) {
        vida2++;
      } else if (vetor[posicaoFutura] == 'Y') {
        vez2 = 0;
      } else if (vetor[posicaoFutura] == 'A') {
        vez1 = 0;
      }
    } else if (vez1 == 0) {
      vez2 = 1;
    }

    if (vida2 < 1) {
      vivo2 = 0;
    } else if (vida1 < 1) {
      vivo1 = 0;
    }
    if (J2 >= 27) {
      J2 = 27;
      Vencedor = 2;
      GameContinue = 0;
      break;
    }

    // Matrz MAPA---------------------------------------------------------------
    matriz[0][0] = 'P';
    matriz[0][1] = 'B';
    matriz[0][2] = 'R';
    matriz[0][3] = 'G';
    matriz[0][4] = 'B';
    matriz[0][5] = 'A';
    matriz[0][6] = 'B';
    matriz[0][7] = 'Y';
    matriz[0][8] = 'B';
    matriz[0][9] = 'R';

    matriz[1][9] = 'G';
    matriz[2][9] = 'P';
    matriz[3][9] = 'A';
    matriz[4][9] = 'B';
    matriz[5][9] = 'B';
    matriz[6][9] = 'R';

    matriz[6][0] = 'R';
    matriz[6][1] = 'A';
    matriz[6][2] = 'B';
    matriz[6][3] = 'V';
    matriz[6][4] = 'R';
    matriz[6][5] = 'B';
    matriz[6][6] = 'Y';
    matriz[6][7] = 'B';
    matriz[6][8] = 'G';

    matriz[3][0] = 'P';
    matriz[4][0] = 'G';
    matriz[5][0] = 'Y';

    //  & = '1' e '2' na matriz que apenas é a imagem
    matriz[py1][px1] = '1';
    if (matriz[py2][px2] == '1') {
      matriz[py2][px2] = '&';
    } else {
      matriz[py2][px2] = '2';
    }

    system("clear");
    for (int linha = 0; linha < 7; linha++) {
      for (int coluna = 0; coluna < 10; coluna++) {
        printf("%c ", matriz[linha][coluna]);
      }
      printf("\n");
    }
    printf("VidaJ1: %i\nVidaJ2: %i\nPosicaoJ1: %i\nPosicaoJ2: %i\n", vida1,
           vida2, J1 + 1, J2 + 1);
    getchar();
    // FIM--------------------------------------------------------------
  }

  system("clear");
  if (Vencedor == 1) {
    printf("Jogador 1 Venceu\nVida Restante: %i", vida1);
  } else if (Vencedor == 2) {
    printf("Jogador 2 Venceu\nVida Restante: %i", vida2);
  } else {
    printf("Jogador 1 e 2 Morreram\n");
  }
  return 0;
}