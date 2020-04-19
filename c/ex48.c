//Lê um vetor de inteiros, coloca o menor valor na primeira posição e o maior na última
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
    int menor = vet[0], pos_menor = 0;
    for(i = 0; i < n; i++){
        if(vet[i] < menor){
            menor = vet[i];
            pos_menor = i;
        }
    }
    vet[pos_menor] = vet[0];
    vet[0] = menor;
    int maior = vet[0], pos_maior = 0;
    for (i = 0; i < n; i++)
    {
        if(vet[i] > maior)
        {
            maior = vet[i];
            pos_maior = i;
        }
    }
    vet[pos_maior] = vet[n-1];
    vet[n-1] = maior;
    for (i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}