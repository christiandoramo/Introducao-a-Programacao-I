#include <stdio.h>
#include <stdlib.h>
// 1) Crie uma estrutura de dados para armazenar os dados de um ingresso na
// qual devem constar campos para:
// - O preço
// - O local
// - A atração
typedef struct {
  float preco;
  char local[30], atracao[30];
} Ingresso;

// 2) Crie uma função chamada preenche que recebe um parâmetro do tipo
// ingresso e preenche seus campos com valores lidos a partir do teclado
void preencheIngresso(Ingresso *ingresso) {
  system("clear");
  printf("Entre com a atracao: ");
  scanf("%[^\n]", ingresso->atracao);
  getchar();
  printf("Entre com o preco: ");
  scanf("%f", &ingresso->preco);
  getchar();
  printf("Entre com o local: ");
  scanf("%[^\n]", (*ingresso).local);
  getchar();
  system("clear");
}

// 3) Crie uma função chamada imprime que recebe um parâmetro do tipo ingresso e
// mostra na tela os valores de seus campos
void imprime(Ingresso *ingresso) {
  printf("\nAtracao: %s", ingresso->atracao);
  printf("\npreco: %.2f", &ingresso->preco);
  printf("\nlocal: %s", ingresso->local);
  getchar();
}

// 4) Crie uma função chamada alteraPreco que recebe um parâmetro do tipo
// ingresso e outro parâmetro contendo um novo_valor de preço que atualiza o
// preço do ingresso para o novo valor.
void alteraPreco(Ingresso *ingresso, float novo_preco) {
  (*ingresso).preco = novo_preco;
}

//   7) Escreva uma função que recebe um vetor de ingressos, o tamanho do
//   vetor, e imprima na tela os eventos
// de ingresso mais barato e mais caros
void ofertaIngressosPorPreco(int tam, Ingresso *ingressos) {
  ingressos = (Ingresso *)malloc(tam * sizeof(Ingresso));
  for (int i = 0; i < tam; i++) {
    preencheIngresso(&ingressos[i]);
  }
  system("clear");

  float menor = 0.0;
  for (int i = 0; i < tam && menor == 0.0; i++) {
    int existeMenor = 0;
    for (int j = 0; j < tam && !existeMenor; j++) {
      if (!existeMenor && ingressos[i].preco > ingressos[j].preco) {
        existeMenor = 1;
      }
    }
    if (!existeMenor) {
      menor = ingressos[i].preco;
    }
  }

  float maior = 0.0;
  for (int i = 0; i < tam && maior == 0.0; i++) {
    int existeMaior = 0;
    for (int j = 0; j < tam && !existeMaior; j++) {
      if (!existeMaior && ingressos[i].preco < ingressos[j].preco) {
        existeMaior = 1;
      }
    }
    if (!existeMaior) {
      maior = ingressos[i].preco;
    }
  }

  for (int i = 0; i < tam; i++) {
    if (ingressos[i].preco == menor) {
      printf("O Ingresso de menor valor é:\n");
      imprime(&ingressos[i]);
    }
    if (ingressos[i].preco == maior) {
      printf("\nO Ingresso de maior valor é:\n");
      imprime(&ingressos[i]);
    }
  }
}

int main(void) {
  Ingresso ingresso;
  preencheIngresso(&ingresso);
  alteraPreco(&ingresso, 10);
  imprime(&ingresso);
  //   5) Escreva uma função main para testar as criadas nas questões anteriores
  //   com elementos de um vetor de
  //tamanho 10.
  Ingresso ingressos[10];
  for (int i = 0; i < 10; i++) {
    preencheIngresso(&ingressos[i]);
  }

  for (int i = 0; i < 10; i++) {
    imprime(&ingressos[i]);
  }
  //   6) Escreva uma função main para testar as anteriores com elementos de um
  //   vetor de tamanho definido
  // dinamicamente (em tempo de execução).
  int tam = 2;
  Ingresso *ingressos2 = NULL;
  ingressos2 = (Ingresso *)malloc(tam * sizeof(Ingresso));

  for (int i = 0; i < tam; i++) {
    preencheIngresso(&ingressos2[i]);
  }
  for (int i = 0; i < tam; i++) {
    imprime(&ingressos2[i]);
  }

  tam = 3;
  ingressos2 = (Ingresso *)realloc(ingressos2, tam * sizeof(Ingresso));
  // struct = 34 bytes
  for (int i = 0; i < tam; i++) {
    preencheIngresso(&ingressos2[i]);
  }
  for (int i = 0; i < tam; i++) {
    imprime(&ingressos2[i]);
  }
  Ingresso *ingressos3; // UM VETOR QUALQUER??
  ofertaIngressosPorPreco(3, ingressos3);
  return 0;
}