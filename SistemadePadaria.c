#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
//                             STRUCT PRODUTO
typedef struct {
  char codigo[5];
  char nome[30];
  int quantidade_disponivel;
  int n_vendas;
  int n_compras;
  int status;
  float preco;
} Produto;

typedef struct {
  char UsuarioAtual[30];
  float Liquida;
  float Receita;
  float Imposto;
  float Taxa;
  float CustoTotal;
  float Orcamento;
  float Ganho;
  int Registros;
} ServicoPadaria;

int inserir(Produto *produtos, int tamanho, int posicao, Produto novo,
            char codigo[5]) {
  // 1. int inserir(Produto* produtos, int tamanho, int posicao, Produto novo)
  int buscador = 0;
  do {
    //     Não pode inserir produto com mesmo código.
    int comparacao = strcmp(codigo, produtos[buscador].codigo) ==
                     0; // testa se codigos igual
    // PEQUENA REDUNDANCIA EM RELAÇÃO AS FUNÇÕES INSERIRUMPRODUTO E
    // PREENCHERLISTA
    int status = produtos[buscador].status == 1;
    // strcmp retorna 0 para igual e 1 para diferente
    if (comparacao && status) {
      // se retornou 0 é pq existe codigo igual e com status = 0

      return 0;
    }
    buscador++;
  } while (buscador < tamanho);

  if (produtos[posicao].status == 0) {
    //     Não pode inserir em um lugar com produto com status 1
    strcpy(novo.codigo, codigo);
    novo.status = 1;
    novo.quantidade_disponivel = 0;
    printf("\nNome do Produto: ");
    scanf("%[^\n]", novo.nome);
    getchar();
    printf("\nPreço do Produto: ");
    scanf("%f", &novo.preco);
    getchar();
    novo.n_vendas = 0;
    novo.n_compras = 0;
    produtos[posicao] = novo;
    system("clear");
    return 1;
  }
  printf("\nPosição ocupada");
  getchar();
  system("clear");
  return 0;
}
void inicializarProduto(Produto *novo, char codigo[5]) {
  strcpy((*novo).codigo, codigo);
  strcpy((*novo).nome, "");
  (*novo).status = 0;
  novo->n_vendas = 0;
  novo->n_compras = 0;
}
void PreencherLista(Produto *produtos, int tamanho, ServicoPadaria *padaria) {
  for (int Contador = 0; Contador < tamanho; Contador++) {
    if (!produtos[Contador].status) {

      char codigo[5];
      sprintf(codigo, "%i", ++(*padaria).Registros); // int++  para string
      Produto novo;
      inicializarProduto(&novo, codigo);
      printf("Inserção #%i\n", Contador + 1);
      inserir(produtos, tamanho, Contador, novo, codigo);
    }
  }
}
void inserirUmProduto(Produto *produtos, int tamanho, ServicoPadaria *padaria) {
  // IMPRIME SEM ORDEM TODOS PRODUTOS COM STATUS = 1
  int inserido = 0;
  int posicao = 0;
  do {
    printf("Indique a posicao do produto para inserir: ");
    scanf("%i", &posicao);
    getchar();
  } while (posicao > tamanho || posicao < 0);
  Produto novo;

  if (!produtos[posicao].status) {
    char codigo[5];
    sprintf(codigo, "%i", ++(*padaria).Registros); // int++  para string
    Produto novo;
    inicializarProduto(&novo, codigo);
    inserido = inserir(produtos, tamanho, posicao, novo, codigo);
  }
  // inseriu o produto
  if (inserido) {
    system("clear");
    printf("Produto inserido com sucesso");
    getchar();
    system("clear");
  } else {
    system("clear");
    printf("\nOperação Invalida");
    getchar();
    system("clear");
  }
}

