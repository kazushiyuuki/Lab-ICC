#include"jogadores.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void iniciarPiecesJog(pontDeque monte, pontJogadores jog)
{
    pontCarta temp;
    for(int i = 0; i < 6; i++)
    {
        jog->piecesJogador[i].cor = monte->inicio->info.cor;
        jog->piecesJogador[i].formato = monte->inicio->info.formato;
        temp = monte->inicio;
        monte->inicio = monte->inicio->prox;
        monte->qtdCartas--;
        free(temp);
    }
    jog->qtdPieces = 6;
}

void trocarPiecesJog(pontDeque monte, pontJogadores jog, int pos)
{
    pontCarta temp = (pontCarta)malloc(sizeof(carta));
    temp->prox = NULL;
    temp->info.cor = jog->piecesJogador[pos].cor;
    temp->info.formato = jog->piecesJogador[pos].formato;
    monte->fim->prox = temp;

    jog->piecesJogador[pos].cor = monte->inicio->info.cor;
    jog->piecesJogador[pos].formato = monte->inicio->info.formato;

    temp = monte->inicio;
    monte->inicio = monte->inicio->prox;
    free(temp);
}

void printarJog(pontJogadores jog)
{
    printf("Jogada de %s\n", jog->nome);
    printf("Pecas disponiveis: ");
    for(int i = 0; i < jog->qtdPieces; i++)
    {
        if(jog->piecesJogador[i].formato != ' ' &&  jog->piecesJogador[i].cor != ' ')
        {
            printf("[%c%c] ", jog->piecesJogador[i].formato, jog->piecesJogador[i].cor);
        }
    }
    printf("\n");
}

void joga(pont board, pontDeque monte, pontJogadores jog, char peca, char numero, int linha, int coluna, int *n_jogada, int *todasJogadas)
{  
    int i, aux = 0, pos;
    if(linha >= board->rows || coluna >= board->columns || linha < 0 || coluna < 0 || board->pieces[linha][coluna].cor != ' ' || board->pieces[linha][coluna].formato != ' '){
        aux = 1;
    }
    else{
        for(i = 0; i < jog->qtdPieces; i++)
        {   
            if(peca == jog->piecesJogador[i].formato && numero == jog->piecesJogador[i].cor)
            {
                aux = 0;
                pos = i;
                break;
            }
            else{
                aux = 1;
            }
        }
    }    
    int verifica = verificarJogada(board, peca, numero, linha, coluna, n_jogada, todasJogadas);
    if(aux == 0 && verifica == 1){
        board->pieces[linha][coluna].formato = peca; 
        board->pieces[linha][coluna].cor = numero;
        reallocBoard(board, linha, coluna, (*n_jogada*2), todasJogadas);
        //Retirando a peça jogada das peças do jogador
        int k = 0;
        for(i = 0; i < jog->qtdPieces; i++){
            if(i != pos){
                jog->piecesJogador[k].formato = jog->piecesJogador[i].formato;
                jog->piecesJogador[k].cor = jog->piecesJogador[i].cor;
                k++;
            }
        }
        jog->piecesJogador[k].formato = ' ';
        jog->piecesJogador[k].cor = ' ';
        jog->qtdPieces--;
        (*n_jogada)++;      //Atualizando o número da jogada
    }
    else{
        printf("***Jogada invalida***\n");
    }
}

