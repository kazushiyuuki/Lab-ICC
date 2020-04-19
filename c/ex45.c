//Soma dos valores de um vetor entre duas posições, inclusive os das posições limitantes
#include<stdio.h>
int main()
{
    int n = 0;
    scanf(" %d", &n);
    int vet[n], k;
    for(k = 0; k < n; k++)
    {
        scanf(" %d", &vet[k]);
    }
    int i, j;
    scanf("%d %d", &i, &j);
    if(i > j)
    {
        int temp = j;
        j = i;
        i = temp;
    }
    if(i < 0 || i >= n || j < 0 || j >= n)
    {
        printf("INVALIDO");
    }
    else{
        int soma = 0;
        for(k = i; k <= j; k++){
            soma += vet[k];
        }
        printf("%d", soma);
    }
}