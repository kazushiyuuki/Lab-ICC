//Imprime a a fita de DNA lida e sua complementar
#include<stdio.h>
int main()
{
    char dna[1000];
    fgets(dna, 1000, stdin);
    int i = 0;
    while(dna[i])
    {
        i++;
    }
    dna[i-1] = '\0';
    char complementar[i];
    int j;
    for(j = 0; j < i; j++)
    {
        switch (dna[j])
        {
        case 'A':
            complementar[j] = 'T';
            break;
        case 'T':
            complementar[j] = 'A';
            break;
        case 'C':
            complementar[j] = 'G';
            break;
        case 'G':
            complementar[j] = 'C';
            break;
        }
    }
    complementar[i-1] = '\0';
    printf("%s\n%s\n", dna, complementar);
}