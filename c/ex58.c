//Lê o num de linhas, num de colunas e o elementos de uma matriz, printa na forma matricial a matriz e a sua transposta
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
    int mat_t[m][n];
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            mat_t[i][j] = mat[j][i];
        }
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", mat_t[i][j]);
        }
        printf("\n");
    }
}