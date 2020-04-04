//Problema dos cangurus link:https://www.hackerrank.com/challenges/kangaroo/problem
#include<stdio.h>
#include<math.h>
int main(){
    float x1, v1, x2, v2, pulos;
    scanf(" %f %f %f %f", &x1, &v1, &x2, &v2);
    float aux;
    pulos = (x2 - x1)/(v1 - v2);
    aux = fmod((x2- x1), (v1 - v2));
    if(aux == 0){
        if(pulos > 0){
            printf("SIM");
        }
        else{
            printf("NAO");
        }
    }
    else{
        printf("NAO");
    }
    return 0;
}