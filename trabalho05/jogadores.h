#include"deck.h"

typedef struct auxJog
{
    piece piecesJogador[6];
    int pontos;
    int qtdPieces;
    char nome[21];
    struct auxJog * proxJog;
}jogadores;

typedef jogadores * pontJogadores;

void iniciarPiecesJog(pontDeque monte, pontJogadores jog);

void trocarPiecesJog(pontDeque monte, pontJogadores jog, int pos);

void printarJog(pontJogadores jog);

void joga(pont board, pontDeque monte,pontJogadores jog, char peca, char numero, int linha, int coluna);

int verificarJogada(pont board, char peca, char numero, int linha, int coluna);

void leituraComandos(pont board, pontDeque monte, pontJogadores jog);

void fgetss(char str[], int n, char tipoComando[]);

void toUpper(char str[]);

int verificaPeca(char formato, char cor);

int verificaTroca(pontDeque monte, pontJogadores jog, piece pecas[], int qtdPecasTtroca);

pontJogadores iniciarJogs(pontDeque monte, int qtdJogs);