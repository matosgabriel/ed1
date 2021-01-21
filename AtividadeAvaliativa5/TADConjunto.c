// Nome: Gabriel Alves Matos

#include "TADConjunto.h"

/*
  A função criaElemento recebe um número inteiro "valor" a ser atribuído ao campo "chave" do elemento a
  ser criado e retorna um ponteiro para o endereço de memória alocado se a alocação for bem
  sucedida ou NULL caso contrário.
*/
Elemento *criaElemento (int valor) {
  // Criação de um novo nó de elemento.
  Elemento *novo = (Elemento *) calloc(1, sizeof(Elemento));
  
  // Se o valor de "novo" for NULL é printada um mensagem de erro, pois não foi possível alocar a memória.
  if (novo == NULL) {
    printf("ERRO: problemas com a alocacao de memoria.\n");
    exit(1); // Programa finalizado de maneira mal sucedida.
  }

  novo->chave = valor; // Atribuição do valor recebido por parâmetro ao campo "chave" do novo elemento.
  novo->prox = NULL; // Atribuição de NULL ao campo "prox" do novo elemento.
  return novo; // Retorno do novo elemento.
}

/*
  A função novaLista não recebe valores e retorna uma lista simplesmente encadeada com nó
  cabeça (um ponteiro de elemento que aponta para o endereço de memória alocado para o nó cabeça) se a
  alocação for bem sucedida ou NULL caso contrário.
*/
Elemento *novaLista() {
  // Criação de um novo nó de elemento (nó cabeça).
  Elemento *novo = (Elemento *) calloc(1, sizeof(Elemento));

  // Se o valor de "novo" for NULL é printada um mensagem de erro, pois não foi possível alocar a memória.
  if (!novo) {
    printf("ERRO: problemas com a alocacao de memoria.\n");
    exit(1);
  }
  novo->prox = NULL; // Atribuição de NULL ao campo "prox" do nó cabeça.

  return novo; // Retorno da nova lista (endereço de memória do nó cabeça). 
}

/*
  A função buscaListaOrd recebe uma lista de elementos (ponteiro que aponta para o nó cabeça),
  um número inteiro "valor" a ser buscado e um ponteiro de ponteiro "pred" que indica o endereço
  de memória do elemento que seria o anterior ao elemento com chave igual ao valor passado por parâmetro.
  Esta função retorna um ponteiro que aponta para o endereço de memória que guarda o elemento com
  chave igual ao valor recebido por parâmetro ou o endereço de memória do elemento que seria posterior
  ao elemento buscado ou NULL caso "valor" seja maior que a chave de todos os elementos da lista.
*/
Elemento *buscaListaOrd (Elemento *L, int valor, Elemento **pred) {
  /*
    Criação de um ponteiro auxiliar para percorrer os elementos da lista,
    recebe inicialmente o endereço de memória do primeiro elemento da lista.
  */
  Elemento *aux = L->prox;

  /*
    Atribuição do endereço de memória do nó cabeça ao valor guardado no endereço de
    memória apontado por "pred".
  */

  (*pred) = L;

  // Laço responsável por percorrer a lista de elementos.
  while (aux != NULL){
    /*
      Se o valor buscado for menor ou igual ao campo "chave" do elemento atual
      o laço é encerrado utilizando um break.
    */
    if (valor <= aux->chave) break;
    
    /*
      Atualização dos ponteiros. O valor guardado no endereço de memória apontado por "pred" será
      igual ao endereço de memória apontado por "aux" e o endereço de memória apontado por "aux" passará
      a ser o endereço do próximo elemento da lista.
    */
    
    (*pred) = aux;
    aux = aux->prox;
  }
  return aux; // Retorno do endereço de memória apontado por "aux";
}

