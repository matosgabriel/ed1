//Nome: Gabriel Alves Matos

#include "TADConjunto.h"

// Criação da estrutura conjunto.
typedef struct conjunto {
  int id;
  Elemento *elementos;
  struct conjunto *prox;

} Conjunto;

/*
  A função criaConjunto recebe um valor inteiro (id) a ser atribuído ao campo "id" do conjunto a
  ser criado e retorna um ponteiro que aponta para o endereço de memória alocado se a alocação for bem
  sucedida ou NULL caso contrário.
*/
Conjunto *criaConjunto(int id) {
  // Criação de um novo nó de conjunto.
  Conjunto *novo = (Conjunto *) calloc(1, sizeof(Conjunto));
  
  // Se o valor de novo for NULL é printada um mensagem de erro, pois não foi possível alocar a memória.
  if (novo == NULL) {
    printf("ERRO: problemas com a alocacao de memoria.\n");
    exit(1);
  }

  // Atribuição de uma nova lista de elementos ao campo de lista de elementos do novo conjunto.
  novo->elementos = novaLista();
  novo->id = id; // Atribuição do id recebido via parâmetro ao campo "id" do novo conjunto.
  novo->prox = NULL; // Atribuição de NULL ao campo "prox" do novo conjunto.

  return novo; // Retorno do novo conjunto.
}

/*
  A função novaListaConjuntos não recebe valores e retorna uma lista simplesmente encadeada com nó
  cabeça (um ponteiro de conjunto que aponta para o endereço de memória alocado para o nó cabeça) se a
  alocação for bem sucedida ou NULL caso contrário.
*/
Conjunto *novaListaConjuntos() {
  // Criação de um novo nó de conjunto (nó cabeça).
  Conjunto *novo = (Conjunto *) calloc(1, sizeof(Conjunto));
  
  // Se o valor de novo for NULL é printada um mensagem de erro, pois não foi possível alocar a memória.
  if (novo == NULL) {
    printf("ERRO: problemas com a alocacao de memoria.\n");
    exit(1); // Término do programa sem êxito.
  }

  novo->prox = NULL; // Atribuição de NULL ao campo "prox" do nó cabeça.

  return novo; // Retorno da nova lista (endereço de memória do nó cabeça). 
}

/*
  A função buscaConjunto recebe uma lista de conjuntos (ponteiro que aponta para o nó cabeça),
  um número inteiro "id" a ser buscado e um ponteiro de ponteiro "pred" que indica o endereço
  de memória do conjunto que seria o anterior ao conjunto com id igual ao id passado por parâmetro.
  Esta função retorna um ponteiro que aponta para o endereço de memória que guarda o conjunto com
  id igual ao id recebido por parâmetro ou o endereço de memória do elemento que seria posterior
  ao elemento buscado ou NULL caso o "id" seja maior que o id de todos os conjuntos da lista.
*/
Conjunto *buscaConjunto (Conjunto *listaConjuntos, int id, Conjunto **pred){
  /*
    Criação de um ponteiro auxiliar para percorrer os conjuntos da lista,
    recebe inicialmente o endereço de memória do primeiro conjunto da lista.
  */
  Conjunto *aux = listaConjuntos->prox;

  /*
    Atribuição do endereço de memória do nó cabeça ao valor guardado no endereço de
    memória apontado por "pred".
  */
  (*pred) = listaConjuntos;

  // Laço responsável por percorrer a lista de conjuntos.
  while (aux != NULL){
    /*
      Se o id buscado for menor ou igual ao campo "id" do conjunto atual
      o laço é encerrado utilizando um break.
    */
    if (id <= aux->id) break;
    
    /*
      Atualização dos ponteiros. O valor guardado no endereço de memória apontado por "pred" será
      igual ao endereço de memória apontado por "aux" e o endereço de memória apontado por "aux" passará
      a ser o endereço do próximo conjunto da lista.
    */
    (*pred) = aux;
    aux = aux->prox;
  }
  return aux; // Retorno do endereço de memória apontado por "aux";
}

