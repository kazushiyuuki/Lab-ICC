//De acordo com a idade informada
//Retorna se o voto é obrigatório, facultativo ou dispensado
#include<stdio.h>
int main(){
    int idade;
    scanf(" %i", &idade);
    if(idade < 16 || idade >= 70){
        printf("DISPENSADO");
    }else if(idade < 18){
        printf("FACULTATIVO");
    }else{
        printf("OBRIGATORIO");
    }
    return 0;
}