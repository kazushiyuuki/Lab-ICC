//Lê duas strings, printa 1 se ela for um anagrama da outra e 0 para o contrário
#include<stdio.h>
int main()
{
    char str1[100];
    fgets(str1, 100, stdin);
    char str2[100];
    fgets(str2, 100, stdin);
    int i = 0, numChar = 0;
    while(str1[i]){
        if(str1[i] != ' ')
        {
            numChar++;
        }
        i++;
    }
    int aux1,cont = 0;
    for(aux1 = 0; str1[aux1]; aux1++)
    {
        int aux2;
        for(aux2 = 0; str2[aux2]; aux2++){
            if(str1[aux1] == str2[aux2] && str1[aux1] != ' ' && str2[aux2] != ' ')
            {
                cont++;
                str2[aux2] = '0';
            }
        }
    }
    if(cont == numChar)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
}