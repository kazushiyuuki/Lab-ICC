//Printa o tamanho de uma string lida
#include<stdio.h>
int main()
{
    char str[100];
    fgets(str, 100, stdin);
    int i, tam;
    for(i = 0; str[i]; i++){
        if(str[i] == '\n'){
            tam = i;
        }
    }
    printf("%d", tam);
}