//Função que verifica se a posição em que a peça vai ser jogada é válida ou não
//Retorna 1 caso seja válida e 0 caso contrário
//Verifica se as casas adjacentes estão ocupadas, se a peça é da mesma cor ou formato que a sua vizinha, se uma linha/coluna já é de uma cor ou formato
// e limita a jogada à mesma linha ou coluna a partir da segunda jogada 
int verificarJogada(pont board, char peca, char numero, int linha, int coluna, int *n_jogada, int *todasJogadas){
    int verifica = 1;   //Variável a ser retornada
    int posAdj = -1;    //Variável que indica qual a posição das peças adjacentes em relação à peça jogada (0 = acima, 1 = esquerda, 2 = direita, 3 = abaixo)
    int pecaIgual = -1;     //Variável que indica se o formato ou a cor são iguais à peça adjacente (1 = formato, 2 = cor)
    
    if(board->columns != 1 && board->rows != 1){
        //Limitando as comparações nas bordas do tabuleiro para que o programa não acesse uma posição inexistente
        if(linha == 0){
            //Caso em que linha e coluna são iguais a 0
            if(coluna == 0){
                if(board->pieces[linha][coluna + 1].formato == ' ' && board->pieces[linha + 1][coluna].formato == ' '){
                    verifica = 0;
                }
                else{
                    //Verificando se o formato e a cor da peça é igual à sua vizinha
                    //Caso seja, a jogada é inválida
                    if(board->pieces[linha][coluna + 1].formato != ' '){
                        if(peca == board->pieces[linha][coluna + 1].formato){
                            if(numero == board->pieces[linha][coluna + 1].cor){
                                verifica = 0;
                            }
                            else{
                                posAdj = 2;
                                pecaIgual = 1;
                            }
                        }
                        else if(numero == board->pieces[linha][coluna + 1].cor){
                            posAdj = 2;
                            pecaIgual = 2;
                        }
                        else{
                            verifica = 0;
                        }
                    }
                    if(board->pieces[linha + 1][coluna].formato != ' '){
                        if(peca == board->pieces[linha + 1][coluna].formato){
                            if(numero == board->pieces[linha + 1][coluna].cor){
                                verifica = 0;
                            }
                            else{
                                posAdj = 3;
                                pecaIgual = 1;
                            }
                        }
                        else if(numero == board->pieces[linha + 1][coluna].cor){
                            posAdj = 3;
                            pecaIgual = 2;
                        }
                        else{
                            verifica = 0;
                        }
                    }
                }
            }
            //Caso em que linha igual a 0 e coluna no tamanho máximo
            else if(coluna == board->columns - 1){
                if(board->pieces[linha][coluna - 1].formato == ' ' && board->pieces[linha + 1][coluna].formato == ' '){
                    verifica = 0;
                }
                else{
                    //Verificando se o formato e a cor da peça é igual à sua vizinha
                    //Caso seja, a jogada é inválida
                    if(board->pieces[linha][coluna - 1].formato != ' '){
                        if(peca == board->pieces[linha][coluna - 1].formato){
                            if(numero == board->pieces[linha][coluna - 1].cor){
                                verifica = 0;
                            }
                            else{
                                posAdj = 1;
                                pecaIgual = 1;
                            }
                        }
                        else if(numero == board->pieces[linha][coluna - 1].cor){
                            posAdj = 1;
                            pecaIgual = 2;
                        }
                        else{
                            verifica = 0;
                        }
                    }
                    if(board->pieces[linha + 1][coluna].formato != ' '){
                        if(peca == board->pieces[linha + 1][coluna].formato){
                            if(numero == board->pieces[linha + 1][coluna].cor){
                                verifica = 0;
                            }
                            else{
                                posAdj = 3;
                                pecaIgual = 1;
                            }
                        }
                        else if(numero == board->pieces[linha + 1][coluna].cor){
                            posAdj = 3;
                            pecaIgual = 2;
                        }
                        else{
                            verifica = 0;
                        }
                    }
                }
            }
            //Caso em que apenas linha igual a 0
            else{
                if(board->pieces[linha][coluna + 1].formato == ' ' && board->pieces[linha][coluna - 1].formato == ' ' && board->pieces[linha + 1][coluna].formato == ' '){
                    verifica = 0;
                }
                else{
                    //Verificando se o formato e a cor da peça é igual à sua vizinha
                    //Caso seja, a jogada é inválida
                    if(board->pieces[linha][coluna + 1].formato != ' '){
                        if(peca == board->pieces[linha][coluna + 1].formato){
                            if(numero == board->pieces[linha][coluna + 1].cor){
                                verifica = 0;
                            }
                            else{
                                posAdj = 2;
                                pecaIgual = 1;
                            }
                        }
                        else if(numero == board->pieces[linha][coluna + 1].cor){ 
                            posAdj = 2;
                            pecaIgual = 2;
                        }     
                        else{
                            verifica = 0;
                        }
                    }
                    if(board->pieces[linha][coluna - 1].formato != ' '){
                        if(peca == board->pieces[linha][coluna - 1].formato){
                            if(numero == board->pieces[linha][coluna - 1].cor){
                                verifica = 0;
                            }
                            else{
                                posAdj = 1;
                                pecaIgual = 1;
                            }
                        }
                        else if(numero == board->pieces[linha][coluna - 1].cor){
                            posAdj = 1;
                            pecaIgual = 2;
                        }
                        else{
                            verifica = 0;
                        }
                    }
                    if(board->pieces[linha + 1][coluna].formato != ' '){
                        if(peca == board->pieces[linha + 1][coluna].formato){
                            if(numero == board->pieces[linha + 1][coluna].cor){
                                verifica = 0;
                            }
                            else{
                                posAdj = 3;
                                pecaIgual = 1;
                            }
                        }
                        else if(numero == board->pieces[linha + 1][coluna].cor){
                            posAdj = 3;
                            pecaIgual = 2;
                        }
                        else{
                            verifica = 0;
                        }
                    }
                }
            }
        }
        else if(linha == board->rows - 1){
            //Caso em que linha igual ao tamanho máximo e coluna igual a 0
            if(coluna == 0){
                if(board->pieces[linha][coluna + 1].formato == ' ' && board->pieces[linha - 1][coluna].formato == ' '){
                    verifica = 0;
                }
                else{
                    //Verificando se o formato e a cor da peça é igual às suas vizinhas
                    //Caso seja, a jogada é inválida
                    if(board->pieces[linha][coluna + 1].formato != ' '){
                        if(peca == board->pieces[linha][coluna + 1].formato){
                            if(numero == board->pieces[linha][coluna + 1].cor){
                                verifica = 0;
                            }
                            else{
                                posAdj = 2;
                                pecaIgual = 1;
                            }
                        }
                        else if(numero == board->pieces[linha][coluna + 1].cor){ 
                            posAdj = 2;
                            pecaIgual = 2;
                        } 
                        else{
                            verifica = 0; 
                        }
                    }
                    if(board->pieces[linha - 1][coluna].formato != ' '){
                        if(peca == board->pieces[linha - 1][coluna].formato){
                            if(numero == board->pieces[linha - 1][coluna].cor){
                                verifica = 0;
                            }
                            else{
                                posAdj = 0;
                                pecaIgual = 1;
                            }
                        }
                        else if(numero == board->pieces[linha - 1][coluna].cor){
                            posAdj = 0;
                            pecaIgual = 2;
                        }
                        else{
                            verifica = 0;
                        }
                    }
                }
            }
            //Caso em que linha e coluna são iguais ao tamanho máximo
            else if(coluna == board->columns - 1){
                if(board->pieces[linha][coluna - 1].formato == ' ' && board->pieces[linha - 1][coluna].formato == ' '){
                    verifica = 0;
                }
                else{
                    //Verificando se o formato e a cor da peça é igual à sua vizinha
                    //Caso seja, a jogada é inválida
                    if(board->pieces[linha][coluna - 1].formato != ' '){
                        if(peca == board->pieces[linha][coluna - 1].formato){
                            if(numero == board->pieces[linha][coluna - 1].cor){
                                verifica = 0;
                            }
                            else{
                                posAdj = 1;
                                pecaIgual = 1;
                            }
                        }
                        else if(numero == board->pieces[linha][coluna - 1].cor){
                            posAdj = 1;
                            pecaIgual = 2;
                        }
                        else{
                            verifica = 0;
                        }
                    }
                    if(board->pieces[linha - 1][coluna].formato != ' '){
                        if(peca == board->pieces[linha - 1][coluna].formato){
                            if(numero == board->pieces[linha - 1][coluna].cor){
                                verifica = 0;
                            }
                            else{
                                posAdj = 0;
                                pecaIgual = 1;
                            }
                        }
                        else if(numero == board->pieces[linha - 1][coluna].cor){
                            posAdj = 0;
                            pecaIgual = 2;
                        }
                        else{
                            verifica = 0;
                        }
                    }
                }
            }
            //Caso em que apenas a linha é do tamanho máximo
            else{
                if(board->pieces[linha][coluna + 1].formato == ' ' && board->pieces[linha][coluna - 1].formato == ' ' && board->pieces[linha - 1][coluna].formato == ' '){
                    verifica = 0;
                }
                else{
                    //Verificando se o formato e a cor da peça é igual à sua vizinha
                    //Caso seja, a jogada é inválida
                    if(board->pieces[linha][coluna + 1].formato != ' '){
                        if(peca == board->pieces[linha][coluna + 1].formato){
                            if(numero == board->pieces[linha][coluna + 1].cor){
                                verifica = 0;
                            }
                            else{
                                posAdj = 2;
                                pecaIgual = 1;
                            }
                        }
                        else if(numero == board->pieces[linha][coluna + 1].cor){ 
                            posAdj = 2;
                            pecaIgual = 2;
                        } 
                        else{
                            verifica = 0;
                        }
                    }
                    if(board->pieces[linha][coluna - 1].formato != ' '){
                        if(peca == board->pieces[linha][coluna - 1].formato){
                            if(numero == board->pieces[linha][coluna - 1].cor){
                                verifica = 0;
                            }
                            else{
                                posAdj = 1;
                                pecaIgual = 1;
                            }
                        }
                        else if(numero == board->pieces[linha][coluna - 1].cor){
                            posAdj = 1;
                            pecaIgual = 2;
                        }
                        else{
                            verifica = 0;
                        }
                    }
                    if(board->pieces[linha - 1][coluna].formato != ' '){
                        if(peca == board->pieces[linha - 1][coluna].formato){
                            if(numero == board->pieces[linha - 1][coluna].cor){
                                verifica = 0;
                            }
                            else{
                                posAdj = 0;
                                pecaIgual = 1;
                            }
                        }
                        else if(numero == board->pieces[linha - 1][coluna].cor){
                            posAdj = 0;
                            pecaIgual = 2;
                        }
                        else{
                            verifica = 0;
                        }
                    }
                }
            }
        }
        //Caso em que apenas a coluna é igual a 0
        else if(coluna == 0){
            if(board->pieces[linha][coluna + 1].formato == ' ' && board->pieces[linha + 1][coluna].formato == ' ' && board->pieces[linha - 1][coluna].formato == ' '){
                verifica = 0;
            }
            else{
                //Verificando se o formato e a cor da peça é igual à sua vizinha
                //Caso seja, a jogada é inválida
                if(board->pieces[linha][coluna + 1].formato != ' '){
                    if(peca == board->pieces[linha][coluna + 1].formato){
                        if(numero == board->pieces[linha][coluna + 1].cor){
                            verifica = 0;
                        }
                        else{
                            posAdj = 2;
                            pecaIgual = 1;
                        }
                    }
                    else if(numero == board->pieces[linha][coluna + 1].cor){
                        posAdj = 2;
                        pecaIgual = 2;
                    } 
                    else{
                        verifica = 0;
                    }
                }
                if(board->pieces[linha + 1][coluna].formato != ' '){
                    if(peca == board->pieces[linha + 1][coluna].formato){
                        if(numero == board->pieces[linha + 1][coluna].cor){
                            verifica = 0;
                        }
                        else{
                            posAdj = 3;
                            pecaIgual = 1;
                        }
                    }
                    else if(numero == board->pieces[linha + 1][coluna].cor){
                        posAdj = 3;
                        pecaIgual = 2;
                    }
                    else{
                        verifica = 0;
                    }
                }
                if(board->pieces[linha - 1][coluna].formato != ' '){
                    if(peca == board->pieces[linha - 1][coluna].formato){
                        if(numero == board->pieces[linha - 1][coluna].cor){
                            verifica = 0;
                        }
                        else{
                            posAdj = 0;
                            pecaIgual = 1;
                        }
                    }
                    else if(numero == board->pieces[linha - 1][coluna].cor){
                        posAdj = 0;
                        pecaIgual = 2;
                    }
                    else{
                        verifica = 0;
                    }
                }
            }
        }
        //Caso em que apenas a coluna é igual ao seu tamanho máximo
        else if(coluna == board->columns - 1){
            if(board->pieces[linha][coluna - 1].formato == ' ' && board->pieces[linha + 1][coluna].formato == ' ' && board->pieces[linha - 1][coluna].formato == ' '){
                verifica = 0;
            }
            else{
                //Verificando se o formato e a cor da peça é igual à sua vizinha
                //Caso seja, a jogada é inválida
                if(board->pieces[linha][coluna - 1].formato != ' '){
                    if(peca == board->pieces[linha][coluna - 1].formato){
                        if(numero == board->pieces[linha][coluna - 1].cor){
                            verifica = 0;
                        }
                        else{
                            posAdj = 1;
                            pecaIgual = 1;
                        }
                    }
                    else if(numero == board->pieces[linha][coluna - 1].cor){
                        posAdj = 1;
                        pecaIgual = 2;
                    }
                    else{
                        verifica = 0;
                    }
                }
                if(board->pieces[linha + 1][coluna].formato != ' '){
                    if(peca == board->pieces[linha + 1][coluna].formato){
                        if(numero == board->pieces[linha + 1][coluna].cor){
                            verifica = 0;
                        }
                        else{
                            posAdj = 3;
                            pecaIgual = 1;
                        }
                    }   
                    else if(numero == board->pieces[linha + 1][coluna].cor){
                        posAdj = 3;
                        pecaIgual = 2;
                    }
                    else{
                        verifica = 0;
                    }
                }
                if(board->pieces[linha - 1][coluna].formato != ' '){
                    if(peca == board->pieces[linha - 1][coluna].formato){
                        if(numero == board->pieces[linha - 1][coluna].cor){
                            verifica = 0;
                        }
                        else{
                            posAdj = 0;
                            pecaIgual = 1;
                        }
                    }
                    else if(numero == board->pieces[linha - 1][coluna].cor){
                        posAdj = 0;
                        pecaIgual = 2;
                    }
                    else{
                        verifica = 0;
                    }
                }
            }
        }
        //Caso em que a posição não é em nenhuma borda do tabuleiro
        else{
            if(board->pieces[linha][coluna + 1].formato == ' ' && board->pieces[linha][coluna - 1].formato == ' ' && board->pieces[linha + 1][coluna].formato == ' ' && board->pieces[linha - 1][coluna].formato == ' '){
                verifica = 0;
            }
            else{
                //Verificando se o formato e a cor da peça é igual à sua vizinha
                //Caso seja, a jogada é inválida
                if(board->pieces[linha][coluna + 1].formato != ' '){
                    if(peca == board->pieces[linha][coluna + 1].formato){
                        if(numero == board->pieces[linha][coluna + 1].cor){
                            verifica = 0;
                        }
                        else{
                            posAdj = 2;
                            pecaIgual = 1;
                        }
                    }
                    else if(numero == board->pieces[linha][coluna + 1].cor){
                        posAdj = 2;
                        pecaIgual = 2;
                    }
                    else{
                        verifica = 0;
                    } 
                }
                if(board->pieces[linha][coluna - 1].formato != ' '){
                    if(peca == board->pieces[linha][coluna - 1].formato){
                        if(numero == board->pieces[linha][coluna - 1].cor){
                            verifica = 0;
                        }
                        else{
                            posAdj = 1;
                            pecaIgual = 1;
                        }
                    }
                    else if(numero == board->pieces[linha][coluna - 1].cor){
                        posAdj = 1;
                        pecaIgual = 2;
                    }
                    else{
                        verifica = 0;
                    }
                }
                if(board->pieces[linha + 1][coluna].formato != ' '){
                    if(peca == board->pieces[linha + 1][coluna].formato){
                        if(numero == board->pieces[linha + 1][coluna].cor){
                            verifica = 0;
                        }
                        else{
                            posAdj = 3;
                            pecaIgual = 1;
                        }
                    }
                    else if(numero == board->pieces[linha + 1][coluna].cor){
                        posAdj = 3;
                        pecaIgual = 2;
                    }
                    else{
                        verifica = 0;
                    }
                }
                if(board->pieces[linha - 1][coluna].formato != ' '){
                    if(peca == board->pieces[linha - 1][coluna].formato){
                        if(numero == board->pieces[linha - 1][coluna].cor){
                            verifica = 0;
                        }
                        else{
                            posAdj = 0;
                            pecaIgual = 1;
                        }
                    }
                    else if(numero == board->pieces[linha - 1][coluna].cor){
                        posAdj = 0;
                        pecaIgual = 2;
                    }
                    else{
                        verifica = 0;
                    }
                }
            }
        }
    }
    //Verifica se a linha ou coluna já é de uma cor ou formato
    int aux_linha, aux_coluna;
    if(verifica == 1){
        if(posAdj == 0){
            aux_linha = linha - 2;
            aux_coluna = coluna;
            while(aux_linha > 0 && board->pieces[aux_linha][aux_coluna].formato != ' ' && board->pieces[aux_linha][aux_coluna].cor != ' '){
                if(pecaIgual == 1){
                    if(board->pieces[aux_linha][aux_coluna].formato != peca){
                        verifica = 0;
                        break;
                    }
                    else if(board->pieces[aux_linha][aux_coluna].cor == numero){
                        verifica = 0;
                        break;
                    }
                }
                else{
                    if(board->pieces[aux_linha][aux_coluna].cor != numero){
                        verifica = 0;
                        break;
                    }
                    else if(board->pieces[aux_linha][aux_coluna].formato == peca){
                        verifica = 0;
                        break;
                    }
                }
                aux_linha--;
            }
        }
        else if(posAdj == 1){
            aux_linha = linha;
            aux_coluna = coluna - 2;
            while(aux_coluna > 0 && board->pieces[aux_linha][aux_coluna].formato != ' ' && board->pieces[aux_linha][aux_coluna].cor != ' '){
                if(pecaIgual == 1){
                    if(board->pieces[aux_linha][aux_coluna].formato != peca){
                        verifica = 0;
                        break;
                    }
                    else if(board->pieces[aux_linha][aux_coluna].cor == numero){
                        verifica = 0;
                        break;
                    }
                }
                else{
                    if(board->pieces[aux_linha][aux_coluna].cor != numero){
                        verifica = 0;
                        break;
                    }
                    else if(board->pieces[aux_linha][aux_coluna].formato == peca){
                        verifica = 0;
                        break;
                    }
                }
                aux_coluna--;
            }
        }
        else if(posAdj == 2){
            aux_linha = linha;
            aux_coluna = coluna + 2;
            while(aux_coluna < board->columns && board->pieces[aux_linha][aux_coluna].formato != ' ' && board->pieces[aux_linha][aux_coluna].cor != ' '){
                if(pecaIgual == 1){
                    if(board->pieces[aux_linha][aux_coluna].formato != peca){
                        verifica = 0;
                        break;
                    }
                    else if(board->pieces[aux_linha][aux_coluna].cor == numero){
                        verifica = 0;
                        break;
                    }
                }
                else{
                    if(board->pieces[aux_linha][aux_coluna].cor != numero){
                        verifica = 0;
                        break;
                    }
                    else if(board->pieces[aux_linha][aux_coluna].formato == peca){
                        verifica = 0;
                        break;
                    }
                }
                aux_coluna++;
            }
        }
        else if(posAdj == 3){
            aux_linha = linha + 2;
            aux_coluna = coluna;
            while(aux_linha < board->rows && board->pieces[aux_linha][aux_coluna].formato != ' ' && board->pieces[aux_linha][aux_coluna].cor != ' '){
                if(pecaIgual == 1){
                    if(board->pieces[aux_linha][aux_coluna].formato != peca){
                        verifica = 0;
                        break;
                    }
                    else if(board->pieces[aux_linha][aux_coluna].cor == numero){
                        verifica = 0;
                        break;
                    }
                }
                else{
                    if(board->pieces[aux_linha][aux_coluna].cor != numero){
                        verifica = 0;
                        break;
                    }
                    else if(board->pieces[aux_linha][aux_coluna].formato == peca){
                        verifica = 0;
                        break;
                    }
                }
                aux_linha++;
            }
        }
    }
    if(verifica == 1){
        int tam = (*n_jogada) * 2, tam_aux = ((*n_jogada) - 1) * 2, i;
        if((*n_jogada) > 1){
            //Limitando a nova jogada à mesma linha ou coluna das jogadas anteriores
            if((*n_jogada) > 2){
                if(todasJogadas[0] == todasJogadas[2]){
                    if(linha != todasJogadas[2]){
                        verifica = 0;
                    }
                }
                else if(todasJogadas[1] == todasJogadas[3]){
                    if(coluna != todasJogadas[3]){
                        verifica = 0;
                    }
                }
            }
        }
        //Acresecentando a nova jogada ao vetor
        todasJogadas[tam - 2] = linha;
        todasJogadas[tam - 1] = coluna;
    }
    return verifica;
}

