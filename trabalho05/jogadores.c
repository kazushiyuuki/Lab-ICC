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

void joga(pont board, pontDeque monte, pontJogadores jog, char peca, char numero, int linha, int coluna)
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
    char jogada[11];
    while(aux != 0){
        printf("***Jogada invalida***\n");
        printf("Jogue novamente: p1 x y\n");
        fgetss(jogada, 11, "jogada");
        toUpper(jogada);
        peca = jogada[0];
        numero = jogada[1];
        int j, cont = 0, k = 0;
        char posicao[4];
        for(j = 3; j < 11; j++){
            if(jogada[j] == '\0' || jogada[j] == ' '){
                break;
            }
            posicao[cont] = jogada[j];
            cont++;
        }
        posicao[cont] = '\0';
        if(cont == 1){
            linha = posicao[0] - '0';    //Transformando a linha, de char para int
        }
        else{
            linha = atoi(posicao);       //Transformando a linha, de string para int
        }
        j++;
        cont = 0;
        for(k = j; k < 11; k++){
            if(jogada[k] == '\0' || jogada[k] == ' '){
                break;
            }
            posicao[cont] = jogada[k];
            cont++;
        }
        posicao[cont] = '\0';
        if(cont == 1){
            coluna = posicao[0] - '0';   //Transformando a coluna, de char para int
        }
        else{
            coluna = atoi(posicao);      //Transformando a coluna, de string para int
        }
    
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
    }
    
    int verifica = verificarJogada(board, peca, numero, linha, coluna);
    if(verifica == 1){
        board->pieces[linha][coluna].formato = peca; 
        board->pieces[linha][coluna].cor = numero;
        reallocBoard(board, linha, coluna);
        
        int k = 0;
        for(i = 0; i < jog->qtdPieces; i++){
            if(i != pos){
                jog->piecesJogador[k].formato = jog->piecesJogador[i].formato;
                jog->piecesJogador[k].cor = jog->piecesJogador[i].cor;
                k++;
            }
        }
        jog->piecesJogador[k].formato = '\0';
        jog->piecesJogador[k].cor = '\0';
        jog->qtdPieces--;
        trocarPiecesJog(monte, jog, jog->qtdPieces);
        //Remove a peça do deck do jogador depois de jogar
        pontCarta apagar = monte->fim;
        free(apagar);
        monte->qtdCartas--;
    }
    else{
        printf("***Jogada invalida***\n");
    }
}

