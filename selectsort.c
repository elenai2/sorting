#include <stdio.h>

// Exemplo de select sorting
//
// array inicial: 5, 9, 7, 6, 4, 0, 2, 3, 8, 1 (ele compara o 5 com todos os numeros ate achar o menor numeoro deles)
//
//        Passo 0: 0, 9, 7, 6, 4, 5, 2, 3, 8, 1 (o numero 0 e o menor numero portanto ele troca de lugar com o 5)
//        Passo 1: 0, 1, 7, 6, 4, 5, 2, 3, 8, 9 (mesmo acontece porem ele determina que 0 e 1 ja foram sorted e continuam apartir dos 2 primeiros e em diante)
//        Passo 2: 0, 1, 2, 6, 4, 5, 7, 3, 8, 9
//        Passo 3: 0, 1, 2, 3, 4, 5, 7, 6, 8, 9
//        Passo 4: 0, 1, 2, 3, 4, 5, 7, 6, 8, 9
//        Passo 5: 0, 1, 2, 3, 4, 5, 7, 6, 8, 9
//        Passo 6: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
//        Passo 7: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
//        Passo 8: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

int main()
{
  int a[] = {5, 9, 7, 6, 4, 0, 2, 3, 8, 1};
  int length = 10; //o array tem 10 numeros
  
  for (int i = 0; i < length - 1; i++) 
  //loop roda por todos os numeros menos o ultimo pois sorting 1:1 ja e feito automaticamente
  {
    int min_pos = i; 
    //assim o menor numero inicial vai ser sempre o numero que esta sendo trabalhado para ser comparado com os outros
    for (int j = i + 1; j < length; j++)
    //o numero vai mudar sempe que achar um numero que seja menor
      if (a[j] > a[min_pos]) min_pos = j;
      //entao achamos um numero menor que o numero que estamos
    
    if (min_pos != i)
    //em caso de precisar mudar o elemento
    {
      int temp = a[i];
      //variavel temporaria pra a[i]
      a[i] = a[min_pos];
      //depois a[i] vira a[posicao minima]
      a[min_pos] = temp;
      //e a minima vai ter o mesmo valor que a variavel temporaria
    }
  }
  
  // printar os arrays
  for (int i = 0; i < length; i++)
    printf("a[%d] = %d\n", i, a[i]);
  
  return 0;
}