//Função recebe o tabuleiro e o ponteiro para o jogador
//O que faz até o momento: identifica as funções trocar, jogar, passar e comandos inválidos. Aceita também os comandos em maiusculo.
//O que falta: identificar as peças que vão ser trocadas ou jogadas para passar para as funções
void leituraComandos(pont board, pontDeque monte, pontJogadores jog, char cheat)
{
   //Definição das strings para comparação com os comandos lidos
    char trocar[] = "TROCAR";
    char jogar[] = "JOGAR";
    char passar[] = "PASSAR";

    int aux = 0, num_jogada = 1, *n_jogada;
    n_jogada = &num_jogada;     //Ponteiro que aponta para a variável que armazena o número da jogada atual do jogador
    int *todasJogadas = (int *)malloc(12 * sizeof(int)); //Vetor que armazena as posições das jogadas do jogador

    int pontosAtual = jog->pontos;

    while(aux != -1)
    {   
        if(aux == 0 || jog->qtdPieces == 0){
            jog->qtdPieces = 6;     //Setando a quantidade de peças iniciais somente em cada nova jogada
            *n_jogada = 1;          //Setando uma nova jogada 
        }
        printBoard(board);
        printf("===========\n");
        printarJog(jog);
        char comando[26];
        char funcao[7];
        int i = 0;
        if(aux == 0)
        {
            printf("Opcoes: trocar p1 [p2 p3...] | jogar p1 x y | passar\n");
            fgetss(comando, 25, "Comando");
            toUpper(comando);
            while(comando[i] != ' ' && i < 6)
            {
                funcao[i] = comando[i];
                i++;
            }
            funcao[i] = '\0';
            if(!strcmp(funcao, trocar))
            {
                int auxTrocar = i+1;
                int tamString = strlen(comando);
                piece pecasTroca[6];
                int contPecas = 0;
                while(auxTrocar+1 < tamString)
                {
                    if(verificaPeca(comando[auxTrocar], comando[auxTrocar+1]))
                    {
                        pecasTroca[contPecas].formato = comando[auxTrocar];
                        pecasTroca[contPecas].cor = comando[auxTrocar+1];
                        contPecas++;
                        aux = -1;
                        auxTrocar += 3;
                    }
                    else
                    {   
                        printf("Comando invalido!\n");
                        aux = 0;
                        break;
                    }
                }
                if(aux == -1)
                {
                    aux = verificaTroca(monte, jog, pecasTroca, contPecas);
                }
            }
            else if(!strcmp(funcao, jogar))
            {
                //Lendo a peça e a posição em que será jogada
                int linha, coluna, j, cont = 0, k = 0;
                char jogada[4];
                for(j = 9; j < 24; j++){
                    if(comando[j] == '\0' || comando[j] == ' '){
                        break;
                    }
                    jogada[cont] = comando[j];
                    cont++;
                }
                jogada[cont] = '\0';
                if(cont == 1){
                    linha = jogada[0] - '0';    //Transformando a linha, de char para int
                }
                else{
                    linha = atoi(jogada);       //Transformando a linha, de string para int
                }
                j++;
                cont = 0;
                for(k = j; k < 24; k++){
                    if(comando[k] == '\0' || comando[k] == ' '){
                        break;
                    }
                    jogada[cont] = comando[k];
                    cont++;
                }
                jogada[cont] = '\0';
                if(cont == 1){
                    coluna = jogada[0] - '0';   //Transformando a coluna, de char para int
                }
                else{
                    coluna = atoi(jogada);      //Transformando a coluna, de string para int
                }
                if(cheat == 'S'){
                    cheatMode(board, monte, jog, comando[6], comando[7], linha, coluna, n_jogada, todasJogadas);
                }
                else{
                    joga(board, monte, jog, comando[6], comando[7], linha, coluna, n_jogada, todasJogadas);    //Chamando a função para jogar
                }
                aux = 2;
            }
            else if(!strcmp(funcao, passar))
            {
                aux = -1;
            }
            else
            {
                printf("Comando invalido!\n");
            }
        }
        else if(aux == 2 && jog->qtdPieces != 0)
        {   
            printf("Opcoes: jogar p1 x y | passar\n");
            fgetss(comando, 24, "Comando");
            toUpper(comando);
            while(comando[i] != ' ' && i < 7)
            {
                funcao[i] = comando[i];
                i++;
            }
            funcao[i] = '\0';
            if(!strcmp(funcao, jogar))
            {
                //Lendo a peça e a posição em que será jogada
                int linha, coluna, j, cont = 0, k = 0;
                char jogada[4];
                for(j = 9; j < 24; j++){
                    if(comando[j] == '\0' || comando[j] == ' '){
                        break;
                    }
                    jogada[cont] = comando[j];
                    cont++;
                }
                jogada[cont] = '\0';
                if(cont == 1){
                    linha = jogada[0] - '0';    //Transformando a linha, de char para int
                }
                else{
                    linha = atoi(jogada);       //Transformando a linha, de string para int
                }
                j++;
                cont = 0;
                for(k = j; k < 24; k++){
                    if(comando[k] == '\0' || comando[k] == ' '){
                        break;
                    }
                    jogada[cont] = comando[k];
                    cont++;
                }
                jogada[cont] = '\0';
                if(cont == 1){
                    coluna = jogada[0] - '0';   //Transformando a coluna, de char para int
                }
                else{
                    coluna = atoi(jogada);      //Transformando a coluna, de string para int
                }
                if(cheat == 'S'){
                    cheatMode(board, monte, jog, comando[6], comando[7], linha, coluna, n_jogada, todasJogadas);
                }
                else{
                    joga(board, monte, jog, comando[6], comando[7], linha, coluna, n_jogada, todasJogadas);    //Chamando a função para jogar
                }
                aux = 2;
            }
            else if(!strcmp(funcao, passar))
            {
                contarPontos(jog, todasJogadas, (num_jogada-1)*2, board);
                if(jog->qtdPieces < 6){
                    reporPiecesJog(jog, monte);
                }
                aux = -1;   
            }
            else
            {
                printf("Comando invalido!\n");
            }
        }
    }
    printf("*********************************************\n");
    printf("***** Pontuacao %s: %d / Pontuacao acumulada: %d\n", jog->nome, jog->pontos, (jog->pontos-pontosAtual));
    printf("*********************************************\n");
    free(todasJogadas);
}