//Função que verifica se a posição em que a peça vai ser jogada é válida ou não
//Retorna 1 caso seja válida e 0 caso contrário
//Até agora verifica se as casas adjacentes estão ocupadas e se a peça é da mesma cor ou formato que a sua vizinha
//Falta limitar a jogada à mesma linha ou coluna após a segunda jogada e verificar se uma linha/coluna já é de uma cor ou formato
int verificarJogada(pont board, char peca, char numero, int linha, int coluna){
    int verifica;
    if(board->columns == 1 && board->rows == 1){
        verifica = 1;
    }
    else{
        //Limitando as comparações nas bordas do tabuleiro para que o programa não acesse uma posição inexistente
        if(linha == 0){
            //Caso em que linha e coluna são iguais a 0
            if(coluna == 0){
                if(board->pieces[linha][coluna + 1].formato == ' ' && board->pieces[linha + 1][coluna].formato == ' '){
                    verifica = 0;
                }
                else{
                    if(peca == board->pieces[linha][coluna + 1].formato || numero == board->pieces[linha][coluna + 1].cor){
                        verifica = 1; 
                    } 
                    else if(peca == board->pieces[linha + 1][coluna].formato || numero == board->pieces[linha + 1][coluna].cor){
                        verifica = 1;
                    }
                    else{
                        verifica = 0;
                    }
                }
            }
            //Caso em que linha igual a 0 e coluna no tamanho máximo
            else if(coluna == board->columns - 1){
                if(board->pieces[linha][coluna - 1].formato == ' ' && board->pieces[linha + 1][coluna].formato == ' '){
                    verifica = 0;
                }
                else{
                    if(peca == board->pieces[linha][coluna - 1].formato || numero == board->pieces[linha][coluna - 1].cor){
                        verifica = 1;
                    }
                    else if(peca == board->pieces[linha + 1][coluna].formato || numero == board->pieces[linha + 1][coluna].cor){
                        verifica = 1;
                    }
                    else{
                        verifica = 0;
                    }
                }
            }
            //Caso em que apenas linha igual a 0
            else{
                if(board->pieces[linha][coluna + 1].formato == ' ' && board->pieces[linha][coluna - 1].formato == ' ' && board->pieces[linha + 1][coluna].formato == ' '){
                    verifica = 0;
                }
                else{
                    if(peca == board->pieces[linha][coluna + 1].formato || numero == board->pieces[linha][coluna + 1].cor){
                        verifica = 1; 
                    } 
                    else if(peca == board->pieces[linha][coluna - 1].formato || numero == board->pieces[linha][coluna - 1].cor){
                        verifica = 1;
                    }
                    else if(peca == board->pieces[linha + 1][coluna].formato || numero == board->pieces[linha + 1][coluna].cor){
                        verifica = 1;
                    }
                    else{
                        verifica = 0;
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
                    if(peca == board->pieces[linha][coluna + 1].formato || numero == board->pieces[linha][coluna + 1].cor){
                        verifica = 1; 
                    } 
                    else if(peca == board->pieces[linha - 1][coluna].formato || numero == board->pieces[linha - 1][coluna].cor){
                        verifica = 1;
                    }
                    else{
                        verifica = 0;
                    }
                }
            }
            //Caso em que linha e coluna são iguais ao tamanho máximo
            else if(coluna == board->columns - 1){
                if(board->pieces[linha][coluna - 1].formato == ' ' && board->pieces[linha - 1][coluna].formato == ' '){
                    verifica = 0;
                }
                else{
                    if(peca == board->pieces[linha][coluna - 1].formato || numero == board->pieces[linha][coluna - 1].cor){
                        verifica = 1;
                    }
                    else if(peca == board->pieces[linha - 1][coluna].formato || numero == board->pieces[linha - 1][coluna].cor){
                        verifica = 1;
                    }
                    else{
                        verifica = 0;
                    }
                }
            }
            //Caso em que apenas a linha é do tamanho máximo
            else{
                if(board->pieces[linha][coluna + 1].formato == ' ' && board->pieces[linha][coluna - 1].formato == ' ' && board->pieces[linha - 1][coluna].formato == ' '){
                    verifica = 0;
                }
                else{
                    if(peca == board->pieces[linha][coluna + 1].formato || numero == board->pieces[linha][coluna + 1].cor){
                        verifica = 1; 
                    } 
                    else if(peca == board->pieces[linha][coluna - 1].formato || numero == board->pieces[linha][coluna - 1].cor){
                        verifica = 1;
                    }
                    else if(peca == board->pieces[linha - 1][coluna].formato || numero == board->pieces[linha - 1][coluna].cor){
                        verifica = 1;
                    }
                    else{
                        verifica = 0;
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
                if(peca == board->pieces[linha][coluna + 1].formato || numero == board->pieces[linha][coluna + 1].cor){
                    verifica = 1; 
                } 
                else if(peca == board->pieces[linha + 1][coluna].formato || numero == board->pieces[linha + 1][coluna].cor){
                    verifica = 1;
                }
                else if(peca == board->pieces[linha - 1][coluna].formato || numero == board->pieces[linha - 1][coluna].cor){
                    verifica = 1;
                }
                else{
                    verifica = 0;
                }
            }
        }
        //Caso em que apenas a coluna é igual ao seu tamanho máximo
        else if(coluna == board->columns - 1){
            if(board->pieces[linha][coluna - 1].formato == ' ' && board->pieces[linha + 1][coluna].formato == ' ' && board->pieces[linha - 1][coluna].formato == ' '){
                verifica = 0;
            }
            else{
                if(peca == board->pieces[linha][coluna - 1].formato || numero == board->pieces[linha][coluna - 1].cor){
                    verifica = 1;
                }
                else if(peca == board->pieces[linha + 1][coluna].formato || numero == board->pieces[linha + 1][coluna].cor){
                    verifica = 1;
                }
                else if(peca == board->pieces[linha - 1][coluna].formato || numero == board->pieces[linha - 1][coluna].cor){
                    verifica = 1;
                }
                else{
                    verifica = 0;
                }
            }
        }
        //Caso em que a posição não é em nenhuma borda do tabuleiro
        else{
            if(board->pieces[linha][coluna + 1].formato == ' ' && board->pieces[linha][coluna - 1].formato == ' ' && board->pieces[linha + 1][coluna].formato == ' ' && board->pieces[linha - 1][coluna].formato == ' '){
                verifica = 0;
            }
            else{
                if(peca == board->pieces[linha][coluna + 1].formato || numero == board->pieces[linha][coluna + 1].cor){
                    verifica = 1; 
                } 
                else if(peca == board->pieces[linha][coluna - 1].formato || numero == board->pieces[linha][coluna - 1].cor){
                    verifica = 1;
                }
                else if(peca == board->pieces[linha + 1][coluna].formato || numero == board->pieces[linha + 1][coluna].cor){
                    verifica = 1;
                }
                else if(peca == board->pieces[linha - 1][coluna].formato || numero == board->pieces[linha - 1][coluna].cor){
                    verifica = 1;
                }
                else{
                    verifica = 0;
                }
            }
        }
    }
    return verifica;
}

//Função recebe o tabuleiro e o ponteiro para o jogador
//O que faz até o momento: identifica as funções trocar, jogar, passar e comandos inválidos. Aceita também os comandos em maiusculo.
//O que falta: identificar as peças que vão ser trocadas ou jogadas para passar para as funções
void leituraComandos(pont board, pontDeque monte, pontJogadores jog)
{
   //Definição das strings para comparação com os comandos lidos
    char trocar[] = "TROCAR";
    char jogar[] = "JOGAR";
    char passar[] = "PASSAR";

    int aux = 0;
    while(aux != -1)
    {   
        if(aux == 0){
            jog->qtdPieces = 6;     //Setando a quantidade de peças iniciais somente em cada nova jogada
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
                if(aux == -1)
                {
                    aux = verificaTroca(monte, jog, pecasTroca, contPecas);
                }
            }
            else if(!strcmp(funcao, jogar))
            {
                printf("Funcao jogar acionada\n");
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
                joga(board, monte, jog, comando[6], comando[7], linha, coluna);    //Chamando a função para jogar
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
            toUpper(comando);
            while(comando[i] != ' ' && i < 7)
            {
                funcao[i] = comando[i];
                i++;
            }
            funcao[i] = '\0';
            if(!strcmp(funcao, jogar))
            {
                printf("Funcao jogar acionada\n");
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
                joga(board, monte ,jog, comando[6], comando[7], linha, coluna);    //Chamando a função para jogar
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