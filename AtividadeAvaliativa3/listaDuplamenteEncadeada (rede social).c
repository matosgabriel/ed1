// Nome: Gabriel Alves Matos


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Amigo (será utilizada para a criação da lista de amigos).
typedef struct amigo {
  int id; // Id do amigo.

  struct amigo *prox; // Ponteiro para o próximo amigo.
  struct amigo *prev; // Ponteiro para o amigo anterior.
} Amigo;

// Definição da estrutura Usuario (representará um usuário do sistema).
typedef struct usuario {
  // Dados do usuário.
  int id;
  char nome[50];
  int idade;
  char email[50];

  struct amigo *amigos; // Ponteiro da lista de amigos.
  struct usuario *prox; // Ponteiro para o próximo usuário.
  struct usuario *prev; // Ponteiro para o usuário anterior.

} Usuario;

/*
  Função responsável por criar um novo amigo (nó).
  Recebe como parâmetro o id do amigo que será criado.
  Retorna um ponteiro que aponta para o novo amigo (nó).
*/

Amigo *criaAmigo(int id) {
  // Alocação de memória (criação do nó) e atribuição ao ponteiro "novo" do tipo Amigo.
  Amigo *novo = (Amigo *) calloc(1, sizeof(Amigo));

  /*
    Caso a alocação de memória não seja executada com sucesso será mostrada uma
    mensagem na tela e o programa será encerrado.
    Caso a alocação seja executada com sucesso serão efetuadas as atribuições dos valores
    aos campos e o retorno do novo amigo (nó).
  */

  if (!novo) {
    printf("Erro: não foi possível alocar.");
    exit(1); // Término do programa sem êxito.
  } else {
    // Atribuição do id recebido como parâmetro ao campo id do novo amigo.
    novo->id = id;
    // Atribuição de NULL aos ponteiros para os amigos próximo e anterior.
    novo->prox = NULL;
    novo->prev = NULL;

    return novo; // Retorno do novo amigo (nó).
  }

}

/*
  Função responsável por criar uma nova lista de amigos (com nó cabeça).
  Não recebe parâmetro algum.
  Retorna a nova lista de amigos duplamente encadeada com nó cabeça.
*/

Amigo *novaListaAmigos() {
  // Alocação de memória (criação do nó cabeça) e atribuição ao ponteiro "novo" do tipo Amigo.
  Amigo *novo = (Amigo *) calloc(1, sizeof(Amigo));

  /*
    Caso a alocação de memória não seja executada com sucesso será mostrada uma
    mensagem na tela e o programa será encerrado.
    Caso a alocação seja executada com sucesso serão efetuadas as atribuições dos valores
    aos campos e o retorno da nova lista.
  */

  if (!novo) {
    printf("Erro: não foi possível alocar.");
    exit(1); // Término do programa sem êxito.
  } else {
    // Atribuição de NULL aos ponteiros para os amigos próximo e anterior do nó cabeça.
    novo->prox = NULL;
    novo->prev = NULL;

    return novo; // Retorno da nova lista de amigos.
  }

}

/*
  Função responsável por criar um novo usuário (nó).
  Recebe como parâmetros o id, o nome, a idade e o email do usuário a ser criado.
  Retorna o novo usuário (nó).
*/

Usuario *criaUsuario(int id, char nome[50], int idade, char email[50]) {
  // Alocação de memória (criação do nó) e atribuição ao ponteiro "novo" do tipo Usuario.
  Usuario *novo = (Usuario *) calloc(1, sizeof(Usuario));

  /*
    Caso a alocação de memória não seja executada com sucesso será mostrada uma
    mensagem na tela e o programa será encerrado.
    Caso a alocação seja executada com sucesso serão efetuadas as atribuições dos valores
    aos campos e o retorno do novo usuário (nó).
  */

  if (!novo) {
    printf("Erro: não foi possível alocar.");
    exit(1); // Término do programa sem êxito.
  } else {
    // Atribuição dos valores recebidos por parâmetro aos campos do novo usuário (nó).
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->idade = idade;
    strcpy(novo->email, email);

    // Atribuição de NULL aos ponteiros para os usuários próximo e anterior.
    novo->prox = NULL;
    novo->prev = NULL;
    novo->amigos = novaListaAmigos(); // Atribuição de uma nova lista de amigos vazia ao campo de amigos.

    return novo; // Retorno do novo usuário (nó).
  }
}

