//Intercala vetores de tamanhos diferentes
#include<stdio.h>
int main()
{
    int n1 = -1;
    scanf(" %d", &n1);
    int a[n1], i;
    for (i = 0; i < n1; i++)
    {
        scanf(" %d", &a[i]);
    }
    int n2 = -1;
    scanf(" %d", &n2);
    int b[n2];
    for (i = 0; i < n2; i++)
    {
        scanf(" %d", &b[i]);
    }
    int res[n1 + n2], cont = 0, j;
    if(n2 > n1){
        for(i = 0; i < (2*n1); i += 2){
            res[i] = b[cont];
            res[i+1] = a[cont];
            cont++;
        }
        for(j = i; j < n1 + n2; j++)
        {
            res[j] = b[cont];
            cont++;
        }
    }
    else{
        for(i = 0; i < (2*n2); i += 2)
        {
            res[i] = a[cont];
            res[i+1] = b[cont];
            cont++;
        }
        for(j = i; j < n1 + n2; j++){
            res[j] = a[cont];
            cont++;
        }
    }
    for (i = 0; i < n1 + n2; i++)
    {
       printf("%d ", res[i]);
    }    
}