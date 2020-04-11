/*Mostra as possibilidades possíveis para organizar uma quantidade de pedregulhos
dado que eles são organizados em quadriculados com um pedregulho no meio*/
#include<stdio.h>
int main(){
    int n;
    scanf(" %d", &n);
    int linhas = 2, colunas = 2, cont = 0;
    int aux = n;
    while(linhas < aux){
        int pedregulhos = 2*(linhas*colunas) - linhas - colunas + 1;
        while (pedregulhos < n){
            colunas++;
            pedregulhos = 2*(linhas*colunas) - linhas - colunas + 1;
        }
        if(pedregulhos == n){
            cont++;
            printf("%d %d\n", linhas, colunas);
            if(colunas < aux){
                aux = colunas;
            }
        }
        colunas = 2;
        linhas++;
    }
    printf("%d", cont);
}