/*
  Função responsável por criar uma nova lista de usuários (com nó cabeça).
  Não recebe parâmetro algum.
  Retorna a nova lista de usuários duplamente encadeada com nó cabeça.
*/

Usuario *novaListaUsuarios() {
  // Alocação de memória (criação do nó cabeça) e atribuição ao ponteiro "novo" do tipo Usuario.
  Usuario *novo = (Usuario *) calloc(1, sizeof(Usuario));

  /*
    Caso a alocação de memória não seja executada com sucesso será mostrada uma
    mensagem na tela e o programa será encerrado.
    Caso a alocação seja executada com sucesso serão efetuadas as atribuições dos valores
    aos campos e o retorno da nova lista.
  */

  if (!novo) {
    printf("Erro: não foi possível alocar.");
    exit(1); // Término do programa sem êxito.
  } else {
    // Atribuição de NULL aos ponteiros para os usuários próximo e anterior do nó cabeça.
    novo->prox = NULL;
    novo->prev = NULL;

    return novo; // Retorno da nova lista de usuários.
  }
}

/*
  Função responsável por limpar a lista de amigos (liberar os espaços de memória alocados).
  Recebe como parâmetro a lista de amigos (lista duplamente encadeada).
  Não há retorno.
*/

void limpaListaAmigos(Amigo *amigos) {
  // Criação do ponteiro auxiliar que irá percorrer a lista. Inicialmente recebe o endereço do nó cabeça.
  Amigo *aux = amigos;

  // Criação do ponteiro auxiliar que será utilizado para liberar a memória alocada para o nó.
  Amigo *deletando = NULL;

  // Laço responsável por percorrer toda a lista de amigos (lista duplamente encadeada).
  while(aux) {
    deletando = aux; // O ponteiro "deletando" recebe o valor do ponteiro "aux";
    aux = aux->prox; // Atualização do ponteiro "aux" para apontar para o próximo amigo (nó) da lista.
    free(deletando); // Libera a memória alocada para o nó.
  }
}

/*
  Função responsável por limpar a lista de usuários (liberar os espaços de memória alocados).
  Recebe como parâmetro a lista de usuários (lista duplamente encadeada).
  Não há retorno.
*/

void limpaListaUsuarios(Usuario *usuarios) {
  // Criação do ponteiro auxiliar que irá percorrer a lista. Inicialmente recebe o endereço do nó cabeça.
  Usuario *aux = usuarios;

  // Criação do ponteiro auxiliar que será utilizado para liberar a memória alocada para o nó.
  Usuario *deletando = NULL;

  // Laço responsável por percorrer toda a lista de usuários (lista duplamente encadeada).
  while(aux) {
    deletando = aux; // O ponteiro "deletando" recebe o valor do ponteiro "aux";
    aux = aux->prox; // Atualização do ponteiro "aux" para apontar para o próximo usuário (nó) da lista.

    // Limpeza da memória alocada para a lista de amigos utilizando a função limpaListaAmigos passando por parâmetro a lista de amigos do usuário atual.
    limpaListaAmigos(deletando->amigos);

    free(deletando); // Libera a memória alocada para o nó.
  }
}

/*
  Função responsável por imprimir os ids de uma lista de amigos.
  Recebe como parâmetro a lista de amigos a ser utilizada.
  Não há retorno.
*/

void imprimeAmigos(Amigo *amigos) {
  // Criação do ponteiro auxiliar que recebe o primeiro amigo da lista.
  Amigo *aux = amigos->prox;

  // Laço responsável por percorrer toda a lista de amigos.
  while(aux) {
    printf("%d ", aux->id);
    aux = aux->prox; // Atualização do ponteiro "aux" para apontar para o próximo amigo (nó) da lista.
  }
  printf("\n\n");
}

/*
  Função responsável por imprimir os dados de um usuário.
  Recebe como parâmetro o usuário que deve ter os dados impressos.
  Não há retorno.
*/

