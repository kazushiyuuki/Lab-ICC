//Verifica se o ano é bissexto
#include<stdio.h>
int main(){
    int ano;
    scanf(" %i", &ano);
    if(ano<=0){
        printf("%i",-1);
    }else if(ano%400 == 0){
        printf("%i", 1);
    }else if(ano%4 == 0 && ano%100 != 0){
        printf("%i", 1);
    }else{
        printf("%i", 0);
    }
}