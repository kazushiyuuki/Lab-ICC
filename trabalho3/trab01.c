
//Jogo da velha, 3x3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void iniciarTabuleiro(char tabuleiro[3][3])
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            tabuleiro[i][j] = ' ';
        }
    }
}

int verificar(char tabuleiro[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        if(tabuleiro [i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1]== tabuleiro[i][2])
        {
            if(tabuleiro[i][0] == 'X')
            {
                return 1;
            }
            else
            {
                return 0;
            }
             
        }
        else if(tabuleiro [0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
        {
            if(tabuleiro[0][i] == 'X')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    if(tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
        {
            if(tabuleiro[0][0] == 'X')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    else if(tabuleiro[2][0] != ' ' && tabuleiro[2][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[0][2])
    {
        if(tabuleiro[2][0] == 'X')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return -1;
}

int posicaoValida(char c, int x, int y)
{
    if(c != ' ' || x > 2 || x < 0 || y > 2 || y < 0)
    {
        return 0;
    }
    return 1;
}

void inserirJogador(char tabuleiro[3][3])
{
    printf("Digite a posicao desejada: ");
    int x, y;
    scanf("%d %d", &x, &y);
    while(posicaoValida(tabuleiro[x][y], x, y) == 0)
    {
        printf("Posicao invvalida. Digite uma nova posicao: ");
        scanf("%d %d", &x, &y);
    }
    tabuleiro[x][y] = 'X';
}

void inserirComputador(char tabuleiro[3][3])
{
    srand(time(NULL));
    int aux = 0;
    while(aux == 0)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        if(tabuleiro[x][y] == ' ')
        {
            tabuleiro[x][y] = 'O';
            aux = 1;
        }
    }
}

void imprimirTabuleiro(char tabuleiro[3][3])
{
    printf("  0   1   2\n");
    for(int i = 0; i < 3; i++)
    {
        printf("%d %c | %c | %c\n",i, tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
    }
}


int main()
{
    char tabuleiro[3][3];
    char controle = 'S';
    while(controle == 'S')
    {
        iniciarTabuleiro(tabuleiro);
        imprimirTabuleiro(tabuleiro);
        int jogadas = 0, resultado = -1;
        while(jogadas < 9 && resultado == -1)
        {
            inserirJogador(tabuleiro);
            jogadas++;
            resultado = verificar(tabuleiro);
            if(resultado == 1)
            {
                printf("X\n");
            }
            else if(resultado == 0)
            {
                printf("O\n");
            }else if(jogadas < 9)
            {
                inserirComputador(tabuleiro);
                jogadas++;
                resultado = verificar(tabuleiro);
                if(resultado == 1)
                {
                    printf("X\n");
                }
                else if(resultado == 0)
                {
                    printf("O\n");
                }
                else
                {
                    imprimirTabuleiro(tabuleiro);
                }
            }
            else
            {
                printf("Empatou\n");
            }
        }
        imprimirTabuleiro(tabuleiro);
        printf("Deseja jogar novamente: ");
        scanf(" %c", &controle);
    }
}