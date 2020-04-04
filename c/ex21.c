//Valor da viagem
//Lê uma distância d, dois valores por km e a distancia a ser percorrida
//um valor vale para distâncias até d e outro para maiores
#include<stdio.h>
int main(){
    float d, v1, v2, x, total;
    scanf(" %f %f %f %f", &d, &v1, &v2, &x); 
    if(x <= d){
        total = x*v1;
    }else{
        total = x*v2;
    }
    printf("%.2f", total);
    return 0;
}