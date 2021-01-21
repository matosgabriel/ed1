// Nome: Gabriel Alves Matos

#include "ABB.h"

/*
  A função criaNode recebe um ponteiro que aponta para um valor genérico "info" a ser atribuído
  ao campo "info" do nó (node) a ser criado e retorna um ponteiro para o endereço de memória alocado se
  a alocação for bem sucedida ou NULL caso contrário.
*/
Node *criaNode(void *info) {
  // Ponteiro "novo" recebe a criação de um novo nó.
  Node *novo = (Node *) calloc(1, sizeof(Node));

  /*
    Se "novo" é igual a NULL houve um erro na alocação da memória, então é impressa uma
    mensagem de erro e o programa é encerrado sem êxito. 
  */
  if (!novo) {
    printf("Erro ao alocar memória!\n");
    exit(1);
  }
  // O campo "info" do novo nó recebe o valor genérico "info" recebido por parâmetro.
  novo->info = info;
  return novo; // Retorno do endereço de memória do novo nó.
}

/*
  A função buscaArvore recebe um ponteiro que aponta para o endereço de memória do nó raiz da árvore "T",
  um ponteiro que aponta para um valor genérico "valor" a ser buscado na árvore e uma função de callback "compara" que
  é uma função de comparação entre dois valores genéricos implementada pelo cliente da biblioteca, esta deve retornar
  1 caso o primeiro parâmetro seja "maior" que o segundo, 0 caso estes sejam "iguais" e -1 caso o segundo seja "maior"
  que o primeiro (o critério de comparação é decidido pelo cliente). A função buscaArvore retorna um ponteiro que aponta
  para um endereço de memória de um nó (node) cujo campo "info" é "igual" a "valor" ou NULL caso este não exista na árvore.
*/
Node *buscaArvore(Node *T, void *valor, int (*compara) (void *, void *)) {
  /*
    Se o valor não for encontrado é retornado NULL.
    Se não, se o valor for encontrado é retornado o nó da árvore.
    Se não, se o campo "info" do nó for "menor" que "valor" a função é chamada recursivamente
    passando como árvore a subárvore à direita.
    Se não (o campo "info" do nó for "maior" que "valor") a função é chamada recursivamente
    passando como árvore a subárvore à esquerda.
  */
  if (!T) return NULL;
  if (compara(T->info, valor) == 0) return T;
  if (compara(T->info, valor) < 0) return buscaArvore(T->dir, valor, compara);
  else return buscaArvore(T->esq, valor, compara);
}

/*
  A função insereNaArvore recebe um ponteiro que aponta para o endereço de memória do nó raiz da árvore "T",
  um ponteiro que aponta para um valor genérico "valor" a ser inserido na árvore e uma função de callback "compara" que
  é uma função de comparação entre dois valores genéricos implementada pelo cliente da biblioteca, esta deve retornar
  1 caso o primeiro parâmetro seja "maior" que o segundo, 0 caso estes sejam "iguais" e -1 caso o segundo seja "maior"
  que o primeiro (o critério de comparação é decidido pelo cliente). A função insereNaArvore retorna um ponteiro que aponta
  para o endereço de memória do nó (node) raiz.
*/
Node *insereNaArvore(Node *T, void *valor, int (*compara) (void *, void *)) {
  /*
    Criação de ponteiros auxiliares, "pai" apontará para o nó pai do que deve ser removido e "aux" apontará
    para o endereço de memória do nó a ser removido.
  */
  Node *pai = NULL, *aux = T;

  Node *novo = criaNode(valor); // Criação de um novo nó usando a função criaNode.

  // Se a árvore for vazia será retornado o endereço de memória do novo nó criado (nova raíz).
  if (!T) return novo;
  
  /*
    Laço responsável por percorrer um caminho na árvore até ser encontrado um nó com campo "info" "igual" a "valor"
    ou até chegar em NULL (não existe na árvore).
  */
  while(aux) {
    /*
      Se o campo "info" do nó atual for "igual" que o valor genérico "valor" o endereço de memória alocado para o novo
      nó é liberado e é retornado o endereço de memória da raiz da árvore. Se não segue a tratativa para decidir a nova
      direção de busca.
    */
    if (compara(aux->info, valor) == 0) {
      free(novo);
      return T;
    } else {
      // "pai" recebe o valor de "aux".
      pai = aux;
      
      /*
        Se o campo "info" do nó atual for "maior" que o valor genérico "valor" então "aux" recebe o endereço da subárvore à
        esquerda do nó atual. Se não "aux" recebe o endereço da subárvore à direita do nó atual
      */
      if (compara(aux->info, valor) > 0) aux = aux->esq;
      else aux = aux->dir;
    }
  }

  /*
    Se o campo "info" do pai for "maior" que o valor genérico recebido por parâmetro o campo "esq" do pai receberá o endereço
    de memória do novo nó criado. Se não, (o campo "info" do pai é "menor" que o valor genérico recebido por parâmetro) então
    o campo "esq" do pai receberá o endereço de memória do novo nó criado.
  */
  if (compara(pai->info, valor) > 0) pai->esq = novo;
  else pai->dir = novo;

  return T; // Retorno do endereço de memória da raiz da árvore.
}

