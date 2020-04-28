//Decompôe o número digitado em números primos
#include<stdio.h>
int main(){
    int n;
    scanf(" %d", &n);
    int primo = 2;
    while(n > 1){
        if(n % primo == 0){
            n = n / primo;
            if(n > 1){
                printf("%d x ", primo);
            }
            else{
                printf("%d", primo);
            }
        }
        else{
            int verificador = 0;
            int temp = primo + 1;
            while(verificador != 1){
                int aux = 2;
                int cont = 2;
                while(aux < temp){
                    if(temp % aux == 0){
                        cont++;
                    }
                    aux++;
                }
                if(cont == 2){
                    verificador = 1;
                }
                else{
                    temp++;
                }
            }
            primo = temp;
        }
    }
}