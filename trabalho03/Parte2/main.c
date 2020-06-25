#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"


typedef struct{
    char c;
    int cpu;
}jogador_t;

int main(int argv, char * argc[]){
    int n;
    char reiniciar = 'S';
    do
    {
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
        printf("Numero de jogadores: ");
        scanf("%d",&m);
        jogador_t * jogs = (jogador_t *)malloc(m*sizeof(jogador_t));

        for(int i=0;i<m;i++){
            printf("--JOGADOR %d--\n",i+1);
            printf("Caractere: ");
            scanf(" %c",&jogs[i].c);
            printf("Eh uma cpu? [1] SIM [0] NAO\n");
            scanf("%d",&jogs[i].cpu);
        }

        int jogadas = n*n;
        int vencedor = -1;
        int jogAt=0;
        int ultimoX;
        int ultimoY;
        while(jogadas >0 && vencedor == -1){
            rendertab(tab,n);
            if(jogs[jogAt].cpu == 0){
                player(tab,jogs[jogAt].c,&ultimoX,&ultimoY);
                vencedor = verificar(tab,ultimoX,ultimoY,n,minSeq,jogs[jogAt].c,jogAt);
            }else{
                cpu(tab,n,jogs[jogAt].c,jogadas,&ultimoX,&ultimoY);
                vencedor = verificar(tab,ultimoX,ultimoY,n,minSeq,jogs[jogAt].c,jogAt);
            }
            jogAt = (jogAt+1)%m;
            jogadas--;
        }
        rendertab(tab,n);

        if(vencedor == -1){
            printf("Empate\n");
        }else{
            printf("Jogador %c venceu\n", jogs[vencedor].c);
        }
        printf("Jogar novamente('S' para sim)? ");
        scanf(" %c", &reiniciar);
        freemat(n, tab);
        free(jogs);
    }while(reiniciar == 'S');
}