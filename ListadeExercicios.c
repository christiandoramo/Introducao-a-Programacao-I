#include <stdio.h>
#include <string.h>

void questao1() {
  // 1) Faça um Programa que peça dois números ao usuário e imprima o maior
  // deles.
  int a, b;
  printf("Digite o Primeiro numero: ");
  scanf("%i", &a);
  getchar();
  printf("\nDigite o Segundo numero: ");
  scanf("%i", &b);
  getchar();
  if (a > b) {
    printf("\n O Maior número é: %i", a);
  } else if (a < b) {
    printf("\n O Maior número é: %i", b);
  } else {
    printf("\n %i = %i ", a, b);
  }
}
void questao2() {
  // 2) Faça um Programa que peça um valor e mostre na tela se o valor é
  // positivo ou negativo.
  int a;
  printf("Digite um numero: ");
  scanf("%i", &a);
  getchar();
  if (a > 0) {
    printf("\n %i é positivo", a);
  } else if (a < 0) {
    printf("\n %i é negativo", a);
  } else {
    printf("\n O número é nulo (0) ");
  }
}
void questao3() {
  //   3) Faça um Programa que verifique se uma letra digitada é "F" ou "M".
  //   Conforme a letra, escrever na
  // tela: F - Feminino, M - Masculino, Sexo Inválido.
  char a;
  printf("Digite uma letra: ");
  scanf("%c", &a);
  a = toupper(a);
  getchar();
  if (a == 'F') {
    printf("%c - Feminino", a);
  } else if (a == 'M') {
    printf("%c - Masculino", a);
  } else {
    printf("Sexo Inválido.");
  }
}
void questao4() {
  // 4) Faça um Programa que peça ao usuário um número inteiro e determine se
  // ele é par ou impar. Dica: utilize o operador módulo (resto da divisão).
  int a;
  printf("Digite um numero: ");
  scanf("%i", &a);
  getchar();
  if (a % 2 == 0) {
    printf("%i é par", a);
  } else {
    printf("%i é ímpar", a);
  }
}
void questao5() {
  // 5) Escreva um programa que receba como entrada o valor (inteiro) do saque
  // realizado pelo cliente de um banco e retorne quantas notas de cada valor
  // serão necessárias para atender ao saque com a menor quantidade de notas
  // possível. Serão utilizadas notas de 100, 50, 20, 10, 5, 2 e 1 reais.
  int a, b;
  printf("Digite o valor do saque inteiro: ");
  scanf("%i", &a);
  b = a;
  getchar();
  int d100 = 0, d50 = 0, d20 = 0, d10 = 0, d5 = 0, d2 = 0, d1 = 0;
  while (a >= 100) {
    a -= 100;
    d100++;
  }
  while (a >= 50) {
    a -= 50;
    d50++;
  }
  while (a >= 20) {
    a -= 20;
    d20++;
  }
  while (a >= 10) {
    a -= 10;
    d10++;
  }
  while (a >= 5) {
    a -= 5;
    d5++;
  }
  while (a >= 2) {
    a -= 2;
    d2++;
  }
  while (a >= 1) {
    a--;
    d1++;
  }
  int notas = d100 + d50 + d20 + d10 + d5 + d2 + d1;
  printf("Quantidade de notas para o troco do saque de R$ %i,00: %i "
         "notas\nNotas de 100 "
         "- %i\nNotas de 50 - %i,\nNotas de 20 - %i,\nNotas de 10 - %i,\nNotas "
         "de 5 - %i,\nNotas de 2 - %i,\nNotas de 1 - %i,",
         b, notas, d100, d50, d20, d10, d5, d2, d1);
}
void questao6() {
  // 6) Crie um programa que receba como entrada a hora e os minutos do dia, o
  // nome do cliente e seu sexo. A partir desses dados, gere na saída do
  // programa (tela) uma saudação que diga:  "Bom dia", "Boa tarde" ou "Boa
  // noite", dependendo da hora do dia, seguido de vírgula.  "senhor" ou
  // "senhora", dependendo do sexo do(a) cliente.  O nome do(a) cliente,
  // seguido de exclamação.  A frase "Em que posso ajudar?" Obs: A manhã se
  // inicia as 00:00 e vai até 11:59. A tarde se inicia às 12:00 e vai até 17:59
  // A noite se inicia às 18:00 e vai até 23:59
  int s, m, h;
  char g, n[30];

  printf("Digite a hora: ");
  scanf("%i", &h);
  getchar();
  printf("Digite a minutos: ");
  scanf("%i", &m);
  getchar();
  printf("Digite a segundos: ");
  scanf("%i", &s);
  getchar();
  printf("Digite o seu nome: ");
  scanf("%s", n);
  getchar();
  printf("Digite o seu gênero (f - feminino ou m - masculino): ");
  scanf("%c", &g);
  getchar();
  system("clear");
  printf("%i:%i:%i\n", h, m, s);
  if (h >= 18) {
    printf("Bom Noite, ");
  } else if (h >= 12) {
    printf("Bom Tarde, ");
  } else {
    printf("Bom Dia, ");
  }
  if (g == 'f') {
    printf("senhora ");
  } else if (g == 'm') {
    printf("senhor ");
  }
  printf("%s! Em que posso ajudar?\n", n);
}
void questao8() {
  //   8) Calcular as áreas das seguintes figuras geométricas: quadrado,
  //   retângulo, triângulo, trapézio e
  // círculo. Deverá ser exibido um menu para que o usuário escolha qual figura
  // quer calcular a área. Após escolhida a figura deverão ser pedidas as
  // entradas necessárias para o cálculo. 1 - Círculo Entrada: Raio 2 -
  // Retângulo Entrada: Lados 3 - Quadrado Entrada: Lado 4 - Trapézio Entrada:
  // Bases e Altura 5 - Triângulo Entrada: Base e Altura

  int figura;
  float area;
  char nome[10];

  do {
    printf("Entre com o numero correspondente a figura que deseja calcular a "
           "area\n1 - Circulo\n2 - Retangulo\n3 - Quadrado\n4 - Trapezio\n5 - "
           "Triangulo\n");
    scanf("%i", &figura);
    getchar();
    system("clear");
  } while (figura > 5 || figura < 1);

  if (figura == 5) {
    float altura, base;
    strcpy(nome, "Triangulo");
    printf("Entre com a Altura: ");
    scanf("%f", &altura);
    getchar();
    printf("Entre com a Base: ");
    scanf("%f", &base);
    getchar();
    area = altura * base / 2.0;
  } else if (figura == 4) {
    float altura, basem, baseM;
    strcpy(nome, "Trapezio");
    printf("Entre com a Altura: ");
    scanf("%f", &altura);
    getchar();
    printf("Entre com a Base maior: ");
    scanf("%f", &baseM);
    getchar();
    printf("Entre com a Base menor: ");
    scanf("%f", &basem);
    getchar();
    area = altura * (baseM + basem) / 2.0;

  } else if (figura == 3) {
    float lado;
    strcpy(nome, "Quadrado");
    printf("Entre com o Lado: ");
    scanf("%f", &lado);
    getchar();
    area = lado * lado;

  } else if (figura == 2) {
    float altura, largura;
    strcpy(nome, "Retangulo");
    printf("Entre com a Altura: ");
    scanf("%f", &altura);
    getchar();
    printf("Entre com a Largura: ");
    scanf("%f", &largura);
    getchar();
    area = altura * largura;
  } else {
    float raio;
    strcpy(nome, "Circulo");
    printf("Entre com o Raio: ");
    scanf("%f", &raio);
    getchar();
    area = raio * raio * 3.1416;
  }

  printf("A area do %s vale: %.2fm²", nome, area);
}
void questao9() {
  //   9) Em certa escola, para ser aprovado por média o aluno precisa ter média
  //   maior ou igual a cinco caso
  // contrário será reprovado por média. Caso o aluno seja aprovado por média
  // ainda é necessário que ele não ultrapasse o limite máximo de 7 faltas, ou
  // seja, caso tenha mais de 7 faltas o aluno será reprovado por falta.
  // Construa um programa que leia e armazene o nome, as três notas e a
  // quantidade de faltas do aluno. Depois calcule a média aritmética e diga se
  // o aluno (nome) está aprovado ou reprovado (caso esteja reprovado imprima o
  // motivo da reprovação) e a média do aluno. Não se esqueça de validar os
  // valores de notas e faltas.
  int faltas;
  float nota1, nota2, nota3, media;
  char nome[30];

  printf("Entre com o nome do aluno: ");
  scanf("%[^\n]", nome);
  getchar();
  printf("Entre com as faltas: ");
  scanf("%i", &faltas);
  getchar();
  printf("Entre com o nota 1: ");
  scanf("%f", &nota1);
  getchar();
  printf("Entre com o nota 2: ");
  scanf("%f", &nota2);
  getchar();
  printf("Entre com o nota 3: ");
  scanf("%f", &nota3);
  getchar();
  system("clear");
  media = (nota1 + nota2 + nota3) / 3;
  if (media < 5 || faltas > 7) {
    printf("%s Reprovado\nMotivo da Reprovação:\n", nome);
    if (media < 5) {
      printf("Media menor do que 5.\nMedia: %f", media);
    }
    if (faltas > 7) {
      printf("Mais de 7 faltas\nFaltas: %i", faltas);
    }
  } else {
    printf("%s Aprovado\nMedia: %f\nFaltas: %i", nome, media, faltas);
  }
}
void questao10() {
  //   10) Em uma competição de ginástica olímpica a nota é determinada por um
  //   painel de seis juízes. Cada
  // um dos juízes atribui uma nota entre zero e dez para o desempenho do
  // atleta. Para calcular a nota final, a nota mais alta e a nota mais baixa
  // são descartadas e é calculada a média das quatro restantes. Escreva um que
  // leia 6 notas entre zero e dez e calcule a média após o descarte da maior e
  // da menor
  // nota.
  float nota[6], media;
  for (int i = 0; i <= 5;) {
    printf("\n\nEntre com a nota do juiz %i: ", i + 1);
    scanf("%f", &nota[i]);
    getchar();
    if (nota[i] >= 0.0 && nota[i] <= 10.0) {
      ++i;
    }
  }

  // se não existe maior então nota[i] é o maior
  int maior;
  for (int i = 0, ExisteMaior = 0, ChecouMaior = 0; !ChecouMaior && i < 6;
       i++) {
    ExisteMaior = 0;
    for (int j = 0; !ExisteMaior && j < 6; j++) {
      if (nota[i] < nota[j]) {
        ExisteMaior = 1;
      }
    }
    if (!ExisteMaior) {
      maior = i;
      ChecouMaior = 1;
    }
  }
  // se não existe menor então nota[i] é o menor
  int menor;
  for (int i = 0, ExisteMenor = 0, ChecouMenor = 0; !ChecouMenor && i < 6;
       i++) {
    ExisteMenor = 0;
    for (int j = 0; !ExisteMenor && j < 6; j++) {
      if (nota[i] > nota[j]) {
        ExisteMenor = 1;
      }
    }
    if (!ExisteMenor) {
      menor = i;
      ChecouMenor = 1;
    }
  }
  nota[menor] = 0;
  nota[maior] = 0;
  for (int i = 0; i < 6; i++) {
    media += nota[i] / 4;
  }
  printf("\n\nA media foi de %.2f pontos.\n", media);
  getchar();
}

int main() {
  // questao1();
  // questao2();
  // questao3();
  // questao4();
  // questao5();
  // questao6();
  // questao8();
  // questao9();
  questao10();
  // questao11();
  return 0;
}