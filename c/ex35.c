//Verica o tamanho da maior sequência de números crescentes lidos
#include<stdio.h>
int main(){
    int n = 1;
    scanf(" %d", &n);
    int vet[n];
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &vet[i]);
    }
    int tam_seq = 1, maior = 1;
    for (int j = 1; j < n; j++)
    {
        if(vet[j] >= vet[j-1]){
            tam_seq++;
        }
        else{
            tam_seq = 1;
        }
        if(tam_seq > maior){
            maior = tam_seq;
        }
    }
    printf("%d", maior);
}