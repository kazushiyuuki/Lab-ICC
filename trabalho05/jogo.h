typedef struct aux
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

void resetBoard(pont board);

void printBoard(pont board);

void insertBoard(pont board);