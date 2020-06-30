#include"deck.h"
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

pontDeque iniciarDeque()
{
    pontDeque aux = (pontDeque)malloc(sizeof(deque));
    aux->fim = NULL;
    aux->inicio = NULL;
    aux->qtdCartas = 0;

    pontDeque monte = gerarMonte();
    srand(time(0));
    int passos;
    pontCarta cartaMonte, cartaAnterior;
    while(monte->qtdCartas != 0) 
    {
        if(monte->qtdCartas != 1)
        {
            passos = rand()%(monte->qtdCartas - 1);
        }
        else
        {
            passos = 0;
        }
        cartaAnterior = NULL;
        cartaMonte = monte->inicio;
        while(passos != 0)
        {
            cartaAnterior = cartaMonte;
            cartaMonte = cartaMonte->prox;
            passos--;
        }
        if(cartaAnterior == NULL)
        {
            monte->inicio = monte->inicio->prox;
            monte->qtdCartas--;
        }
        else
        {
            cartaAnterior->prox = cartaMonte->prox;
            monte->qtdCartas--;
        }
        if(aux->inicio == NULL)
        {
            aux->inicio = cartaMonte;
            aux->fim = cartaMonte;
            aux->fim->prox = NULL;
            aux->qtdCartas++;
        }
        else
        {
            pontCarta temp = aux->inicio;
            aux->inicio = cartaMonte;
            aux->inicio->prox = temp;
            aux->qtdCartas++;
        }
        
    }
    return aux;
}

pontDeque gerarMonte()
{
    // Q - Quadrado
    // C - Circulo
    // L - Losango
    // E - Estrela 4 pontas
    // F - Flor
    // S - Superestrela...
    char formato[] = {'Q','C','L', 'E', 'F', 'S'};
    int cor[] = {1, 2, 3, 4, 5, 6};
    pontDeque monte = (pontDeque)malloc(sizeof(deque));
    pontCarta cartaAtual, cartaAnterior = NULL;
    for(int m = 0; m < 3; m++)
    {
        for(int j = 0; j < 6; j++)
        {
            for(int k = 0; k < 6; k++)
            {
                cartaAtual = (pontCarta)malloc(sizeof(carta));
                if(cartaAnterior != NULL)
                {
                    cartaAnterior->prox = cartaAtual;
                }
                else
                {
                    monte->inicio = cartaAtual;
                }
                cartaAtual->info.formato = formato[j];
                cartaAtual->info.cor = cor[k];
                cartaAnterior = cartaAtual;
                monte->qtdCartas++;
                monte->fim = cartaAtual;
            }
        }
    }
    return monte;
}

void resetarDeque(pontDeque deque)
{
    pontCarta aux = deque->inicio;
    pontCarta apagar;
    while(aux != NULL && deque->qtdCartas != 0)
    {
        apagar = aux;
        if(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        free(apagar);
        deque->qtdCartas--;
    }
    free(deque);
}

void printDeque(pontDeque deque)
{
    pontCarta aux = deque->inicio;
    int cont = 1; 
    printf("Imprimindo deque: %d cartas\n", deque->qtdCartas);
    while(aux != NULL && cont <= deque->qtdCartas)
    {
        printf("%d : [%c%d]\n", cont, aux->info.formato, aux->info.cor);
        aux = aux->prox;
        cont++;
    }
    printf("Fim--------------\n");
}
