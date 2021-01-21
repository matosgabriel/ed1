// Nome: Gabriel Alves Matos

#include <stdio.h>
#include <stdlib.h>

/*
  Função responsável por inserir um valor no início da lista circular estática.
  Recebe como parâmetros um ponteiro de inteiro "vet" (vetor), um inteiro "n" que guarda o tamanho da lista (vetor), o ponteiro de inteiro "ocupado" que aponta
  para o endereço de memória que guarda o número de posições ocupadas da lista, um inteiro "num" que guarda o número a ser inserido e um ponteiro de inteiro
  "inicio" que aponta para um endereço de memória que guarda a posição do início da lista.
  Não há retorno.
*/

void insereInicio(int *vet, int n, int *ocupado, int num, int *inicio) {
  /*
    Se o número de posições ocupadas for menor que n (a lista não está cheia) então segue a tratativa para a inserção.
    Senão (a lista está cheia) é mostrada uma mensagem de erro.
  */

  if (*ocupado < n) {
    /*
      Se o número de posições ocupadas for igual a zero não é necessário alterar o início da lista, assim, o valor guardado no endereço
      de memória apontado por "inicio" será o próprio valor já guardado.
      Senão, se o valor guardado no endereço de memória apontado por "inicio" decrescido em uma unidade for maior ou igual a zero
      (o novo início não é negativo) então o valor guardado no endereço de memória apontado por "inicio" é decrescido em uma unidade.
      Senão, o valor guardado no endereço de memória apontado por "inicio" será o número de elementos do vetor decrescido de uma unidade
      (última posição do vetor).
    */

    if (*ocupado == 0) {
      *inicio = *inicio;
    } else if (*inicio - 1 >= 0) {
      *inicio = *inicio - 1;
    } else {
      *inicio = n - 1;
    }

    // O valor guardado no endereço de memória apontado por "ocupado" é acrescido de uma unidade pois foi inserido um novo número na lista
    *ocupado = *ocupado + 1;

    vet[*inicio] = num; // O vetor na posição do valor guardado no endereço de memória apontado por "inicio" recebe o número a ser inserido recebido por parâmetro.
    printf("\nInserido no inicio com sucesso!\n\n");
  } else {
    printf("\nImpossivel inserir. Lista cheia!\n\n");
  }
}

/*
  Função responsável por inserir um valor no fim da lista circular estática.
  Recebe como parâmetros um ponteiro de inteiro "vet" (vetor), um inteiro "n" que guarda o tamanho da lista (vetor), o ponteiro de inteiro "ocupado" que aponta para o endereço de memória que guarda
  o número de posições ocupadas da lista, um inteiro "num" que guarda o número a ser inserido e um ponteiro de inteiro "fim" que aponta para um endereço
  de memória que guarda a posição do fim da lista.
  Não há retorno.
*/

void insereFim(int *vet, int n, int *ocupado, int num, int *fim) {
  /*
    Se o número de posições ocupadas for menor que n (a lista não está cheia) então segue a tratativa para a inserção.
    Senão (a lista está cheia) é mostrada uma mensagem de erro.
  */

  if (*ocupado < n) {
    /*
      Se o número de ocupados for igual a zero não é necessário alterar o fim da lista, assim, o valor guardado no endereço
      de memória apontado por "fim" será o próprio valor já guardado.
      Senão, se o valor guardado no endereço de memória apontado por "fim" acrescido em uma unidade for menor que n
      (o novo fim não é maior que a última posição n-1) então o valor guardado no endereço de memória apontado por "fim" é acrescido em uma unidade.
      Senão, o valor guardado no endereço de memória apontado por "fim" será 0 (primeira posição do vetor).
    */

    if (*ocupado == 0) {
      *fim = *fim;
    } else if (*fim + 1 < n) {
      *fim = *fim + 1;
    } else {
      *fim = 0;
    }

    // O valor guardado no endereço de memória apontado por "ocupado" é acrescido de uma unidade pois foi inserido um novo número na lista
    *ocupado = *ocupado + 1;

    vet[*fim] = num; // O vetor na posição do valor guardado no endereço de memória apontado por "fim" recebe o número a ser inserido recebido por parâmetro.
    printf("\nInserido no fim com sucesso!\n\n");
  } else {
    printf("\nImpossivel inserir. Lista cheia!\n\n");
  }
}