void imprimeUsuario(Usuario *usuario) {
  // Impressão dos dados do usuário.
  printf("\nId: %d\n", usuario->id);
  printf("Nome: %s\n", usuario->nome);
  printf("Idade: %d ano(s)\n", usuario->idade);
  printf("Email: %s\n", usuario->email);

  /*
    Se o usuário não tiver amigos (lista de amigos vazia, ou seja, usuario->amigos->prox igual a NULL) será impressa uma mensagem
    informando que o usuário não possui amigos.
    Se não (o usuário tem amigos e usuario->amigos->prox é diferente de NULL), será utilizada a função imprimeAmigos passando como
    parâmetro a lista de amigos deste usuário.
  */

  if (!usuario->amigos->prox) {
    printf("Este usuario ainda nao possui amigos!\n\n");
  } else {
    printf("Id dos amigos: ");
    imprimeAmigos(usuario->amigos);
  }
}

/*
  Função responsável por fazer a busca ordenada (ordem crescente por id)
  de um usuário em uma lista de usuários.
  Recebe como parâmetros a lista de usuários que deve ser utilizada na busca e o id do usuário buscado.
  Retorna o usuário (nó) com id igual ao recebido por parâmetro ou o próximo usuário (nó) com id maior ou NULL.
  As duas últimas opções de retorno indicam a não existência do usuário na lista fornecida.
*/

Usuario *buscaUsuario(Usuario *usuarios, int id) {
  // Criação de um ponteiro auxiliar "aux" que recebe o primeiro usuário da lista ou NULL (caso seja vazia).
  Usuario *aux = usuarios->prox;

  /*
    Laço responsável por percorrer a lista de usuários (lista duplamente encadeada).
    O laço será encerrado quando a lista for totalmente percorrida (aux será NULL), ou seja, o id informado é menor
    que o id do próximo usuário (for encontrado usuário (nó) com id igual ao recebido por parâmetro ou o próximo usuário (nó) com id maior).
  */

  while(aux && id > aux->id) {
    aux = aux->prox; // Atualização do ponteiro para o próximo nó da lista.
  }

  // Retorno do usuário (nó) com id igual ao id recebido por parâmetro, o próximo usuário (nó) com id maior ou NULL.
  return aux;
}

/*
  Função responsável por fazer a busca ordenada (ordem crescente por id)
  de um amigo em uma lista de amigos.
  Recebe como parâmetros a lista de amigos que deve ser utilizada na busca e o id do amigo buscado.
  Retorna o amigo (nó) com id igual ao recebido por parâmetro ou o próximo amigo (nó) com id maior ou NULL.
  As duas últimas opções de retorno indicam a não existência do amigo na lista fornecida.
*/

Amigo *buscaAmigo(Amigo *amigos, int id) {
  // Criação de um ponteiro auxiliar "aux" que recebe o primeiro amigo da lista ou NULL (caso seja vazia).
  Amigo *aux = amigos->prox;

  /*
    Laço responsável por percorrer a lista de amigos (lista duplamente encadeada).
    O laço será encerrado quando a lista for totalmente percorrida (aux será NULL), ou seja, o id informado é menor
    que o id do próximo amigo (for encontrado amigo (nó) com id igual ao recebido por parâmetro ou o próximo amigo (nó) com id maior).
  */

  while(aux && id > aux->id) {
    aux = aux->prox; // Atualização do ponteiro para o próximo nó da lista.
  }

  // Retorno do amigo (nó) com id igual ao id recebido por parâmetro ou o próximo amigo (nó) com id maior ou NULL.
  return aux;
}

/*
  Função responsável por fazer a inserção ordenada (ordem crescente por id) de um usuário em uma lista de usuários.
  Recebe como parâmetros a lista de usuários que deve receber o novo usuário e os dados do novo usuário (id, nome, idade e email).
  Não há retorno.
*/

