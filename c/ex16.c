//Cálculo de potência usando somas
#include<stdio.h>
int mult(int a, int b){
    int soma = 0;
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
    return soma;
}
int main(){
    int a, b, potencia = 1;
    scanf(" %i %i", &a, &b);
    while(b > 0){
        potencia = mult(potencia, a);
        b--;
    }
    printf("%i", potencia);
}