/*
  Função responsável por excluir o valor do início da lista circular estática.
  Recebe como parâmetros um inteiro "n" que guarda o tamanho da lista (vetor), um ponteiro de inteiro "ocupado" que aponta para o endereço de memória que guarda
  o número de posições ocupadas da lista, e um ponteiro de inteiro "inicio" que aponta para um endereço de memória que guarda a posição do início da lista.
  Não há retorno.
*/

void excluiInicio(int n, int *ocupado, int *inicio) {
  /*
    Se o número de posições ocupadas for maior que 0 (a lista não está vazia) então segue a tratativa para a exclusão.
    Senão (a lista está vazia) é mostrada uma mensagem de erro.
  */

  if (*ocupado > 0) {
    /*
      Se o número de posições ocupadas for igual a 1 então não é necessário alterar o inicio da lista, somente o número de posições ocupadas.
      Assim o valor guardado pelo endereço de memória apontado por "ocupado" será 0.
      Senão, se o valor guardado no endereço de memória apontado por "inicio" acrescido de uma unidade for menor que n, então é alterado o valor
      guardado no endereço de memória apontado por "inicio" (acrescido em uma unidade) e também o valor guardado no endereço de memória apontado por
      "ocupado" (acrescido em uma unidade).
      Senão, o valor guardado no endereço de memória apontado por "inicio" receberá 0 (primeira posição do vetor) e o número de posições ocupadas é
      decrescido de uma unidade.
    */

    if (*ocupado == 1) {
      *ocupado = 0;
    } else if (*inicio + 1 < n) {
      *inicio = *inicio + 1;
      *ocupado = *ocupado - 1;
    } else {
      *inicio = 0;
      *ocupado = *ocupado - 1;
    }

    printf("\nElemento do inicio excluido com sucesso!\n\n");
  } else {
    printf("\nNao ha elementos para excluir!\n\n");
  }
}

/*
  Função responsável por excluir o valor do fim da lista circular estática.
  Recebe como parâmetros um inteiro "n" que guarda o tamanho da lista (vetor), um ponteiro de inteiro "ocupado" que aponta para o endereço de memória que guarda
  o número de posições ocupadas da lista, e um ponteiro de inteiro "fim" que aponta para um endereço de memória que guarda a
  posição do fim da lista.
  Não há retorno.
*/

void excluiFim(int n, int *ocupado, int *fim) {
  /*
    Se o número de posições ocupadas for maior que 0 (a lista não está vazia) então segue a tratativa para a exclusão.
    Senão (a lista está vazia) é mostrada uma mensagem de erro.
  */

  if (*ocupado > 0) {
    /*
      Se o número de posições ocupadas for igual a 1 então não é necessário alterar o fim da lista, somente o número de posições ocupadas.
      Assim o valor guardado pelo endereço de memória apontado por "ocupado" será 0.
      Senão, se o valor guardado no endereço de memória apontado por "fim" decrescido de uma unidade for maior ou igual a 0, então é alterado o valor
      guardado no endereço de memória apontado por "fim" (decrescido em uma unidade) e também o valor guardado no endereço de memória apontado por
      "ocupado" (decrescido em uma unidade).
      Senão, o valor guardado no endereço de memória apontado por "fim" receberá n-1 (última posição do vetor) e o número de posições ocupadas é
      decrescido de uma unidade (o valor guardado no endereço de memória apontado por "ocupado" será o valor atual guardado decrescido de uma unidade).
    */

    if (*ocupado == 1) {
      *ocupado = 0;
    } else if (*fim - 1 >= 0) {
      *fim = *fim - 1;
      *ocupado = *ocupado - 1;
    } else {
      *fim = n - 1;
      *ocupado = *ocupado - 1;
    }
    printf("\nElemento do fim excluido com sucesso!\n\n");
  } else {
    printf("\nNao ha elementos para excluir!\n\n");
  }
}

