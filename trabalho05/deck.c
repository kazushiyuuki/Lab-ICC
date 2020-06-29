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

    char formato[] = {'Q','C','L', 'E', 'F', 'S'};
    int cor[] = {1, 2, 3, 4, 5, 6};
    int qtd[] = {3, 3, 3, 3, 3, 3};
    srand(time(0));

    int num;
    pontCarta ant;
    //Tá tudo torto, primeiro pensar em alguma forma de sortear todas as 36 cartas, e também consertar o preenchimento do deque
    while(aux->qtdCartas < 108)
    {
        num = rand()%6;
        while(qtd[num] == 0)
        {
            num = (num+1)%6;
        }
        for(int i=0; i < 6; i++)
        {
            printf("-%d-", qtd[i]);
        }
        pontCarta card = (pontCarta)malloc(sizeof(carta));
        card->info.cor = cor[num];
        card->info.formato = formato[num];
        qtd[num]--;
        aux->qtdCartas++; 

        printf("%d : [%c%d]\n", aux->qtdCartas, card->info.formato, card->info.cor);
        free(card);

        if(aux->qtdCartas == 0)
        {
            aux->inicio = card;
            ant = aux->inicio;
        }
        else
        {
            ant->prox = card;
            ant = card;
        }
    }
    return aux;
}

void resetarDeque(pontDeque deque)
{
    pontCarta aux = deque->inicio;
    pontCarta apagar;
    while(deque->qtdCartas != 0)
    {
        apagar = aux;
        if(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        free(apagar);
        deque->qtdCartas--;
    }
}

int main()
{
    pontDeque deque = iniciarDeque();
    resetarDeque(deque);
}
