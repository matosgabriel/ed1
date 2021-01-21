// Nome: Gabriel Alves Matos

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Monomio
typedef struct monomio {
  int exp;
  int coef;
  struct monomio *prox;
} Monomio;

/*
  Função responsável por criar um novo monômio
  Recebe como parâmetros o coeficiente e o expoente do monômio que será criado
  Retorna um ponteiro que aponta para o novo monômio
*/

Monomio *criaMonomio(int coef, int exp) {
  Monomio *novo = (Monomio *) calloc(1, sizeof(Monomio));

  /*Caso a alocação de memória não for executada com sucesso será mostrada uma
    mensagem na tela e o programa será encerrado.
    Caso a alocação for executada com sucesso serão efetuadas as atribuições dos valores
    aos atributos e o retorno do novo monômio (ponteiro)
  */
  if (!novo) {
    printf("Erro ao alocar memória");
    exit(1); // Término do programa sem êxito
  } else {
    // Atribuição dos valores recebidos por parâmetro aos campos
    novo->coef = coef;
    novo->exp = exp;
    novo->prox = NULL;

    return novo;
  }
}

/*
  Função responsável por inserir um novo monômio ao polinômio (lista encadeada)
  Recebe como parâmetros o polinômio que deve receber o novo monômio, o coeficiente e o expoente do novo monômio
  Retorna um ponteiro que aponta para a primeira posição da lista encadeada que representa
  o novo polinômio (agora contendo o novo monômio com coeficiente e expoente recebidos via parâmetro)
*/

Monomio *insereMonomio(Monomio *polinomio, int coef, int exp) {
  // Criação do novo monômio e dos ponteiros auxiliares
  Monomio *novo = criaMonomio(coef, exp);
  Monomio *pred = NULL;
  Monomio *aux = polinomio;

  /*Caso a lista encadeada esteja vazia a sua primeira posição receberá o novo monômio,
    caso contrário segue a tratativa para uma lista não vazia
  */
  if (!aux) {
    polinomio = novo;
  } else {
    /*
      Laço responsável por percorrer o polinômio (lista encadeada) com o intuito de inserir
      o novo monômio já em posição ordenada (nesse caso em ordem decrescente por expoente)
      Os ponteiros auxiliares têm seus valores atualizados a cada execução do laço
    */
    while (aux && aux->exp > exp) {
      pred = aux;
      aux = aux->prox;
    }

    /*
      Tratativa para o caso de o expoente do novo monômio ser maior que o expoente de todos
      os monômios já presentes no polinômio
      O ponteiro ainda tem valor NULL, ou seja, a condição do laço não foi atendida nenhuma vez
      Caso contrário o novo monômio será inserido no "meio" do polinômio (lista)
    */
    if (!pred) {
      novo->prox = polinomio;
      polinomio = novo;
    } else {
      pred->prox = novo;
      novo->prox = aux;
    }
  }

  return polinomio;
}

/*
  Função responsável por simplificar o polinômio (resultado do produto de polinômios)
  removendo repetição de expoente e monômios com coeficiente 0
  Recebe como parâmetros o polinômio a ser simplificado
  Retorna um ponteiro que aponta para a primeira posição da lista encadeada que representa
  o polinômio simplificado (sem expoentes repetidos)
*/

Monomio *simplificaPolinomio(Monomio *polinomio) {
  // Criação do polinômio resultante (lista encadeada) e das variáveis auxiliares
  int soma = 0, exp = NULL;
  Monomio *aux = polinomio;
  Monomio *novo = NULL;

  // Somente se o polinômio for não nulo (lista não vazia) será realizada a simplificação
  if (polinomio) {
    exp = polinomio->exp;
  }

  //Laço responsável por somar os coeficientes para cada expoente
  while(exp >= 0) {
    soma = 0; // Soma dos coeficientes de monômios com expoente igual

    /*
      Laço responsável por percorrer todos os monômios com expoente maior ou igual ao expoente "atual"
    */
    while(aux && aux->exp >= exp) {
      // Caso o expoente do monômio seja igual ao expoente "atual" é acrescentado o valor do coeficiente à soma
      if (aux->exp == exp) soma += aux->coef;
      aux = aux->prox;
    }

    // Caso o resultado da soma dos coeficientes for diferente de zero o monômio será inserido no novo polinômio
    if (soma != 0 ) novo = insereMonomio(novo, soma, exp);

    exp--; // Decremento do expoente atual
  }

  return novo; // Retorno do novo polinômio simplificado
}

