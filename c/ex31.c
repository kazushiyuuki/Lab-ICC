//Lê n números e mostra se a sequência deles é crescente ou decrescente
#include<stdio.h>
int main(){
    int n, i = 1, num, controle = 2;
    scanf(" %i", &n);
    while(i <= n){
        int aux;
        scanf(" %i", &aux);
        if(i == 1){
            num = aux;
        }
        else{
            if(num < aux){
                if(controle == 2 || controle == 1){
                    controle = 1;
                    num = aux;
                }else{
                    controle = 0;
                }
            }else if(num > aux){
                if(controle == 2 || controle == -1){
                    controle = -1;
                }
                else{
                    controle = 0;
                }
            }
        }
        i++;
    }
    if(controle == 2){
        controle = 1;
    }
    printf("%i", controle);
    return 0;
}