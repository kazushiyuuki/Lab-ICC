//Verifica se o número é palíndromo
#include<stdio.h>
int exponenciacao(int x, int n){
    int exp = 1;
    while(n > 0){
        exp *= x;
        n--;
    }
    return exp;
}
int main(){
    int n, aux, cont = 0, soma = 0;
    scanf(" %i", &n);
    aux = n;
    while(aux > 0){
        aux = aux / 10;
        cont++;
    }
    aux = n;
    cont--;
    while(aux > 0){
        int temp;
        temp = aux % 10;
        soma += temp * exponenciacao(10, cont);
        cont--;
        aux = aux / 10;
    }
    if(soma == n){
        printf("S");
    }
    else{
        printf("N");
    }
}