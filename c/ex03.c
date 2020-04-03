// Calcula o MDC entre dois números
#include<stdio.h>
int main(){
    int n1, n2;
    scanf(" %i\n %i", &n1, &n2);
    while(n2 > 0){
        n1 = n1 % n2;
        int aux = n1;
        n1 = n2;
        n2 = aux;
    }
    printf("%i", n1);
    return 0;
}