int buscar(Produto *produtos, int tamanho, char codigo[5]) {
  // 3. int buscar(Produto* produtos, int tamanho, char[] codigo)
  int buscador = tamanho - 1;
  do {
    // testa se o codigo é o igual ao codigo do produto na lista
    if (!strcmp(codigo, produtos[buscador].codigo) &&
        produtos[buscador].status == 1) {
      return buscador; // retorna index da busca por codigo
    }
    buscador--;
  } while (buscador >= 0);
  printf("Operação Inválida");
  getchar();
  system("clear");
  return buscador; // buscador vale -1
}
int remover(Produto *produtos, int tamanho, char codigo[5]) {
  // 2. int remover(Produto* produtos, int tamanho, char[] codigo)
  int buscador = 0;
  do {
    //  Não pode remover um produto que não existe - com status = 0
    int comparacao = strcmp(codigo, produtos[buscador].codigo) == 0;
    int status = produtos[buscador].status == 1;
    // achou um codigo igual, e NOT de 0 é 1
    if (comparacao && status) {
      produtos[buscador].status = 0;
      return 1;
    }
    buscador++;
  } while (buscador < tamanho);
  return 0;
}
int comprar(Produto *produtos, int tamanho, char codigo[5],
            ServicoPadaria *padaria) {
  // 4. int comprar(Produto* produtos, int tamanho, char[] codigo)
  int buscador = 0;
  do {
    int status = produtos[buscador].status == 1;
    int comparacodigo = strcmp(codigo, produtos[buscador].codigo) == 0;
    // status produtos buscador é 1 e se compara codigo=0 igual é 1
    if (comparacodigo && status) {
      produtos[buscador].quantidade_disponivel++;
      produtos[buscador].n_compras++;
      (*padaria).CustoTotal += produtos[buscador].preco;
      (*padaria).Orcamento -= produtos[buscador].preco;
      return 1;
    }
    buscador++;
  } while (buscador < tamanho);
  return 0; // buscador vai retornar -1
}

int vender(Produto *produtos, int tamanho, char codigo[5],
           ServicoPadaria *padaria) {
  // 5. int vender(Produto* produtos, int tamanho, char[] codigo)
  int buscador = tamanho - 1;
  while (buscador >= 0) {
    int status = produtos[buscador].status == 1;
    int hadisponivel = produtos[buscador].quantidade_disponivel > 0;
    // testa se o codigo é o igual ao codigo do produto na lista
    int comparacodigo = strcmp(codigo, produtos[buscador].codigo) == 0;
    // produto só se tornará indisponivel, quando vender em 'hadisponivel'
    // não precisa alterar status para 0, pois ficará complicado
    // de comprá-lo novamente em 'comprar()''
    if (comparacodigo && status && hadisponivel) {
      produtos[buscador].quantidade_disponivel--;
      produtos[buscador].n_vendas++;

      float ReceitaAtual = produtos[buscador].preco +
                           (produtos[buscador].preco * (*padaria).Ganho / 100);

      float Imposto = ReceitaAtual * (*padaria).Taxa / 100;

      // atribuindo FIXADAMENTE
      (*padaria).Receita += ReceitaAtual;
      (*padaria).Imposto += Imposto;
      (*padaria).Liquida += ReceitaAtual - Imposto;
      (*padaria).Orcamento += ReceitaAtual - Imposto;
      return 1; // sempre retorna 1 para sucesso
    }
    buscador--;
  }
  system("clear");
  return (buscador + 1);
}

