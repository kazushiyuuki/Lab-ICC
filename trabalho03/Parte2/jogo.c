#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void zerarTab(char ** tab, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tab[i][j] = ' ';
        }
    }
}

void player(char ** tab, char c, int *x, int *y){
    int lin,col;
    do{
        scanf("%d %d",&lin,&col);
    }while(tab[lin][col] != ' ');

    *x = lin;
    *y = col; 
    tab[lin][col] = c;
}

void cpu(char ** tab,int n, char c, int jogadas, int *x, int * y){
    char ** vazias = (char **) malloc(jogadas * sizeof(char *));
    int ** pos = (int **) malloc(jogadas*sizeof(int *));

    for(int i=0;i<jogadas;i++){
        pos[i] = (int *) malloc(2*sizeof(int));
    }

    int aux = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(tab[i][j] == ' '){
                vazias[aux] = &tab[i][j];
                pos[aux][0] = i;
                pos[aux][1] = j;
                aux++;
            }
        }
    }

    srand(time(NULL));
    int selec = rand() % jogadas;

    *x = pos[selec][0];
    *y = pos[selec][1];
    *vazias[selec] = c;

    for(int i=0; i < jogadas; i++)
    {
        free(pos[i]);
    }
    free(vazias);
    free(pos);
}

int verificar(char ** tab,int x, int y, int n,int min,char c, int jogador){
    int lin = 0;
    int col = 0;

    for(int i=0;i<n;i++){
        if(tab[x][i] == c){
            lin++;
        }else if(lin < min){
            lin = 0;
        }
        
        if(tab[i][y] == c){
            col++;
        }else if(col< min){
            col = 0;
        }
    }

    if(lin >= min || col >= min){
        return jogador;
    }else{
        int cimaX = x-1;
        int cimaY = y-1;
        int baixoX = x+1;
        int baixoY = y+1;
        int soma = 1;
        while(cimaX >= 0 && cimaY >= 0 && tab[cimaX][cimaY] == c && soma < min){
            cimaX--;
            cimaY--;
            soma++;
        }
        while(baixoX < n && baixoY < n && tab[baixoX][baixoY] == c && soma < min){
            baixoX++;
            baixoY++;
            soma++;
        }

        if(soma == min){
            return jogador;
        }

        cimaX = x-1;
        cimaY = y+1;
        baixoX = x+1;
        baixoY = y-1;
        soma = 1;

        while(cimaX >= 0 && cimaY < n && tab[cimaX][cimaY] == c && soma < min){
            cimaX--;
            cimaY++;
            soma++;
        }
        while(baixoX < n && baixoY >= 0 && tab[baixoX][baixoY] == c && soma < min){
            baixoX++;
            baixoY--;
            soma++;
        }

        if(soma >= min){
            return jogador;
        }
    }

    return -1;
}


void rendertab(char ** tab,int n,int x, int y){
    printf("\e[1;1H\e[2J");
    printf("  ");
     for(int i=0;i<n;i++){
         printf(" %d ",i);
     }
     printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ", i );
        for(int j=0;j<n;j++){
            printf("[%c]",tab[i][j]);
        }
        printf("\n");
    }
}

void freemat(int n, char **v)
{
  int  i;
  for (i=0; i<n; i++) free (v[i]); 
  free (v);      
}