void insereUsuario(Usuario *usuarios, int id, char nome[50], int idade, char email[50]) {
  // Criação do novo usuário (nó) e atribuição a um ponteiro "novo" do tipo Usuario.
  Usuario *novo = criaUsuario(id, nome, idade, email);

  // Criação dos ponteiros auxiliares.
  Usuario *aux = buscaUsuario(usuarios, id); // Recebe o retorno da busca do id informado na lista de amigos.
  Usuario *auxUsuarios = usuarios->prox; // Recebe o primeiro usuário (nó) ou NULL (lista vazia).
  Usuario *emailExistente = NULL; // Ponteiro utilizado para verificar a existência de usuário utilizando o email fornecido.
  Usuario *idExistente = NULL; // Ponteiro utilizado para verificar a existência de usuário utilizando o id fornecido.

  // Laço utilizado para percorrer toda a lista de usuários.

  while(auxUsuarios) {
    /*
      Caso o email do usuário atual ou seu id sejam iguais aos recebidos via parâmetro o ponteiro
      "receberá" esse usuário (nó).
    */ 
    if (strcmp(auxUsuarios->email, email) == 0) {
      emailExistente = auxUsuarios;
      break; // Sai do laço.
    }
    
    if (auxUsuarios->id == id) {
      idExistente = auxUsuarios;
      break; // Sai do laço.
    }

    auxUsuarios = auxUsuarios->prox; // Atualização do ponteiro para o próximo nó da lista.
  }

  /*
    Condição responsável por determinar de qual forma o usuário será inserido na lista tendo em vista o resultado da busca.
    Se "emailExistente" for diferente de NULL então existe usuário utilizando o email fornecido.
    Se não, se "idExistente" for diferente de NULL então existe usuário utilizando o id fornecido.
    Se não, se o id fornecido for maior que os ids de todos os usuários já presentes na lista (aux igual a NULL)
    segue a tratativa, pois a lista pode ser vazia ou não portanto o novo amigo será inserido no início ou fim da lista.
    Se não, como "aux" não é NULL então a lista não foi totalmente percorrida, o usuário (nó) será inserido no início ou no "meio" da lista.
  */

  if (emailExistente) {
    printf("\nErro no cadastrado. Email em uso!\n\n");
  } else if (idExistente) {
    printf("\nErro no cadastrado. Id em uso!\n\n");
  } else if (!aux) {
    /*
      Se a lista for vazia (usuarios->prox == NULL) então o usuário será inserido no início da lista.
      Se não o usuário (nó) será inserido no fim na lista.
    */
    if (!(usuarios->prox)) {
      // Os campos prox e prev do nó cabeça recebem o novo nó (o novo usuário é primeiro e último da lista).
      usuarios->prox = novo;
      usuarios->prev = novo;
    } else {
      usuarios->prev->prox = novo; // O campo prox do último nó (usuarios->prev) recebe o novo nó (o sucessor do último usuário será o novo usuário).
      novo->prev = usuarios->prev; // O campo prev do novo nó recebe o antigo último nó (o anterior do novo usuário será o antigo último usuário da lista).
      usuarios->prev = novo; // O campo prev do nó cabeça recebe o novo nó (agora o novo usuário é o último da lista).
    }

    printf("Usuario cadastrado com sucesso!\n\n");
  } else {
    novo->prox = aux; // O campo prox do novo nó recebe o nó retornado da busca na lista de usuários (o sucessor do novo usuário será o usuário retornado pela busca).

    /*
      Se o id do novo usuário for menor que o id de todos os outros usuários ele será inserido no início da lista
      (o campo prev do nó retornado pela busca é igual a NULL).
      Se não, o novo usuário será inserido no "meio" da lista.
    */

    if (!aux->prev) usuarios->prox = novo; // O novo usuário é inserido no início da lista (o campo prox do nó cabeça recebe o novo nó).
    else {
      // O campo prev do novo nó receberá o campo prev do nó retornado pela busca (o anterior do novo usuário será o anterior do usuário retornado pela busca).
      novo->prev = aux->prev;
      // O campo prox do nó anterior ao retornado pela busca receberá o novo nó (o sucessor do anterior do usuário retornado pela busca será o novo usuário).
      (aux->prev)->prox = novo;
    }

    // O campo prev do nó retornado pela busca receberá o novo nó (o usuário anterior do retornado pela busca será o novo usuário).
    aux->prev = novo;
    printf("Usuário cadastrado com sucesso!\n\n");
  }
}

/*
  Função responsável por fazer a inserção ordenada (ordem crescente por id) de um amigo em uma lista de amigos.
  Recebe como parâmetros a lista de amigos que deve receber o novo amigo e os dados do novo amigo (id, nome, idade e email).
  Não há retorno.
*/

