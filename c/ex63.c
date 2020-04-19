//Printa a qtd de consoantes de uma string
#include<stdio.h>
int main()
{
    char str[100];
    fgets(str, 100, stdin);
    int i = 0, cont_consoante = 0;
    while(str[i] != '\n'){
        if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != ' ')
        {
            cont_consoante++;
        }
        i++;
    }
    printf("%d", cont_consoante);
}