//Função para leitura de string que não tem problema de buffer e não dá segfault se passar do limite
//str é vetor onde quer armazenar e n é a última posição do possível do vetor
void fgetss(char str[], int n, char tipoComando[])
{
  char a;
  int i;
  for(i = 0; i < n; i++)
  {
    a = getc(stdin);
    if(a == '\n')
    {
      str[i] = '\0';
      break;
    }
    str[i] = a;
  }
  i = 0;
  while(a != '\n')
  {
    if(i == 1)
    {
      printf("\n%s maior que o limite! Serao considerados apenas os primeiros %d caracteres.\n", tipoComando, n);
      str[n] = '\0';
    }
    a = getc(stdin);
    i++;
  }
}

void toUpper(char str[])
{
    int tam = strlen(str);
    for(int i = 0; i <= tam; i++){
        if((str[i] >= 97 ) && (str[i] <= 122 ))
        {
            str[i] = str[i] - 32;            
        }
    }
}

//Retorna 1 se os caracteres de formato e cor forem válidos e 0 para o contrário
int verificaPeca(char formato, char cor)
{
    //Definição dos vetores contendo os formatos e cores possíveis
    char formatos[] = {'Q','C','L', 'E', 'F', 'S'};
    char cores[] = {'1', '2', '3', '4', '5', '6'};

    int resFormato = 0, resCor = 0, i;
    for(i = 0; i < 6 && resFormato == 0; i++)
    {
        if(formatos[i] == formato)
        {
            resFormato = 1;
        }
    }
    for(i = 0; i < 6 && resCor == 0; i++)
    {
        if(cores[i] == cor)
        {
            resCor = 1;
        }
    }
    if(resCor == 1 && resFormato == 1)
    {
        return 1;
    }
    return 0;
}

