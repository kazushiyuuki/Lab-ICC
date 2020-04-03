//Radar
//Limite de velocidade L
//Aplicado uma multa fixa mais uma taxa por km/h acima do limite
#include<stdio.h>
int main(){
    float limite, fixo, variavel, vel;
    scanf(" %f %f %f %f", &limite, &fixo, &variavel, &vel);
    if(vel > limite){
        printf("%.2f", (fixo + (vel - limite)*variavel));
    }else{
        printf("%.2f", 0.0);
    }
}