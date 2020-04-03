//Potência por estrutura de repetição
#include<stdio.h>
int main(){
    int a, b, potencia = 1;
    scanf(" %i %i", &a, &b);
    while(b > 0){
        potencia *= a;
        b--;
    }
    printf("%i", potencia);
}