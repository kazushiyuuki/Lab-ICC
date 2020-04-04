//Soma de dígitos de um número
#include<stdio.h>
int main(){
    long long int n;
    int soma = 0;
    scanf(" %lli", &n);
    while(n > 0){
        soma += n % 10;
        n = n / 10;
    }
    printf("%i", soma);
    return 0;
}