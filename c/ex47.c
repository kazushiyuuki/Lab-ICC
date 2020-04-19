//Lê um vetor de inteiros e imprime um o vetor formado pelos inteiros maiores que um valor determinado
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
    int valor, cont = 0, maiores[n];
    scanf(" %d", &valor);
    for(i = 0; i < n; i++)
    {
        if(vet[i] > valor){
            maiores[cont] = vet[i];
            cont++;
        }
    }
    for(i = 0; i < cont; i++){
        printf("%d ", maiores[i]);
    }
    printf("\n");
}