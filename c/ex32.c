//Verifica se o número é produot de três números consecutivos
#include<stdio.h>
int main(){
    int num, controle = 0, i = 1;
    scanf(" %i", &num);
    while(i < num && controle == 0){
        int temp = i * (i + 1) * (i + 2);
        if(temp == num){
            controle = 1;
        }
        else{
            i++;
        }
    }
    if(controle == 1){
        printf("S");
    }else{
        printf("N");
    }
}