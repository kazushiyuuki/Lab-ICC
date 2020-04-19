//Insere um elemento em um vetor, printando o vetor resultante
#include<stdio.h>
int main()
{
    int n = 0;
    scanf(" %d", &n);
    int a[n], i;
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &a[i]);
    }
    int indice, valor;
    scanf(" %d %d", &indice, &valor);
    if(indice < 0)
    {
        printf("INVALIDO");
    }
    else
    {
        int vet_res[n+1];
        if(indice >= n)
        {
            for(i = 0; i < n; i++)
            {
                vet_res[i] = a[i];
            }
            vet_res[n] = valor;
        }
        else
        {
            for(i = 0; i < indice; i++){
                vet_res[i] = a[i];
            }
            vet_res[indice] = valor;
            for(i = indice + 1; i <= n; i++){
                vet_res[i] = a[i - 1];
            }
        }
        for(i = 0; i <= n; i++)
        {
            printf("%d ", vet_res[i]);
        }
    }
}