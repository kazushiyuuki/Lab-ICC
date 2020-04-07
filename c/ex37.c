//Lê 7 temperaturas e mostra a qtd delas que estão acima da média
#include<stdio.h>
int main(){
    int temps[7], soma = 0;
    for (int i = 0; i < 7; i++)
    {
        scanf(" %d", &temps[i]);
        soma += temps[i];
    }
    int media = soma/7;
    int qtd = 0;
    for(int j = 0; j < 7; j++){
        if(temps[j] > media){
            qtd++;
        }
    }
    printf("%d", qtd);
}