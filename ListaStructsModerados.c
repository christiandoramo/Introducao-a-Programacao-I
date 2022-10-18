#include <stdio.h>
#include <stdlib.h>

// Exercícios Moderados.

// 1) Considerando a estrutura
// struct Ponto {
// int x;
// int y;
// };
// para representar um ponto em uma grade 2D, implemente uma função que indique
// se um ponto p está localizado dentro ou fora de um círculo. O círculo é
// definido por seu centro c e seu raio r. A função deve retornar 1 caso o ponto
// esteja localizado dentro do círculo e 0 caso contrário. Essa função deve
// obedecer o protótipo: int dentroCirculo (struct Ponto* c, int raio, struct
// Ponto* p);
typedef struct {
  int x;
  int y;
} Ponto;
int dentroCirculo(Ponto *circulo, Ponto *ponto, int raio) {
  printf("Entre com o ponto X do centro do circulo ");
  scanf("%i", &circulo->x);
  getchar();
  printf("Entre com o ponto Y do centro do circulo ");
  scanf("%i", &(*circulo).y);
  getchar();
  printf("Entre com o ponto X do Ponto ");
  scanf("%i", &ponto->x);
  getchar();
  printf("Entre com o ponto Y do Ponto ");
  scanf("%i", &ponto->y);
  getchar();
  int distanciaX = ponto->x >= circulo->x ? ponto->x - circulo->x
                                          : -1 * (ponto->x - circulo->x);
  int distanciaY =
      ponto->y >= circulo->y ? ponto->y - circulo->y : circulo->y - ponto->y;

  printf("DistanciaX = %i\nDistancaY = %i\nRaio = %i ", distanciaX, distanciaY,
         raio);
  if (distanciaX <= raio && distanciaY <= raio) {
    return 1;
  } else {
    return 0;
  }
}
// 2) Considerando a estrutura
// struct Vetor {
// float x;
// float y;
// float z;
// };
// para representar um vetor no R3, implemente uma função que calcule a soma de
// dois vetores. Essa função deve obedecer ao protótipo: void soma (struct
// Vetor* v1, struct Vetor* v2, struct Vetor* res); onde os parâmetros v1 e v2
// são ponteiros para os vetores a serem somados, e o parâmetro res é um
// ponteiro para uma estrutura vetor onde o resultado da operação deve ser
// armazenado.
typedef struct {
  float x;
  float y;
  float z;
} Vetor;
void preencheVetor(Vetor *v) {
  printf("Entre com o ponto X do Vetor: ");
  scanf("%f", &v->x);
  getchar();
  printf("Entre com o ponto Y do Vetor: ");
  scanf("%f", &v->y);
  getchar();
  printf("Entre com o ponto Z do Vetor: ");
  scanf("%f", &v->z);
  getchar();
};
void calculaSomade2VetoresR3(Vetor *v1, Vetor *v2, Vetor *vresultante) {
  preencheVetor(v1);
  preencheVetor(v2);
  vresultante->x = v1->x + v2->x;
  (*vresultante).y = (*v1).y + v2->y;
  (*vresultante).z = (*v1).z + (*v2).z; //  a setinha -> tanto quanto (*) estão
                                        //  trabalhando conteúdo e n endereço
}
// 3). Considerando a estrutura
// struct Vetor {
// float x;
// float y;
// float z;
// };
// para representar um vetor no R3, implemente uma função que calcule a
// subtração de dois vetores. Essa função deve obedecer o protótipo: void sub
// (struct Vetor* v1, struct Vetor* v2, struct Vetor* res); onde os parâmetros
// v1 e v2 são ponteiros para os vetores a serem subtraídos, e o parâmetro res é
// um ponteiro para uma estrutura vetor onde o resultado da operação v1 − v2
// deve ser armazenado.
void calculaSubtracaode2VetoresR3(Vetor *v1, Vetor *v2, Vetor *vresultante) {
  preencheVetor(v1);
  preencheVetor(v2);
  vresultante->x = v1->x - v2->x;
  (*vresultante).y = (*v1).y - v2->y;
  (*vresultante).z = (*v1).z - (*v2).z; //  a setinha -> tanto quanto (*) estão
                                        //  trabalhando conteúdo e n endereço
}
// 4) Considerando a estrutura
// struct Vetor {
// float x;
// float y;
// float z;
// };
// para representar um vetor no R3, implemente uma função que calcule o produto
// escalar de dois vetores. Essa função deve obedecer o protótipo: float dot
// (struct Vetor* v1, struct Vetor* v2); onde os parâmetros v1 e v2 são
// ponteiros para os vetores a serem multiplicados, e o resultado da operação v1
// · v2 deve ser retornado.
float calculaMultiplicacaode2VetoresR3(Vetor *v1, Vetor *v2) {
  preencheVetor(v1);
  preencheVetor(v2);
  float resultado = (v1->x * v2->x) + ((*v1).y * v2->y) + ((*v1).z * (*v2).z);
  return resultado;
}
// 5) Considerando a estrutura
// struct Vetor {
// float x;
// float y;
// float z;
// };
// para representar um vetor no R3, implemente uma função que multiplique os
// componentes de um vetor por um número escalar. Essa função deve obedecer ao
// protótipo: void mult (struct Vetor* v, float escalar); (continua...)
// onde o parâmetros v é um ponteiro para o vetor a ser multiplicado e escalar é
// o valor pelo qual os componentes do vetor devem ser multiplicados. Observe
// que o vetor apontado pelo ponteiro v tem seu conteúdo alterado por essa
// função.
void MultiplicacaoPorEscalar(Vetor *vetor, float alfa) {
  preencheVetor(vetor);
  vetor->x *= alfa;
  vetor->y *= alfa;
  (*vetor).z = alfa * vetor->z;
  printf("%f * vetor = (%f, %f, %f)", alfa, (*vetor).x, (*vetor).y, (*vetor).z);
}
//// 6) Considerando as declarações struct aluno { char nome[81]; char
// matricula[8]; char turma; float p1; float p2; float p3;
// };
// typedef struct aluno Aluno;
// para representar o cadastro de alunos de uma disciplina, implemente uma
// função imprime_reprovados que imprima o número de matrícula, o nome, a turma
// e a média de todos os alunos que não foram aprovados na disciplina. Inclua as
// definições de estrutura exatamente como acima no seu arquivo de resposta, mas
// não inclua a função main. Inclua também a referência a quaisquer arquivos de
// biblioteca que você use (e.g., stdio.h). Os dados de cada aluno reprovado na
// disciplina devem ser impressos em uma única linha, seguindo o formato
// numero_de_matricula nome_do_aluno turma media
// As linhas descritas acima devem ser a única coisa impressa pela sua função.
// Não imprima cabe ̧calhos, terminadores, separadores ou qualquer outro tipo de
// decoração que fuja ao padrão especificado. Caso nenhum aluno se encaixe na
// busca, não imprima nada. Assuma que o critério para aprovação é (p1 + p2 +
// p3) /3 >= 5.0 Essa função deve obedecer o protótipo
// void imprime_reprovados (Aluno** turmas, int n);
// onde o parâmetro turmas representa um vetor de ponteiros para estruturas do
// tipo Aluno e o parâmetro n é o comprimento do mesmo. Obs.: podem haver
// posições não utilizadas no vetor turmas, contendo o valor NULL.
typedef struct {
  char nome[81];
  char matricula[8];
  char turma;
  float p1;
  float p2;
  float p3;
} Aluno;

