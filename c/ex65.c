//Ler um inteiro positivo e imprimir o  seu correspondente em binário
#include<stdio.h>
int main()
{
    int n; 
    scanf(" %d", &n);
    int aux = n, cont = 0;
    while(aux > 0)
    {
        aux = aux / 2;
        cont++;
    }
    aux = n;
    char bin[cont + 1];
    bin[cont] = '\0';
    cont--;
    if(cont == -1){
        bin[0] = '0';
    }
    for(cont = cont; cont >= 0; cont--)
    {
        if(aux % 2 == 1){
            bin[cont] = '1';
        }
        else{
            bin[cont] = '0';
        }
        aux = aux / 2;
    }
    for(cont = 0; bin[cont]; cont++)
    {
        printf("%c", bin[cont]);
    }
    printf("\n");
}