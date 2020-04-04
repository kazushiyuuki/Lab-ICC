//Lê n, lê n números, retorna a qtd do maior
#include<stdio.h>
int main(){
    int velas, maior, qtd=0;
    scanf(" %i", &velas);
    while(velas > 0){
        int tamanho;
        scanf(" %i", &tamanho);
        if(qtd == 0 || tamanho > maior){
            maior = tamanho;
            qtd = 1; 
        }
        else if(tamanho == maior){
            qtd++;
        }
        velas--;
    }
    printf("%i", qtd);
    return 0;
}