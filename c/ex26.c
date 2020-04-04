//Lê idades, até ler uma inválida, imprime, média, qtd de maiores de idade e porcetagem de idosos
#include<stdio.h>
int main(){
    int idade = 1, qtd_geral = 0, qtd_maiores = 0, qtd_idosos = 0;
    float soma = 0;
    while(idade >= 0){
        scanf(" %i", &idade);
        if(idade >= 0){
            qtd_geral++;
            soma += idade;
            if(idade >= 18){
                qtd_maiores++;
                if(idade > 75){
                    qtd_idosos++;
                }
            }
        }
        else{
            if(qtd_geral == 0){
                qtd_geral++;
            }
        }
    }
    float media, pocentagem_idosos;
    media = soma / qtd_geral;
    pocentagem_idosos = ((qtd_idosos*1.0)/(qtd_geral))*100;
    printf("%.2f\n%i\n%.2f%%", media, qtd_maiores, pocentagem_idosos);
    return 0;
}