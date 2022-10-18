#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int Condicao = 0;

  {

    char matriz[5][5];
    int var1 = 0, var2 = 0, var3 = 0, var4 = 0, FimdeFase = 1;
    for (int linha = 0; linha < 5; linha++) {
      for (int coluna = 0; coluna < 5; coluna++) {
        matriz[linha][coluna] = '_';
      }
    }
    matriz[0][0] = 'P';
    matriz[0][3] = '1';
    matriz[1][3] = '2';
    matriz[2][3] = '2';
    matriz[3][3] = '3';
    matriz[4][3] = '3';

    matriz[0][4] = '1';
    matriz[1][4] = '1';
    matriz[2][4] = '2';
    matriz[3][4] = '4';
    matriz[4][4] = '4';

    int posicaoY = 0;
    int posicaoX = 0;

    do {
      matriz[0][0] = 'P';
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          printf("%c ", matriz[i][j]);
        }
        printf("\n");
      }

      if (posicaoY == 0 && posicaoX == 0) {
        printf("\nLembre-se de pegar APENAS 1 item de cada para sair pela "
               "porta\n");
      };

      char entrada;
      scanf("%c", &entrada);
      getchar();

      system("clear");
      switch (entrada) {
      case 'w':
        if (posicaoY > 0) {
          if ((matriz[posicaoY - 1][posicaoX] == '1') ||
              (matriz[posicaoY - 1][posicaoX] == '2') ||
              (matriz[posicaoY - 1][posicaoX] == '3') ||
              (matriz[posicaoY - 1][posicaoX] == '4')) {
            if (matriz[posicaoY - 1][posicaoX] == '1') {
              var1++;
            }
            if (matriz[posicaoY - 1][posicaoX] == '2') {
              var2++;
            }
            if (matriz[posicaoY - 1][posicaoX] == '3') {
              var3++;
            }
            if (matriz[posicaoY - 1][posicaoX] == '4') {
              var4++;
            }
          }

          matriz[posicaoY - 1][posicaoX] = 'W';
          matriz[posicaoY][posicaoX] = '_';
          posicaoY--;
        }

        break;
      case 's':
        if (posicaoY < 4) {

          if ((matriz[posicaoY + 1][posicaoX] == '1') ||
              (matriz[posicaoY + 1][posicaoX] == '2') ||
              (matriz[posicaoY + 1][posicaoX] == '3') ||
              (matriz[posicaoY + 1][posicaoX] == '4')) {
            if (matriz[posicaoY + 1][posicaoX] == '1') {
              var1++;
            }
            if (matriz[posicaoY + 1][posicaoX] == '2') {
              var2++;
            }
            if (matriz[posicaoY + 1][posicaoX] == '3') {
              var3++;
            }
            if (matriz[posicaoY + 1][posicaoX] == '4') {
              var4++;
            }
          }

          matriz[posicaoY + 1][posicaoX] = 'W';
          matriz[posicaoY][posicaoX] = '_';
          posicaoY++;
        }
        break;
      case 'a':
        if (posicaoX > 0) {

          if ((matriz[posicaoY][posicaoX - 1] == '1') ||
              (matriz[posicaoY][posicaoX - 1] == '2') ||
              (matriz[posicaoY][posicaoX - 1] == '3') ||
              (matriz[posicaoY][posicaoX - 1] == '4')) {
            if (matriz[posicaoY][posicaoX - 1] == '1') {
              var1++;
            }
            if (matriz[posicaoY][posicaoX - 1] == '2') {
              var2++;
            }
            if (matriz[posicaoX][posicaoX - 1] == '3') {
              var3++;
            }
            if (matriz[posicaoY][posicaoX - 1] == '4') {
              var4++;
            }
          }

          matriz[posicaoY][posicaoX - 1] = 'W';
          matriz[posicaoY][posicaoX] = '_';
          posicaoX--;
        }
        break;
      case 'd':
        if (posicaoX < 4) {

          if ((matriz[posicaoY][posicaoX + 1] == '1') ||
              (matriz[posicaoY][posicaoX + 1] == '2') ||
              (matriz[posicaoY][posicaoX + 1] == '3') ||
              (matriz[posicaoY][posicaoX + 1] == '4')) {
            if (matriz[posicaoY][posicaoX + 1] == '1') {
              var1++;
            }
            if (matriz[posicaoY][posicaoX + 1] == '2') {
              var2++;
            }
            if (matriz[posicaoY][posicaoX + 1] == '3') {
              var3++;
            }
            if (matriz[posicaoY][posicaoX + 1] == '4') {
              var4++;
            }
          }

          matriz[posicaoY][posicaoX + 1] = 'W';
          matriz[posicaoY][posicaoX] = '_';
          posicaoX++;
        }
        break;
      default:
        break;
      }

      if (var1 > 1 || var2 > 1 || var3 > 1 || var4 > 1) {
        FimdeFase = 0;
        Condicao = 1;
      }

      if (var1 == 1 && var2 == 1 && var3 == 1 && var4 == 1) {
        if (posicaoX == 0 && posicaoY == 0) {
          Condicao = 2;
          FimdeFase = 0;
        } else {
          printf("\nWALTER! Corra para a Porta ('P')\n");
        }
      }
    } while (FimdeFase);
  }

  system("clear");
  if (Condicao == 2) {

    // FASE 2 -----------------------------------------------------

    Condicao = 0;

    char matriz[3][10];
    int FimdeFase = 1, decarro = 0;
    for (int linha = 0; linha < 3; linha++) {
      for (int coluna = 0; coluna < 10; coluna++) {
        matriz[linha][coluna] = '_';
      }
    }

    int posicaoY = 0;
    int posicaoX = 0;

    if (decarro == 1) {
      matriz[posicaoY][posicaoX] = '5';
    }
    matriz[0][0] = 'P';
    matriz[2][9] = 'S';

    // mantém os carros na matriz após Walter sair de cima
    if (posicaoY != 0 && posicaoX > 2) {
      switch (posicaoX) {
      case 3:
        matriz[0][3] = '1';
        matriz[0][4] = '2';
        // WALTER ESTÁ AQUI
        matriz[0][6] = '4';
        matriz[0][7] = '5';
        matriz[0][8] = '6';
        matriz[0][9] = '7';
        break;
      case 4:
        matriz[0][3] = '1';
        matriz[0][4] = '2';
        matriz[0][5] = '3';
        // WALTER ESTÁ AQUI
        matriz[0][7] = '5';
        matriz[0][8] = '6';
        matriz[0][9] = '7';
        break;
      case 6:
        matriz[0][3] = '1';
        matriz[0][4] = '2';
        matriz[0][5] = '3';
        matriz[0][6] = '4';
        matriz[0][7] = '5';
        // WALTER ESTÁ AQUI
        matriz[0][9] = '7';
        break;
      case 7:
        matriz[0][3] = '1';
        matriz[0][4] = '2';
        matriz[0][5] = '3';
        matriz[0][6] = '4';
        matriz[0][7] = '5';
        matriz[0][8] = '6';
        // WALTER ESTÁ AQUI
        break;
      default:
        break;
      }
    } else {
      matriz[0][3] = '1';
      matriz[0][4] = '2';
      matriz[0][5] = '3';
      matriz[0][6] = '4';
      matriz[0][7] = '5';
      matriz[0][8] = '6';
      matriz[0][9] = '7';
    }

    do {

      // IMPRIMI MATRIZ
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
          printf("%c ", matriz[i][j]);
        }
        printf("\n");
      }

      if (posicaoY == 0 && posicaoX == 0) {
        printf("\nPegue o Seu Carro (numero: 5)\n");
      };

      char entrada;
      scanf("%c", &entrada);
      getchar();

      system("clear");
      switch (entrada) {
      case 'w':
        if (posicaoY > 0) {

          matriz[posicaoY - 1][posicaoX] = 'W';
          matriz[posicaoY][posicaoX] = '_';
          posicaoY--;
        }
        break;
      case 's':
        if (posicaoY < 3) {

          matriz[posicaoY + 1][posicaoX] = 'W';
          matriz[posicaoY][posicaoX] = '_';
          posicaoY++;
        }
        break;
      case 'a':
        if (posicaoX > 0) {

          matriz[posicaoY][posicaoX - 1] = 'W';
          matriz[posicaoY][posicaoX] = '_';
          posicaoX--;
        }
        break;
      case 'd':
        if (posicaoX < 9) {

          matriz[posicaoY][posicaoX + 1] = 'W';
          matriz[posicaoY][posicaoX] = '_';
          posicaoX++;
        }
        break;
      default:
        break;
      }

      if (posicaoX == 7 && posicaoY == 0 && decarro == 0) {
        decarro++;
      }

      if (posicaoX == 9 && posicaoY == 2 && decarro == 1) {
        Condicao = 2;
        FimdeFase = 0;
      }

      if (decarro == 1) {
        matriz[posicaoY][posicaoX] = '5';
      }
      matriz[0][0] = 'P';
      matriz[2][9] = 'S';

      // mantém os carros na matriz após Walter sair de cima
      if (posicaoY == 0 && posicaoX > 2) {
        switch (posicaoX) {
        case 3:
          // WALTER ESTÁ AQUI
          matriz[0][4] = '2';
          matriz[0][5] = '3';
          matriz[0][6] = '4';
          matriz[0][7] = '5';
          matriz[0][8] = '6';
          matriz[0][9] = '7';
          break;
        case 4:

          matriz[0][3] = '1';
          // WALTER ESTÁ AQUI
          matriz[0][5] = '3';
          matriz[0][6] = '4';
          matriz[0][7] = '5';
          matriz[0][8] = '6';
          matriz[0][9] = '7';
          break;
        case 6:
          matriz[0][3] = '1';
          matriz[0][4] = '2';
          matriz[0][5] = '3';
          // WALTER ESTÁ AQUI
          matriz[0][7] = '5';
          matriz[0][8] = '6';
          matriz[0][9] = '7';
          break;
        case 7:
          matriz[0][3] = '1';
          matriz[0][4] = '2';
          matriz[0][5] = '3';
          matriz[0][6] = '4';
          // WALTER ESTÁ AQUI
          matriz[0][8] = '6';
          matriz[0][9] = '7';
          break;
        case 8:
          matriz[0][3] = '1';
          matriz[0][4] = '2';
          matriz[0][5] = '3';
          matriz[0][6] = '4';
          matriz[0][7] = '5';
          // WALTER ESTÁ AQUI
          matriz[0][9] = '7';

          break;
        case 9:
          matriz[0][3] = '1';
          matriz[0][4] = '2';
          matriz[0][5] = '3';
          matriz[0][6] = '4';
          matriz[0][7] = '5';
          matriz[0][8] = '6';
          // WALTER ESTÁ AQUI
          break;
        default:
          break;
        }
      } else {
        matriz[0][3] = '1';
        matriz[0][4] = '2';
        matriz[0][5] = '3';
        matriz[0][6] = '4';
        matriz[0][7] = '5';
        matriz[0][8] = '6';
        matriz[0][9] = '7';
      }

      // AVISA CARRO ERRADO TÃO SIMPLES N ? KKK
      if (posicaoY == 0) {
        if (posicaoX > 2 && posicaoX != 7) {
          printf("Esse não é o seu Carro!!!\n");
        }
      }

    } while (FimdeFase);
  }

  system("clear");

  // apenas para testar Condicao  = 2

  int GameContinue = 1;

  if (Condicao == 2) {
    srand(time(NULL));
    // inicio FASE 3

    Condicao = 0;
    char matriz[8][10];
    int itens = 0, item1 = 1, item2 = 1, item3 = 1, item4 = 1;

    for (int linha = 0; linha < 8; linha++) {
      for (int coluna = 0; coluna < 10; coluna++) {
        matriz[linha][coluna] = '_';
      }
    }

    matriz[0][0] = 'E';
    matriz[1][9] = 'P';
    matriz[4][5] = 'P';
    matriz[6][3] = 'J';
    matriz[7][9] = 'S';
    matriz[2][9] = '1';
    matriz[5][5] = '2';
    matriz[2][0] = '3';
    matriz[1][5] = '4';

    matriz[0][9] = 'x';
    matriz[0][8] = 'x';
    matriz[0][7] = 'x';
    matriz[0][6] = 'x';
    matriz[1][1] = 'x';
    matriz[1][2] = 'x';
    matriz[1][3] = 'x';
    matriz[1][4] = 'x';
    matriz[2][1] = 'x';
    matriz[2][2] = 'x';
    matriz[2][3] = 'x';
    matriz[2][4] = 'x';
    matriz[2][5] = 'x';
    matriz[2][6] = 'x';
    matriz[2][7] = 'x';
    matriz[2][8] = 'x';

    matriz[4][1] = 'x';
    matriz[4][2] = 'x';
    matriz[4][3] = 'x';
    matriz[4][4] = 'x';
    matriz[4][6] = 'x';
    matriz[4][7] = 'x';
    matriz[4][8] = 'x';

    matriz[5][2] = 'x';
    matriz[5][3] = 'x';
    matriz[5][4] = 'x';
    matriz[5][6] = 'x';
    matriz[5][7] = 'x';
    matriz[5][9] = 'x';

    matriz[6][0] = 'x';
    matriz[6][2] = 'x';
    matriz[6][4] = 'x';
    matriz[6][6] = 'x';
    matriz[6][7] = 'x';
    matriz[6][9] = 'x';

    matriz[7][0] = 'x';

    int J = 0;  // BOOL pegou Jesse Sim ou Não
    int P1 = 0, // BOOL policial 1 se ja colidiu UMA vez com Walter
        P2 = 0; // BOOL policial 2 se ja colidiu UMA vez com Walter
    int posicaoX = 0, posicaoY = 0;
    do {
      for (int linha = 0; linha < 8; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
          printf("%c ", matriz[linha][coluna]);
        }
        printf("\n");
      }
      printf("\n\Produtos: %i\n", itens);
      if (posicaoY == 7 && posicaoX == 9 && !J) {
        printf("\nPegue Jesse para sair!! ('J')");
      }
      char entrada;
      scanf("%c", &entrada);
      getchar();
      system("clear");
      switch (entrada) {
      case 'w':
        if (matriz[posicaoY - 1][posicaoX] != 'x' &&
            matriz[posicaoY - 1][posicaoX] != 'E' && posicaoY > 0) {
          matriz[posicaoY - 1][posicaoX] = 'W';
          matriz[posicaoY][posicaoX] = '_';
          posicaoY--;
        }
        break;
      case 's':
        if (matriz[posicaoY + 1][posicaoX] != 'x' && posicaoY < 7) {
          matriz[posicaoY + 1][posicaoX] = 'W';
          matriz[posicaoY][posicaoX] = '_';
          posicaoY++;
        }
        break;
      case 'd':
        if (matriz[posicaoY][posicaoX + 1] != 'x' && posicaoX < 9) {
          matriz[posicaoY][posicaoX + 1] = 'W';
          matriz[posicaoY][posicaoX] = '_';
          posicaoX++;
        }
        break;
      case 'a':
        if (matriz[posicaoY][posicaoX - 1] != 'x' &&
            matriz[posicaoY][posicaoX - 1] != 'E' && posicaoX > 0) {
          matriz[posicaoY][posicaoX - 1] = 'W';
          matriz[posicaoY][posicaoX] = '_';
          posicaoX--;
        }
        break;
      }

      matriz[0][0] = 'E'; // Correção para 'E' não virar '_'
      matriz[7][9] = 'S'; // Correção para 'S' não virar '_'

      // ITENS
      if (posicaoY == 2 && posicaoX == 9 && item1 == 1) {
        itens++;
        item1--;
      }
      if (posicaoY == 5 && posicaoX == 5 && item2 == 1) {
        itens++;
        item2--;
      }
      if (posicaoY == 2 && posicaoX == 0 && item3 == 1) {
        itens++;
        item3--;
      }
      if (posicaoY == 1 && posicaoX == 5 && item4 == 1) {
        itens++;
        item4--;
      }

      // JESSE
      if (posicaoY == 6 && posicaoX == 3 && J == 0) {
        J++;
      }

      // POLICIAIS

      if (posicaoY == 1 && posicaoX == 9 && P1 == 0) {
        int prob =
            rand() % 2; // se prob = 0 é preso senão perde metade dos itens
        if (prob > 0) {
          itens /= 2;
        } else {
          Condicao = 3;
          GameContinue = 0;
          break;
        }
        P1++;
      }
      if (posicaoY == 4 && posicaoX == 5 && P2 == 0) {
        int prob =
            rand() % 2; // se prob = 0 é preso senão perde metade dos itens
        if (prob > 0) {
          itens /= 2;
        } else {
          Condicao = 3;
          GameContinue = 0;
          break;
        }
        P2++;
      }

      // SAÍDA
      if (J && posicaoY == 7 && posicaoX == 9) {
        if (itens >= 2) {
          Condicao = 4;
        } else if (itens == 1) {
          Condicao = 2;
        }
        GameContinue = 0;
      }

    } while (GameContinue);
  }

  // Fim de Jogo
  system("clear");
  if (Condicao == 1) {
    printf("Você morreu");
  } else if (Condicao == 4) {
    printf("Produção Dobrada");
  } else if (Condicao == 2) {
    printf("Produção Normal");
  } else if (Condicao == 3) {
    printf("Você foi Preso");
  } else {
    printf("Não Haverá Trabalho Hoje");
  }
  printf("\n\nJOGO ENCERRADO\n\n");
  return 0;
}