int verificaTroca(pontDeque monte, pontJogadores jog, piece pecas[], int qtdPecasTtroca)
{
    int cont = 0;
    int posTroca[6];
    for(int i = 0; i < qtdPecasTtroca; i++)
    {
        for(int j = 0; j < jog->qtdPieces; j++)
        {
            if(pecas[i].formato == jog->piecesJogador[j].formato)
            {
                if(pecas[i].cor == jog->piecesJogador[j].cor)
                {
                    posTroca[cont] = j;
                    cont++;
                }
            }
        }
    }
    if(cont >= qtdPecasTtroca)
    {
        printf("Realizando troca de: ");
        int k;
        for(k = 0; k < qtdPecasTtroca; k++)
        {
            printf("[%c%c] ", pecas[k].formato, pecas[k].cor);
        }
        printf("\n");
        for(k = 0; k < cont; k++)
        {
            trocarPiecesJog(monte, jog, posTroca[k]);
        }
        return -1;
    }
    else
    {
        printf("Pecas invalidas para troca!\n");
        return 0;
    }
    
}

pontJogadores iniciarJogs(pontDeque monte, int qtdJogs)
{
    int i = 0;
    pontJogadores jogador, jogAnterior = NULL, inicioJog;
    while(i < qtdJogs)
    {
        jogador = (pontJogadores)malloc(sizeof(jogadores));
        if(i == 0)
        {
          inicioJog = jogador;
        }
        if(jogAnterior != NULL)
        {
            jogAnterior->proxJog = jogador;
        }
        iniciarPiecesJog(monte, jogador);
        jogador->pontos = 0;
        jogador->proxJog = NULL;
        jogAnterior = jogador;
        i++;
    }
    return inicioJog;
}

