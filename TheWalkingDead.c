#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Cadastro do jogo
  int Tamanho, Dificuldade, Balas = 0, Zumbi = 0;
  char Personagem;
  printf("\nOlá, Bem-Vindo ao The Walking Dead!\nDê as informações logo "
         "abaixo.\n\n");

  printf("Entre com o tamanho do Campo: ");
  scanf("%i", &Tamanho);
  getchar();
  printf("Nível da Dificuldade (max: %i): ", (Tamanho * Tamanho) / 2);
  scanf("%i", &Dificuldade);
  getchar();
  printf("Digite a primeira letra do seu nome: ");
  scanf("%c", &Personagem);
  getchar();
  Personagem = toupper(Personagem);

  // coordenadas do personagem inicio e ao longo do jogo
  int coluna = -1, linha = -1;
  do {
    printf("Escolha a sua coordenada de início (ex.1: 90 0 ex.2: 10 51): ");
    scanf("%i %i", &coluna, &linha);
    getchar();
    system("clear");
    if ((linha >= 0 && linha < Tamanho) && (coluna >= 0 && coluna < Tamanho))
      break;
  } while (1); // true sempre retorna true ou seja loop "infinito"

  printf("Inicio de Jogo! Aperte Enter tecla para Começar");
  getchar();
  system("clear");
  // inicio do jogo
  srand(time(NULL)); // seeding(semente/fonte) para a f. time em srand
  // abastece a matriz
  char campo[Tamanho][Tamanho];
  for (int i = 0; i < Tamanho; i++) {
    for (int j = 0; j < Tamanho; j++) {
      campo[i][j] = '-';
    }
  }

  // cria obstaculos e titans
  for (int Obstaculos = 0; (Obstaculos + Zumbi) < Dificuldade;) {
    int pObstaculoX = rand() % Tamanho;
    int pObstaculoY = rand() % Tamanho;
    int pTitanX = rand() % Tamanho;
    int pTitanY = rand() % Tamanho;
    int pBalaX = rand() % Tamanho;
    int pBalaY = rand() % Tamanho;
    if (campo[pObstaculoX][pObstaculoY] == '-') {
      campo[pObstaculoX][pObstaculoY] = 'O';
      Obstaculos++;
    }
    if (campo[pTitanX][pTitanY] == '-') {
      campo[pTitanX][pTitanY] = 'Z';
      Zumbi++;
    }
    if (Zumbi < Dificuldade / 2 && campo[pBalaX][pBalaY] == '-') {
      campo[pBalaX][pBalaY] = 'B';
    }
    // balas
  }

  // spawna Rick na coordenada escolhida e ciclo do jogo
  int GameContinue = 1;
  campo[linha][coluna] = Personagem;
  do {
    // imprimi o campo atual
    for (int i = 0; i < Tamanho; i++) {
      for (int j = 0; j < Tamanho; j++) {
        printf("%c ", campo[i][j]);
      }
      printf("\n");
    }
    printf("\n\nBalas: %i", Balas);

    // movimento do personagem
    printf("\nPara ir para Cima, Esquerda, Baixo ou Direita pressione - "
           "w/a/s/d)\n");

    char Direcao;
    scanf("%c", &Direcao);
    getchar();
    system("clear");
    Direcao = tolower(Direcao);
    switch (Direcao) {
    case 'w':
      if (linha > 0) {
        // pega posicao anterior e posterior, atualiza
        char espacoAcima = campo[linha - 1][coluna];
        if (espacoAcima == '-') {
          campo[linha - 1][coluna] = Personagem;
          campo[linha][coluna] = '-';
          linha--;
        } else if (espacoAcima == 'Z') {
          if (Balas > 0) {
            campo[linha][coluna] = '-';
            campo[linha - 1][coluna] = Personagem;
            Zumbi--;
            Balas--;
            linha--;
          } else {
            GameContinue = 0;
          }
        } else if (espacoAcima == 'B') {
          campo[linha][coluna] = '-';
          campo[linha - 1][coluna] = Personagem;
          Balas++;
          linha--;
        }
      }
      break;
    case 's':
      if (linha + 1 < Tamanho) {
        // pega posicao anterior e posterior, atualiza
        char espacoAbaixo = campo[linha + 1][coluna];
        if (espacoAbaixo == '-') {
          campo[linha + 1][coluna] = Personagem;
          campo[linha][coluna] = '-';
          linha++;
        } else if (espacoAbaixo == 'Z') {
          if (Balas > 0) {
            campo[linha][coluna] = '-';
            campo[linha + 1][coluna] = Personagem;
            Zumbi--;
            Balas--;
            linha++;
          } else {
            GameContinue = 0;
          }
        } else if (espacoAbaixo == 'B') {
          campo[linha][coluna] = '-';
          campo[linha + 1][coluna] = Personagem;
          Balas++;
          linha++;
        }
      }
      break;
    case 'a':
      if (coluna > 0) {
        // pega posicao anterior e posterior, atualiza
        char espacoAesquerda = campo[linha][coluna - 1];
        if (espacoAesquerda == '-') {
          campo[linha][coluna - 1] = Personagem;
          campo[linha][coluna] = '-';
          coluna--;
        } else if (espacoAesquerda == 'Z') {
          if (Balas > 0) {
            campo[linha][coluna - 1] = Personagem;
            campo[linha][coluna] = '-';
            Zumbi--;
            Balas--;
            coluna--;
          } else {
            GameContinue = 0;
          }
        } else if (espacoAesquerda == 'B') {
          campo[linha][coluna] = '-';
          campo[linha][coluna - 1] = Personagem;
          Balas++;
          coluna--;
        }
      }
      break;
    case 'd':
      if (coluna + 1 < Tamanho) {
        // pega posicao anterior e posterior, atualiza
        char espacoAdireita = campo[linha][coluna + 1];
        if (espacoAdireita == '-') {
          campo[linha][coluna + 1] = Personagem;
          campo[linha][coluna] = '-';
          coluna++;
        } else if (espacoAdireita == 'Z') {
          if (Balas > 0) {
            campo[linha][coluna] = '-';
            campo[linha][coluna + 1] = Personagem;
            Zumbi--;
            Balas--;
            coluna++;
          } else {

            GameContinue = 0;
          }
        } else if (espacoAdireita == 'B') {
          campo[linha][coluna] = '-';
          campo[linha][coluna + 1] = Personagem;
          Balas++;
          coluna++;
        }
      }
      break;
    }
    if (Zumbi <= 0)
      GameContinue = 0;
  } while (GameContinue);
  system("clear");
  printf("Fim de Jogo");
  getchar();
  return 0;
}