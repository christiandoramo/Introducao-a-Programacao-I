#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // JOGO POKÉMON
  srand(time(NULL));
  char campo[12][10];
  int Ax = 0, Ay = 0;
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 10; j++) {
      campo[i][j] = 'x';
    }
  }
  campo[0][1] = 'M';
  campo[0][6] = 'M';
  campo[0][5] = 'M';
  campo[0][4] = 'M';
  campo[0][3] = 'M';
  campo[0][2] = 'M';
  campo[0][8] = 'M';
  campo[0][9] = 'M';

  campo[1][0] = 'M';
  campo[1][6] = 'M';
  campo[1][8] = 'M';

  campo[2][0] = 'M';
  campo[2][6] = 'M';
  campo[2][8] = 'M';

  campo[3][0] = 'M';
  campo[3][6] = 'M';
  campo[3][7] = 'M';
  campo[3][8] = 'M';

  campo[4][0] = 'M';
  campo[4][1] = 'M';
  campo[4][2] = 'M';
  campo[4][4] = 'M';
  campo[4][8] = 'M';

  campo[5][8] = 'M';
  campo[5][2] = 'M';
  campo[5][4] = 'M';
  campo[5][5] = 'M';

  campo[6][2] = 'M';
  campo[6][4] = 'M';
  campo[6][8] = 'M';

  campo[7][0] = 'M';
  campo[7][1] = 'M';
  campo[7][2] = 'M';
  campo[7][3] = 'M';
  campo[7][4] = 'M';
  campo[7][5] = 'M';
  campo[7][7] = 'M';
  campo[7][8] = 'M';

  campo[8][3] = 'M';
  campo[8][7] = 'M';

  campo[9][1] = 'M';
  campo[9][2] = 'M';
  campo[9][3] = 'M';
  campo[9][4] = 'M';
  campo[9][5] = 'M';
  campo[9][7] = 'M';

  campo[10][3] = 'M';
  campo[10][5] = 'M';
  campo[10][7] = 'M';

  campo[11][0] = 'M';
  campo[11][1] = 'M';
  campo[11][2] = 'M';
  campo[11][3] = 'M';
  campo[11][5] = 'M';
  campo[11][7] = 'M';
  campo[0][0] = 'a';

  int pokebolas = 10;
  while (pokebolas > 0) {
    int px = rand() % 10;
    int py = rand() % 12;
    if (campo[py][px] == 'M') {
      campo[py][px] = 'b';
      pokebolas--;
    }
  }
  int pokemons = 10;
  while (pokemons > 0) {
    int px = rand() % 10;
    int py = rand() % 12;
    if (campo[py][px] == 'M') {
      campo[py][px] = 'p';
      pokemons--;
    }
  }
  // LOOP DO MAPA
  int InterageBrock = 0, InteragePokemon = 0;
  int Vencedor = 0;
  do {

    if (Ax != 0 || Ay != 0) {
      campo[0][0] = 'x';
    }
    if (Ax != 0 || Ay != 11) {
      campo[11][0] = 'E';
    }
    system("clear");
    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 10; j++) {
        printf(" %c ", campo[i][j]);
      }
      printf("\n");
    }
    printf("\nPokebolas {%i}\n", pokebolas);
    printf("\nPokemons {%i}\n", pokemons);
    printf("\nw a s d - cima esquerda baixo direita\n");
    char entrada;
    scanf(" %c", &entrada);
    getchar();
    if (entrada == 'w' && Ay > 0 && campo[Ay - 1][Ax] != 'x') {
      if (campo[Ay - 1][Ax] == 'b') {
        pokebolas++;
      } else if (campo[Ay - 1][Ax] == 'E') {
        InterageBrock = 1;
      } else if (campo[Ay - 1][Ax] == 'p') {
        InteragePokemon = 1;
      }
      campo[Ay][Ax] = 'M';
      Ay--;
      campo[Ay][Ax] = 'a';
    } else if (entrada == 's' && Ay < 11 && campo[Ay + 1][Ax] != 'x') {
      if (campo[Ay + 1][Ax] == 'b') {
        pokebolas++;
      } else if (campo[Ay + 1][Ax] == 'E') {
        InterageBrock = 1;
      } else if (campo[Ay + 1][Ax] == 'p') {
        InteragePokemon = 1;
      }
      campo[Ay][Ax] = 'M';
      Ay++;
      campo[Ay][Ax] = 'a';
    } else if (entrada == 'a' && Ax > 0 && campo[Ay][Ax - 1] != 'x') {
      if (campo[Ay][Ax - 1] == 'b') {
        pokebolas++;
      } else if (campo[Ay][Ax - 1] == 'E') {
        InterageBrock = 1;
      } else if (campo[Ay][Ax - 1] == 'p') {
        InteragePokemon = 1;
      }
      campo[Ay][Ax] = 'M';
      Ax--;
      campo[Ay][Ax] = 'a';
    } else if (entrada == 'd' && Ax < 9 && campo[Ay][Ax + 1] != 'x') {
      if (campo[Ay][Ax + 1] == 'b') {
        pokebolas++;
      } else if (campo[Ay][Ax + 1] == 'E') {
        InterageBrock = 1;
      } else if (campo[Ay][Ax + 1] == 'p') {
        InteragePokemon = 1;
      }
      campo[Ay][Ax] = 'M';
      Ax++;
      campo[Ay][Ax] = 'a';
    }

    if (InteragePokemon && pokebolas > 0) {
      // inico DA CAPTURA
      int chance = 1 + rand() % 99;
      if (chance <= 80) {
        pokemons++;
        pokebolas--;
      }
      InteragePokemon = 0;
    }

    if (InterageBrock) {
      if (pokemons > 2) {
        // INICIO DA LUTA
        printf("Inicio do Combate");
        getchar();
        for (int PokemonsMortosAsh = 0, PokemonsMortosBrock = 0;
             PokemonsMortosAsh < 3 && PokemonsMortosBrock < 3;) {
          int diceAsh = 1 + rand() % 10;
          int diceBrock = 1 + rand() % 10;
          system("clear");
          printf("\nPokemon do Ash: %i de 3\nPokemon do Brock: %i de 3\n",
                 PokemonsMortosAsh + 1, PokemonsMortosBrock + 1);
          getchar();
          if (diceAsh > diceBrock) {
            printf("Pokemon de Ash Venceu");
            PokemonsMortosBrock++;

          } else if (diceAsh == diceBrock) {
            printf("Empate");

          } else {
            printf("Pokemon de Brock Venceu");
            PokemonsMortosAsh++;
          }
          getchar();
          if (PokemonsMortosAsh < PokemonsMortosBrock) {
            Vencedor = 1;
          } else {
            Vencedor = 2;
          }
        }

      } else {
        printf("\nPegue 3 pokemons para combater com o lider de ginasio\n");
        getchar();
      }
      InterageBrock = 0;
    }
  } while (!Vencedor);

  system("clear");
  if (Vencedor == 1) {
    printf("ASH VENCEU E RECEBEU SUA INSÍGNIA DA PEDRA");
  } else {
    printf("BROCK VENCEU");
  }
  return 0;
}