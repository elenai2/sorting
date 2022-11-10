#include <stdio.h>

int main ()
    {
        int a[] = {8,4,9,5,7,6,3,2};
        //comecamos com a esquerda e comparamos o primeiro numero ao segundo se o primeirro numero
        //maior que o proximo numero entao inserimos o segundo numero logo apos o menor valor que ele
        
        insertion_sort(a,8);
        for (int i = 0; i < 8; i++)
            printf ("a[%d] = %d\n", i, a[i]);
            //print dos elementos sorted
        
    
        return 0;
        
    }
    void insertion_sort(int a[], int lenght)
    {
        for (int i = 1; i < lenght; i++)
        {
            int key = a [i];
            int j = i - 1;
        //o loop ve todos os elementos do array um por um (o primeiro nao e peciso ser feito por
        //isso temos -1)
        while (j >= 0 && a[j] > key)
        {
            a[j + 1 ] = a[j];
            j = j -1;
            //o while vai ver se o numeor e menor que o numero
        }
        a[j + 1] = key;
        //vai inserir o numero
        
        }
    }
{