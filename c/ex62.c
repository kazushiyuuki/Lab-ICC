//Printa a qtd de vogais em uma string digitada
#include<stdio.h>
int main()
{
    char str[100];
    fgets(str, 100, stdin);
    int i = 0, cont_vogal = 0;
    while(str[i]){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            cont_vogal++;
        }
        i++;
    }
    printf("%d", cont_vogal);
}