/*
  Função responsável por somar dois polinômios
  Recebe como parâmetros os polinômios a serem somados
  Retorna um ponteiro que aponta para a primeira posição da lista encadeada que representa
  o polinômio resultante da soma dos dois polinômios recebidos como parâmetros
*/

Monomio *somaPolinomios(Monomio *p1, Monomio *p2) {
  // Criação do polinômio resultante (lista encadeada) e dos ponteiros auxiliares
  Monomio *aux1 = p1;
  Monomio *aux2 = p2;
  Monomio *p3 = NULL;

  // Laço responsável por percorrer o primeiro polinômio inserindo cada monômio deste no polinômio resultante
  while(aux1) {
    p3 = insereMonomio(p3, aux1->coef, aux1->exp);
    aux1 = aux1->prox;
  }

  // Laço responsável por percorrer o segundo polinômio inserindo cada monômio deste no polinômio resultante
  while(aux2) {
    p3 = insereMonomio(p3, aux2->coef, aux2->exp);
    aux2 = aux2->prox;
  }

  // Retorno do polinômio resultante simplificado
  return simplificaPolinomio(p3);
}

/*
  Função responsável por subtrair um polinômio de outro polinômio
  Recebe como parâmetros os polinômios a serem subtraidos
  Retorna um ponteiro que aponta para a primeira posição da lista encadeada que representa
  o polinômio resultante da subtração dos dois polinômios recebidos como parâmetros
*/

Monomio *subtraiPolinomios(Monomio *p1, Monomio *p2) {
  // Criação do polinômio resultante (lista encadeada) e dos ponteiros auxiliares
  Monomio *aux1 = p1;
  Monomio *aux2 = p2;
  Monomio *p3 = NULL;

  // Laço responsável por percorrer o primeiro polinômio inserindo cada monômio deste no polinômio resultante
  while(aux1) {
    p3 = insereMonomio(p3, aux1->coef, aux1->exp);
    aux1 = aux1->prox;
  }

  // Laço responsável por percorrer o segundo polinômio inserindo cada monômio deste multiplicado por -1 no polinômio resultante (subtração)
  while(aux2) {
    p3 = insereMonomio(p3, aux2->coef * -1, aux2->exp);
    aux2 = aux2->prox;
  }

  // Retorno do polinômio resultante simplificado
  return simplificaPolinomio(p3);
}

/*
  Função responsável por multiplicar dois polinômios
  Recebe como parâmetros os polinômios a serem multiplicados
  Retorna um ponteiro que aponta para a primeira posição da lista encadeada que representa
  o polinômio resultante do produto dos dois polinômios recebidos como parâmetros
*/

