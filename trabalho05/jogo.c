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
    int i, j;
    int linhasIniciais = board->rows;
    int colunasIniciais = board->columns;
    if(linha == 0)
    {
        board->rows++;
        board->pieces = realloc(board->pieces, (board->rows)*sizeof(piece*));
        board->pieces[board->rows-1] = (piece*)malloc(board->columns*sizeof(piece));
        for(i = board->rows-1; i > 0; i--)
        {
            piece *aux = board->pieces[i];
            board->pieces[i] = board->pieces[i-1];
            board->pieces[i-1] = aux;
        }
        for(j = 0; j < board->columns; j++)
        {
            board->pieces[i][j].cor = ' ';
            board->pieces[i][j].formato = ' ';
        }

    }
    if(linha == linhasIniciais - 1)
    {
        board->rows++;
        board->pieces = realloc(board->pieces, (board->rows)*sizeof(piece*));
        board->pieces[board->rows-1] = (piece*)malloc(board->columns*sizeof(piece));
        for(j = 0; j < board->columns; j++)
        {
            board->pieces[board->rows-1][j].cor = ' ';
            board->pieces[board->rows-1][j].formato = ' ';
        }
    }
    if(coluna == 0)
    {
        board->columns++;
        for(i = 0; i < board->rows; i++)
        {
            board->pieces[i] = realloc(board->pieces[i], (board->columns)*sizeof(piece));
            for(j = board->columns-1; j > 0; j--)
            {
                piece aux = board->pieces[i][j];
                board->pieces[i][j] = board->pieces[i][j-1];
                board->pieces[i][j-1] = aux;
            }
            board->pieces[i][j].cor = ' ';
            board->pieces[i][j].formato = ' ';
        }
    }
    if(coluna == colunasIniciais-1)
    {
        board->columns++;
        for(i = 0; i < board->rows; i++)
        {
            board->pieces[i] = realloc(board->pieces[i], (board->columns)*sizeof(piece));
            board->pieces[i][board->columns-1].cor = ' ';
            board->pieces[i][board->columns-1].formato = ' ';
        }
    }
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
    printBoard(board);
    board->pieces[0][0].cor = '1';
    board->pieces[0][0].formato = 'E';
    reallocBoard(board, 0, 0);
    printBoard(board);
    board->pieces[1][2].cor = '2';
    board->pieces[1][2].formato = 'E';
    reallocBoard(board, 1, 2);
    printBoard(board);
}