void selecionarVencedor(pontJogadores inicio)
{
    int maiorPontos = 0, qtdPiecesVencedor = 0, qtdVencedores = 0;
    char nome[21];
    pontJogadores jogAtual = inicio;
    while(jogAtual != NULL)
    {
        if(jogAtual->pontos > maiorPontos)
        {
            maiorPontos = jogAtual->pontos;
            qtdPiecesVencedor = jogAtual->qtdPieces;
            qtdVencedores = 1;
        }
        else if(jogAtual->pontos == maiorPontos)
        {
            if(jogAtual->qtdPieces < qtdPiecesVencedor)
            {
                qtdPiecesVencedor = jogAtual->qtdPieces;
                qtdVencedores = 1;
            }
            else if(jogAtual->qtdPieces == qtdPiecesVencedor)
            {
                qtdVencedores++;
            }
        }
        jogAtual = jogAtual->proxJog;
    }

    jogAtual = inicio;
    int i = qtdVencedores; 
    while(i != 0)
    {
        if(jogAtual->pontos == maiorPontos && jogAtual->qtdPieces == qtdPiecesVencedor)
        {
            printf("O jogador %s ganhou! Acumulou %d pontos e sobraram %d pecas\n", jogAtual->nome, jogAtual->pontos, jogAtual->qtdPieces);
            i--;
        }
        jogAtual = jogAtual->proxJog;
    }
}

