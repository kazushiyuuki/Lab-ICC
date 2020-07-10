 #include"jogo.h"

typedef struct aux
{
    piece info;
    struct aux * prox;
}carta, * pontCarta;

typedef struct
{
    pontCarta inicio;
    pontCarta fim;
    int qtdCartas;
}deque;

typedef deque * pontDeque;

pontDeque iniciarDeque();

pontDeque gerarMonte();

void resetarDeque(pontDeque deque);