void insereAmigo(Amigo *amigos, int id) {
  // Criação do novo amigo (nó) e atribuição a um ponteiro "novo" do tipo Amigo.
  Amigo *novo = criaAmigo(id);

  // Criação do ponteiro auxiliar que recebe o retorno da busca do id informado na lista de amigos passada por parâmetro.
  Amigo *aux = buscaAmigo(amigos, id);

  /*
    Condição responsável por determinar de qual forma o amigo será inserido na lista tendo em vista o resultado da busca.
    Caso o id fornecido seja maior que os ids de todos os amigos já presentes na lista (aux igual a NULL)
    segue a tratativa, pois a lista pode ser vazia ou não portanto o novo amigo será inserido no início ou fim da lista.
    Se não, como "aux" não é NULL então a lista não foi totalmente percorrida, o amigo (nó) será inserido no início ou no "meio" da lista.
  */

  if (!aux) {
    /*
      Se a lista for vazia (amigos->prox == NULL) então o amigo será inserido no início da lista.
      Se não o amigo (nó) será inserido no fim na lista.
    */
    if (!(amigos->prox)) {
      // Os campos prox e prev do nó cabeça recebem o novo nó (o novo amigo é primeiro e último da lista).
      amigos->prox = novo;
      amigos->prev = novo;
    } else {
      amigos->prev->prox = novo; // O campo prox do último nó (amigos->prev) recebe o novo nó (o sucessor do último amigo será o novo amigo).
      novo->prev = amigos->prev; // O campo prev do novo nó recebe o antigo último nó (o anterior do novo amigo será o antigo último amigo da lista).
      amigos->prev = novo; // O campo prev do nó cabeça recebe o novo nó (agora o novo amigo é o último da lista).
    }
  } else {
    novo->prox = aux; // O campo prox do novo nó recebe o nó retornado da busca na lista de amigos (o sucessor do novo amigo será o amigo retornado pela busca).

    /*
      Se o id do novo amigo for menor que o id de todos os outros amigos ele será inserido no início da lista
      (o campo prev do nó retornado pela busca é igual a NULL).
      Se não, o novo amigo será inserido no "meio" da lista.
    */

    if (!(aux->prev)) amigos->prox = novo; // O novo amigo é inserido no início da lista (o campo prox do nó cabeça recebe o novo nó).
    else {
      // O campo prev do novo nó receberá o campo prev do nó retornado pela busca (o anterior do novo amigo será o anterior do amigo retornado pela busca).
      novo->prev = aux->prev;
      // O campo prox do nó anterior ao retornado pela busca receberá o novo nó (o sucessor do anterior do amigo retornado pela busca será o novo amigo).
      (aux->prev)->prox = novo;
    }

    // O campo prev do nó retornado pela busca receberá o novo nó (o amigo anterior do retornado pela busca será o novo amigo).
    aux->prev = novo;
  }
}

/*
  Função responsável por criar uma amizade entre dois usuários (utiliza a função insereAmigo).
  Recebe como parâmetros a lista de usuários e os ids dos dois usuários a serem relacionados.
  Não há retorno.
*/

void criaAmizade(Usuario *usuarios, int id1, int id2) {
  // Criação de ponteiros auxiliares que irão armazenar o retorno da busca de usuário utilizando os ids recebidos por parâmetro.
  Usuario *usuario1 = buscaUsuario(usuarios, id1);
  Usuario *usuario2 = buscaUsuario(usuarios, id2);

  // Ponteiro auxiliar que irá armazenar o retorno da busca nas listas de amigos dos usuários.
  Amigo *aux = NULL;

  /*
    Se os dois ids passados por parâmetro forem iguais será impressa uma mensagem de erro pois não é
    possível criar amizade de um usuário com ele mesmo.
    Se não, se não existir usuários com id igual ao recebido por parâmetro é impressa uma mensagem de erro.
    Se não segue a tratativa pois os usuário podem já serem amigos.
  */

  if (id1 == id2) {
    printf("\nImpossivel cadastrar uma amizade do usuario com ele mesmo!\n\n");
  } else if (!usuario1 || !usuario2 || (usuario1 && usuario1->id != id1) || (usuario2 && usuario2->id != id2)) {
    printf("\nErro ao criar amizade. O usuario deve estar cadastrado!\n\n");
  } else {

    // "aux" recebe o retorno da busca do usuário de id igual a "id2" na lista de amigos do usuário de id igual a "id1".
    aux = buscaAmigo(usuario1->amigos, id2);

    /*
      Caso o usuário de id igual a "id2" não exista na lista de amigos de usuário de id igual a "id1"
      ("aux" igual a NULL ou "aux" diferente de NULL porém o campo id diferente de "id2") então cada um será
      inserido na lista de amigos do outro.
      Se não será um impressa uma mensagem informando que os usuários já são amigos.
    */

    if (!aux || (aux && aux->id != id2)) {
      // Inserção dos usuários um na lista de amigos do outro.
      insereAmigo(usuario1->amigos, id2);
      insereAmigo(usuario2->amigos, id1);

      printf("\nAmizade criada com sucesso!\n\n");
    } else {
      printf("\nEsses usuarios ja sao amigos!\n\n");
    }
  }
}

