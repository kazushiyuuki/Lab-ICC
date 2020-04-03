//Chocolates
//Informa a quantidade de chocolates que é possível obter
//Sabe-se o preço do chocolate
//O dinheiro disponível
//E a quantidade embalagens de chocolates necessárias para trocar por um novo
#include<stdio.h>
int main(){
    int dinheiro, preco, promo, qtd_emb, qtd_choc = 0;
    scanf(" %i\n %i\n %i", &dinheiro, &preco, &promo);
    qtd_emb = dinheiro / preco;
    qtd_choc = qtd_emb;
    while(qtd_emb >= promo){
        qtd_choc++;
        qtd_emb = qtd_emb - promo + 1;
    }
    printf("%i", qtd_choc);
    return 0;
}