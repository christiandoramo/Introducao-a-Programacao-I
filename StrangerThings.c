#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
  srand(time(NULL));
  int tam = 3, vida = 100, taxa_raiva = 0;
  char escola[tam][tam];
  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++) {
      escola[i][j] = '.';
    }
  }

  int Ex = 0, Ey = 0;
  int TentaAbrirPortal = 0, EntraPortal = 0;
  int portal = 0;
  escola[Ex][Ey] = 'E';

  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++) {
      printf("%c ", escola[i][j]);
    }
    printf("\n");
  }
  printf("\nVida: { %i }", vida);
  printf("\nTaxa de raiva: { %i }", taxa_raiva);

  do {

    char entrada;
    scanf(" %c", &entrada);

    if (entrada == 'w' && Ey > 0) {
      if (escola[Ey - 1][Ex] == 'P') {
        EntraPortal = 1;
      }
      TentaAbrirPortal++;
      escola[Ey][Ex] = '.';
      Ey--;
      escola[Ey][Ex] = 'E';
    } else if (entrada == 's' && Ey < 2) {
      if (escola[Ey + 1][Ex] == 'P') {
        EntraPortal = 1;
      }
      TentaAbrirPortal++;
      escola[Ey][Ex] = '.';
      Ey++;
      escola[Ey][Ex] = 'E';
    } else if (entrada == 'a' && Ex > 0) {
      if (escola[Ey][Ex - 1] == 'P') {
        EntraPortal = 1;
      }
      TentaAbrirPortal++;
      escola[Ey][Ex] = '.';
      Ex--;
      escola[Ey][Ex] = 'E';
    } else if (entrada == 'd' && Ex < 2) {
      if (escola[Ey][Ex + 1] == 'P') {
        EntraPortal = 1;
      }
      TentaAbrirPortal++;
      escola[Ey][Ex] = '.';
      Ex++;
      escola[Ey][Ex] = 'E';
    }

    if (!portal) {
      if (TentaAbrirPortal) {
        taxa_raiva = rand() % 101;
        if (taxa_raiva >= 60) {
          while (!portal) {
            int px = rand() % 3;
            int py = rand() % 3;
            if (escola[py][px] == '.') {
              escola[py][px] = 'P';
              portal++;
            }
          }
        } else {
          vida -= 20;
        }
        TentaAbrirPortal = 0;
      }
    }

    if (vida <= 0) {
      break;
    }

    system("clear");
    for (int i = 0; i < tam; i++) {
      for (int j = 0; j < tam; j++) {
        printf("%c ", escola[i][j]);
      }
      printf("\n");
    }
    printf("\nVida: { %i }", vida);
    printf("\nTaxa de raiva: { %i }\n", taxa_raiva);
  } while (!EntraPortal);

  system("clear");

  if (EntraPortal) {

    // No mundo invertido
    tam = 10;
    char mundoInvertido[tam][tam];
    char planoDemodogs[tam][tam];

    for (int i = 0; i < tam; i++) {
      for (int j = 0; j < tam; j++) {
        mundoInvertido[i][j] = '.';
      }
    }

    for (int arvores = 0; arvores < 10;) {
      int px = rand() % tam;
      int py = rand() % tam;
      if (mundoInvertido[py][px] == '.') {
        mundoInvertido[py][px] = 'A';
        arvores++;
      }
    }
    for (int carros = 0; carros < 5;) {
      int px = rand() % tam;
      int py = rand() % tam;
      if (mundoInvertido[py][px] == '.') {
        mundoInvertido[py][px] = 'C';
        carros++;
      }
    }
    for (int abandonadas = 0; abandonadas < 5;) {
      int px = rand() % tam;
      int py = rand() % tam;
      if (mundoInvertido[py][px] == '.') {
        mundoInvertido[py][px] = 'H';
        abandonadas++;
      }
    }
    for (int panquecas = 0; panquecas < 10;) {
      int px = rand() % tam;
      int py = rand() % tam;
      if (mundoInvertido[py][px] == '.') {
        mundoInvertido[py][px] = 'p';
        panquecas++;
      }
    }

    for (int demodogs = 0; demodogs < 4;) {
      int px = rand() % tam;
      int py = rand() % tam;
      if (mundoInvertido[py][px] == '.') {
        planoDemodogs[py][px] = 'D';
        demodogs++;
      }
    }

    for (int eleven = 0; eleven < 1;) {
      int px = rand() % tam;
      int py = rand() % tam;
      if (mundoInvertido[py][px] == '.') {
        mundoInvertido[py][px] = 'E';
        Ex = px;
        Ey = py;
        eleven++;
      }
    }

    int Wx, Wy;
    for (int will = 0; will < 1;) {
      int px = rand() % tam;
      int py = rand() % tam;
      if (mundoInvertido[py][px] == '.') {
        mundoInvertido[py][px] = 'W';
        Wx = px;
        Wy = py;
        will++;
      }
    }

    system("clear");
    for (int i = 0; i < tam; i++) {
      for (int j = 0; j < tam; j++) {
        printf("%c ", mundoInvertido[i][j]);
      }
      printf("\n");
    }
    printf("\nVida: { %i }", vida);
    printf("\nTaxa de raiva: { %i }", taxa_raiva);

    int will = 0, Combate = 0, SpawnD = 0, Estado = 0, portal = 0, PortalY = -1,
        PortalX = -1;
    do {
      char entrada;
      scanf(" %c", &entrada);

      if (entrada == 'w' && Ey > 0 &&
          (mundoInvertido[Ey - 1][Ex] != 'C' &&
           mundoInvertido[Ey - 1][Ex] != 'A' &&
           mundoInvertido[Ey - 1][Ex] != 'H')) {
        if (mundoInvertido[Ey - 1][Ex] == 'p') {
          if (vida <= 95) {
            vida += 5;
          } else {
            vida = 100;
          }
        }
        if (will) {
          TentaAbrirPortal++;
        }
        if (mundoInvertido[Ey - 1][Ex] == 'W') {
          will++;
        }
        if (planoDemodogs[Ey - 1][Ex] == 'D') {
          Combate = 1;
          will = 0;
        }
        mundoInvertido[Ey][Ex] = '.';
        Ey--;
        mundoInvertido[Ey][Ex] = 'E';
      } else if (entrada == 's' && Ey < 9 &&
                 (mundoInvertido[Ey + 1][Ex] != 'C' &&
                  mundoInvertido[Ey + 1][Ex] != 'H' &&
                  mundoInvertido[Ey + 1][Ex] != 'A')) {
        if (mundoInvertido[Ey + 1][Ex] == 'p') {
          if (vida <= 95) {
            vida += 5;
          } else {
            vida = 100;
          }
        }
        if (will) {
          TentaAbrirPortal++;
        }
        if (mundoInvertido[Ey + 1][Ex] == 'W') {
          will++;
        }
        if (planoDemodogs[Ey + 1][Ex] == 'D') {
          Combate = 1;
          will = 0;
        }
        mundoInvertido[Ey][Ex] = '.';
        Ey++;
        mundoInvertido[Ey][Ex] = 'E';
      } else if (entrada == 'a' && Ex > 0 &&
                 (mundoInvertido[Ey][Ex - 1] != 'C' &&
                  mundoInvertido[Ey][Ex - 1] != 'H' &&
                  mundoInvertido[Ey][Ex - 1] != 'A')) {
        if (mundoInvertido[Ey][Ex - 1] == 'p') {
          if (vida <= 95) {
            vida += 5;
          } else {
            vida = 100;
          }
        }
        if (will) {
          TentaAbrirPortal++;
        }
        if (mundoInvertido[Ey][Ex - 1] == 'W') {
          will++;
        }
        if (planoDemodogs[Ey][Ex - 1] == 'D') {
          Combate = 1;
          will = 0;
        }
        mundoInvertido[Ey][Ex] = '.';
        Ex--;
        mundoInvertido[Ey][Ex] = 'E';
      } else if (entrada == 'd' && Ex < 9 &&
                 (mundoInvertido[Ey][Ex + 1] != 'C' ||
                  mundoInvertido[Ey][Ex + 1] != 'H' &&
                      mundoInvertido[Ey][Ex + 1] != 'A')) {
        if (mundoInvertido[Ey][Ex + 1] == 'p') {
          if (vida <= 95) {
            vida += 5;
          } else {
            vida = 100;
          }
        }
        if (will) {
          TentaAbrirPortal++;
        }
        if (mundoInvertido[Ey][Ex + 1] == 'W') {
          will++;
        }
        if (planoDemodogs[Ey][Ex + 1] == 'D') {
          Combate = 1;
          will = 0;
        }
        mundoInvertido[Ey][Ex] = '.';
        Ex++;
        mundoInvertido[Ey][Ex] = 'E';
      }

      if ((Wx - Ex <= 2 || Wy - Ey <= 2 || Ex - Wx <= 2 || Ey - Wy <= 2) &&
          !SpawnD) {
        for (int demodogs = 0; demodogs < 2;) {
          int px = Ex - 1 + rand() % 3; // 9 m² em volta de Eleven
          int py = Ey - 1 + rand() % 3;
          if (mundoInvertido[py][px] == '.') {
            planoDemodogs[py][px] = 'D';
            demodogs++;
          }
        }
        SpawnD = 1;
      }

      if (!portal) {
        if (TentaAbrirPortal) {
          if (will) {
            taxa_raiva = rand() % 101;
            if (taxa_raiva >= 60) {
              while (!portal) {
                int px = rand() % 10;
                int py = rand() % 10;
                if (mundoInvertido[py][px] == '.') {
                  mundoInvertido[py][px] = 'P';
                  PortalX = px;
                  PortalY = py;
                  portal++;
                }
              }
            } else {
              vida -= 20;
            }
          }
          TentaAbrirPortal = 0;
        }
      }

      // MOVIMENTO WILL
      if (!will) {
        int wMoviment = rand() % 4;
        if (wMoviment == 0 && Wy > 0 && mundoInvertido[Wy - 1][Wx] == '.') {
          if (mundoInvertido[Wy][Wx] != 'E' && mundoInvertido[Wy][Wx] != 'P') {
            mundoInvertido[Wy][Wx] = '.';
          }
          Wy--;
          mundoInvertido[Wy][Wx] = 'W';
        }
        if (wMoviment == 1 && Wy < 9 && mundoInvertido[Wy + 1][Wx] == '.') {
          if (mundoInvertido[Wy][Wx] != 'E' && mundoInvertido[Wy][Wx] != 'P') {
            mundoInvertido[Wy][Wx] = '.';
          }
          Wy++;
          mundoInvertido[Wy][Wx] = 'W';
        }
        if (wMoviment == 2 && Wx > 0 && mundoInvertido[Wy][Wx - 1] == '.') {
          if (mundoInvertido[Wy][Wx] != 'E' && mundoInvertido[Wy][Wx] != 'P') {
            mundoInvertido[Wy][Wx] = '.';
          }
          Wx--;
          mundoInvertido[Wy][Wx] = 'W';
        }
        if (wMoviment == 3 && Wx < 9 && mundoInvertido[Wy][Wx + 1] == '.') {
          if (mundoInvertido[Wy][Wx] != 'E' && mundoInvertido[Wy][Wx] != 'P') {
            mundoInvertido[Wy][Wx] = '.';
          }
          Wx++;
          mundoInvertido[Wy][Wx] = 'W';
        }
      } else {
        Wy = Ey;
        Wx = Ex;
      }

      // Combate com o Demodog
      if (Combate) {
        if (vida > 10) {
          vida -= 10;
          planoDemodogs[Ey][Ex] = ' ';
        } else {
          break;
        }
        Combate = 0;
      }
      if (vida <= 0) {
        break;
      }

      if (portal) {
        mundoInvertido[PortalY][PortalX] = 'P';
      }
      system("clear");
      for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
          printf("%c ", mundoInvertido[i][j]);
        }
        printf("\n");
      }
      printf("\nVida: { %i }", vida);
      printf("\nTaxa de raiva: { %i }", taxa_raiva);
      if (portal) {
        printf("\nAgora Vá até o portal 'P' com Will\n");
      } else if (will) {
        printf("\nAche um portal 'P' para sair com Will\n");
      } else {
        printf("\nAche Will\n");
      }

      if (will && PortalX == Ex && PortalY == Ey) {
        Estado = 1;
      }
    } while (!Estado);

    system("clear");
    if (Estado) {
      printf("Eleven Viva com Will.\nVida { %i }", vida);
    } else {
      printf("Eleven Morreu");
    }

  } else {
    // Morreu
    printf("Eleven Morreu");
  }

  return 0;
}