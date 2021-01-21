// Nome: Gabriel Alves Matos

#include <stdio.h>
#include <stdlib.h>

// a)
int buscaBinaria(int *V, int inicio, int fim, int num) {
  int meio = 0;                   // Complexidade 1

  while(inicio <= fim) {          // Complexidade 1
    meio = (inicio + fim) / 2;    // Complexidade 1

    if (num < V[meio]) {          // Complexidade 1
      fim = meio - 1;             // Complexidade 1
    } else if (num > V[meio]) {   // Complexidade 1
      inicio = meio + 1;          // Complexidade 1
    }else {
      return meio;                // Nas aulas apresentadas não possuia complexidade
    }
  }

  // Para o pior caso teremos complexidade 4 dentro do while (atribuição da variável meio, verificação dos 2 if's e atribuição da variável inicio)
  // Considerando a complexidade 1 da comparação do while e o número máximo de vezes para a repetição (k) teremos complexidade igual a 5*log2(n)

  return -1;                      // Nas aulas apresentadas não possuia complexidade
}

/*
  b) É garantido que o algoritmo termina através da condição do while. Caso seja encontrado o valor em alguma posição esta será retornada.
  Se não for encontrado, o vetor será "dividido" sucessivamente e na última execução do laço while (inicio = fim) caso o número buscado seja menor que o vetor na posição meio
  a variável fim receberá (meio - 1), assim inicio será maior que fim fazendo com que não seja executado o código no interior do while novamente e será retornado o valor -1, já para
  o caso de o número buscado ter valor maior que o vetor na posição meio a variável inicio receberá (meio + 1), assim inicio será maior que fim da mesma forma que o caso anterior.
*/


// c)
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

/*
  d) A quantidade de vezes que o código dentro do while é executado não é fixa uma vez que podemos ter casos diferentes.
  Pode acontecer de se encontrar o número muito rapidamente, reduzir o vetor várias vezes para encontrá-lo ou reduzir o vetor o máximo de vezes e não encontrar o valor procurado.
  Considerando o pior caso (não encontrar o valor), o intervalo do vetor é diminuido na metade sucessivas vezes até sobrar somente uma posição a verificar.
  Tendo um tamanho n, o vetor é "diminuido" da seguinte forma: n, n/2, n/2^2, ..., n/2^k (k = número de repetições para o qual o intervalo é 1 elemento no vetor).
  Para descobrir em quantas repetições o vetor terá somente um elemento a verificar é necessário resolver a igualdade n/2^k = 1

  n/2^k = 1
  2^k = 1
  log2(n) = log2(2^k)
  k = log2(n) (log na base 2)

  O número máximo de divisões para que o vetor tenha seu intervalo diminuído a 1 é aproximadamente igual a k.

  Somando a complexidade da primeira atribuição da variável meio, temos que a complexidade total da função é f(n) = 1 + 5*log2(n).
  O(n) = log2(n)
*/