void removerUmProduto(Produto *produtos, int tamanho) {
  int produtosRemoviveis = 0;
  for (int buscador = 0; buscador < tamanho; buscador++) {
    if (produtos[buscador].status == 1) { // checa se numero de produtos
      produtosRemoviveis++;               // com status 1, ou seja, removivel
    }
  }
  printf("\nEntre com o Código do Produto: ");
  char codigo[5];
  scanf("%s", codigo);
  getchar();
  if (remover(produtos, tamanho, codigo)) {
    // i = i-1 sempre que remove um produto da lista
    system("clear");
    printf("Produto removido com sucesso");
    getchar();
    system("clear");
  } else {
    printf("Operação Invalida");
    system("clear");
  }
  // caso n digite o codigo certo, o programa pede novamente o codigo
}
void buscarProduto(Produto *produtos, int tamanho) {
  printf("\nEntre com o Código do Produto: ");
  char codigo[5];
  scanf("%s", codigo);
  getchar();
  int busca = buscar(produtos, tamanho, codigo);
  if (busca < 0) {
    printf("Código Inválido");
    getchar();
    system("clear");
    // só sai do loop se removeu numero de produtos desejado
  } else {
    printf("\nIndex: %i\n", busca);
    printf("codigo: %s\n", produtos[busca].codigo);
    printf("nome: %s\n", produtos[busca].nome);
    printf("preco: %.2f\n", produtos[busca].preco);
    printf("quantidade: %i\n", produtos[busca].quantidade_disponivel);
    printf("compras: %i\n", produtos[busca].n_compras);
    printf("vendas: %i\n", produtos[busca].n_vendas);
    getchar();
    system("clear");
  }
}
void venderProdutos(Produto *produtos, int tamanho, ServicoPadaria *padaria) {
  char codigo[5];
  printf("\nEntre com o Código do Produto: ");
  scanf("%s", codigo);
  getchar();
  printf("\nQuantos produtos deseja vender: ");
  int n_vendas = 0;
  scanf("%i", &n_vendas);
  getchar();
  while (n_vendas > 0) {
    if (vender(produtos, tamanho, codigo, padaria)) {
      n_vendas--;
    } else {
      printf("Operação Invalida");
      getchar();
      break;
    }
  }
}
void comprarProdutos(Produto *produtos, int tamanho, ServicoPadaria *padaria) {
  char codigo[5];
  printf("\nEntre com o Código do Produto: ");
  scanf("%s", codigo);
  getchar();
  printf("\nQuantos produtos deseja comprar: ");
  int n_compras = 0;
  scanf("%i", &n_compras);
  getchar();
  while (n_compras > 0) {
    if (comprar(produtos, tamanho, codigo, padaria)) {
      n_compras--;
    } else {
      printf("Operação Inválida");
      getchar();
      break;
    }
  }
  getchar();
}

