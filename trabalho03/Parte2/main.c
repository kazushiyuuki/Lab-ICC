#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"


typedef struct{
    char c;
    int cpu;
}jogador_t;

int main(int argv, char * argc[]){
    int n;

    printf("Tamanho do tabuleiro: ");
    scanf("%d",&n);
    char **tab = (char ** )malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        tab[i] = (char *) malloc(n*sizeof(char));
    }

    zerarTab(tab,n);

    int minSeq;
    printf("Sequencia minima para vencer: ");
    scanf("%d",&minSeq);

    int m;
    printf("numero de jogadores: ");
    scanf("%d",&m);
    jogador_t * jogs = (jogador_t *)malloc(m*sizeof(jogador_t));

    for(int i=0;i<m;i++){
        printf("--JOGADOR %d--\n",i+1);
        printf("caracter: ");
        scanf(" %c",&jogs[i].c);
        printf("eh uma cpu? [1] SIM [0] NAO\n");
        scanf("%d",&jogs[i].cpu);
    }

    int jogadas = n*n;
    int vencedor =0;
    int jogAt=0;
    int ultimoX;
    int ultimoY;
    while(jogadas >0 && !vencedor){
        rendertab(tab,n,ultimoX,ultimoY);
        jogAt = (jogAt+1)%m;
        if(jogs[jogAt].cpu == 0){
            player(tab,jogs[jogAt].c,&ultimoX,&ultimoY);
            vencedor = verificar(tab,ultimoX,ultimoY,n,minSeq,jogs[jogAt].c,jogAt);
        }else{
            cpu(tab,n,jogs[jogAt].c,jogadas,&ultimoX,&ultimoY);
            vencedor = verificar(tab,ultimoX,ultimoY,n,minSeq,jogs[jogAt].c,jogAt);
        }
        jogadas--;
    }
    rendertab(tab,n,ultimoX,ultimoY);

    if(vencedor == 0){
        printf("Empate\n");
    }else{
        printf("jogador %c venceu\n", jogs[vencedor].c);
    }
}