//Printa o maior número e sua respectiva posição no vetor
#include<stdio.h>
int main()
{
    int n = 0;
    scanf(" %d", &n);
    int vet[n];
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &vet[i]);
    }
    int maior = vet[0], posicao = 0;
    for (int i = 0; i < n; i++)
    {
        if(vet[i] > maior){
            maior = vet[i];
            posicao = i;
        }
    }
    printf("%d\n%d", maior, posicao);
}