/*
  A função insereConjunto recebe uma lista de conjuntos (ponteiro que aponta para o nó cabeça)
  e um número inteiro "id" que é o id do conjunto a ser inserido. Não retorna valores
  pois a lista tem nó cabeça então o primeiro nó nunca será alterado. Caso não exista um conjunto (nó)
  com campo "id" igual ao inteiro "id" será inserido um conjunto na lista com este id.
*/
void insereConjunto (Conjunto *conjuntos, int id) {
  // Criação de ponteiros auxiliares.
  Conjunto *novo = criaConjunto(id); // "novo" recebe o novo conjunto (nó) criado passando como parâmetro "id".
  Conjunto *pred = NULL; // Apontará para o endereço de memória do conjunto que será o anterior do novo.
  Conjunto *aux = buscaConjunto(conjuntos, id, &pred); // Atribuição da busca ao ponteiro "aux".

  /*
    Se não existe um conjunto com o id igual ao valor passado por parâmetro será inserido o novo
    conjunto à lista passada por parâmetro.
  */
  if (!aux || (aux && aux->id != id)) {
    /*
      O campo "prox" do novo conjunto (nó) será o resultado da busca. O campo "prox" do conjunto (nó)
      anterior ao resultado da busca será o endereço do novo conjunto.
    */
    novo->prox = aux;
    pred->prox = novo;
  }
}

/*
  A função imprimeConjuntos recebe uma lista de conjuntos (ponteiro que aponta para o nó cabeça)
  e não retorna valores pois não altera o primeiro nó da lista. Esta função imprime na tela as chaves
  dos elementos presentes nas listas de elementos dos conjuntos presentes na lista.
*/
void imprimeConjuntos(Conjunto *conjuntos) {
  // Criação de ponteiro auxiliar e atribuição a este do primeiro conjunto da lista.
  Conjunto *aux = conjuntos->prox;

  /*
    Se a lista for vazia será impressa uma mensagem informando que não há nenhum conjunto.
    Se não será impressa uma mensagem prévia da impressão.
  */
  if (!aux) {
    printf("\nNenhum conjunto ainda!\n");
  } else {
    printf("\nTodos os conjuntos armazenados: \n\n");
  }

  // Laço responsável por percorrer toda a lista de conjuntos.
  while(aux) {
    printf("Conjunto de id %d: ", aux->id);
    imprimeListaElementos(aux->elementos); // Impressão das chaves dos elementos do conjunto atual.
    aux = aux->prox; // Atualização do ponteiro "aux" para apontar para o próximo conjunto (nó).
  }

  printf("\n");
}

/*
  A função limpaConjunto recebe um conjunto e não retorna valores. Esta função libera a
  memória alocada para o conjunto (nó) criado.
*/
void limpaConjunto(Conjunto *conjunto) {
  // Criação de ponteiros auxiliares.
  Elemento *aux = conjunto->elementos; // "aux" recebe o endereço do nó cabeça da lista.
  Elemento *removido = conjunto->elementos; // "removido" recebe o endereço do nó cabeça da lista.

  // Laço responsável por percorrer toda a lista de elementos do conjunto.
  while(aux) {
    removido = aux; // "removido" recebe o valor de "aux".
    aux = aux->prox; // "aux" é atualizado para apontar para o próximo elemento (nó).

    free(removido); // Liberação da memória alocada para o elemento (nó).
  }

  free(conjunto); // Liberação de memória alocada para o conjunto (nó).
}

/*
  A função limpaListaConjuntos recebe uma lista de conjuntos e não retorna valores. Esta função
  libera a memória alocada para os nós criados para a lista de conjuntos.
*/
void limpaListaConjuntos(Conjunto *conjuntos) {
  // Criação de ponteiros auxiliares.
  Conjunto *aux = conjuntos; // "aux" recebe o endereço do nó cabeça da lista.
  Conjunto *removido = conjuntos; // "removido" recebe o endereço do nó cabeça da lista.

  // Laço responsável por percorrer toda a lista de conjuntos.
  while(aux) {
    removido = aux; // "removido" recebe o valor de "aux".
    aux = aux->prox; // "aux" é atualizado para apontar para o próximo conjunto (nó).

    // É utilizada a função limpaConjunto para liberar a memória alocada para o conjunto (nó).
    limpaConjunto(removido);
  }
}

