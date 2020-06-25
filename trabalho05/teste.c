#include<stdio.h>
#include<malloc.h>
void iniciarBoard(int **tabuleiro, int linhas, int colunas)
{
    printf("Iniciando tabuleiro, %d linhas e  %d colunas\n", linhas, colunas);
    tabuleiro = (int**)malloc(linhas*sizeof(int*));
    for(int i = 0; i < linhas; i++)
    {
        tabuleiro[i] = (int*)malloc(colunas*sizeof(int));
    }
    printf("Tabuleiro iniciado\n");
    imprime(tabuleiro, linhas, colunas);
}

void imprime(int **tabuleiro, int linhas, int colunas)
{
    printf("Imprimindo tabuleiro\n");
    for(int i = 0; i < linhas; i++)
    {
        printf("%d : ", i);
        for(int j = 0; j < colunas; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("Fim\n");
    imprime(tabuleiro, linhas, colunas);
}

void limpar(int **tabuleiro, int linhas)
{
    for(int i = 0; i < linhas; i++)
    {
        free(tabuleiro[i]);
    }
    free(tabuleiro);
}

int main()
{
    int **tabuleiro;
    int linhas = 4, colunas = 3;
    iniciarBoard(tabuleiro, linhas, colunas);
   // imprime(tabuleiro, linhas, colunas);
  //  limpar(tabuleiro, linhas);
}