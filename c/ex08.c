//Dado um número n, retorna-se o número harmônico H de ordem n
//H = 1 + 1/2 + 1/3 + ... + 1/n
#include<stdio.h>
int main(){
    int n, i = 1;
    double h = 0.0;
    scanf(" %i", &n);
    while(i <= n){
        h += 1.0 / i;
        i++;
    }
    printf("%.4f", h);
    return 0;
}