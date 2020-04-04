//Lê um número x
//Depois lê números até que um negativo seja digitado, contando quantos números iguais a x 
#include<stdio.h>
int main(){
    int x, n = 0, qtd = 0;
    scanf(" %i", &x);
    while(n >= 0){
        scanf(" %i", &n);
        if(n == x){
            qtd++;
        }
    }
    printf("%i", qtd);
    return 0;
}