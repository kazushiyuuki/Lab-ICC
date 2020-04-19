//Lê um vetor e um índice, remove o elemento do vetor com esse índice
#include<stdio.h>
int main()
{
    int n = 0;
    scanf(" %d", &n);
    int vet[n], i;
    for(i = 0; i < n; i++){
        scanf(" %d", &vet[i]);
    }
    int posicao = -1;
    scanf(" %d", &posicao);
    if(posicao < 0 || posicao >= n)
    {
        printf("INVALIDO");
    }
    else
    {
        int vet_res[n-1], cont = 0;
        for(i = 0; i < n; i++)
        {
            if(i != posicao){
                vet_res[cont] = vet[i];
                cont++;
            }
        }
        for (i = 0; i < (n-1); i++)
        {
            printf("%d ", vet_res[i]);
        }
        printf("\n");        
    }
}