/*
  Função responsável por listar os amigos em comum entre dois usuários.
  Recebe como parâmetros a lista de usuários e os ids dos dois usuários a ser listados os amigos em comum.
  Retorna uma lista de amigos (comum entre os dois) ou NULL caso os usuários não tenham amigos em comum.
*/

void listaAmigosEmComum(Usuario *usuarios, int id1, int id2) {
  // Criação de ponteiros que irão armazenar o retorno da busca de usuário utilizando os id's recebidos por parâmetro.
  Usuario *usuario1 = buscaUsuario(usuarios, id1);
  Usuario *usuario2 = buscaUsuario(usuarios, id2);

  // Criação de ponteiro do tipo Amigo que recebe uma nova lista de amigos vazia.
  Amigo *amigosEmComum = novaListaAmigos();

  // Criação de ponteiros auxiliares usados para percorrer as listas de amigos.
  Amigo *aux1 = NULL;
  Amigo *aux2 = NULL;

  /*
    Se um dos usuários (nó) não existir será impressa uma mensagem de erro.
    Se não será feita a busca dos amigos em comum entre os usuários.
  */

  if (!usuario1 || !usuario2 || usuario1->id != id1 || usuario2->id != id2) {
    printf("\nErro ao buscar amigos em comum. O usuario deve estar cadastrado!\n\n");
  } else {
    aux1 = usuario1->amigos->prox; // "aux1" recebe o primeiro amigo da lista de amigos do usuário 1 ou NULL caso ele não tenha amigos.

    // Laço responsável por percorrer toda a lista de amigos do usuário 1.

    while(aux1) {
      // "aux2" recebe o retorno da busca pelo amigo atual da lista de amigos do usuário 1 na lista de amigos do usuário 2.
      aux2 = buscaAmigo(usuario2->amigos, aux1->id);

      /*
        Se o amigo atual da lista de amigos do usuário 1 existir na lista de amigos do usuário 2 então será inserido na lista
        de amigos em comum um amigo com este id.
      */

      if (aux2 && aux2->id == aux1->id) {
        insereAmigo(amigosEmComum, aux1->id);
      }
      aux1 = aux1->prox; // Atualização do ponteiro para o próximo usuário (nó) da lista.
    }

    /*
      Se a lista for vazia (listaAmigos->prox igual a NULL) é impressa uma mensagem informando que os usuários
      não têm amigos em comum.
      Se não, é impressa a lista de amigos em comum.
    */

    if (!amigosEmComum->prox) {
      printf("\nNenhum amigo em comum!\n\n");
    } else {
      printf("\nId dos amigos em comum: ");
      imprimeAmigos(amigosEmComum); // Impressão dos ids dos amigos em comum.
    }
    
    // Liberação de memória da lista de amigos em comum (foi criada uma nova lista que não será utilizada novamente).
    limpaListaAmigos(amigosEmComum);
  }
}

/*
  Função responsável por excluir a amizade entre dois usuários (remover da lista de amigos).
  Recebe como parâmetros a lista de usuários e os ids dos dois usuários que deve ser desfeita a amizade.
  Não há retorno.
*/

