//Imprime os n primeiros números, n fornecido pelo usuário, da sequência de Fibonacci
#include<stdio.h>
int main(){
    int n, fib =1, controle = 0;
    scanf(" %i", &n);
    while(n > 0){
        printf("%i ", fib);
        int aux;
        aux = fib;
        fib += controle;
        controle = aux;
        n--;
    }
}