//                        FUNÇÕES EXTRAS
int ListaEstaVazia(Produto *produtos, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    if (produtos[i].status == 1) {
      return 0;
    }
  }
  return 1;
}
int HaCompras(Produto *produtos, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    int HaCompras = produtos[i].n_compras > 0, status = produtos[i].status == 1;
    char temCodigo[5];
    strcpy(temCodigo, produtos[i].codigo);
    if (status && HaCompras) {
      return 1;
    }
    if (HaCompras) {
      return 1;
    }
  }
  return 0;
}
void tam1paratam2(Produto *produtos1, Produto *produtos2, int tamanhoAnterior,
                  int *tamanhoNovo) {
  *tamanhoNovo = 0;
  for (int i = 0; i < tamanhoAnterior; i++) {
    if (produtos1[i].status == 1) {
      produtos2[(*tamanhoNovo)++] = produtos1[i];
    }
  }
}
void abertura() {
  time_t horaEmC;
  time(&horaEmC);                             // hora em numeros
  struct tm *horaLocal = localtime(&horaEmC); // hora local em algum local
  int horas = horaLocal->tm_hour - 3;         // fuso-horario Pernambuco
  int minutos = horaLocal->tm_min;
  int dia = horaLocal->tm_mday;
  int mes = horaLocal->tm_mon + 1;
  int ano = horaLocal->tm_year + 1900;
  sleep(1);
  printf("\nData: %02d/%02d/%02d\n", dia, mes, ano);
  sleep(1);
  printf("Hora: %02d:%02d\n", horas, minutos);
  sleep(1);
}
void inicializarPadaria(ServicoPadaria *padaria) {
  abertura();
  printf("Nome do usuário: ");
  scanf("%[^\n]", (*padaria).UsuarioAtual);
  getchar();
  printf("Taxa de Imposto sobre Receita: ");
  scanf("%f", &(*padaria).Taxa);
  getchar();
  printf("Taxa de lucro das vendas: ");
  scanf("%f", &(*padaria).Ganho);
  getchar();
  printf("Orçamento Comercial: ");
  scanf("%f", &(*padaria).Orcamento);
  getchar();
  (*padaria).Liquida = 0.0;
  (*padaria).Receita = 0.0;
  (*padaria).CustoTotal = 0.0;
  (*padaria).Imposto = 0.0;
  (*padaria).Registros = 0;
}
void inicializarLista(Produto *produtos, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    strcpy(produtos[i].codigo, "");
    produtos[i].status = 0;
    produtos[i].n_vendas = 0;
    produtos[i].n_compras = 0;
  }
}
void EncerrarPrograma(ServicoPadaria padaria) {
  abertura();
  printf("\tPrograma Encerrado.\n\n\nVolte sempre, %s", padaria.UsuarioAtual);
}
//                           LETRA (B)
void ListarMaisVendidos(Produto *produtos, int tamanho) {
  // 1. Lista ordenada dos produtos mais vendidos
  int tamanho2;
  Produto MaisVendidos[tamanho];
  tam1paratam2(produtos, MaisVendidos, tamanho, &tamanho2);
  for (int i = 0; i < tamanho2; i++) {
    for (int j = i + 1; j < tamanho2; j++) {
      if (MaisVendidos[i].n_vendas < MaisVendidos[j].n_vendas) {
        // AUXILIAR <- ANTERIORmeno
        // ANTERIORmenor <- POSTERIORmaior
        // POSTERIORmaior<- AUXILIAR
        // Assim o maior fica atras e o menor na frente
        // fazendo isso da esquerda para direita
        // varrendo todo o array, mas sempre nessa RELAÇÃO
        Produto auxiliar = MaisVendidos[i];
        MaisVendidos[i] = MaisVendidos[j];
        MaisVendidos[j] = auxiliar;
      }
    }
  }
  printf("\n\tProdutos mais Vendidos\t\n");
  for (int i = 0; i < tamanho2; i++) {
    printf("\n#%i\nCódigo: %s\nNome: %s\nVendas: %i\n", i + 1,
           MaisVendidos[i].codigo, MaisVendidos[i].nome,
           MaisVendidos[i].n_vendas);
  }
}
void ListarMaisComprados(Produto *produtos, int tamanho) {
  // 2. Lista ordenada dos produtos mais comprados
  Produto MaisComprados[tamanho];
  int tamanho2;
  tam1paratam2(produtos, MaisComprados, tamanho, &tamanho2);
  for (int i = 0; i < tamanho2; i++) {
    for (int j = i + 1; j < tamanho2; j++) {
      if (MaisComprados[i].n_compras < MaisComprados[j].n_compras) {
        Produto auxiliar = MaisComprados[i];
        MaisComprados[i] = MaisComprados[j];
        MaisComprados[j] = auxiliar;
      }
    }
  }
  printf("\n\tProdutos mais Comprados\t\n");
  for (int i = 0; i < tamanho2; i++) {
    usleep(666);
    printf("\n#%i\nCódigo: %s\nNome: %s\nCompras: %i\n", i + 1,
           MaisComprados[i].codigo, MaisComprados[i].nome,
           MaisComprados[i].n_compras);
  }
}
void MostrarEstoque(Produto *produtos, int tamanho) {
  printf("\n\tEstoque\t\n");
  for (int i = 0; i < tamanho; i++) {
    if (produtos[i].status == 1) {
      printf("\nIndex %i\nCodigo: %s\n", i + 1, produtos[i].codigo);
      printf("nome: %s\n", produtos[i].nome);
      printf("preco Atual: %.2f\n", produtos[i].preco);
      printf("quantidade em estoque: %i\n", produtos[i].quantidade_disponivel);
    }
  }
}
void extratoAtual(Produto *produtos, int tamanho, ServicoPadaria *padaria) {
  // 3. Extrato da conta da padaria
  printf("\n\tExtrato de vendas\t\n");
  for (int i = 0; i < tamanho; i++) {
    if (produtos[i].status == 1) {
      float vendaAtual =
          (produtos[i].n_vendas * produtos[i].preco) +
          (produtos[i].n_vendas * produtos[i].preco * (*padaria).Ganho / 100);
      float compraAtual = produtos[i].n_compras * produtos[i].preco;
      float ImpostoAtual = vendaAtual * (*padaria).Taxa / 100;
      float liquida = vendaAtual - (compraAtual + ImpostoAtual);
      printf("\nProduto '%s'", produtos[i].nome);
      printf("\nGasto com o produto: %.2f", compraAtual);
      printf("\nImposto da venda: %.2f\n", ImpostoAtual);
      printf("\nReceita da venda: %.2f\n", vendaAtual);
      printf("\nGanho real: %.2f\n", liquida);
    }
  }

  // BUG EM RECEITA LIQUIDA
  int temProduto = 0;
  for (int i = 0; i < tamanho; i++) {
    if (produtos[i].status == 1) {
      temProduto = 1;
    }
  }
  if (!temProduto) {
    (*padaria).Liquida = 0;
  }
  printf("\n\tValores totais\t\n");
  printf("\nReceita Bruta Total: $%.2f", (*padaria).Receita);
  printf("\nGastos Totais: $%.2f\n", (*padaria).CustoTotal);
  printf("\n\nImpostos totais: %.2f\n", (*padaria).Imposto);
  printf("\nReceita Líquida: %.2f\n", (*padaria).Liquida);
  if ((*padaria).Orcamento >= 0) {
    printf("\nVocê está com: $%.2f\n", (*padaria).Orcamento);
  } else {
    printf("\nVocê está devendo: $%.2f\n", -1 * (*padaria).Orcamento);
  }
  getchar();
  system("clear");
}
void GerarRelatorio(Produto *produtos, int tamanho, ServicoPadaria *padaria) {
  // 4. Produtos em estoque
  system("clear");
  printf("\t\tRelatório\t\n");
  ListarMaisVendidos(produtos, tamanho);
  ListarMaisComprados(produtos, tamanho);
  MostrarEstoque(produtos, tamanho);
  extratoAtual(produtos, tamanho, padaria);
}
void imprimirPorIndex(Produto *produtos, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    printf("\t\nINDEX %i\n", i);
    if (produtos[i].status == 1) {
      printf("\nCodigo: %s\n", produtos[i].codigo);
      printf("nome: %s\n", produtos[i].nome);
      printf("preco: %.2f\n", produtos[i].preco);
      printf("quantidade: %i\n", produtos[i].quantidade_disponivel);
      printf("compras: %i\n", produtos[i].n_compras);
      printf("vendas: %i\n", produtos[i].n_vendas);
    } else {
      printf("\nPosicao vaga\n");
    }
  }
  getchar(); // pausa dramática
}