void reporPiecesJog(pontJogadores jog, pontDeque monte)
{
    while(monte->qtdCartas > 0 && jog->qtdPieces < 6)
    {   
        jog->piecesJogador[jog->qtdPieces].formato = monte->inicio->info.formato;
        jog->piecesJogador[jog->qtdPieces].cor = monte->inicio->info.cor;
        jog->qtdPieces++;

        pontCarta temp = monte->inicio;
        monte->inicio = monte->inicio->prox;
        monte->qtdCartas--;
        free(temp);
    }
}

void cheatMode(pont board, pontDeque monte, pontJogadores jog, char peca, char numero, int linha, int coluna, int *n_jogada, int *todasJogadas)
{  
    int i, aux = 0, pos = -1;
    if(linha >= board->rows || coluna >= board->columns || linha < 0 || coluna < 0 || board->pieces[linha][coluna].cor != ' ' || board->pieces[linha][coluna].formato != ' '){
        aux = 1;
    }
    else{
        //Verifica se a peça jogada está entre as peças do jogador
        for(i = 0; i < jog->qtdPieces; i++)
        {   
            if(peca == jog->piecesJogador[i].formato && numero == jog->piecesJogador[i].cor)
            {
                aux = 0;
                pos = i;
                break;
            }
            else{
                aux = 1;
            }
        }
        //Se a peça não estiver entre as peças do jogador, procura no monte
        if(aux == 1){
            pontCarta carta = monte->inicio;
            pontCarta anterior = NULL;
            pontCarta apagar;
            while(carta != NULL && monte->qtdCartas != 0)
            {   
                if(carta->info.formato == peca && carta->info.cor == numero)
                {
                    if(anterior == NULL)
                    {
                        monte->inicio = carta->prox;
                    }
                    else
                    {
                        anterior->prox = carta->prox;
                    }
                    aux = 0;
                    apagar = carta;
                    free(apagar);
                    carta = NULL;
                    monte->qtdCartas--;
                    break;
                }
                else
                {
                    aux = 1;
                    anterior = carta;
                    carta = carta->prox;
                }
            }
        }
    }    
    int verifica = verificarJogada(board, peca, numero, linha, coluna, n_jogada, todasJogadas);
    if(aux == 0 && verifica == 1){
        board->pieces[linha][coluna].formato = peca; 
        board->pieces[linha][coluna].cor = numero;
        reallocBoard(board, linha, coluna, (*n_jogada*2), todasJogadas);
        //Caso a peça tenha sido encontrada no deck do jogador
        if(pos != -1){
            //Retirando a peça jogada das peças do jogador
            int k = 0;
            for(i = 0; i < jog->qtdPieces; i++){
                if(i != pos){
                    jog->piecesJogador[k].formato = jog->piecesJogador[i].formato;
                    jog->piecesJogador[k].cor = jog->piecesJogador[i].cor;
                    k++;
                }
            }
            jog->piecesJogador[k].formato = ' ';
            jog->piecesJogador[k].cor = ' ';
            jog->qtdPieces--;
        }
        (*n_jogada)++;      //Atualizando o número da jogada
    }
    else{
        printf("***Jogada invalida***\n");
    }
}

