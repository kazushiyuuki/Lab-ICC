//Imprime os n primeiros números, n fornecido pelo usuário, da sequência de Fibonacci
#include<stdio.h>
int main(){
    int n;
    unsigned long fib = 1, controle = 0;
    scanf(" %i", &n);
    while(n > 0){
        if(n > 1){
            printf("%lu ", fib);
        }
        else
        {
            printf("%lu", fib);
        }
        
        int aux;
        aux = fib;
        fib += controle;
        controle = aux;
        n--;
    }
}