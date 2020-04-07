//Verifica se o número é perfeito, isto é, é igual a soma dos seus divisores positivos diferentes dele mesmo
#include<stdio.h>
int main(){
    int n, aux = 1, soma = 0;
    scanf(" %i", &n);
    while(aux < n){
        if(n % aux == 0){
            soma += aux;
        } 
        aux++;
    }
    if(soma == n){
        printf("S");
    }else{
        printf("N");
    }
}