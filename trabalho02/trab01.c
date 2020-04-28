//Gerador do triângulo de Pascal
#include<stdio.h>
double fat(int n)
{
    double fat = 1;
    while(n > 1)
    {
        fat *= n;
        n--;
    }
    return fat;
}

int main()
{
    int n;
    scanf(" %d", &n);
    double pascal[n][n];
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= i; j++)
        {
            pascal[i][j] = fat(i) / (fat(j) * fat(i - j));
            printf("%.0lf ", pascal[i][j]);
        }
        printf("\n");
    }
}