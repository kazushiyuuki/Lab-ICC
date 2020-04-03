//Lê um sequência de número, imprime a soma de pares, soma de impares e a soma total
#include<stdio.h>
int main(){
    int n = 1, soma_par = 0, soma_impar = 0;
    while(n != 0){
        scanf(" %i", &n);
        if(n%2 == 0){
            soma_par += n;
        }else{
            soma_impar += n;
        }
    }
    printf("%i\n%i\n%i", soma_par, soma_impar, soma_impar+soma_par);
    return 0;
}