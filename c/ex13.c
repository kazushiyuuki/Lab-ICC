//Soma dos fatoriais de dos números de 0 até n
#include<stdio.h>
int fatorial(int n){
    int fatorial = 1;
    while(n > 1){
        fatorial *= n;
        n--;
    }
    return fatorial;
}
int main(){
    int n, soma = 0, i = 0;
    scanf(" %i", &n);
    while(i <= n){
        soma += fatorial(i);
        i++;
    }
    printf("%i", soma);
}