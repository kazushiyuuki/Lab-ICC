//Intercala dois vetores
#include<stdio.h>
int main()
{
    int n = 0;
    scanf(" %d", &n);
    int a[n], b[n], i;
    for(i = 0; i < n; i++)
    {
        scanf(" %d", &a[i]);
    }
    for(i = 0; i < n; i++)
    {
        scanf(" %d", &b[i]);
    }
    int c[2*n], cont = 0;
    for(i = 0; i < (2*n); i+=2)
    {
        c[i] = a[cont]; 
        cont++;
    }
    cont = 0;
    for(i = 1; i < (2*n); i+=2)
    {
        c[i] = b[cont];
        cont++;
    }
    for (i = 0; i < (2*n); i++)
    {
        printf("%d ", c[i]);
    }    
}