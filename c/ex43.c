//Troca valores adjacentes 
#include<stdio.h>
int main()
{
    int n = 0;
    scanf(" %d", &n);
    int vet[n], i;
    for(i = 0; i < n; i++){
        scanf(" %d", &vet[i]);
    }
    for(i = 0; i < (n - 1); i += 2)
    {
        int temp = vet[i+1];
        vet[i+1] = vet[i];
        vet[i] = temp;
    }
    for(i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
}