void excluiAmizade(Usuario *usuarios, int id1, int id2) {
  // Criação de ponteiros que irão armazenar o retorno da busca (na lista de usuários) utilizando os ids recebidos por parâmetro.
  Usuario *usuario1 = buscaUsuario(usuarios, id1);
  Usuario *usuario2 = buscaUsuario(usuarios, id2);

  /*
    Criação de ponteiros auxiliares que irão armazenar o retorno da busca (um na lista de amigos do outro)
    utilizando os ids recebidos por parâmetro.
  */
  Amigo *aux1 = NULL;
  Amigo *aux2 = NULL;

  /*
    Se um dos usuários não existir (ou os dois) será impressa uma mensagem de erro.
    Se não, segue a verificação de existência de amizade entre os usuários.
  */

  if (!usuario1 || !usuario2) {
    printf("\nO usuario deve estar cadastrado!\n\n");
  } else if ((usuario1->id != id1) || (usuario2->id != id2)) {
    printf("\nO usuario deve estar cadastrado!\n\n");
  } else {
    // Os ponteiros auxiliares recebem o resultado da busca nas listas de amigos dos usuários.
    aux1 = buscaAmigo(usuario1->amigos, id2);
    aux2 = buscaAmigo(usuario2->amigos, id1);
  
    /*
      Se os usuários não forem amigos (a busca na lista de amigos do usuário 1 passando o id2 retornou NULL ou o id do amigo retornado é diferente)
      então será impressa uma mensagem informando que estes usuário não são amigos.
      Se não a amizade entre os usuários será desfeita (é removido o nó com o id de um da lista de amigos do outro).
    */
    
    if (!aux1 || (aux1 && aux1->id != id2)) {
      printf("\nEstes usuarios nao sao amigos!\n\n");
    } else {
      /*
        Se o amigo a ser excluído não for o último da lista (aux1->prox ou aux2->prox diferente de NULL) então o anterior do próximo amigo do amigo retornado
        pela busca será o anterior do amigo retornado.
      */

      if (aux1->prox) aux1->prox->prev = aux1->prev;

      if (aux2->prox) aux2->prox->prev = aux2->prev;

      /*
        Se o amigo a ser excluído não for o primeiro da lista de amigos (aux1->prev ou aux2->prev diferente de NULL) então
        o próximo amigo do amigo anterior ao retornado pela busca será agora o próximo amigo do retornado.
        Se não (o amigo a ser excluído está no início da lista) então o início da lista de amigos é agora o próximo amigo do amigo retornado pela busca.
      */

      if (aux1->prev) aux1->prev->prox = aux1->prox;
      else usuario1->amigos->prox = aux1->prox;

      if (aux2->prev) aux2->prev->prox = aux2->prox;
      else usuario2->amigos->prox = aux2->prox;

      free(aux1); //Libera a memória alocada para o nó (o nó apontado não será mais utilizado).
      free(aux2); //Libera a memória alocada para o nó (o nó apontado não será mais utilizado).

      printf("\nAmizade desfeita com sucesso!\n\n");
    }
  }
}

/*
  Função responsável por excluir um usuário de uma lista de usuários.
  Recebe como parâmetros a lista de usuários e o id do usuário a ser excluído.
  Não há retorno.
*/

void excluiUsuario(Usuario *usuarios, int id) {
  // Criação do ponteiro que irá armazenar o retorno da busca (na lista de usuários) utilizando o id recebido por parâmetro.
  Usuario *usuario = buscaUsuario(usuarios, id);

  // Criação de ponteiros auxiliares do tipo Amigo para a exclusão das amizades do usuário.
  Amigo *aux;
  Amigo *anterior;

  /*
    Caso o usuário não exista na lista passada por parâmetro será impressa uma mensagem de erro.
    Se não serão excluídas as amizades do usuário e posteriormente o próprio usuário.
  */

  if (!usuario || (usuario && usuario->id != id)) {
    printf("\nNao existe um usuario com este id!\n\n");
  } else {
    aux = usuario->amigos->prox; // Ponteiro "aux" recebe o primeiro amigo da lista de amigos (ou NULL caso o usuário não tenha amigos).

    // Laço responsável por percorrer toda a lista de amigos do usuário.    

    while(aux) {
      anterior = aux; // Ponteiro "anterior" recebe o valor do ponteiro "aux";
      aux = aux->prox; // Atualização do ponteiro "aux" para o próximo amigo (nó) da lista.
      excluiAmizade(usuarios, id, anterior->id); // Efetuada a exclusão da amizade entre o usuário a ser excluído e o amigo atual.
    }

    /*
      Se o usuário a ser excluído não for o último da lista (usuario->prox diferente de NULL) então o anterior do próximo usuário do usuário retornado
      pela busca será o anterior do usuário retornado.
    */

    if (usuario->prox) usuario->prox->prev = usuario->prev;

    /*
      Se o usuário a ser excluído não for o primeiro da lista de usuários (usuario->prev diferente de NULL) então
      o próximo usuário do usuário anterior ao retornado pela busca será agora o próximo usuário do retornado.
      Se não (o usuário a ser excluído está no início da lista) então o início da lista de usuários é agora o próximo usuário do usuário retornado pela busca.
    */

    if (usuario->prev) usuario->prev->prox = usuario->prox;
    else usuarios->prox = usuario->prox;

    printf("\nUsuario deletado com sucesso!\n\n");
  }
}

