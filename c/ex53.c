//Lê uma matriz e printa as somas das colunas
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
    for(j = 0; j < m; j++){
        int soma = 0;
        for(i = 0; i < n; i++){
            soma += mat[i][j];
        }
        printf("%d\n", soma);
    }
}