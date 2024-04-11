#include <stdio.h>
#include <stdlib.h>

char *isGreater(int *num1, const int num2)
{
  // Dereference precisa ser feita antes de somar o num1 + 1,
  // pois no parametro da função recebemos um POINTER e aqui estamos
  // fazendo dereference para mutar a variável em si
  (*num1)++;

  return (*num1 > num2) ? "true" : "false";
}

int main()
{
  // malloc retorna um (void *) que automaticamente infere um tipo baseado na variavel
  int *ptr_NUM = malloc(sizeof(int));

  // Printa o valor da memória em hexadecimal (ex: 0x7ffec3ad989c)
  printf("%p \n", ptr_NUM);

  // Printa o valor de quem está sendo apontado
  printf("%d \n", *ptr_NUM);

  // Uma array inteira não pode ser passada como paramêtro de função
  int arr[] = {23, 10, 5};

  // Printa quantos elementos tem em uma array dividindo a somatória total de bytes da array
  // pelo byte do primeiro elemento, pois todos os elementos da array tem o mesmo byte
  printf("%d \n", sizeof(arr) / sizeof(arr[0]));

  // Aqui passamos o endereço em memória da variável para função
  printf("%s \n", isGreater(ptr_NUM, 2));

  // Vemos que o valor do ponteiro mudou pela função isGreater que passou
  // o ponteiro como paramêtro
  printf("POINTER: %d", *ptr_NUM);

  // Use free para liberar espaço de memória de um ponteiro que teve sua memória alocada
  // dinamicamente com o malloc
  free(ptr_NUM);

  // Retorno 0 significa sucesso
  // Retorno 1 significa erro
  return 0;
}