/*
  A função insereElemento recebe uma lista de elementos (ponteiro que aponta para o nó cabeça)
  e um número inteiro "valor" que é a chave do elemento a ser inserido de forma ordenada na lista.
  Não retorna valores pois a lista tem nó cabeça então o primeiro nó nunca será alterado. Caso não exista
  um nó com chave igual ao inteiro "valor" será inserido um elemento na lista com esta chave.
*/
void insereElemento (Elemento *L, int valor) {
  // Criação de ponteiros auxiliares.
  Elemento *novo = criaElemento(valor); // "novo" recebe o novo elemento (nó) criado passando como parâmetro "valor".
  Elemento *pred = NULL; // Apontará para o endereço de memória do elemento que será o anterior do novo.
  Elemento *aux = buscaListaOrd(L, valor, &pred); // Atribuição do retorno da busca ao ponteiro "aux".

  /*
    Se não existe um elemento com a chave igual ao valor passado por parâmetro será inserido o novo
    elemento na lista passada por parâmetro.
  */
  
  if (!aux || (aux && aux->chave != valor)) {
    /*
      O campo "prox" do novo elemento (nó) será o resultado da busca. O campo "prox" do elemento (nó)
      anterior ao resultado da busca será o endereço do novo elemento.
    */
    novo->prox = aux;
    pred->prox = novo;
  }
}

/*
  A função removeElemento recebe uma lista de elementos (ponteiro que aponta para o nó cabeça)
  e um número inteiro "valor" que é a chave do elemento a ser removido da lista. Não retorna valores pelo
  mesmo motivo da função anterior. Caso não exista um nó com chave igual ao inteiro "valor" este será
  removido da lista e a memória alocada para o nó será liberada.
*/
void removeElemento (Elemento *L, int valor) {
  // Criação de ponteiros auxiliares.
  Elemento *aux = L->prox; // Atribuição do primeiro elemento da lista ao ponteiro "aux".
  Elemento *pred = NULL;

  aux = buscaListaOrd(L, valor, &pred); // Atribuição do resultado da busca ao ponteiro "aux".

  // Se existe um elemento com a chave igual ao valor passado por parâmetro este será removido da lista.
  if (aux && aux->chave == valor) {
    /*
      O campo "prox" do elemento (nó) anterior ao resultado da busca será o valor do campo "prox" do
      resultado da busca.
    */
    pred->prox = aux->prox;
    free(aux); // Liberação da memória alocada para o nó.
  }
}

/*
  A função esvaziaLista recebe uma lista de elementos (ponteiro que aponta para o nó cabeça)
  e não retorna valores. Esta função remove todos os elementos da lista exceto o nó da cabeça
  (utiliza a função removeElemento);
*/
void esvaziaLista (Elemento *L) {
  // Criação de ponteiros auxiliares.
  Elemento *removido = NULL; // Guarda o endereço de memória do nó a ser removido.
  Elemento *aux = L->prox; // Atribuição do primeiro elemento da lista a "aux".
  
  // Laço responsável por percorrer toda a lista de elementos.
  while(aux) {
    removido = aux; // Atribuição do endereço de memória do elemento atual ao ponteiro "removido".
    aux = aux->prox; // Atualização do ponteiro "aux" para apontar para o próximo elemento da lista.
    removeElemento(L, removido->chave); // É removido o elemento com chave igual a chave do elemento atual.
  }
}

/*
  A função verificaListaVazia recebe uma lista de elementos (ponteiro que aponta para o nó cabeça)
  e retorna um valor inteiro, o valor retornado é 1 caso a lista seja vazia e 0 caso contrário. 
*/
int verificaListaVazia(Elemento *L) {
  Elemento *aux = L->prox; // Atribuição do primeiro elemento da lista ao ponteiro auxiliar "aux".

  /*
    Se o valor do endereço de memória apontado por aux for NULL será retornado o inteiro 1 (lista vazia).
    Se não será retornado o inteiro 0 (lista não vazia);
  */
  if (!aux) {
    return 1;
  } else {
    return 0;
  }
}

