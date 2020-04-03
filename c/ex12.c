//Cálculo de fatorial ne um número
#include<stdio.h>
int main(){
    int n, fatorial = 1;
    scanf(" %i", &n);
    while(n > 1){
        fatorial *= n;
        n--;
    }
    printf("%i", fatorial);
}