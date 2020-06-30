#include"jogadores.h"
#include<stdio.h>
#include<stdlib.h>

pontJogadores iniciarPiecesJog(pontDeque monte)
{
    pontJogadores jog = (pontJogadores)malloc(sizeof(jogadores));
    pontCarta temp;
    for(int i = 0; i < 6; i++)
    {
        jog->piecesJogador[i].cor = monte->inicio->info.cor;
        jog->piecesJogador[i].formato = monte->inicio->info.formato;
        temp = monte->inicio;
        monte->inicio = monte->inicio->prox;
        monte->qtdCartas--;
        free(temp);
    }
    jog->qtdPieces = 6;
    jog->pontos = 0;
    return jog;
}

void trocarPiecesJog(pontDeque monte, pontJogadores jog, int pos)
{
    pontCarta temp = (pontCarta)malloc(sizeof(carta));
    temp->prox = NULL;
    temp->info.cor = jog->piecesJogador[pos].cor;
    temp->info.formato = jog->piecesJogador[pos].formato;
    monte->fim->prox = temp;

    jog->piecesJogador[pos].cor = monte->inicio->info.cor;
    jog->piecesJogador[pos].formato = monte->inicio->info.formato;

    temp = monte->inicio;
    monte->inicio = monte->inicio->prox;
    free(temp);
}

void printarJog(pontJogadores jog)
{
    printf("Jogador: %s\n", jog->nome);
    for(int i = 0; i < jog->qtdPieces; i++)
    {
        printf("[%c%d] ", jog->piecesJogador[i].formato, jog->piecesJogador[i].cor);
    }
    printf("\n");
}

//Função de leitura, e classificação de funcao de trocar jogar ou passar
//Função de posição valida
//Funcao de contar pontos
