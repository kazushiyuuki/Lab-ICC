#include"jogadores.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

pontJogadores iniciarPiecesJog(pontDeque monte)
{
    pontJogadores jog = (pontJogadores)malloc(sizeof(jogadores));
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
    jog->pontos = 0;
    return jog;
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
        printf("[%c%c] ", jog->piecesJogador[i].formato, jog->piecesJogador[i].cor);
    }
    printf("\n");
}

void jogar(pont board, pontJogadores jog)
{   
    printf("\n");
    printBoard(board);
    printf("\n");
    char peca, numero;
    int linha, coluna;
    printf("jogar p1 x y\n");
    scanf(" %c%c %d %d", &peca, &numero, &linha, &coluna);
    int i, aux = 0;
    for(i = 0; i < jog->qtdPieces; i++)
    {
        if(peca == jog->piecesJogador[i].formato && numero == jog->piecesJogador[i].cor)
        {
            aux = 0;
            break;
        }
        else{
            aux++;
        }
    }
    while(linha >= board->rows || coluna >= board->columns || aux != 0){
        printf("\n***invalid move***\n");
        printf("jogar p1 x y\n");
        scanf(" %c%c %d %d", &peca, &numero, &linha, &coluna);
        for(i = 0; i < jog->qtdPieces; i++)
        {
            if( peca == jog->piecesJogador[i].formato && (int)numero == jog->piecesJogador[i].cor)
            {
                aux = 0;
                break;
            }
            else{
                aux++;
            }
        }
    }
    board->pieces[linha][coluna].cor = numero;
    board->pieces[linha][coluna].formato = peca;
    reallocBoard(board, linha, coluna);
}

//Função recebe o tabuleiro e o ponteiro para o jogador
//O que faz até o momento: identifica as funções trocar, jogar, passar e comandos inválidos. Aceita também os comandos em maiusculo.
//O que falta: identificar as peças que vão ser trocadas ou jogadas para passar para as funções
void leituraComandos(pont board, pontJogadores jog)
{
   //Definição das strings para comparação com os comandos lidos
    char trocar[] = "trocar";
    char jogar[] = "jogar";
    char passar[] = "passar";

    int aux = 0;
    while(aux != -1)
    {
        printBoard(board);
        printf("===========\n");
        printarJog(jog);
        char comando[26];
        char funcao[7];
        int i = 0;
        if(aux == 0)
        {
            printf("Opcoes: trocar p1 [p2 p3...] | jogar p1 x y | passar\n", aux);
            fgetss(comando, 25, "Comando");
            toLower(comando);
            while(comando[i] != ' ' && i < 6)
            {
                funcao[i] = comando[i];
                i++;
            }
            funcao[6] = '\0';
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
                //Até aqui a função verifica se as entradas são válidas, falta comparar com as peças do jogador para saber se o jogador possui essas peças 
            }
            else if(!strcmp(funcao, jogar))
            {
                printf("Funcao jogar acionada\n");
                aux = 2;
            }
            else if(!strcmp(funcao, passar))
            {
                printf("Funcao passar acionada\n");
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
            while(comando[i] != ' ' && i < 7)
            {
                funcao[i] = comando[i];
                i++;
            }
            funcao[i] = '\0';
            toLower(funcao);
            if(!strcmp(funcao, jogar))
            {
                printf("Funcao jogar acionada\n");
                aux = 2;
            }
            else if(!strcmp(funcao, passar))
            {
                printf("Funcao passar acionada\n");
                aux = -1;   
            }
            else
            {
                printf("Comando invalido!\n");
            }
        }
    }
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

void toLower(char str[])
{
    int tam = strlen(str);
    for(int i = 0; i <= tam; i++){
        if((str[i] >= 65 ) && (str[i] <= 90 ))
        {
            str[i] = str[i] + 32;            
        }
    }
}

//Retorna 1 se os caracteres de formato e cor forem válidos e 0 para o contrário
int verificaPeca(char formato, char cor)
{
    //Definição dos vetores contendo os formatos e cores possíveis
    char formatos[] = {'q','c','l', 'e', 'f', 's'};
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