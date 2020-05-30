#include<stdio.h>
#include "conta.h"
#include "entrada.h"
#include "saida.h"
int main()
{
    int x, y;
    leianumeros(&x, &y);
    int s = soma(x, y);
    imprimeresultado(s);
}