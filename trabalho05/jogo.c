#include<stdio.h>
#include<malloc.h>
#include"jogo.h"

pont startBoard()
{
    pont board = (pont)malloc(sizeof(board));
    board->rows = 1;
    board->columns = 1;
    board->pieces = (piece**)malloc(sizeof(piece*));
    board->pieces[0] = (piece*)malloc(sizeof(piece));
    return board;
}

void reallocBoard(pont board, int linha, int coluna)
{
    //Função para realocar memória do tabuleiro para mostrar dinamicamente o mesmo
}

void resetBoard(pont board)
{
    for(int i=0; i < board->rows; i++)
    {
        free(board->pieces[i]);
    }
    free(board->pieces);
    free(board);
}

void printBoard(pont board)
{
    char formato, cor;
    for(int i=0; i<board->rows; i++)
    {
        for(int j=0; j<board->columns; j++)
        {
            formato = board->pieces[i][j].formato;
            cor = board->pieces[i][j].cor;
            printf("[%c%c] ", formato, cor);
        }
        printf("\n");
    }
}

void insertBoard(pont board)
{
    board->pieces[0][0].cor = '1';
    board->pieces[0][0].formato = 'E';
}