void contarPontos(pontJogadores jog, int *todasJogadas, int tam, pont board)
{
    int jogadaHorizontal, jogadaVertical;
    int ultimaPosicaoH = todasJogadas[tam-2];
    int ultimaPosicaoV = todasJogadas[tam-1];
    int auxPontos = 0, auxPontosH = 0, auxPontosV = 0;
    if(tam >= 4)
    {
        jogadaHorizontal = todasJogadas[tam-2] - todasJogadas[tam-4];
        jogadaVertical = todasJogadas[tam-1] - todasJogadas[tam-3];
        printf("%d %d\n", jogadaHorizontal, jogadaVertical);
        if(jogadaHorizontal == 0)
        {
            auxPontosH = contarPosicoesHorizontal(board, ultimaPosicaoH, ultimaPosicaoV) + 1;
            printf("Pontos na horizontal: %d\n", auxPontosH);
            if( auxPontosH == 6)
            {
                auxPontos = auxPontosH*2;
            }
            else
            {
                auxPontos = auxPontosH;
            }
            int k = 0;
            while(k < tam)
            {
                auxPontosV = contarPosicoesVertical(board, todasJogadas[k], todasJogadas[k+1]);
                if(auxPontosV == 5)
                {
                    auxPontos += (auxPontosV+1)*2;
                }
                else if(auxPontosV >= 1)
                {
                    auxPontos += auxPontosV+1;
                }
                k+=2;
            }
            jog->pontos += auxPontos;
        }
        else if(jogadaVertical == 0)
        {
            auxPontosV = contarPosicoesVertical(board, ultimaPosicaoH, ultimaPosicaoV) + 1;
            printf("Pontos na vertical: %d\n", auxPontosV);
            if( auxPontosV == 6)
            {
                auxPontos = auxPontosV*2;
            }
            else
            {
                auxPontos = auxPontosV;
            }
            int k = 0;
            while(k < tam)
            {
                auxPontosH = contarPosicoesHorizontal(board, todasJogadas[k], todasJogadas[k+1]);
                if(auxPontosH == 5)
                {
                    auxPontos += (auxPontosH+1)*2;
                }
                else if(auxPontosH >= 1)
                {
                    auxPontos += auxPontosH+1;
                }
                k+=2;
            }
            jog->pontos += auxPontos;
        }
    }
    else
    {
        auxPontosH = contarPosicoesHorizontal(board, ultimaPosicaoH, ultimaPosicaoV)+1;
        auxPontosV = contarPosicoesVertical(board, ultimaPosicaoH, ultimaPosicaoV);
        if(auxPontosH == 6)
        {
            auxPontos = auxPontosH*2;
        }
        else
        {
            auxPontos = auxPontosH;
        }
        if(auxPontosV == 5)
        {
            auxPontos += (auxPontosV+1)*2;
        }
        else if(auxPontosV >= 1)
        {
            auxPontos += auxPontosV+1;
        }
        jog->pontos += auxPontos;
    }
}

int contarPosicoesHorizontal(pont board, int posHInicial, int posVInicial)
{
    int pontos = 0;
    int controlePosicao = posVInicial + 1;
    while(board->pieces[posHInicial][controlePosicao].formato != ' ')
    {
        controlePosicao++;
        pontos++;
    }
    controlePosicao = posVInicial - 1;
    while(board->pieces[posHInicial][controlePosicao].formato != ' ')
    {
        controlePosicao--;
        pontos++;
    }
    return pontos;
}

int contarPosicoesVertical(pont board, int posHInicial, int posVInicial)
{
    int pontos = 0;
    int controlePosicao = posHInicial + 1;
    while(board->pieces[controlePosicao][posVInicial].formato != ' ')
    {
        controlePosicao++;
        pontos++;
    }
    controlePosicao = posHInicial - 1;
    while(board->pieces[controlePosicao][posVInicial].formato != ' ')
    {
        controlePosicao--;
        pontos++;
    }
    return pontos;
}