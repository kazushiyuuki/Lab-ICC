//Calcula o x^n
#include<stdio.h>
int xelevadon(int x, int n){
    if(n==1){
        return x;
    }
    else{
        return x * xelevadon(x, n-1);
    }
}