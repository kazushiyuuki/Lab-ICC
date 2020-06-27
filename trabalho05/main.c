#include<stdio.h>
#include"jogo.h"

int main()
{
    pont board = startBoard();
    insertBoard(board);
    printBoard(board);
    resetBoard(board);
}