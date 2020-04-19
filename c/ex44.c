//Soma dois vetores
#include<stdio.h>
int main()
{
    int n = 0;
    scanf(" %d", &n);
    int vet1[n], vet2[n], i;
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &vet1[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &vet2[i]);
    }
    int vet_res[n];
    for(i = 0; i < n; i++)
    {
        vet_res[i] = vet1[i] + vet2[i];
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", vet_res[i]);
    }
}