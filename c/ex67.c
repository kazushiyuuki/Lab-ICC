//Intercala dois vetores ordenados em outro também ordenado
#include<stdio.h>
int main()
{
    int n;
    scanf(" %d", &n);
    int a[n], i;
    for(i = 0; i < n; i++)
    {
        scanf(" %d", &a[i]);
    }
    int m;
    scanf(" %d", &m);
    int b[m];
    for(i = 0; i < m; i++)
    {
        scanf(" %d", &b[i]);
    }
    int c[n + m], j = 0, k = 0;
    for(i = 0; i < n + m; i++)
    {
        if(j < n && k < m)
        {
            if(b[k] < a[j]){
                c[i] = b[k];
                k++;
            }
            else{
                c[i] = a[j];
                j++;
            }
        }
        else{
            if(j < n){
                c[i] = a[j];
                j++;
            }
            else{
                c[i] = b[k];
                k++;
            }
        }
    }
    for(i = 0; i < n + m; i++)
    {
        printf("%d ", c[i]);
        if(i == n + m - 1){
            printf("\n");
        }
    }
}