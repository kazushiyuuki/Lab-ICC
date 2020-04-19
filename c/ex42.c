//Escreve um vetor em ordem inversa
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
    for(i = (n-1); i >= 0; i--)
    {
        printf("%d ", vet[i]);
    }
}