/*
  A função verificaElementoLista recebe uma lista de elementos (ponteiro que aponta para o nó cabeça)
  e um inteiro "valor". Retorna um valor inteiro 1 ou 0 que correspondem, respectivamente, a
  o elemento existir na lista e o caso contrário. 
*/
int verificaElementoLista(Elemento *L, int valor) {
  // Criação de ponteiros auxiliares;
  Elemento *pred = NULL;
  Elemento *aux = buscaListaOrd(L, valor, &pred); // Atribuição da busca na lista pelo inteiro "valor" a "aux".

  /*
    Se existir um elemento com chave igual ao valor passado via parâmetro será retornado 1
    (elemento contido na lista).
    Se não será retornado 0 (elemento não contido na lista).
  */
  if (aux && aux->chave == valor) return 1;
  else return 0;
}

/*
  A função verificaListaContida recebe duas listas de elementos (ponteiro que aponta para o nó cabeça)
  e retorna um inteiro. O valor retornado é 1 caso existam elementos com a chave igual à chave
  de todos os elementos da primeira lista na segunda lista (a primeira lista está contida na segunda)
  e 0 caso contrário (a primeria lista não está contida na segunda). 
*/
int verificaListaContida(Elemento *L1, Elemento *L2) {
  // Criação de ponteiro/variável auxiliar.
  Elemento *aux1 = L1->prox; // Atribuição do endereço de memória do primeiro elemento da primeira lista a "aux".
  int contido = 1; // Supõe-se inicialmente que a primeira lista está contida na segunda atribuindo 1 a "contido".

  // Laço responsável por percorrer toda a lista de elementos.
  while(aux1) {
    // Se não existe um elemento com chave igual à chave do elemento atual na segunda lista "contido" recebe 0.
    if (verificaElementoLista(L2, aux1->chave) == 0) contido = 0;
    aux1 = aux1->prox; // Atualização do ponteiro "aux" para apontar para o próximo elemento (nó).
  }

  return contido; // Retorno do valor de "contido".
}

/*
  A função verificaListasIguais recebe duas listas de elementos (ponteiro que aponta para o nó cabeça)
  e retorna um inteiro. O valor retornado é 1 caso as listas sejam iguais e 0 caso contrário.
*/
int verificaListasIguais(Elemento *L1, Elemento *L2) {
  /*
    Se as listas estão contidas uma na outra (as listas são iguais) é retornado 1;
    Se não é retornado 0;
  */
  if (verificaListaContida(L1, L2) == 1 && verificaListaContida(L2, L1) == 1) {
    return 1;
  } else {
    return 0;
  }
}

/*
  A função imprimeListaElementos recebe uma lista de elementos (ponteiro que aponta para o nó cabeça)
  e não retorna valores. Esta função imprime na tela os valores das chaves dos elementos existentes na lista.
*/
void imprimeListaElementos (Elemento *L) {
  // Atribuição do endereço de memória do primeiro elemento da lista ao ponteiro auxiliar "aux".
  Elemento *aux = L->prox;
  
  // Se a lista é vazia será impressa uma mensagem informando que ela é vazia.
  if (verificaListaVazia(L)) {
    printf("vazio!");
  }
  
  // Laço responsável por percorrer toda a lista de elementos.
  while (aux){
    printf("%d ",aux->chave); // Impressão do campo "chave" do elemento.
    aux = aux->prox; // Atualização do ponteiro "aux" para apontar para o próximo elemento (nó).
  }
  printf("\n");
}

/*
  A função uniaoListas recebe duas listas de elementos (ponteiro que aponta para o nó cabeça)
  e retorna uma nova lista de elementos que é a união entre os elementos das duas listas
  (lista com todos os elementos de ambas as listas sem repetições).
*/
Elemento *uniaoListas(Elemento *L1, Elemento *L2) {
  Elemento *nova = novaLista(); // Nova lista de elementos (receberá o resultado da união).

  /*
    Criação de ponteiros auxiliares e atribuição do endereço de memória do primeiro elemento de cada lista ao
    seu respectivo ponteiro auxiliar.
  */
  Elemento *aux1 = L1->prox; // Ponteiro auxiliar para a primeira lista.
  Elemento *aux2 = L2->prox; // Ponteiro auxiliar para a segunda lista.

  // Laço responsável por percorrer toda a primeira lista de elementos.
  while(aux1) {
    insereElemento(nova, aux1->chave); // Inserção do elemento atual na nova lista de elementos.
    aux1 = aux1->prox; // Atualização do ponteiro "aux1" para apontar para o próximo elemento (nó).
  }

  // Laço responsável por percorrer toda a segunda lista de elementos.
  while(aux2) {
    insereElemento(nova, aux2->chave); // Inserção do elemento atual na nova lista de elementos.
    aux2 = aux2->prox; // Atualização do ponteiro "aux2" para apontar para o próximo elemento (nó).
  }

  return nova; // Retorno da nova lista de elementos (endereço de memória do nó cabeça).
}

