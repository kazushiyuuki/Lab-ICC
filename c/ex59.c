// Imprime os caracteres de um string
#include<stdio.h>
int main()
{
    char s[100];
    fgets(s, 100, stdin);
    int i = 0;
    while(s[i])
    {
        i++;
    }
    s[i-1] = '\0';
    i = 0;
    while(s[i]){
        printf("%c ", s[i]);
        i++;
    }
}