//Soma de números primos de 1 até n
#include<stdio.h>
int primo(int n){
    int i = 1, divisores = 0;
    while(i <= n){
        if(n%i == 0){
            divisores++;
        }
        i++;
    }
    if(divisores== 2){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int n, i = 2, soma = 0;
    scanf(" %i", &n);
    while(i <= n){
        if(primo(i) == 1){
            soma += i;
        }
        i++;
    }
    printf("%i", soma);
}