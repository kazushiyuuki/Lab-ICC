//Lê um vetor e um valor, printa um novo vetor com apenas os elementos diferentes do valor
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
    int valor, cont = 0;
    scanf(" %d", &valor);
    for (i = 0; i < n; i++)
    {
        if(vet[i] == valor)
        {
            cont++;
        }
    }
    int vet_res[n - cont], aux = 0;
    for(i = 0; i < n; i++)
    {
        if(vet[i] != valor)
        {
            vet_res[aux] = vet[i];
            aux++;
        }
    }
    for(i = 0; i < n-cont; i++)
    {
        printf("%d ", vet_res[i]);
    }
    printf("\n");    
}