Monomio *multiplicaPolinomios(Monomio *p1, Monomio  *p2) {
  // Criação do polinômio resultante (lista encadeada) e das variáveis auxiliares
  Monomio *aux1 = p1;
  Monomio *aux2 = p2;
  Monomio *p3 = NULL;
  int coef = 0, exp = 0;

  /*
    Laço responsável por percorrer todo o primeiro polinômio (lista encadeada)
    Obs.: o caso de um dos polinômios for nulo (ou os dois) já é automaticamente tratado
  */
  while(aux1) {
    aux2 = p2;
    /*
      Laço responsável por percorrer todo o segundo polinômio (lista encadeada)
      Cada monômio do primeiro polinômio será multiplicado por cada monômio do segundo polinômio
    */
    while(aux2) {
      // É aplicada a lógica do produto de monômios (soma dos expoentes e produto dos coeficientes)
      coef = aux1->coef * aux2->coef;
      exp = aux1->exp + aux2->exp;
      p3 = insereMonomio(p3, coef, exp); // Inserção do monômio resultante do produto dos dois monômios no novo polinômio
      aux2 = aux2->prox; // Atualização do ponteiro auxiliar
    }
    aux1 = aux1->prox; // Atualização do ponteiro auxiliar
  }

  /*Automaticamente é tratado o caso de um dos polinômios ser nulo, pois sendo assim o laço mais de fora ou o laço mais de fora
    não será executado fazendo com que p3 permaneça como NULL (polinômio nulo)
  */

  return simplificaPolinomio(p3); // Retorno do polinômio resultante do produto dos polinômios já simplificado
}

/*
  Função responsável por imprimir um polinômio
  Recebe como parâmetros o polinômio a ser impresso
*/

void imprimePolinomio(Monomio *polinomio) {
  // Caso o polinômio (lista encadeada) seja nulo será impressa a mensagem
  if (!polinomio) {
    printf("\nPolinomio resultante nulo!");
  }

  // Laço responsável por percorrer todos os monômios do polinômios
  while(polinomio) {
    // Caso o coeficiente seja maior que 0 imprimir o sinal positivo, caso contrário imprimir
    // o sinal negativo e multiplicar por -1 o coeficiente
    if (polinomio->coef > 0) printf("+");
    else {
      polinomio->coef = polinomio->coef * -1;
      printf("-");
    }

    // Caso o expoente seja maior que 0 imprimir o mesmo, caso contrário não é necessário imprimir
    if (polinomio->exp > 0) printf(" %dx^%d ", polinomio->coef, polinomio->exp);
    else printf(" %d ", polinomio->coef);

    polinomio = polinomio->prox;
  }

  printf("\n\n");
}

void limpaPolinomio(Monomio *monomio) {
  Monomio *limpar = NULL;

  while(monomio) {
    limpar = monomio;
    monomio = monomio->prox;
    free(limpar);
  }
}

int main() {
  Monomio *p1 = NULL;
  Monomio *p2 = NULL;
  Monomio *p3 = NULL;
  int grau = 0, coef = 0, escolha = 0;

  do {
    printf("--Operacoes com polinomios--\n1 - Adicao\n2 - Subtracao\n3 - Produto\n4 - Sair\n\nSua escolha: ");
    scanf("%d", &escolha);

    if (escolha != 4) {
      printf("\nInforme o grau do primeiro polinomio: ");
      scanf("%d", &grau);

      for(int i=0; i<=grau; i++) {
        printf("Informe o coeficiente do monomio com grau %d: ", i);
        scanf("%d", &coef);
        p1 = insereMonomio(p1, coef, i);
      }

      printf("\nInforme o grau do segundo polinomio: ");
      scanf("%d", &grau);

      for(int i=0; i<=grau; i++) {
        printf("Informe o coeficiente do monomio com grau %d: ", i);
        scanf("%d", &coef);
        p2 = insereMonomio(p2, coef, i);
      }
    }

    switch(escolha) {
      case 1:
        p3 = somaPolinomios(p1, p2);
        imprimePolinomio(p3);
        break;
      case 2:
        p3 = subtraiPolinomios(p1, p2);
        imprimePolinomio(p3);
        break;
      case 3:
        p3 = multiplicaPolinomios(p1, p2);
        imprimePolinomio(p3);
        break;
      case 4:
        break;
      default:
        printf("Opção inválida.");
    }

    // Liberando a memória alocada para os nós e setando null aos ponteiros
    limpaPolinomio(p3);
    p3 = NULL;
    limpaPolinomio(p2);
    p2 = NULL;
    limpaPolinomio(p1);
    p1 = NULL;

  } while(escolha != 4);

  return 0;
}
