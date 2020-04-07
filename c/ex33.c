//Imprime os n primeiros números, n fornecido pelo usuário, da sequência de Fibonacci
#include<stdio.h>
int main(){
    int n;
    long int fib = 1, controle = 0;
    scanf(" %d", &n);
    while(n > 0){
        printf("%ld ", fib);
        int aux;
        aux = fib;
        fib += controle;
        controle = aux;
        n--;
    }
}