//Soma da sequência dos números entre dois números dados
//É incluído os dois números limites
#include<stdio.h>
int main(){
    int n, m, soma = 0;
    scanf(" %i\n %i", &n, &m);
    while(m >= n){
        soma += n;
        n++;
    } 
    printf("%i", soma);
    return 0;
}