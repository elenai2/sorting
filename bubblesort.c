#include <stdio.h>

int main (void)
{
    int a[] = {1,3,7,9,0,2,4,5,8,6};
    //bubble sort passa pelos arrays e vai do primeiro ao ultimo numero comparando
    //com o numero mais proximo e so seria trocado se for menor
    //por exemplo 1 seria comparado com 3 porem como 1 e menor que 3 ele nao seria trocado
    int lenght = 10;
    //a quantidade de elementos dentro do arrays
    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < (lenght-1); j++)
        //controla o numero de passos pelo arrays
        {
            for (int j = 0; j < (lenght - 1); j++)  
            //compara os elementos
            {
                if (a[j] > a [j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    //a variavel temporaria salva a[j] dps a[j] vira a[j] + 1 pra fazer a troca entre os elementos
                }   
        }
    }
     //printa os elementos sorted vvvv
    for (int i = 0; i < lenght; i++)
    printf("a[%d] = %d\n", i, a[i]);
    
    return 0;

    

