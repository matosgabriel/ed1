/*
  Autor: Gabriel Alves Matos
  Matrícula: 2019108652

  Este arquivo: TADConjunto.h
  Breve descrição da biblioteca:
  Esta biblioteca implementa um tipo abstrato de dados chamado conjunto, que utiliza
  as funcionalidades de uma lista simplesmente encadeada.
*/

#ifndef __TADCONJUNTO_H__
#define __TADCONJUNTO_H__

// Inclusão de outras interfaces necessárias para entender esta interface.

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Elemento que é utilizada pela biblioteca.
typedef struct elemento {
  int chave;
  struct elemento *prox;
} Elemento;

// Protótipos das funções da biblioteca.

/*
  A função criaElemento recebe um número inteiro "valor" a ser atribuído ao campo "chave" do elemento a
  ser criado e retorna um ponteiro para o endereço de memória alocado se a alocação for bem
  sucedida ou NULL caso contrário.
*/
Elemento *criaElemento(int valor);

/*
  A função novaLista não recebe valores e retorna uma lista simplesmente encadeada com nó
  cabeça (um ponteiro de elemento que aponta para o endereço de memória alocado para o nó cabeça) se a
  alocação for bem sucedida ou NULL caso contrário.
*/
Elemento *novaLista();

/*
  A função buscaListaOrd recebe uma lista de elementos (ponteiro que aponta para o nó cabeça),
  um número inteiro "valor" a ser buscado e um ponteiro de ponteiro "pred" que indica o endereço
  de memória do elemento que seria o anterior ao elemento com chave igual ao valor passado por parâmetro.
  Esta função retorna um ponteiro que aponta para o endereço de memória que guarda o elemento com
  chave igual ao valor recebido por parâmetro ou o endereço de memória do elemento que seria posterior
  ao elemento buscado ou NULL caso "valor" seja maior que a chave de todos os elementos da lista.
*/
Elemento *buscaListaOrd (Elemento *L, int valor, Elemento **pred);

/*
  A função insereElemento recebe uma lista de elementos (ponteiro que aponta para o nó cabeça)
  e um número inteiro "valor" que é a chave do elemento a ser inserido de forma ordenada na lista.
  Não retorna valores pois a lista tem nó cabeça então o primeiro nó nunca será alterado. Caso não exista
  um nó com chave igual ao inteiro "valor" será inserido um elemento na lista com esta chave.
*/
void insereElemento (Elemento *L, int valor);

/*
  A função removeElemento recebe uma lista de elementos (ponteiro que aponta para o nó cabeça)
  e um número inteiro "valor" que é a chave do elemento a ser removido da lista. Não retorna valores pelo
  mesmo motivo da função anterior. Caso não exista um nó com chave igual ao inteiro "valor" este será
  removido da lista e a memória alocada para o nó será liberada.
*/
void removeElemento (Elemento *L, int valor);

/*
  A função esvaziaLista recebe uma lista de elementos (ponteiro que aponta para o nó cabeça)
  e não retorna valores. Esta função remove todos os elementos da lista exceto o nó da cabeça
  (utiliza a função removeElemento);
*/
void esvaziaLista (Elemento *L);

/*
  A função verificaListaVazia recebe uma lista de elementos (ponteiro que aponta para o nó cabeça)
  e retorna um valor inteiro, o valor retornado é 1 caso a lista seja vazia e 0 caso contrário. 
*/
int verificaListaVazia(Elemento *L);

/*
  A função verificaElementoLista recebe uma lista de elementos (ponteiro que aponta para o nó cabeça)
  e um inteiro "valor". Retorna um valor inteiro 1 ou 0 que correspondem, respectivamente, a
  o elemento existir na lista e o caso contrário. 
*/
int verificaElementoLista(Elemento *L, int valor);

/*
  A função verificaListaContida recebe duas listas de elementos (ponteiro que aponta para o nó cabeça)
  e retorna um inteiro. O valor retornado é 1 caso existam elementos com a chave igual à chave
  de todos os elementos da primeira lista na segunda lista (a primeira lista está contida na segunda)
  e 0 caso contrário (a primeria lista não está contida na segunda). 
*/
int verificaListaContida(Elemento *L1, Elemento *L2);

/*
  A função verificaListasIguais recebe duas listas de elementos (ponteiro que aponta para o nó cabeça)
  e retorna um inteiro. O valor retornado é 1 caso as listas sejam iguais e 0 caso contrário.
*/
int verificaListasIguais(Elemento *L1, Elemento *L2);

/*
  A função imprimeListaElementos recebe uma lista de elementos (ponteiro que aponta para o nó cabeça)
  e não retorna valores. Esta função imprime na tela os valores das chaves dos elementos existentes na lista.
*/
void imprimeListaElementos (Elemento *L);

/*
  A função uniaoListas recebe duas listas de elementos (ponteiro que aponta para o nó cabeça)
  e retorna uma nova lista de elementos que é a união entre os elementos das duas listas
  (lista com todos os elementos de ambas as listas sem repetições).
*/
Elemento *uniaoListas(Elemento *L1, Elemento *L2);

/*
  A função intersecaoListas recebe duas listas de elementos (ponteiro que aponta para o nó cabeça)
  e retorna uma nova lista de elementos que é a interseção entre os elementos das duas listas
  (lista com elementos com chaves presentes nas duas listas).
*/
Elemento *intersecaoListas(Elemento *L1, Elemento *L2);

/*
  A função complementoRelativoListas recebe duas listas de elementos (ponteiro que aponta para o nó cabeça)
  e retorna uma nova lista de elementos que é o complemento relativo da segunda lista em relação à primeira
  (lista com todos elementos da primeira lista exceto os que também existem na segunda lista).
*/
Elemento *complementoRelativoListas(Elemento *L1, Elemento *L2);

#endif