/*
  A função imprimeArvore recebe um ponteiro "T" que aponta para para o endereço de memória do nó raiz da árvore,
  um inteiro "nivel" que representa o nível do nó (sempre receberá 1 na chamada da função) e uma função de callback
  "imprime" que é uma função de impressão de uma chave dos valores genéricos implementada pelo cliente da biblioteca.
  A função imprimeArvore é responsável por imprimir uma árvore, percorrendo ela e utilizando a função de callback "imprime"
  para imprimir a identificação de cada nó. Não há retorno de valores. 
*/
void imprimeArvore(Node *T, int nivel, void (*imprime) (void *)) {
  // Se "T" for diferente de NULL (árvore não vazia) serão impressos os nós da árvore.
  if (T) {
    // Laço responsável por imprimir uma quantidade de "tabs" para cada nível dos nós na árvore.
    for(int i=0; i<nivel-1; i++) {
      printf("\t");
    }
    // Utilização da função de callback "imprime" para imprimir o identificador do campo "info" do nó atual.
    imprime(T->info);

    // Chamada recursiva da função para imprimir os nós das subárvores do nó atual.
    imprimeArvore(T->esq, nivel+1, imprime);
    imprimeArvore(T->dir, nivel+1, imprime);
  }
}

/*
  A função imprimeNode recebe um ponteiro "T" que aponta para para o endereço de memória do nó raiz da árvore,
  um ponteiro "valor" que aponta para um valor genérico a ser impresso e uma função de callback "compara" que é uma função de comparação
  entre dois valores genéricos implementada pelo cliente da biblioteca, esta deve retornar 1 caso o primeiro parâmetro seja "maior"
  que o segundo, 0 caso estes sejam "iguais" e -1 caso o segundo seja "maior" que o primeiro (o critério de comparação é decidido
  pelo cliente) e uma função de callback "imprimeDados" que é uma função de impressão de um valor genérico implementado
  pelo cliente da biblioteca. A função imprimeNode é responsável por buscar na árvore um nó cujo campo "info" seja "igual" ao
  valor genérico "valor" recebido por parâmetro e utilizar a função "imprimeDados" passando como parâmetro o resultado da busca caso este
  diferente de NULL. Não retorna valores. 
*/
void imprimeNode(Node *T, void *valor, int (*compara)(void *, void *), void (*imprimeDados)(void *)) {
  // Ponteiro "resultado" receberá o resultado da busca de "valor" na árvore "T".
  Node *resultado = buscaArvore(T, valor, compara);

  /*
    Se o resultado da busca for diferente de NULL será utilizada a função imprimeDados para imprimir
    o valor genérico armazenado no campo "info" do nó.
  */
  if (resultado)
    imprimeDados(resultado->info);
}

void liberaNode(Node *node, void (*liberaInfo) (void *)) {
  // Liberação da memória alocada para o campo "info" do nó utilizando a função de callback "liberaInfo".
  liberaInfo(node->info);
  free(node); // Liberação da memória alocada para o nó.
}

