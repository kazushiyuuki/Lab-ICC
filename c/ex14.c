//Soma por somas
#include<stdio.h>
int main(){
    int a, b, soma = 0;
    scanf(" %i\n %i", &a, &b);
    if(b > a){
        int aux;
        aux = b;
        b = a;
        a = aux;
    }
    while(b > 0){
        soma += a;
        b--;
    }
    printf("%i", soma);
}