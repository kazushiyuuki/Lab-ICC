//Cálculo do salário com bônus
//Lê o salário e o total de vendas 
//O salário final é o salário mais 18% do total de vendas
#include<stdio.h>
int main(){
    float salario, vendas;
    scanf(" %f\n %f", &salario, &vendas);
    printf("%.2f", (salario+0.18*vendas));
}