int main() {
  // Criação de variáveis auxiliares.
  int escolha = 0, id1 = 0, id2 = 0;

  // Criação da lista de usuários do sistema.
  Usuario *usuarios = novaListaUsuarios();

  // Criação de ponteiro auxiliar de usuário atual (usado na busca de usuário da opção 1).
  Usuario *usuarioAtual = NULL;

  // Variáveis auxiliares para receber os valores informados para os campos do novo usuário (opção 2).
  int id;
  char nome[50];
  int idade;
  char email[50];
  char enter;

  // Laço responsável por repetir o menu e a operação enquanto o usuário não escolher sair do programa.

  do {
    printf("----Menu de opcoes----\n");
    printf("1 - Buscar usuario\n2 - Criar usuario\n3 - Excluir usuario\n4 - Cadastrar amizade\n");
    printf("5 - Listar amigos em comum\n6 - Excluir amizade\n7 - Sair\n\n");
    printf("Sua escolha: ");
    scanf("%d", &escolha);

    // Estrutura condicional responsável por realizar a operação de acordo a escolha do usuário.

    switch(escolha) {
      case 1:
        printf("\nInforme o id do usuario: ");
        scanf("%d", &id1);
        // Busca pelo usuário na lista de usuários utilizando a função buscaUsuario passando como parâmetro o id digitado.
        usuarioAtual = buscaUsuario(usuarios, id1);

        /*
          Se o usuário existir é utilizada a função imprimeUsuario para imprimir seus dados.
          Se não, é impressa uma mensagem informando que o usuário não foi encontrado.
        */

        if (usuarioAtual && usuarioAtual->id == id1) imprimeUsuario(usuarioAtual);
        else printf("\nUsuario nao encontrado no sistema!\n\n");
        break;
      case 2:
        // Leitura dos dados do usuário a ser criado.
        printf("\nInforme o id: ");
        scanf("%d", &id);
        scanf("%c", &enter);
        printf("Informe o nome: ");
        scanf("%[^\n]", nome);
        printf("Informe a idade: ");
        scanf("%d", &idade);
        printf("Informe o email: ");
        scanf("%s", email);
        printf("\n");

        // Inserção do novo usuário na lista de usuário passando seus dados como parâmetros.
        insereUsuario(usuarios, id, nome, idade, email);
        break;
      case 3:
        // Leitura do id do usuário a ser excluído.
        printf("\nInforme o id do usuario: ");
        scanf("%d", &id1);

        // Utilizando a função excluiUsuario passando como parâmetro a lista de usuários e o id lido.
        excluiUsuario(usuarios, id1);
        break;
      case 4:
        // Leitura dos id dos usuários a serem relacionados.
        printf("\nInforme o id do primeiro usuario: ");
        scanf("%d", &id1);
        printf("Informe o id do segundo usuario: ");
        scanf("%d", &id2);

        // Utilizando a função criaAmizade passando a lista de amigos e os ids lidos para efetuar a criação da amizade.
        criaAmizade(usuarios, id1, id2);
        break;
      case 5:
        // Leitura dos ids dos usuários que devem ser listados os amigos em comum.
        printf("\nInforme o id do primeiro usuario: ");
        scanf("%d", &id1);
        printf("Informe o id do segundo usuario: ");
        scanf("%d", &id2);

        listaAmigosEmComum(usuarios, id1, id2);
        break;
      case 6:
        // Leitura dos ids dos usuários que devem ter a amizade desfeita.
        printf("\nInforme o id do primeiro usuario: ");
        scanf("%d", &id1);
        printf("Informe o id do segundo usuario: ");
        scanf("%d", &id2);

        // Utilizando a função excluiAmizade passando a lista de usuários e os ids lidos para efetuar a exclusão da amizade entre os usuários.
        excluiAmizade(usuarios, id1, id2);
        break;
      case 7:
        // Opção de saída (nada será feito).
        break;
      default:
        // Foi lida uma opção inválida.
        printf("\nEscolha invalida!\n\n");
    }
  } while(escolha != 7);

  limpaListaUsuarios(usuarios); // Liberação da memória alocada para os nós da lista de usuários.

  return 0; // Retorno de 0 indicando que o programa foi executado com sucesso.
}
