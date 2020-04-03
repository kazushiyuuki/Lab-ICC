//Verifica se o número é primo ou não
#include<stdio.h>
int main(){
    int n, soma_divisores = 0, i = 1;
    scanf(" %i", &n);
    while(i <= n){
        if(n%i == 0){
            soma_divisores++;
        }
        i++;
    }
    if(soma_divisores == 2){
        printf("%i", 1);
    }else{
        printf("%i", 0);
    }
}