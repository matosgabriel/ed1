// Nome: Gabriel Alves Matos

#include "ABB.h"
#include <string.h>

// Criação da estrutura Pessoa.
typedef struct pessoa {
  int id;
  int idade;
  char nome[100];
} Pessoa;

/*
  A função comparaId recebe dois ponteiros que apontam para um valor genérico. É feito o casting dos dois ponteiros
  para dois ponteiros do tipo Pessoa. Retorna 1 caso o id da primeira pessoa seja maior que o da segunda, 0 caso os
  ids sejam iguais e -1 caso o id da primeira pessoa seja menor que o da segunda.
*/
int comparaId(void *info1, void *info2) {
  // Criação dos ponteiros do tipo Pessoa que recebem o casting dos ponteiros do tipo void recebidos por parâmetro.
  Pessoa *aux1 = (Pessoa *) info1;
  Pessoa *aux2 = (Pessoa *) info2;

  /*
    Se o id da primeira pessoa for maior que o da segunda é retornado 1. Se não se o id da primeira pessoa for menor
    que o da segunda é retornado -1. Se não (os ids forem iguais) é retornado 0.
  */
  if (aux1->id > aux2->id) return 1;
  else if (aux1->id < aux2->id) return -1;
  else return 0;
}

/*
  A função imprimePessoa recebe um ponteiro que aponta para um valor genérico. É feito o casting do ponteiro
  para um ponteiro do tipo Pessoa. É impresso o id da pessoa. Não há retorno.
*/
void imprimePessoa(void *info) {
  // Criação do ponteiro do tipo Pessoa que recebe o casting do ponteiro do tipo void recebido por parâmetro.
  Pessoa *aux = (Pessoa *) info;
  
  printf("Id %d\n", aux->id);
}

/*
  A função imprimeDadosPessoa recebe um ponteiro que aponta para um valor genérico. É feito o casting do ponteiro
  para um ponteiro do tipo Pessoa. São impressas as informações da pessoa. Não há retorno.
*/
void imprimeDadosPessoa(void *pessoa) {
  // Criação do ponteiro do tipo Pessoa que recebe o casting do ponteiro do tipo void recebido por parâmetro.
  Pessoa *pessoaResultado = (Pessoa *) pessoa;

  printf("\n\tDados: ");
  printf("\nId: %d", pessoaResultado->id);
  printf("\nNome: %s", pessoaResultado->nome);
  printf("\nIdade: %d anos\n", pessoaResultado->idade);
}

/*
  A função liberaPessoa recebe um ponteiro que aponta para um valor genérico. É feito o casting do ponteiro
  para um ponteiro do tipo Pessoa. É liberada a memória alocada para o nó. Não há retorno.
*/
void liberaPessoa(void *info) {
  // Criação do ponteiro do tipo Pessoa que recebe o casting do ponteiro do tipo void recebido por parâmetro.
  Pessoa *pessoa = (Pessoa *) info;
  free(pessoa); // Liberação da memória alocada para o nó.
}

int main() {
  // Criação de variáveis auxiliares.
  int op = 0, num = 0, idade = 0;
  char nome[100], enter;

  Node *T = NULL; // Criação de uma nova árvore.

  // Laço de repetição responsável por repetir o menu até o usuário escolher sair.
  do {
    printf("\tMenu\n");
    printf("1 - Inserir de uma pessoa.\n");
    printf("2 - Buscar uma pessoa.\n");
    printf("3 - Excluir uma pessoa.\n");
    printf("4 - Imprimir a árvore.\n");
    printf("5 - Sair\n\n");
    printf("Escolha: ");
    scanf("%d", &op);

    // Estrutura condicional responsável por realizar a operação de acordo com a escolha do usuário.
    switch (op){
    case 1:
      printf("Informe o id da nova pessoa: ");
      scanf("%d", &num);
      printf("Informe a idade da nova pessoa: ");
      scanf("%d", &idade);
      printf("Informe o nome da nova pessoa (até 100 caracteres): ");
      scanf("%c", &enter);
      scanf("%[^\n]", nome);
      scanf("%c", &enter);

      // Criação de novo nó do tipo Pessoa.
      Pessoa *novaPessoa = (Pessoa *) calloc(1, sizeof(Pessoa));
      // Atribuição dos valores lidos aos campos da nova pessoa.
      novaPessoa->id = num;
      strcpy(novaPessoa->nome, nome);
      novaPessoa->idade = idade;

      /*
        Se existe uma pessoa na árvore com id informado é liberada a memória alocada para
        o nó e impressa uma mensagem de erro.
        Se não é inserido o novo nó na árvore e impressa uma mensagem de informação.
      */
      if (buscaArvore(T, novaPessoa, comparaId)) {
        free(novaPessoa);
        printf("\nJa existe uma pessoa cadastrada com este id!");
      } else {
        // Inserção da nova pessoa utilizando a função insereNaArvore.
        T = insereNaArvore(T, novaPessoa, comparaId);
        printf("\nPessoa inserida com sucesso na arvore!");
      }
      printf("\n\n");
      break;
    case 2:
      printf("Informe o id da pessoa a ser buscada: ");
      scanf("%d", &num);

      Pessoa pessoa1; // Criação de uma nova variável do tipo pessoa.
      pessoa1.id = num; // Atribuição do id lido ao campo "id" da nova pessoa.
      
      /*
        Se existe uma pessoa na árvore com id igual ao lido são impressas as informações desta.
        Se não é impressa uma mensagem de erro.
      */
      if (buscaArvore(T, &pessoa1, comparaId)) {
        // Impressão das informações da pessoa utilizando a função imprimeNode.
        imprimeNode(T, &pessoa1, comparaId, imprimeDadosPessoa);
      } else {
        printf("\nNao existe uma pessoa com este id na arvore!\n");
      }
      printf("\n");
      break;
    case 3:
      printf("Informe o id da pessoa a ser removida: ");
      scanf("%d", &num);

      Pessoa pessoa2; // Criação de uma nova variável do tipo pessoa.
      pessoa2.id = num; // Atribuição do id lido ao campo "id" da nova pessoa.

      /*
        Se existe uma pessoa na árvore com id igual ao id lido o nó é removido.
        Se não é impressa uma mensagem de erro.
      */
      if (buscaArvore(T, &pessoa2, comparaId)) {
        // Remoção do nó da árvore utilizando a função removeDaArvore.
        T = removeDaArvore(T, &pessoa2, comparaId, liberaPessoa);
        printf("\nPessoa removida com sucesso!\n");
      } else {
        printf("\nNao existe uma pessoa com este id na arvore!\n");
      }
      
      printf("\n");
      break;
    case 4:
      printf("\n\tArvore:\n");
      
      /*
        Se "T" for NULL é impressa uma mensagem informando que a árvore é vazia.
        Se não é impressa a árvore.
      */
      if (!T) printf("\n\tVazia!\n");
      else imprimeArvore(T, 1, imprimePessoa); // Impressão da árvore utilizando a função imprimeArvore.
      printf("\n");
      break;
    case 5: break;
    default:
      break; // Usuário escolheu sair. Nada é feito.
    }
  } while(op != 5);
  
  // Liberação da memória alocada para os nós da árvore.
  liberaArvore(T, liberaPessoa);

  return 0; // Retorno de 0 indicando o fim do programa com êxito.
}