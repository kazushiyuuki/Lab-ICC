//Imprime os caracteres de uma string em ordem inversa
#include<stdio.h>
int main()
{
    char str[100];
    fgets(str, 100, stdin);
    int i = 0;
    while(str[i]){
        if(str[i] == '\n'){
            str[i] = '\0';
        }
        i++;
    }
    for(i = i - 2; i >= 0; i--)
    {
        printf("%c ", str[i]);
    }
}