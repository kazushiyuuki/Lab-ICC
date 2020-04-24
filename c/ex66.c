//Lê um número em base binária e converte para decimal
#include<stdio.h>
int pot(int n, int x){
    int pot = 1;
    while(x > 0){
        pot *= n;
        x--;
    }
    return pot;
}
int main()
{
    char bin[50];
    fgets(bin, 50, stdin);
    int cont = 0, i;
    for(i = 0; bin[i] != '\0'; i++){
        cont++;
    }
    cont -= 2;
    int soma = 0;
    for(i = 0; bin[i] != '\0'; i++){
        if(bin[i] == '1'){
            soma += pot(2, cont);
        }
        cont--;
    }
    printf("%d\n", soma);
}