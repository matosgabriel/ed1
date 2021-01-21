/*
  Nome: Gabriel Alves Matos
  Matrícula: 2019108652
*/

#ifndef __ABB_H__
#define __ABB_H__

// Criação da estrutura Node que é utilizada pela biblioteca para representar os nós da árvore.
typedef struct node {
  void *info;
  struct node *dir, *esq;
} Node;

// Inclusão de outras interfaces necessárias para entender esta interface.

#include <stdio.h>
#include <stdlib.h>

// Protótipos das funções da biblioteca.

/*
  A função criaNode recebe um ponteiro que aponta para um valor genérico "info" a ser atribuído
  ao campo "info" do nó (node) a ser criado e retorna um ponteiro para o endereço de memória alocado se
  a alocação for bem sucedida ou NULL caso contrário.
*/
Node *criaNode(void *info);

/*
  A função buscaArvore recebe um ponteiro que aponta para o endereço de memória do nó raiz da árvore "T",
  um ponteiro que aponta para um valor genérico "valor" a ser buscado na árvore e uma função de callback "compara" que
  é uma função de comparação entre dois valores genéricos implementada pelo cliente da biblioteca, esta deve retornar
  1 caso o primeiro parâmetro seja "maior" que o segundo, 0 caso estes sejam "iguais" e -1 caso o segundo seja "maior"
  que o primeiro (o critério de comparação é decidido pelo cliente). A função buscaArvore retorna um ponteiro que aponta
  para um endereço de memória de um nó (node) cujo campo "info" é "igual" a "valor" ou NULL caso este não exista na árvore.
*/
Node *buscaArvore(Node *T, void *valor, int (*compara) (void *, void *));

/*
  A função insereNaArvore recebe um ponteiro que aponta para o endereço de memória do nó raiz da árvore "T",
  um ponteiro que aponta para um valor genérico "valor" a ser inserido na árvore e uma função de callback "compara" que
  é uma função de comparação entre dois valores genéricos implementada pelo cliente da biblioteca, esta deve retornar
  1 caso o primeiro parâmetro seja "maior" que o segundo, 0 caso estes sejam "iguais" e -1 caso o segundo seja "maior"
  que o primeiro (o critério de comparação é decidido pelo cliente). A função insereNaArvore retorna um ponteiro que aponta
  para o endereço de memória do nó (node) raiz.
*/
Node *insereNaArvore(Node *T, void *valor, int (*compara) (void *, void *));

/*
  A função imprimeArvore recebe um ponteiro "T" que aponta para para o endereço de memória do nó raiz da árvore,
  um inteiro "nivel" que representa o nível do nó (sempre receberá 1 na chamada da função) e uma função de callback
  "imprime" que é uma função de impressão de uma chave dos valores genéricos implementada pelo cliente da biblioteca.
  A função imprimeArvore é responsável por imprimir uma árvore, percorrendo ela e utilizando a função de callback "imprime"
  para imprimir a identificação de cada nó. Não há retorno de valores. 
*/
void imprimeArvore(Node *T, int nivel, void (*imprime) (void *));

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
void imprimeNode(Node *T, void *valor, int (*compara)(void *, void *), void (*imprimeDados)(void *));

/*
  A função liberaArvore recebe um ponteiro que aponta para para o endereço de memória do nó raiz da árvore "T" e uma
  função de callback "libera" que é uma função que libera os espaços de memória alocados para os valores do tipo
  genérico implementado pelo cliente da biblioteca. A função liberaArvore é responsável por liberar os espaços de
  memória alocados para os nós de uma árvore, percorrendo ela e utilizando a função de callback "libera"
  para liberar os espaços de memória alocados para os campos "info" dos nós e posteriormente fazendo a liberação do espaço de
  memória alocado para o nó (node). Não há retorno de valores.
*/
void liberaArvore(Node *T, void (*libera) (void *));

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
Node *removeDaArvore(Node *T, void *valor, int (*compara) (void *, void *), void (*libera)(void *));

#endif