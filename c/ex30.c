//Esse algoritmo lê N inteiros  e imprime os dois maiores dos lidos em ordem decrescente
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, maior1, maior2, aux, num=0;
    setbuf(stdin, NULL);
    scanf(" %i", &n);
    aux = n;
    while(n>=1){
        setbuf(stdin, NULL);
        scanf(" %i", &num);
        if(aux == n){
            maior1 = num;
        }
        else if((aux-1) == n){
            maior2 = num;
        }
        if(num > maior1){
            maior2 = maior1;
            maior1 = num;
        }
        else if(num > maior2){
            maior2 = num;
        }
        n--;
    }

    printf("%i\n%i", maior1, maior2);
    return 0;
}