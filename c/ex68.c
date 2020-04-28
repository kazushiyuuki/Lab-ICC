//Verifica se a string lida é um palíndromo
#include<stdio.h>
int main()
{
    char str[100];
    fgets(str, 100, stdin);
    int cont = 0;
    while(str[cont])
    {
        cont++;
    }
    cont--;
    int i = 0, j = cont - 1, meio = cont/2, controle = 0, aux = 0;
    while(aux <= meio){
        if(str[i] == ' '){
            i++;
        }
        if(str[j] == ' '){
            j--;
        }
        if(str[i] != str[j]){
            controle = 1;
        }
        i++;
        j--;
        aux++;
    }
    if(controle == 0){
        printf("%d\n", 1);
    }
    else{
        printf("%d\n", 0);
    }
}