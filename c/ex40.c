//Busca um número e informa sua posição em um vetor
#include<stdio.h>
int main()
{
    int n = 0;
    scanf(" %d", &n);
    int vet[n], i;
    for(i = 0; i < n; i++)
    {
        scanf(" %d", &vet[i]);
    }
    int busca, pos = -1;
    scanf(" %d", &busca);
    for (i = 0; i < n; i++)
    {
        if(vet[i] == busca){
            pos = i;
            break;
        }
    }
    printf("%d", pos);
}