//Lê dois números e imprime o maior deles
#include<stdio.h>
int main(){
    int n1, n2;
    scanf(" %i", &n1);
    scanf(" %i", &n2);
    if(n1 >= n2){
        printf("%i", n1);
    }
    else{
        printf("%i", n2);
    }
    return 0;
}