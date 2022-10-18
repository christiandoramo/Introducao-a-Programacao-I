#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));
  {
    // 1º quesito

    char tabuleiro[8][8], pecas = 0;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        tabuleiro[i][j] = '.';
      }
    }
    int px = rand() % 8;
    int py = rand() % 8;
    tabuleiro[py][px] = 'L';
    for (int pecasSemBotar = 8; pecasSemBotar > 0;) {
      int px = rand() % 8;
      int py = rand() % 8;
      if (tabuleiro[py][px] == '.') {
        tabuleiro[py][px] = 'I';
        pecasSemBotar--;
      }
    }
    for (int pecasSemBotar = 8; pecasSemBotar > 0;) {
      int px = rand() % 8;
      int py = rand() % 8;
      if (tabuleiro[py][px] == '.') {
        tabuleiro[py][px] = 'A';
        pecasSemBotar--;
      }
    }

    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        printf("%c ", tabuleiro[i][j]);
      }
      printf("\n");
    }

    if (py + 1 <= 7) {
      if (px + 2 <= 7) {
        if (tabuleiro[py + 1][px + 2] == 'I') {
          printf("\nPeça na Posicao:[%i][%i]", py + 1 + 1, px + 2 + 1);
          pecas++;
        }
      }
      if (px - 2 >= 0) {
        if (tabuleiro[py + 1][px - 2] == 'I') {
          printf("\nPeça na Posicao:[%i][%i]", py + 1 + 1, px - 2 + 1);
          pecas++;
        }
      }
    }

    if (py - 1 >= 0) {
      if (px + 2 <= 7) {
        if (tabuleiro[py - 1][px + 2] == 'I') {
          printf("\nPeça na Posicao:[%i][%i]", py - 1 + 1, px + 2 + 1);
          pecas++;
        }
      }
      if (px - 2 >= 0) {
        if (tabuleiro[py - 1][px - 2] == 'I') {
          printf("\nPeça na Posicao:[%i][%i]", py - 1 + 1, px - 2 + 1);
          pecas++;
        }
      }
    }

    if (py + 2 <= 7) {
      if (px + 1 <= 7) {
        if (tabuleiro[py + 2][px + 1] == 'I') {
          printf("\nPeça na Posicao:[%i][%i]", py + 2 + 1, px + 1 + 1);
          pecas++;
        }
      }
      if (px - 1 >= 0) {
        if (tabuleiro[py + 2][px - 1] == 'I') {
          printf("\nPeça na Posicao:[%i][%i]", py + 2 + 1, px - 1 + 1);
          pecas++;
        }
      }
    }

    if (py - 2 >= 0) {
      if (px + 1 <= 7) {
        if (tabuleiro[py - 2][px + 1] == 'I') {
          printf("\nPeça na Posicao:[%i][%i]", py - 2 + 1, px + 1 + 1);
          pecas++;
        }
      }
      if (px - 1 >= 0) {
        if (tabuleiro[py - 2][px - 1] == 'I') {
          printf("\nPeça na Posicao:[%i][%i]", py - 2 + 1, px - 1 + 1);
          pecas++;
        }
      }
    }

    printf("\n\nPeças Possíveis = %i\n", pecas);
    printf("\nPeças Aliadas = A\n");
    printf("\nPeças Inimigas = I\n");
    printf("\nCavalo[%i][%i] = L\n", py + 1, px + 1);
  }
  getchar();
  system("clear");
  printf("Segundo Jogo");
  getchar();

  // 2º quesito
  {
    char tabuleiro[4][4], pecas = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        tabuleiro[i][j] = 'X';
      }
    }

    int cartoes[4][4];
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0;
    for (int m = 0; m < 4;) {
      for (int n = 0; n < 4;) {
        int i = 1 + rand() % 8;
        if (i == 1 && c1 < 2) {
          cartoes[m][n] = '1';
          c1++;
          n++;
        }
        if (i == 2 && c2 < 2) {
          cartoes[m][n] = '1';
          n++;
          c2++;
        }
        if (i == 3 && c3 < 2) {
          cartoes[m][n] = '2';
          n++;
          c3++;
        }
        if (i == 4 && c4 < 2) {
          cartoes[m][n] = '3';
          n++;
          c4++;
        }
        if (i == 5 && c5 < 2) {
          cartoes[m][n] = '4';
          n++;
          c5++;
        }
        if (i == 6 && c6 < 2) {
          cartoes[m][n] = '5';
          n++;
          c6++;
        }
        if (i == 7 && c7 < 2) {
          cartoes[m][n] = '6';
          n++;
          c7++;
        }
        if (i == 8 && c8 < 2) {
          cartoes[m][n] = '8';
          n++;
          c8++;
        }
      }
      m++;
    }

    int Vencedor = 0, J1 = 0, J2 = 0;
    do {
      system("clear");
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
      }
      // jogador 1
      int p1, p2;
      printf(
          "\n\nJogador 1 Escolha a linha e coluna da\nPRIMEIRA CARTA _ _ ex: 3 "
          "1, ou 4 "
          "4\n\n");
      int Naprovado = 1;
      while (Naprovado) {
        scanf("%i %i", &p1, &p2);
        if (tabuleiro[p1 - 1][p2 - 1] != 'X') {
          printf("\n Cartão inválido - Já descoberto\n");
        } else if (p1 <= 0 || p2 <= 0 || p1 >= 5 || p2 >= 5) {
          printf("\n Cartão inválido - linha e coluna de 1 a 4 \n");
        } else {
          Naprovado = 0;
        }
        getchar();
      }
      p1--;
      p2--;
      system("clear");
      tabuleiro[p1][p2] = cartoes[p1][p2];
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
      }

      int p3, p4;
      printf(
          "\n\nJogador 1 Escolha a linha e coluna da\nSEGUNDA CARTA _ _ ex: 3 "
          "1, ou 4 "
          "4\n\n");
      Naprovado = 1;
      while (Naprovado) {
        scanf("%i %i", &p3, &p4);
        if (tabuleiro[p3 - 1][p4 - 1] != 'X') {
          printf("\n Cartão inválido - Já descoberto\n");
        } else if (p3 <= 0 || p4 <= 0 || p3 >= 5 || p4 >= 5) {
          printf("\n Cartão inválido - linha e coluna de 1 a 4 \n");
        } else {
          Naprovado = 0;
        }
        getchar();
      }
      p3--;
      p4--;
      system("clear");
      tabuleiro[p3][p4] = cartoes[p3][p4];
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
      }

      if (cartoes[p1][p2] == cartoes[p3][p4]) {
        printf("Jogador 1 Acertou");
        getchar();
        J1++;
        tabuleiro[p1][p2] = cartoes[p1][p2];
        tabuleiro[p3][p4] = cartoes[p3][p4];
      } else {
        printf("Jogador 1 Errou");
        getchar();
        tabuleiro[p1][p2] = 'X';
        tabuleiro[p3][p4] = 'X';
      }

      if (J1 > 4) {
        Vencedor = 1;
        break;
      } else if (J1 == J2 && J1 == 4) {
        Vencedor = -1;
        break;
      }

      // jogador 2

      system("clear");
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
      }
      // jogador 1
      int p5, p6;
      printf(
          "\n\nJogador 2 Escolha a linha e coluna da\nPRIMEIRA CARTA _ _ ex: 3 "
          "1, ou 4 "
          "4\n\n");
      Naprovado = 1;
      while (Naprovado) {
        scanf("%i %i", &p5, &p6);
        if (tabuleiro[p5 - 1][p6 - 1] != 'X') {
          printf("\n Cartão inválido - Já descoberto\n");
        } else if (p5 <= 0 || p6 <= 0 || p5 >= 5 || p6 >= 5) {
          printf("\n Cartão inválido - linha e coluna de 1 a 4 \n");
        } else {
          Naprovado = 0;
        }
        getchar();
      }
      p5--;
      p6--;
      system("clear");
      tabuleiro[p5][p6] = cartoes[p5][p6];
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
      }

      int p7, p8;
      printf(
          "\n\nJogador 2 Escolha a linha e coluna da\nSEGUNDA CARTA _ _ ex: 3 "
          "1, ou 4 "
          "4\n\n");
      Naprovado = 1;
      while (Naprovado) {
        scanf("%i %i", &p7, &p8);
        if (tabuleiro[p7 - 1][p8 - 1] != 'X') {
          printf("\n Cartão inválido - Já descoberto\n");
        } else if (p7 <= 0 || p8 <= 0 || p7 >= 5 || p8 >= 5) {
          printf("\n Cartão inválido - linha e coluna de 1 a 4 \n");
        } else {
          Naprovado = 0;
        }
        getchar();
      }
      p7--;
      p8--;
      system("clear");
      tabuleiro[p7][p8] = cartoes[p7][p8];
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
      }

      if (cartoes[p5][p6] == cartoes[p7][p8]) {
        printf("Jogador 2 Acertou");
        getchar();
        J2++;
        tabuleiro[p5][p6] = cartoes[p5][p6];
        tabuleiro[p7][p8] = cartoes[p7][p8];
      } else {
        printf("Jogador 2 Errou");
        getchar();
        tabuleiro[p5][p6] = 'X';
        tabuleiro[p7][p8] = 'X';
      }

      if (J2 > 4) {
        Vencedor = 2;
        break;
      } else if (J1 == J2 && J1 == 4) {
        Vencedor = -1;
        break;
      }
    } while (!Vencedor);

    if (Vencedor == 1) {
      printf("Vencedor = jogador 1");
    } else if (Vencedor == 2) {
      printf("Vencedor = jogador 2");
    } else {
      printf("Empate");
    }
    getchar();
  }
  return 0;
}