/*
  Função responsável por imprimir os valores presentes na lista circular estática e suas respectivas posições.
  Recebe como parâmetros um ponteiro de inteiro "vet" (vetor), um inteiro "n" que guarda o tamanho da lista (vetor),
  um inteiro "ocupado" cujo valor é a quantidade de posições ocupadas do vetor e um inteiro "inicio" cujo valor
  é a posição do início da lista (vetor).
  Não há retorno.
*/

void imprime(int *vet, int n, int ocupado, int inicio) {
  // Criação de uma variável auxiliar.
  int aux = 0;

  /*
    Se o número de posições ocupados for maior que zero serão impressos os valores e suas posições.
    Se não será impressa uma mensagem informando que a lista está vazia.
  */

  if (ocupado > 0) {
    /*
      Laço responsável por percorrer a lista circular estática (vetor), o conteúdo do laço será executado um número de
      vezes igual a quantidade de posições ocupadas.
    */

    while (aux < ocupado) {
      /*
        Se o valor de "inicio" for maior que o índice da última posição do vetor (n-1) então "inicio" receberá 0
        (foi feita uma volta completa na lista circular).
      */
      if (inicio > n - 1) inicio = 0;

      printf("\n%d (posicao %d)", vet[inicio], inicio); // Impressão do elemento e da posição.

      // Incremento de uma unidade no valor da variável auxiliar e da variável "inicio".
      aux += 1;
      inicio += 1;
    }
  } else {
    printf("vazia!");
  }
}

// Função principal (main).
int main() {
  // Criação das variáveis necessárias.
  int n = -1, escolha = 0, num = 0, ocupado = 0;
  int inicio = 0, fim = 0, numElementos = 0;

  /*
    Laço responsável por controlar a entrada do usuário. Enquanto for inserido um valor de tamanho
    menor que zero será feita a leitura novamente.
  */

  while(n < 0) {
    printf("Informe o tamanho da lista circular (inteiro positivo): ");
    scanf("%d", &n);
  }

  printf("\n");

  // Criação do vetor com o tamanho igual ao tamanho informado pelo usuário (n).
  int vet[n];

  // Laço responsável por repetir o menu e a operação enquanto o usuário não escolher sair do programa (escolha diferente de 6).
  do {
    printf("----Menu de opcoes----\n");
    printf("1 - Inserir no inicio\n2 - Inserir no fim\n3 - Excluir do inicio\n4 - Excluir do fim\n");
    printf("5 - Imprimir\n6 - Sair\n\n");
    printf("Sua escolha: ");
    scanf("%d", &escolha); // Leitura da escolha do usuário.

    // Estrutura condicional responsável por realizar a operação de acordo a escolha do usuário.
    switch(escolha) {
      case 1:
        printf("Informe o numero que deseja inserir no inicio: ");
        scanf("%d", &num); // Leitura do número a ser inserido.

        // Chamada da função de inserção no início da lista circular estática.
        insereInicio(vet, n, &ocupado, num, &inicio);
        break;
      case 2:
        printf("Informe o numero que deseja inserir no fim: ");
        scanf("%d", &num); // Leitura do número a ser inserido.

        // Chamada da função de inserção no fim da lista circular estática.
        insereFim(vet, n, &ocupado, num, &fim);
        break;
      case 3:
        // Chamada da função de exclusão do elemento do início da lista circular estática.
        excluiInicio(n, &ocupado, &inicio);
        break;
      case 4:
        // Chamada da função de exclusão do elemento do fim da lista circular estática.
        excluiFim(n, &ocupado, &fim);
        break;
      case 5:
        printf("\nLista: ");

        // Chamada da função de impressão dos elementos e suas respectivas posições na lista circular estática.
        imprime(vet, n, ocupado, inicio);
        printf("\n\n");
        break;
      case 6: break; // Foi escolhida a opção "Sair". Nada será feito.
      default:
        // Foi lida uma opção inválida (não existe "case" para tal escolha).
        printf("\nEscolha invalida!\n\n");
      }

  } while(escolha != 6);

  return 0; // Retorno de 0 indicando que o programa foi executado com sucesso.
}
