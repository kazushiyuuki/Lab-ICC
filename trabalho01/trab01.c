//Lê um número inteiro não negativo e inverte-o, ex: 1882 -> 2881
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
    cont--;
    while(n > 0){
        int temp;
        temp = n % 10;
        soma += temp * exponenciacao(10, cont);
        cont--;
        n = n / 10;
    }
    printf("%i", soma);
}