/*
  A função intersecaoListas recebe duas listas de elementos (ponteiro que aponta para o nó cabeça)
  e retorna uma nova lista de elementos que é a interseção entre os elementos das duas listas
  (lista com elementos com chaves presentes nas duas listas).
*/
Elemento *intersecaoListas(Elemento *L1, Elemento *L2) {
  Elemento *nova = novaLista(); // Nova lista de elementos (receberá o resultado da união).
  
  // Ponteiro auxiliar da primeira lista de elementos, recebe o endereço de memória do primeiro elemento.
  Elemento *aux1 = L1->prox; // Criação de ponteiro "aux1" que apontará para o primeiro elemento da primeira lista.

  Elemento *aux = NULL; // Criação de ponteiro auxiliar "aux" que receberá o retorno da busca.
  Elemento *pred = NULL; // Criação de ponteiro auxiliar "pred" para a busca.

  // Laço responsável por percorrer toda a primeira lista.
  while(aux1) {
    /*
      Ponteiro "aux" recebe o resultado da busca de um elemento com chave igual à chave do elemento atual
      da primeira lista na segunda lista.
    */
    aux = buscaListaOrd(L2, aux1->chave, &pred);

    // Se o elemento atual da primeira lista existir na segunda lista este será inserido na lista resultante.
    if (aux && aux->chave == aux1->chave) {
      insereElemento(nova, aux1->chave); // Inserção do elemento na lista resultante "nova";
    }

    aux1 = aux1->prox; // Atualização do ponteiro "aux1" para apontar para o próximo elemento (nó).
  }

  return nova; // Retorno da nova lista de elementos (endereço de memória do nó cabeça).
}

/*
  A função complementoRelativoListas recebe duas listas de elementos (ponteiro que aponta para o nó cabeça)
  e retorna uma nova lista de elementos que é o complemento relativo da segunda lista em relação à primeira
  (lista com todos elementos da primeira lista exceto os que também existem na segunda lista).
*/
Elemento *complementoRelativoListas(Elemento *L1, Elemento *L2) {
  // Criação de ponteiros auxiliares.
  Elemento *nova = novaLista(); // Nova lista de elementos (receberá o resultado do complemento relativo).
  Elemento *aux1 = L1->prox; // Criação de ponteiro "aux1" que apontará para o primeiro elemento da primeira lista.

  Elemento *aux = NULL; // Criação de ponteiro auxiliar "aux" que receberá o retorno da busca.
  Elemento *pred = NULL; // Criação de ponteiro auxiliar "pred" para a busca.

  // Laço responsável por percorrer toda a primeira lista de elementos.
  while(aux1) {
    /*
      Ponteiro "aux" recebe o resultado da busca de um elemento com chave igual à chave do elemento atual
      da primeira lista na segunda lista.
    */
    aux = buscaListaOrd(L2, aux1->chave, &pred);

    // Se o elemento não existir no conjunto B ele será inserido na lista resultante "nova".
    if (!aux || (aux && aux->chave != aux1->chave)) {
      insereElemento(nova, aux1->chave); // Inserção do elemento na lista resultante.
    }
    aux1 = aux1->prox; // Atualização do ponteiro "aux1" para apontar para o próximo elemento (nó).
  }

  return nova; // Retorno da nova lista de elementos (endereço de memória do nó cabeça).
}