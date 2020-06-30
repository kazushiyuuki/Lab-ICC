#include<stdio.h>
#include"jogadores.h"

int main()
{
    pontDeque monte = iniciarDeque();
    printf("Nome: ");
    printDeque(monte);
    pontJogadores jog = iniciarPiecesJog(monte);
    fgets(jog->nome, 20, stdin);
    printarJog(jog);
    printDeque(monte);
    resetarDeque(monte);
}