void imprime_reprovados(Aluno *aluno, int alunos) {
  float mediaTotalReprovados = 0, contador = 1;
  for (int i = 0; i < alunos; i++) {
    float media = (aluno[i].p1 + aluno[i].p2 + aluno[i].p3) / 3;
    if (media < 5) {
      printf("%s %s %c %f\n", aluno[i].matricula, aluno[i].nome, aluno[i].turma,
             media);
      mediaTotalReprovados = ((media + mediaTotalReprovados) / (contador++));
    }
  }
}
void cadastro_disciplina(Aluno *aluno, int alunos) {
  aluno = (Aluno *)malloc(alunos * sizeof(Aluno));
  for (int i = 0; i < alunos; i++) {
    printf("Numero da matricula do aluno %i: ", i + 1);
    scanf("%s", (aluno + i)->matricula);
    getchar();
    printf("Nome do aluno %i: ", i + 1);
    scanf("%[^\n]", (aluno + i)->nome);
    getchar();
    printf("Turma do aluno %i: ", i + 1);
    scanf("%c", &(aluno + i)->turma);
    getchar();
    printf("Nota 1 do aluno %i: ", i + 1);
    scanf("%f", &(aluno + i)->p1);
    getchar();
    printf("Nota 2 do aluno %i: ", i + 1);
    scanf("%f", &(aluno + i)->p2);
    getchar();
    printf("Nota 3 do aluno %i: ", i + 1);
    scanf("%f", &(aluno + i)->p3);
    getchar();
    imprime_reprovados(aluno, alunos);
  }
}

