//Conta a qtd de um caractere dado em um string dada
#include<stdio.h>
int main()
{
    char str[100];
    fgets(str, 100, stdin);
    char c;
    scanf(" %c", &c);
    int i = 0, cont = 0;
    while(str[i] != '\n')
    {
        if(str[i] == c)
        {
            cont++;
        }
        i++;
    }
    printf("%d", cont);
}