//Pintando a parede
//Informado o custo da lata de tinta e quantos m² ela é capaz de pintar
//E as dimensões da parede, calcula-se o custo para pintar essa parede
#include<stdio.h>
int main(){
    float c, m, l, a;
    scanf(" %f %f %f %f", &l, &a, &c, &m);
    float area = l * a;
    int latas = area / m;
    if(latas * m != area){
        latas++;
    }
    printf("%i\n%.2f", latas, latas*c);
}