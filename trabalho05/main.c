#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"jogadores.h"

int main()
{
    int controleJogar = 1;
    while(controleJogar == 1)
    {
        pont board = startBoard();
        pontDeque monte = iniciarDeque();
        int qtdJogs;
        char aux[2];
        printf("Digite o numero de jogadores: ");
        fgetss(aux, 1, "Numero de jogadores");
        qtdJogs = atoi(aux);
        /*
        while(qtdJogs < 2 && qtdJogs > 4)
        {
            printf("Digite novamente o numero de jogadores, quantidade minima de 2 e maxima de 4 jogadores: ");
            scanf("%d", &qtdJogs);
        }
        */
        pontJogadores inicio =  iniciarJogs(monte, qtdJogs);
        pontJogadores jogAtual;
        jogAtual = inicio;
        int i = 1;
        while(jogAtual != NULL)
        {
            char nome[21];
            printf("Digite o nome do jogador %d: ", i);
            fgetss(nome, 20, "Nome");
            strcpy(jogAtual->nome, nome);
            jogAtual = jogAtual->proxJog;
            i++;
        }
        /*
        while(monte->qtdCartas != 0)
        {
            jogAtual = inicio;
            while(jogAtual != NULL)
            {
                leituraComandos(board, monte, jogAtual);
                jogAtual = jogAtual->proxJog;
            }
        }
        */
        //Verificando se o usuário quer jogar em cheat mode
        printf("Cheat mode (S/N): ");
        char cheat;
        scanf(" %c", &cheat);
        if(cheat == 's' || cheat == 'n'){
            cheat = cheat - 32;
        }
        while(cheat != 'S' && cheat != 'N'){
            printf("Cheat mode (S/N): ");
            scanf(" %c", &cheat);
            if(cheat == 's' || cheat == 'n'){
                cheat = cheat - 32;
            }
        }
        getchar();
        //Apenas para teste
        jogAtual = inicio;
        leituraComandos(board, monte, jogAtual, cheat);
        jogAtual->pontos = 12;
        leituraComandos(board, monte, jogAtual->proxJog, cheat);
        jogAtual->proxJog->pontos = 12;
        selecionarVencedor(inicio);
        controleJogar = 2;
    }
}