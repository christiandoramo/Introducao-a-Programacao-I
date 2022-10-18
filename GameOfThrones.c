#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  char mapa[10][10];
  // preenchendo linha coluna
  for (int linha = 0; linha < 10; linha++) {
    for (int coluna = 0; coluna < 10; coluna++) {
      // prenche mapa
      mapa[linha][coluna] = '_';
    }
  }
  // definindo posicoes aleatorias
  srand(time(NULL));
  for (int obstaculos = 0; obstaculos < 20;) {
    int oX = rand() % 10, oY = rand() % 10;
    if (mapa[oY][oX] == '_') {
      mapa[oY][oX] = 'O';
      obstaculos++;
    }
  }
  for (int inimigos = 0; inimigos < 20;) {
    int iX = rand() % 10, iY = rand() % 10;
    if (mapa[iY][iX] == '_') {
      mapa[iY][iX] = 'I';
      inimigos++;
    }
  }
  for (int pocoes = 0; pocoes < 10;) {
    int pX = rand() % 10, pY = rand() % 10;
    if (mapa[pY][pX] == '_') {
      mapa[pY][pX] = 'P';
      pocoes++;
    }
  }

  // status iniciais
  int vidaAtualJ = 100, vidaMaxJ = 100, vidaC = 100, vidaAtualN = 200;
  int temPocao = 0, temInimigo = 0, tentativas = 5, Negociacao = 0,
      estadoCersei = 0,
      estadoRei = 0; // verificadores
  // definindo loop principal e posicao Inicial
  int Continue = 1, Progresso = 0, posicaoY = 0, posicaoX = 0;
  do {
    // posicoes fixadas
    mapa[0][0] = 'W';
    if (estadoCersei == 0)
      mapa[4][4] = 'C';
    mapa[9][9] = 'N';
    // imprimindo matriz
    for (int linha = 0; linha < 10; linha++) {
      for (int coluna = 0; coluna < 10; coluna++) {
        printf("%c ", mapa[linha][coluna]);
      }
      printf("\n");
    }
    printf("\n\nVida Atual: %i\n", vidaAtualJ);

    // controles e checa obstaculos
    printf("\nAperte w/a/s/d - cima/esquerda/baixo/direita\n");
    char entrada;
    scanf("%c", &entrada);
    getchar();
    if (entrada == 'w' && posicaoY > 0 && mapa[posicaoY - 1][posicaoX] != 'O') {
      if (mapa[posicaoY - 1][posicaoX] == 'I') {
        temInimigo = 1;
      } else if (mapa[posicaoY - 1][posicaoX] == 'P') {
        temPocao = 1;
      }
      mapa[posicaoY - 1][posicaoX] = 'J';
      mapa[posicaoY][posicaoX] = '_';
      posicaoY--;
    }
    if (entrada == 's' && posicaoY < 9 && mapa[posicaoY + 1][posicaoX] != 'O') {
      if (mapa[posicaoY + 1][posicaoX] == 'I') {
        temInimigo = 1;
      } else if (mapa[posicaoY + 1][posicaoX] == 'P') {
        temPocao = 1;
      }
      mapa[posicaoY + 1][posicaoX] = 'J';
      mapa[posicaoY][posicaoX] = '_';
      posicaoY++;
    }
    if (entrada == 'd' && posicaoX < 9 && mapa[posicaoY][posicaoX + 1] != 'O') {
      if (mapa[posicaoY][posicaoX + 1] == 'I') {
        temInimigo = 1;
      } else if (mapa[posicaoY][posicaoX + 1] == 'P') {
        temPocao = 1;
      }
      mapa[posicaoY][posicaoX + 1] = 'J';
      mapa[posicaoY][posicaoX] = '_';
      posicaoX++;
    }
    if (entrada == 'a' && posicaoX > 0 && mapa[posicaoY][posicaoX - 1] != 'O') {
      if (mapa[posicaoY][posicaoX - 1] == 'I') {
        temInimigo = 1;
      } else if (mapa[posicaoY][posicaoX - 1] == 'P') {
        temPocao = 1;
      }
      mapa[posicaoY][posicaoX - 1] = 'J';
      mapa[posicaoY][posicaoX] = '_';
      posicaoX--;
    }
    // Interacoes e Regras do Jogo

    // Regra pocoes
    if (temPocao) {
      if (vidaAtualJ < 200 - 5 && vidaAtualJ > 100) {
        vidaAtualJ += 5;
      } else if (vidaAtualJ >= 200 - 5 && vidaAtualJ < 200) {
        vidaAtualJ = 200;
      } else if (vidaAtualJ <= vidaMaxJ - 5) {
        vidaAtualJ += 5;
      } else if (vidaAtualJ >= vidaMaxJ - 5 && vidaAtualJ < vidaMaxJ) {
        vidaAtualJ = 100;
      }
      temPocao = 0;
    }
    // Regra inimigos
    if (temInimigo) {
      vidaAtualJ -= 1;
      temInimigo = 0;
    }
    // Negociação Cersei
    if (tentativas > 0 && posicaoY == 4 && posicaoX == 4) {
      if (tentativas > 0) {
        int chanceNegociar = rand() % 101;
        if (chanceNegociar >= 60) {
          Negociacao++;
          if (Negociacao == 3) {
            vidaAtualJ += 100;
            estadoCersei = 2;
          }
        }
        tentativas--;
      }
      // Guerra Cersei
      if (Negociacao < 3 && tentativas == 0 && estadoCersei == 0) {
        system("clear");
        printf("Inicio da Guerra contra Cersei\n");
        getchar();
        system("clear");
        while (vidaAtualJ > 0 && vidaC > 0) {
          system("clear");
          printf("Continue apertando enter para lutar\n");
          getchar();
          int ataqueJ = rand() % 101;
          int ataqueC = rand() % 101;
          while (vidaAtualJ > 0 && ataqueJ >= 50) {
            vidaC -= 10;

            printf("\n\nVida de Jon: %i\nVida de Cersei: %i\n\n", vidaAtualJ,
                   vidaC);
            ataqueJ = rand() % 101;
            getchar();
            system("clear");
            if (vidaC <= 0) {
              estadoCersei = 1;
              printf("Você Venceu Cersei\nAgora Enfrente o Rei da Noite");
              getchar();
              break;
            }
          }
          while (vidaC > 0 && ataqueC >= 50) {
            vidaAtualJ -= 10;
            printf(
                "\n\nVocê Errou o seu ataque, agora é o turno de Cersei\n\n");

            ataqueC = rand() % 101;
            printf("\n\nVida de Jon: %i\nVida de Cersei: %i\n\n", vidaAtualJ,
                   vidaC);
            getchar();
            system("clear");
            if (vidaAtualJ <= 0) {
              Continue = 0;
              Progresso = 1;
              break;
            }
          }

          // fim Negociação
        }
      }
    }

    // luta Rei da Noite
    if (posicaoX == 9 && posicaoY == 9) {
      if (estadoCersei != 0) {

        system("clear");
        printf("Inicio da Guerra contra o Rei da Noite\n");
        getchar();
        system("clear");
        while (vidaAtualJ > 0 && vidaAtualN > 0) {
          system("clear");
          printf("Continue apertando enter para lutar\n");
          getchar();
          int ataqueJ = rand() % 101;
          int ataqueN = rand() % 101;
          while (vidaAtualJ > 0 && ataqueJ >= 50) {
            vidaAtualN -= 10;

            printf("\n\nVida de Jon: %i\nVida dO Rei da Noite: %i\n\n",
                   vidaAtualJ, vidaAtualN);
            ataqueJ = rand() % 101;
            getchar();
            system("clear");
            if (vidaAtualN <= 0) {
              Progresso = 2;
              Continue = 0;
              break;
            }
          }
          while (vidaAtualN > 0 && ataqueN >= 50) {
            vidaAtualJ -= 5;
            vidaAtualN += 5;
            printf("\n\nVocê Errou o seu ataque, agora é o turno do Rei da "
                   "Noite\n\n");

            ataqueN = rand() % 101;
            printf("\n\nVida de Jon: %i\nVida do Rei da Noite: %i\n\n",
                   vidaAtualJ, vidaAtualN);
            getchar();
            system("clear");
            if (vidaAtualJ <= 0) {
              Continue = 0;
              Progresso = 1;

              break;
            }
          }
        }
      } else {
        printf("\nNegocie com Cersei antes de enfrentar o Rei da Noite\nAperte "
               "Enter para continuar");
        getchar();
      }
    }
    system("clear");
  } while (Continue);
  system("clear");

  // finalizações
  if (Progresso == 1) {
    printf("Você Morreu");
  } else if (Progresso == 2) {
    printf("Você venceu o Rei da Noite");
  }

  return 0;
}