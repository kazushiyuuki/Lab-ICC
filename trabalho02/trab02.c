//Decodificador de senhas - Lê o tamanho de substring e busca a mais frequente
#include<stdio.h>
int main()
{
    int tam_substring;
    scanf(" %d ", &tam_substring);
    char msg[100];
    fgets(msg, 100, stdin);
    int tam_senha = 0;
    while(msg[tam_senha] != '\n')
    {
        tam_senha++;
    }
    if(tam_senha <= tam_substring)
    {
        printf("%s", msg);
    }
    else{
        int qtd_substring = tam_senha - tam_substring + 1;
        char matriz_substring[qtd_substring][tam_substring];
        int i, j, aux = 0;
        for(i = 0; i < qtd_substring; i++)
        {
            for(j = 0; j < tam_substring; j++)
            {
                matriz_substring[i][j] = msg[aux+j];
            }
            aux++;
        }
        int indice_senha = 0, frequencia = 0, controle = 0, k, frequencia_maior = 0;
        for(k = 0; k < qtd_substring; k++)
        {
            for(i = 0; i < qtd_substring; i++)
            {
                for(j = 0; j < tam_substring; j++){
                    if(matriz_substring[i][j] != matriz_substring[k][j])
                    {
                        controle = 1;
                    }
                }
                if(controle == 0)
                {
                    frequencia++;
                }
                else
                {
                    controle = 0;
                }
            }
            if(frequencia_maior < frequencia)
            {
                frequencia_maior = frequencia;
                indice_senha = k;
            }
            frequencia = 0;
        }
        for(j = 0; j < tam_substring; j++)
        {
            printf("%c", matriz_substring[indice_senha][j]);
        }
        printf("\n");
    }
}