// 7) Considerando as declarações struct aluno { char nome[81]; char
// matricula[8]; char turma; float p1; float p2; float p3;
// };
// typedef struct aluno Aluno;
// para representar o cadastro de alunos de uma disciplina, implemente uma
// função imprime_media que imprima o número de matrícula, o nome, a turma e a
// média de todos os alunos que tiveram a média de suas três provas maior ou
// igual a um determinado valor (passado como parâmetro). Inclua as definições
// de estrutura exatamente como acima no seu arquivo de resposta, mas não
// inclua a função main. Inclua também a referência a quaisquer arquivos de
// biblioteca que você use (e.g., stdio.h). Os dados de cada aluno com nota
// acima da média especificada devem ser impressos em uma única linha,
// seguindo o formato numero_de_matricula nome_do_aluno turma media As linhas
// descritas acima devem ser a única coisa impressa pela sua função. Não
// imprima cabe ̧calhos, terminadores, separadores ou qualquer outro tipo de
// decoração que fuja ao padrão especificado. Caso nenhum aluno se encaixe na
// busca, não imprima nada. A média de cada aluno é calculada pela fórmula (p1
// + p2 + p3)/3 Essa função deve obedecer o protótipo void imprime_media
// (Aluno** turmas, int n, float media); onde o parâmetro turmas representa um
// vetor de ponteiros para estruturas do tipo Aluno, o parâmetro n é o
// comprimento do mesmo, e o parâmetro media é o valor da média mínima que
// queremos usar para selecionar os dados dos alunos que devem ser impressos.
// Obs.: podem haver posições não utilizadas no vetor turmas, contendo o valor
// NULL.

// 8) Considerando as declarações struct aluno { char nome[81]; char
// matricula[8]; char turma; float p1; float p2; float p3;
// };
// typedef struct aluno Aluno;
// para representar o cadastro de alunos de uma disciplina, implemente uma
// função imprime_turma que imprima o número de matrícula, o nome, a turma e a
// média de todos os alunos que pertencem a uma determinada turma (passada
// como parâmetro). Inclua as definições de estrutura exatamente como acima no
// seu arquivo de resposta, mas não inclua a função main. Inclua também a
// referência a quaisquer arquivos de biblioteca que você use (e.g., stdio.h).
// Os dados de cada aluno da turma devem ser impressos em uma única linha,
// seguindo o formato numero_de_matricula nome_do_aluno turma media As linhas
// descritas acima devem ser a única coisa impressa pela sua função. Não
// imprima cabe ̧calhos, terminadores, separadores ou qualquer outro tipo de
// decoração que fuja ao padrão especificado. Caso nenhum aluno se encaixe na
// busca, não imprima nada. A média de cada aluno é calculada pela fórmula (p1
// + p2 + p3)/3. Essa função deve obedecer o protótipo: void imprime_turma
// (Aluno** turmas, int n, char turma); onde o parâmetro turmas representa um
// vetor de ponteiros para estruturas do tipo Aluno, o parâmetro n é o
// comprimento do mesmo, e o parâmetro turma é a turma que queremos usar para
// selecionar os dados dos alunos que devem ser impressos. Obs.: podem haver
// posições não utilizadas no vetor turmas, contendo o valor NULL.
int main() {
  /*
  //Questao 1
  Ponto circulo;
  Ponto ponto;
  // o endereço é passado & pois o parametro ponteiro vai receber um endereço,
  // para ser trabalhado parametro de tipo variavel recebe uma variavel como
  // parametro, ou seu dado/valor ja o ponteiro ENDEREÇOO!!! * recebe &u
  printf("%i", dentroCirculo(&circulo, &ponto, 2));
  */
  /*
  // Questao 2
  Vetor u1, u2, res;
  calculaSomade2VetoresR3(&u1, &u2, &res);
  printf("\n(%f, %f, %f) + (%f, %f, %f) = (%f, %f, %f)\n", u1.x, u1.y, u1.z,
         u2.x, u2.y, u2.z, res.x, res.y, res.z);
  */
  /*
  // Questao 3

  Vetor w1, w2, result;
  calculaSubtracaode2VetoresR3(&w1, &w2, &result);
  printf("\n(%f, %f, %f) - (%f, %f, %f) = (%f, %f, %f)\n", w1.x, w1.y, w1.z,
           w2.x, w2.y, w2.z, result.x, result.y, result.z);
  */
  /*
  // Questao 4
  Vetor v1, v2;
  printf("%f", calculaMultiplicacaode2VetoresR3(&v1, &v2));
  */
  /*
  // Questao 5
  Vetor v;
  MultiplicacaoPorEscalar(&v, 2);
  */
  // Questao 6
  int n = 1;
  Aluno alunos;
  cadastro_disciplina(&alunos, n);

  return 0;
}