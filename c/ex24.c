//Lê n números, determinado pelo usuário, imprime o maior, o menor, a soma
#include<stdio.h>
int main(){
    int n, i = 1, soma = 0, maior, menor;
    scanf(" %i", &n);
    while(i <= n){
        int aux;
        scanf(" %i", &aux);
        if(i == 1){
            maior = aux;
            menor = aux;
        }
        else if(aux > maior){
            maior = aux;
        }
        else if(aux < menor){
            menor = aux;
        }
        soma += aux;
        i++;
    }
    printf("%i\n%i\n%i", maior, menor, soma);
    return 0;
} 