int main() {
  // Criação de ponteiro/variáveis auxiliares.
  Conjunto *pred = NULL, *aux1 = NULL, *aux2 = NULL;

  Conjunto *conjuntos = novaListaConjuntos(); // Lista de conjuntos.
  // Conjunto que será utilizado no guardar a lista resultante das operações entre dois conjuntos.
  Conjunto *resultado = criaConjunto(0);

  int chave = 0, escolha = 0, id1 = 0, id2 = 0;

  do {
    printf("---Menu de opcoes---");
    printf("\n1  - Criar conjunto\n2  - Inserir elemento\n3  - Remover elemento\n4  - Imprimir elementos de um conjunto\n5  - Esvaziar conjunto");
    printf("\n6  - Verificar se o conjunto esta vazio\n7  - Verificar se um elemento pertence a um conjunto\n");
    printf("8  - Verificar se um conjunto A esta contido em outro conjunto B\n9  - Verificar se dois conjuntos sao iguais\n");
    printf("10 - Fazer a uniao de dois conjuntos\n11 - Fazer a intersecao de dois conjuntos\n");
    printf("12 - Fazer o complemento relativo de um conjunto B em um conjunto A (A - B)\n13 - Mostrar todos conjuntos\n14 - Sair\n\nEscolha: ");
    scanf("%d", &escolha);

    switch(escolha) {
      case 1:
        printf("\nInforme o id do novo conjunto: ");
        scanf("%d", &id1);
        
        // "aux1" recebe o retorno da busca na lista de conjuntos pelo id inserido.
        aux1 = buscaConjunto(conjuntos, id1, &pred);

        /*
          Se o conjunto já existir na lista de conjuntos será impressa uma mensagem informando que não
          foi possível inserir o conjunto na lista.
          Se não o novo conjunto é inserido na lista com o id inserido pelo usuário.
        */
        if (aux1 && aux1->id == id1) {
          printf("\nJa existe um conjunto com este id!\n\n");
        } else {
          insereConjunto(conjuntos, id1);
          printf("\nConjunto criado com sucesso!\n\n");
        }

        break;
      case 2:
        printf("\nInforme o id do conjunto que deseja inserir um elemento: ");
        scanf("%d", &id1);
        printf("\nInforme o elemento a ser inserido: ");
        scanf("%d", &chave);

        // "aux1" recebe o retorno da busca na lista de conjuntos pelo id inserido.
        aux1 = buscaConjunto(conjuntos, id1, &pred);

        /*
          Se existir um conjunto com o id informado será inserido um elemento com chave igual ao valor
          informado na lista de elementos do conjunto (caso não exista um elemento com esta chave).
          Se não será impressa uma mensagem informando que não existe um conjunto com o id informado.
        */
        if (aux1 && aux1->id == id1) {
          insereElemento(aux1->elementos, chave);
          printf("\nElemento inserido (se este não existia no conjunto)!\n\n");
        } else {
          printf("\nNao existe um conjunto com este id!\n\n");
        }

        break;
      case 3:
        printf("\nInforme o id do conjunto que deseja remover um elemento: ");
        scanf("%d", &id1);
        printf("\nInforme o elemento a ser removido: ");
        scanf("%d", &chave);

        // "aux1" recebe o retorno da busca na lista de conjuntos pelo id inserido.
        aux1 = buscaConjunto(conjuntos, id1, &pred);

        /*
          Se existir um conjunto com o id informado será removido o elemento com chave igual ao valor
          informado na lista de elementos do conjunto (caso exista um elemento com esta chave).
          Se não será impressa uma mensagem informando que não existe um conjunto com o id informado.
        */
        if (aux1 && aux1->id == id1) {
          removeElemento(aux1->elementos, chave);
          printf("\nElemento removido (se este existia no conjunto)!\n\n");
        } else {
          printf("\nNao existe um conjunto com este id!\n\n");
        }

        break;
      case 4:
        printf("\nInforme o id do conjunto que deseja imprimir os elementos: ");
        scanf("%d", &id1);

        // "aux1" recebe o retorno da busca na lista de conjuntos pelo id inserido.
        aux1 = buscaConjunto(conjuntos, id1, &pred);

        /*
          Se existir um conjunto com o id informado será impressa a lista de elementos deste conjunto.
          Se não será impressa uma mensagem informando que não existe um conjunto com o id informado.
        */
        if (aux1 && aux1->id == id1) {
          printf("\nConjunto de id %d: ", id1);
          imprimeListaElementos(aux1->elementos);
          printf("\n");
        } else {
          printf("\nNao existe um conjunto com este id!\n\n");
        }
        break;
      case 5:
        printf("\nInforme o id do conjunto que deseja esvaziar: ");
        scanf("%d", &id1);

        // "aux1" recebe o retorno da busca na lista de conjuntos pelo id inserido.
        aux1 = buscaConjunto(conjuntos, id1, &pred);

        /*
          Se existir um conjunto com o id informado este terá sua lista de elementos esvaziada.
          Se não será impressa uma mensagem informando que não existe um conjunto com o id informado.
        */
        if (aux1 && aux1->id == id1) {
          esvaziaLista(aux1->elementos);
          printf("\nConjunto esvaziado com sucesso!\n\n");
        } else {
          printf("\nNao existe um conjunto com este id!\n\n");
        }
        break;
      case 6:
        printf("\nInforme o id do conjunto que deseja verificar: ");
        scanf("%d", &id1);

        // "aux1" recebe o retorno da busca na lista de conjuntos pelo id inserido.
        aux1 = buscaConjunto(conjuntos, id1, &pred);

        /*
          Se existir um conjunto com o id informado segue a tratativa para informar se o conjunto
          é ou não vazio.
          Se não será impressa uma mensagem informando que não existe um conjunto com o id informado.
        */
        if (aux1 && aux1->id == id1) {
          /*
            Condição responsável por definir qual mensagem será impressa. Se o retorno da verificação
            sobre a lista de elementos estar vazia for 1 será impressa uma mensagem informando que o conjunto
            está vazio. Se não será impressa uma mensagem informando que o conjunto não está vazio.
          */
          if (verificaListaVazia(aux1->elementos) == 1) printf("\nEste conjunto esta vazio!\n\n");
          else printf("\nEste conjunto nao esta vazio!\n\n");
        } else {
          printf("\nNao existe um conjunto com este id!\n\n");
        }
        
        break;
      case 7:
        printf("\nInforme o id do conjunto em que deseja buscar: ");
        scanf("%d", &id1);
        printf("Informe o número que deseja buscar: ");
        scanf("%d", &chave);

        // "aux1" recebe o retorno da busca na lista de conjuntos pelo id inserido.
        aux1 = buscaConjunto(conjuntos, id1, &pred);

        /*
          Se existir um conjunto com o id informado segue a tratativa para verificar se o elemento pertence
          ao conjunto.
          Se não será impressa uma mensagem informando que não existe um conjunto com o id informado.
        */
        if (aux1 && aux1->id == id1) {
          /*
            Condição responsável por definir qual mensagem será impressa. Se o retorno da verificação
            sobre o elemento pertencer à lista de elementos será impressa uma mensagem informando que o elemento pertence ao
            conjunto. Se não será impressa uma mensagem informando que o elemento não pertence ao conjunto.
          */
          if (verificaElementoLista(aux1->elementos, chave) == 1) printf("\nO elemento pertence ao conjunto!\n\n");
          else printf("\nO elemento nao pertence ao conjunto!\n\n");
        } else {
          printf("\nNao existe um conjunto com este id!\n\n");
        }

        break;
      case 8:
        printf("\nInforme o id do conjunto A: ");
        scanf("%d", &id1);
        printf("Informe o id do conjunto B: ");
        scanf("%d", &id2);

        /*
          "aux1" recebe o retorno da busca na lista de conjuntos pelo id1 inserido.
          "aux2" recebe o retorno da busca na lista de conjuntos pelo id2 inserido.
        */
        aux1 = buscaConjunto(conjuntos, id1, &pred);
        aux2 = buscaConjunto(conjuntos, id2, &pred);

        /*
          Se existirem os conjuntos com os ids informados segue a tratativa para verificar se o conjunto A está
          contido no conjunto B.
          Se não será impressa uma mensagem informando que não existe um conjunto com o id informado.
        */
        if (aux1 && aux1->id == id1 && aux2 && aux2->id == id2) {
          /*
            Condição responsável por definir qual mensagem será impressa. Se o retorno da verificação
            sobre a primeira lista estar contida na segunda for 1 será impressa uma mensagem informando
            que o conjunto A está contido no conjunto B. Se não será impressa uma mensagem informando que
            o conjunto A não está contido no conjunto B.
          */
          if (verificaListaContida(aux1->elementos, aux2->elementos) == 1) 
            printf("\nO conjunto A esta contido no conjunto B!\n\n");
          else printf("\nO conjunto A nao esta contido no conjunto B!\n\n");
        } else {
          printf("\nNao existe um conjunto com este id!\n\n");
        }
        break;
      case 9:
        printf("\nInforme o id do conjunto A: ");
        scanf("%d", &id1);
        printf("Informe o id do conjunto B: ");
        scanf("%d", &id2);

        /*
          "aux1" recebe o retorno da busca na lista de conjuntos pelo id1 inserido.
          "aux2" recebe o retorno da busca na lista de conjuntos pelo id2 inserido.
        */
        aux1 = buscaConjunto(conjuntos, id1, &pred);
        aux2 = buscaConjunto(conjuntos, id2, &pred);

        /*
          Se existirem os conjunto com os ids informados segue a tratativa para verificar se o conjunto A é
          igual ao conjunto B.
          Se não será impressa uma mensagem informando que não existe um conjunto com o id informado.
        */

        if (aux1 && aux1->id == id1 && aux2 && aux2->id == id2) {
          /*
            Condição responsável por definir qual mensagem será impressa. Se o retorno da verificação
            sobre a primeira lista ser igual a segunda for 1 será impressa uma mensagem informando
            que o conjunto A é igual ao conjunto B. Se não será impressa uma mensagem informando que
            o conjunto A não é igual ao contido no conjunto B.
          */
          if (verificaListasIguais(aux1->elementos, aux2->elementos) == 1) 
            printf("\nOs conjuntos A e B sao iguais!\n\n");
          else printf("\nOs conjuntos A e B nao sao iguais!\n\n");
        } else {
          printf("\nNao existe um conjunto com este id!\n\n");
        }
        break;
      case 10:
        printf("\nInforme o id do conjunto A: ");
        scanf("%d", &id1);
        printf("Informe o id do conjunto B: ");
        scanf("%d", &id2);

        /*
          "aux1" recebe o retorno da busca na lista de conjuntos pelo id1 inserido.
          "aux2" recebe o retorno da busca na lista de conjuntos pelo id2 inserido.
        */
        aux1 = buscaConjunto(conjuntos, id1, &pred);
        aux2 = buscaConjunto(conjuntos, id2, &pred);

        /*
          Se existirem os conjunto com os ids informados segue a tratativa para mostrar a união do conjunto A
          com o conjunto B.
          Se não será impressa uma mensagem informando que não existe um conjunto com o id informado.
        */
        if (aux1 && aux1->id == id1 && aux2 && aux2->id == id2) {
          /*
            A lista de elementos do conjunto "resultado" recebe o retorno da função de união passando como
            parâmetro os dois conjuntos.
          */
          resultado->elementos = uniaoListas(aux1->elementos, aux2->elementos);
          printf("\nUniao dos conjuntos A e B: ");

          imprimeListaElementos(resultado->elementos); // Impressão a lista de elementos do conjunto resultante.
          printf("\n");
        } else {
          printf("\nNao existe um conjunto com este id!\n\n");
        }

        /*
          É esvaziada a lista de elementos do conjunto resultante, consequentemente é liberada a memória
          alocada para os elementos (nós).
        */
        esvaziaLista(resultado->elementos);
        break;
      case 11:
        printf("\nInforme o id do conjunto A: ");
        scanf("%d", &id1);
        printf("Informe o id do conjunto B: ");
        scanf("%d", &id2);

        /*
          "aux1" recebe o retorno da busca na lista de conjuntos pelo id1 inserido.
          "aux2" recebe o retorno da busca na lista de conjuntos pelo id2 inserido.
        */
        aux1 = buscaConjunto(conjuntos, id1, &pred);
        aux2 = buscaConjunto(conjuntos, id2, &pred);

        /*
          Se existirem os conjunto com os ids informados segue a tratativa para mostrar a interseção do
          conjunto A com o conjunto B.
          Se não será impressa uma mensagem informando que não existe um conjunto com o id informado.
        */
        if (aux1 && aux1->id == id1 && aux2 && aux2->id == id2) {
          /*
            A lista de elementos do conjunto "resultado" recebe o retorno da função de interseção passando
            como parâmetro os dois conjuntos.
          */
          resultado->elementos = intersecaoListas(aux1->elementos, aux2->elementos);
          printf("\nIntersecao dos conjuntos A e B: ");
          
          imprimeListaElementos(resultado->elementos); // Impressão a lista de elementos do conjunto resultante.
          printf("\n");
        } else {
          printf("\nNao existe um conjunto com este id!\n\n");
        }

        /*
          É esvaziada a lista de elementos do conjunto resultante, consequentemente é liberada a memória
          alocada para os elementos (nós).
        */
        esvaziaLista(resultado->elementos);
        break;
      case 12:
        printf("\nInforme o id do conjunto A: ");
        scanf("%d", &id1);
        printf("Informe o id do conjunto B: ");
        scanf("%d", &id2);

        /*
          "aux1" recebe o retorno da busca na lista de conjuntos pelo id1 inserido.
          "aux2" recebe o retorno da busca na lista de conjuntos pelo id2 inserido.
        */
        aux1 = buscaConjunto(conjuntos, id1, &pred);
        aux2 = buscaConjunto(conjuntos, id2, &pred);

        /*
          Se existirem os conjunto com os ids informados segue a tratativa para mostrar o complemento relativo
          do conjunto B no conjunto A.
          Se não será impressa uma mensagem informando que não existe um conjunto com o id informado.
        */
        if (aux1 && aux1->id == id1 && aux2 && aux2->id == id2) {
          resultado->elementos = complementoRelativoListas(aux1->elementos, aux2->elementos);
          printf("\nComplemento relativo do conjunto B no conjunto A: ");

          imprimeListaElementos(resultado->elementos); // Impressão a lista de elementos do conjunto resultante.
          printf("\n");
        } else {
          printf("\nNao existe um conjunto com este id!\n\n");
        }

        /*
          É esvaziada a lista de elementos do conjunto resultante, consequentemente é liberada a memória
          alocada para os elementos (nós).
        */
        esvaziaLista(resultado->elementos);
        break;
      case 13:
        // Impressão da lista de elementos dos conjuntos da lista de conjuntos.
        imprimeConjuntos(conjuntos);
        break;
      case 14: break; // Usuário escolheu sair. Nada é feito.
      default:
        printf("\nEscolha invalida!\n\n");
    }

  } while(escolha != 14);

  limpaConjunto(resultado); // Liberação da memória alocada para o nó do conjunto resultante.
  limpaListaConjuntos(conjuntos); // Liberação da memória alocada para os nós da lista de conjuntos.

  return 0; // Retorno de 0 indicando término do programa com êxito.
}