/*
  A função liberaArvore recebe um ponteiro que aponta para para o endereço de memória do nó raiz da árvore "T" e uma
  função de callback "libera" que é uma função que libera os espaços de memória alocados para os valores do tipo
  genérico implementado pelo cliente da biblioteca. A função liberaArvore é responsável por liberar os espaços de
  memória alocados para os nós de uma árvore, percorrendo ela e utilizando a função de callback "libera"
  para liberar os espaços de memória alocados para os campos "info" dos nós e posteriormente fazendo a liberação do espaço de
  memória alocado para o nó (node). Não há retorno de valores.
*/
void liberaArvore(Node *T, void (*liberaInfo) (void *)) {
  // Se "T" for diferente de NULL (árvore não vazia) será liberada a memória alocada para os nós da árvore.
  if (T) {
    // Chamada recursiva da função para a liberação das subárvores do nó atual.
    liberaArvore(T->dir, liberaInfo);
    liberaArvore(T->esq, liberaInfo);
    liberaNode(T, liberaInfo); // Chamada da função liberaNode para liberar a memória alocada para o nó atual.
  }
}

/*
  A função removeDaArvore recebe um ponteiro "T" que aponta para o endereço de memória do nó raiz da árvore,
  um ponteiro "valor" que aponta para um valor genérico a ser removido, uma função de callback "compara" que é uma função de comparação
  entre dois valores genéricos implementada pelo cliente da biblioteca, esta deve retornar 1 caso o primeiro parâmetro seja "maior"
  que o segundo, 0 caso estes sejam "iguais" e -1 caso o segundo seja "maior" que o primeiro (o critério de comparação é decidido
  pelo cliente) e uma função de callback "libera" que é uma função que libera os espaços de memória alocados para os valores do tipo
  genérico implementado pelo cliente da biblioteca. A função removeDaArvore é responsável por remover da árvore um nó com o
  campo "info" "igual" ao valor genérico "valor" recebido por parâmetro. Retorna um ponteiro que aponta para o endereço de memória da
  raiz da árvore agora com o nó removido caso exista nó com campo "info" "igual" a "valor" na árvore.
*/
Node *removeDaArvore(Node *T, void *valor, int (*compara) (void *, void *), void (*liberaInfo)(void *)) {
  /*
    Criação de ponteiros auxiliares, "pai" apontará para o nó pai do que deve ser removido e "aux" apontará
    para o endereço de memória do nó a ser removido.
  */
  Node *pai = NULL, *aux = T;

  // Se a árvore for vazia será retornado NULL.
  if (T == NULL) return NULL;

  /*
    Laço responsável por percorrer um caminho na árvore até ser encontrado um nó com campo "info" "igual" a "valor"
    ou até chegar em NULL (não existe na árvore um nó com campo "info" "igual" a "valor").
  */
  while(aux) {
    /*
      Se o campo "info" do nó atual for "igual" ao valor genérico "valor" o laço é encerrado com break. Se não segue
      a tratativa para decidir a nova direção de busca.
    */
    if (compara(aux->info, valor) == 0) {
      break;
    } else {
      // "pai" recebe o valor de "aux".
      pai = aux;
      
      /*
        Se o campo "info" do nó atual for "maior" que o valor genérico "valor" então "aux" recebe o endereço da subárvore à
        esquerda do nó atual. Se não (o campo "info" do nó atual é "menor" que o valor genérico "valor") então "aux" recebe o
        endereço da subárvore à direita do nó atual.
      */
      if (compara(aux->info, valor) > 0) aux = aux->esq;
      else aux = aux->dir;
    }
  }

  /*
    Se "aux" for igual a NULL (não existe um nó com o campo "info" "igual" a "valor") então é retornado o endereço da raiz
    da árvore. Se não se a árvore não possui subárvores segue a tratativa para remover o nó. Se não se a árvore possui
    somente a subárvore à direita segue a tratativa para remover o nó. Se não se a árvore possui somente a subárvore à
    esquerda segue a tratativa para remover o nó. Se não (a árvore tiver as duas subárvores) segue a tratativa para
    remover o nó.
  */
  if (!aux) {
    return T; // Retorno do endereço de memória da raiz da árvore.
  } else if (aux && (aux->dir == NULL && aux->esq == NULL)) {
    /*
      Se "pai" for igual a NULL então o nó a ser removido é a raiz da árvore, então é liberada a memória alocada
      para o nó e retornado NULL.
      Se não se o campo "info" do pai for "maior" que o campo "info" do nó a ser removido então o campo "dir" 
      (subárvore à direita) do pai receberá NULL. Se não (o campo "info" do pai é "menor" que o campo "info"
      do nó a ser removido) então o campo "esq" (subárvore à esquerda) do pai receberá NULL.
    */
    if (!pai) {
      liberaNode(aux, liberaInfo); // Liberação da memória alocada para o nó removido.
      return NULL;
    } else if (compara(pai->info, aux->info) < 0)
      pai->dir = NULL;
    else
      pai->esq = NULL;

    liberaNode(aux, liberaInfo); // Liberação da memória alocada para o nó removido.
  } else if (aux && (aux->dir != NULL && aux->esq == NULL)) {
    /*
      Se "pai" for NULL (raiz da árvore) é liberada a memória alocada para o nó e retornado o campo "dir" do nó a ser removido.
      Se não se o campo "info" do pai for "menor" que o campo "info" do nó a ser removido então o campo "dir" do pai recebe o
      campo "dir" do nó a ser removido. Se não (o campo "info" do pai é "maior" que o campo "info" do nó a ser removido) então o
      campo "esq" do pai recebe o campo "dir" do nó a ser removido.
    */
    if (!pai) {
      liberaNode(aux, liberaInfo); // Liberação da memória alocada para o nó removido.
      return aux->dir;
    } else if (compara(pai->info, aux->info) < 0)
      pai->dir = aux->dir;
    else 
      pai->esq = aux->dir;

    liberaNode(aux, liberaInfo); // Liberação da memória alocada para o nó removido.
    
  } else if (aux && (aux->dir == NULL && aux->esq != NULL)) {
    /*
      Se "pai" for NULL (raiz da árvore) é liberada a memória alocada para o nó e retornado o campo "esq" do nó a ser removido.
      Se não se o campo "info" do pai for "menor" que o campo "info" do nó a ser removido então o campo "dir" do pai recebe o
      campo "esq" do nó a ser removido. Se não (o campo "info" do pai é "maior" que o campo "info" do nó a ser removido) então
      o campo "esq" do pai recebe o campo "esq" do nó a ser removido.
    */
    if (!pai) {
      liberaNode(aux, liberaInfo); // Liberação da memória alocada para o nó removido.
      return aux->esq;
    } else if (compara(pai->info, aux->info) < 0)
      pai->dir = aux->esq;
    else 
      pai->esq = aux->esq;

    liberaNode(aux, liberaInfo); // Liberação da memória alocada para o nó removido.
  } else {
    /*
      Criação de ponteiros auxiliares. "predecessor" apontará para o endereço de memória do nó cujo campo "info" tem
      identificador maior entre os menores em relação ao identificador do campo "info" do nó a ser removido e recebe
      inicialmente o endereço de memória da raiz da subárvore à esquerda do nó a ser removido.
    */
    Node *predecessor = aux->esq;
    void *auxiliarPredecessor;

    // Laço responsável por chegar ao predecessor, percorrendo o máximo possível a subárvore à direita.
    while(predecessor->dir)
      predecessor = predecessor->dir;
    
    // "auxiliarPredecessor" receberá o campo "info" do nó a ser removido.
    auxiliarPredecessor = aux->info;
    // O campo "info" do nó a ser removido receberá o campo "info" do nó predecessor.
    aux->info = predecessor->info;
    // O campo "info" do nó predecessor receberá o valor de "auxiliarPredecessor" (campo "info" do nó a ser removido).
    predecessor->info = auxiliarPredecessor;

    /*
      O campo "esq" do nó a ser removido receberá o retorno da chamada recursiva da função passando como parâmetros a
      subárvore à esquerda do nó a ser removido, o campo "info" do nó predecessor e as funções de callback.
    */
    aux->esq = removeDaArvore(aux->esq, predecessor->info, compara, liberaInfo);
  }

  return T; // Retorno do endereço de memória da raiz da árvore.
}