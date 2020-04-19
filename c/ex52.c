//Lê uma matriz e imprime as somas das linhas
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
        int soma = 0;
        for(j = 0; j < m; j++){
            soma += mat[i][j];
        }
        printf("%d\n", soma);
    }
}