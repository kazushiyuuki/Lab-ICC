//Lê os valores de uma matriz em linha, e printa no formato matricial
#include<stdio.h>
int main()
{
    int n, m;
    scanf(" %d %d", &n, &m);
    int mat[n][m], i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf(" %d", &mat[i][j]);
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}