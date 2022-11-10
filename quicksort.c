#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//                   6 , 3 , 7 , 5 , 1 , 3 , [4] 
//                                            | separa tods os numeros que sao
//                                            | menores e maiores que quatro
//                                            | e separam eles 
//                                    3 1 [2] 4 6 7 [5]   mesmo com o 2 e 5
//                                         |         |
//                                       1 2 3       5 7 [6]
//                                                        |
//                                                        6 7

void swap(int *x, int *y);
void quicksort(int array[], int length);
void quicksort_recursion(int array[], int low, int high);
int partition(int array[], int low, int high);

int main()
{
  // cria um array de teste
  int a[] = {10,11,23,44,8,15,3,9,12,45,56,45,45};
  int length = 13;
  
  // usa quicksort para ordenar o array
  quicksort(a, length);
  
  // printa array para garantir que foi sorted
  for (int i = 0; i < length; i++)
    printf("%d ", a[i]);
  printf("\n");

  return 0;
}

// troca o valor do que x está apontando com o valor do que y é
// apontando para, usado para realizar trocas de elementos de array no quicksort
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

// aplica o  quicksort ao array com o comprimento dado
void quicksort(int array[], int length)
{
  // quicksort seleciona aleatoriamente o elemento principal, entao usamos o random
  // para garantir a randomização de nossos números aleatórios
  srand(time(NULL));
  
  // chama o algoritmo recursivo quicksort com nosso array e um
  // limite de índice inferior de 0 e limite de índice alto do elemento final no
  // array... ou seja, aplica quicksort a todo o comprimento do array
  quicksort_recursion(array, 0, length - 1);
}

// aplica a parte recursiva de dividir e conquistar do algoritmo quicksort
// ao array... aplicando quicksort ao array entre os índices baixo-alto
void quicksort_recursion(int array[], int low, int high)
{
  // interrompe a recursão quando baixo >= alto
  if (low < high)
  {
    
   // particiona o array por um pivô e retorna o índice do elemento pivô
    int pivot_index = partition(array, low, high);

    // aplica quicksort ao subarray do lado esquerdo
    quicksort_recursion(array, low, pivot_index - 1);

    // aplica quicksort ao subarray do lado direito
    quicksort_recursion(array, pivot_index + 1, high);
  }
}

// particiona o array entre índices baixo-alto por um valor principal e retorna
// o índice do elemnto  principal
int partition(int array[], int low, int high)
{
  // seleciona aleatoriamente um valor de um elemento principal entre baixo-alto selecionando aleatoriamente um
  // índice no intervalo baixo - alto... fazemos isso em vez de apenas selecionar
  // o último elemento de cada vez porque é tecnicamente possível que sempre
  // selecionar o mesmo elemento principal terá um desempenho ruim se o array acontecer
  // para conter valores de uma forma abaixo do ideal
  int pivot_index = low + (rand() % (high - low));
  
  // troca o elemento no pivot_index pelo elemento no índice alto (ou seja,
  // o último elemento nesta parte do array), isso nos permite
  // aplica o algoritmo de particionamento abaixo
  if (pivot_index != high)
    swap(&array[pivot_index], &array[high]);
  
  // o valor do elemento principal agora é o que estiver no índice alto
  int pivot_value = array[high];
  
  
// o algoritmo de particionamento mudará os elementos que são menores que o elemento principal
  // valor para a parte frontal dos índices de array baixo - alto, com i mantendo
  // rastreia onde começam os elementos que são maiores que o valor do elemento principal
  int i = low; 
  
  // incrementa j de baixo para cima até mas não incluindo o valor do numero principal em alto
  for (int j = low; j < high; j++)
  {
    // se o valor do array em j for menor que o valor do elemento principal, realiza uma troca com
    // o valor no array no índice i... isso efetivamente move este "menos
    // do que os valores de pivô" para a parte frontal, e incrementamos i para
    // reflete onde os valores maiores que o elemento pirncipal agora começam
    if (array[j] <= pivot_value)
    {
      swap(&array[i], &array[j]);
      i++;
    }
  }
  
  // agora sabemos que o valor no índice i é maior ou igual ao elemento principal
  // então trocamos com o valor do elemento pincipal para completar a partição
  swap(&array[i], &array[high]);
  
  // índice i agora contém o valor do elemento principal, então retorne isso para que o
  // função quicksort_recursion sabe onde dividir o array ao aplicar
  // o algoritmo para os subarrays resultantes
  return i;
}