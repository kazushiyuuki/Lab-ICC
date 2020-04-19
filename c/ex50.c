//Inverte um vetor sem criar outro vetor
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
    int meio = n /2;
    for(i = 0; i < meio; i++){
        int temp = vet[i];
        vet[i] = vet[n - 1 - i];
        vet[n - 1 - i] = temp;
    }
    for(i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}