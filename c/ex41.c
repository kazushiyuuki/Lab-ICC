//Conta quantas vezes um número ocorre no vetor
#include<stdio.h>
int main()
{
    int n = 0;
    scanf(" %d", &n);
    int vet[n], i;
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &vet[i]);
    }
    int busca, cont = 0;
    scanf(" %d", &busca);
    for (i = 0; i < n; i++)
    {
        if(vet[i] == busca)
        {
            cont++;
        }
    }
    printf("%d", cont);
}