int main() {
  system("clear");
  ServicoPadaria padaria;
  printf("\n\tOlá, Bem-vindo ao sistema da padaria\t\n\n");
  inicializarPadaria(&padaria);
  int tamanho = 0;
  do {
    printf("Insira o tamanho da lista de produtos: ");
    scanf("%i", &tamanho);
    getchar();
    system("clear");
  } while (tamanho < 1); // checa se lista maior do que 0

  // COLOCANDO STATUS 0 NAS POSICOES
  Produto produtos[tamanho];
  inicializarLista(produtos, tamanho);
  int Encerrar = 0;
  do {
    system("clear");
    printf("\n0. Mostrar posicoes vagas e ocupadas\n");
    printf("1. Inserir VÁRIOS produtos\n");
    printf("2. Buscar por um produto\n");
    printf("3. Remover produto\n");
    printf("4. Comprar produtos\n");
    printf("5. Vender produtos\n");
    printf("6. Gerar Relatório\n");
    printf("7. Inserir um produto\n");
    printf("8. Encerrar Programa\n");
    printf("\n\n\tQual a sua opção: ");
    int escolha;
    scanf("%i", &escolha);
    getchar();
    system("clear");
    switch (escolha) {
    case 0:
      imprimirPorIndex(produtos, tamanho);
      break;
    case 1:
      PreencherLista(produtos, tamanho, &padaria);
      break;
    case 2:
      if (!ListaEstaVazia(produtos, tamanho)) {
        buscarProduto(produtos, tamanho);
      }
      break;
    case 3:
      if (!ListaEstaVazia(produtos, tamanho)) {
        removerUmProduto(produtos, tamanho);
      }
      break;
    case 4:
      if (!ListaEstaVazia(produtos, tamanho)) {
        comprarProdutos(produtos, tamanho, &padaria);
      }
      break;
    case 5:
      if (!ListaEstaVazia(produtos, tamanho)) {
        venderProdutos(produtos, tamanho, &padaria);
      }
      break;
    case 6:
      if (HaCompras(produtos, tamanho) == 1 ||
          HaCompras(produtos, tamanho) == 2) {
        GerarRelatorio(produtos, tamanho, &padaria);
      } else {
        printf("Ainda nao há compras ou vendas");
        getchar();
      }
      break;
    case 7:
      inserirUmProduto(produtos, tamanho, &padaria);
      break;
    case 8:

      Encerrar = 1;
      break;
    default:
      printf("Opção inválida");
      break;
    }
    system("clear");
  } while (!Encerrar);
  EncerrarPrograma(padaria);
  return 0;
}