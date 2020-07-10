typedef struct
{
    char formato;
    char cor;
}piece;

typedef struct 
{
    piece ** pieces;
    int rows;
    int columns;
}board;

typedef board * pont;

pont startBoard();

void reallocBoard(pont board, int linha, int coluna);

void resetBoard(pont board);

void printBoard(pont board);