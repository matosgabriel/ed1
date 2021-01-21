// Nome: Gabriel Alves Matos

#include <stdio.h>
#include <stdlib.h>


// a)
int buscaBinaria(int *V, int inicio, int fim, int num) {
  int meio = 0;

  if(inicio <= fim) {
    meio = (inicio + fim) / 2;

    if (num < V[meio]) {
      return buscaBinaria(V, inicio, (meio-1), num);  // Passo recursivo
    } else if (num > V[meio]) {
      return buscaBinaria(V, (meio+1), fim, num);     // Passo recursivo
    }else {
      return meio; // Caso base
    }
  } else {
    return -1;     // Caso base
  }
}

/*
  b) O código sempre converge para o(s) caso(s) base pois, caso o número buscado exista no vetor, a sua posição será retornada. Uma vez que o intervalo de busca é
  reduzido sucessivamente e é verificada a posição meio em cada nova execução da função.
  Já para o caso de o número não existir no vetor, o intervalo será diminuído sucessivamente até que tenha somente 1 posição a ser verificada (para este caso inicio = fim),
  assim dependendo do número buscado o inicio será acrescido em 1 ou o fim será decrescido em 1, tornando assim o inicio maior que o fim. Como a condição do primeiro if
  é que inicio seja menor ou igual a fim, o código dentro do else será executado retornando -1.
*/

/*
  c) O passo recursivo é chamar novamente a função passando os novos valores para as variáveis inicio e fim caso o número buscado não esteja na posição meio do vetor.
  O subproblema é realizar a busca binária, ou seja, comparar (verificar se é igual, maior ou menor) o valor do vetor na posição meio com o número
  buscado no novo subintervalo que é menor que o anterior.
*/

// d)
int main() {
  int *vet = NULL;
  int num = 0;
  int n = 0;
  int pos = -1;
  int i = 0;

  printf("Informe o tamanho do vetor: ");
  scanf("%d", &n);

  vet = (int *) malloc(n * sizeof(int));

  printf("\nLembre-se, o vetor deve estar ordenado e somente com valores inteiros!\n\n");

  for(i = 0; i < n; i++) {
    printf("Informe o valor da %da posicao: ", i+1);
    scanf("%d", &vet[i]);
  }

  printf("\n[");
  for(i = 0; i < n; i++) {
    i == (n-1) ? printf("%d", vet[i]) : printf("%d, ", vet[i]);
  }
  printf("]\n");

  printf("\nInforme o numero que deseja buscar: ");
  scanf("%d", &num);

  pos = buscaBinaria(vet, 0, (n-1), num);

  if (pos != -1) {
    printf("\n%d esta na %da posicao!", num, pos + 1);
  } else {
    printf("\nO elemento informado nao existe no vetor.");
  }

  free(vet);
}
