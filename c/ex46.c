//Lê um vetor de inteiros e armazena em um vetor os números pares e em outro os ímpares
#include<stdio.h>
int main()
{
    int n = 0;
    scanf(" %d", &n);
    int vet[n], a[n], b[n], cntrl_a = 0, cntrl_b = 0, i = 0;
    for(i = 0; i < n; i++)
    {
        scanf(" %d", &vet[i]);
        if(vet[i] % 2 == 0){
            a[cntrl_a] = vet[i];
            cntrl_a++;
        }
        else{
            b[cntrl_b] = vet[i];
            cntrl_b++;
        }
    }
    for (i = 0; i < cntrl_a; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (i = 0; i < cntrl_b; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");    
}