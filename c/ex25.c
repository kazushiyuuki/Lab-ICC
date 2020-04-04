//Lê o tamanho dos lados de um triângulo e classifica-o
#include<stdio.h>
int main(){
    int a, b, c;
    scanf(" %i %i %i", &a, &b, &c);
    if((a + b) < c || (a + c) < b || (b + c) < a){
        printf("INVALIDO");
    }
    else if(a == b && b == c){
        printf("EQUILATERO");
    }
    else if(a == b || b == c || c == a){
        printf("ISOSCELES");
    }else{
        printf("ESCALENO");
    }
    return 0;
}