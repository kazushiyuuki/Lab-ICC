//Lê n números, n determinado pelo usuário, e imprime o maior deles
#include<stdio.h>
int main(){
    int n, i=1, maior;
    scanf(" %i", &n);
    while(i <= n){
        int aux;
        scanf(" %i", &aux);
        if(i == 1){
            maior = aux;
        }else if(aux > maior){
            maior = aux;
        }
        i++;
    }
    printf("%i", maior);
    return 0;
}