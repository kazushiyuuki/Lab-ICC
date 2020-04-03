//Soma das raízes de uma eq. do segundo grau 
#include<stdio.h>
int main(){
    float a, b, c, delta;
    scanf(" %f\n %f\n %f", &a, &b, &c);
    delta = b*b - 4*a*c;
    float soma;
    if(delta >= 0){
        soma = -b/a;
        printf("%.2f", soma);
    }
    else{
        printf("nan");
    }
}