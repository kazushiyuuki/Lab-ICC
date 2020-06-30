#include"deck.h"

typedef struct
{
    piece piecesJogador[6];
    int qtdPieces;
}aux;


typedef struct jogadores
{
    aux * deck;
    char nome[20];
};


