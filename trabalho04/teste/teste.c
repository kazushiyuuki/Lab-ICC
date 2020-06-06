#include<stdio.h>

void input(char *string,int length)
{
    int x=0;

    fgets(string,length,stdin);
    while(*string)
    {
        if(*string == '\n')
        {
            *string = '\0';
            return;
        }
        x++;
        if(x == length)
        {
            *string = '\0';
            return;
        }
        string++;
    }
}

int main()
{
    char str[20];
    input(str, 20);
    printf("%s\n", str);
    input(str, 20);
    printf("%s\n", str);
}