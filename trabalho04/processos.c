#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"users.h"
#include"seguidores.h"
#include"posts.h"



/*Conta-se o numero de usuarios no arquivo 'user_data.txt'
*/

int count_user(){

  
  FILE *arquivo = fopen("user_data.txt", "r");

  if(!arquivo){
    printf("Nao foi possivel abrir o arquivo.");
    exit(1);
  }

  fseek(arquivo, 0, SEEK_END);
  
  //Posicao do arquivo no fim
  int pos = ftell(arquivo);
  //Numero de structs User no arquivo.
  int num = pos/sizeof(User);

  fseek(arquivo, 0, SEEK_SET);

  fclose(arquivo);

  return num;

}
/*Conta-se o numero de posts no arquivo 'posts.txt'
*/
int count_posts(){

  FILE *arquivo = fopen("posts.txt", "r");

  if(!arquivo){
    printf("Nao foi possivel abrir o arquivo.");
    exit(1);
  }

  fseek(arquivo, 0, SEEK_END);
  //Posicao do arquivo no fim
  int pos = ftell(arquivo);
  //Numero de structs Post no arquivo.
  int num = pos/sizeof(Post);

  fseek(arquivo, 0, SEEK_SET);

  fclose(arquivo);

  return num;


}
/*Conta-se o numero de structs Seguidor no arquivo 'seguidores.txt'
*/
int count_seguidores(){

  FILE *arquivo = fopen("seguidores.txt", "r");

  if(!arquivo){
    printf("Nao foi possivel abrir o arquivo.");
    exit(1);
  }

  fseek(arquivo, 0, SEEK_END);
  //Posicao no fim do arquivo.
  int pos = ftell(arquivo);
  //Numero de structs Seguidor no arquivo.
  int num = pos/sizeof(Seguidor);

  fseek(arquivo, 0, SEEK_SET);

  fclose(arquivo);

  return num;


}
/*
Funcao para entrada que evita problemas de buffer, pois nao insere '\n' apos a string. Ela recebe caracteres ate atingir o limite n. Caso sejam escritos mais caracteres do que o limite, a funcao coloca o '/0' no ultimo caracter da string.
*/
void fgetss(char str[], int n){
  char a;
  int i;
  for(i = 0; i < n; i++){
    a = getc(stdin);
    if(a == '\n'){
      str[i] = '\0';
      break;
    }
    str[i] = a;
  }
  i = 0;
  while(a != '\n'){
    if(i == 1){
      printf("\nMensagem maior que o limite! Serao considerados apenas os primeiros %d caracteres.\n", n);
      str[n] = '\0';
    }
    a = getc(stdin);
    i++;
  }
}

/*
Recebe um ponteiro para um ponteiro de struct Seguidor e 'carrega' o vetor com os dados do arquivo 'seguidores.txt'.
*/

void get_all_seg(Seguidor **seg){
  //Abre o arquivo.
  FILE *arquivo = fopen("seguidores.txt", "r");

  if(!arquivo){
    printf("Nao foi possivel abrir o arquivo.");
    exit(1);
  }
  //Conta o numero de structs Seguidor no arquivo
  int num = count_seguidores();
  //Aloca dinamicamente o ponteiro.
  *seg = (Seguidor*) malloc(sizeof(Seguidor)*num);

  if(!arquivo){
    printf("Problema de alocacao de memoria");
  }

  int i;

  fseek(arquivo, 0, SEEK_SET);
  //Coloca no vetor de structs os dados do arquivo
  for(i = 0; i < num; i++){
    fread(&((*seg)[i]), sizeof(Seguidor), 1, arquivo);
  }

  fclose(arquivo);

}

/*
Recebe um ponteiro para um ponteiro de struct User e 'carrega' o vetor com os dados do arquivo 'user_data.txt'.
*/
void all_users(User **list_users){
    //Abre o arquivo
    FILE *arquivo = fopen("user_data.txt", "r");

    if(!arquivo){
    printf("Nao foi possivel abrir o arquivo.");
    exit(1);
    }
    //Contao o numero de structs User no arquivo.
    int num = count_user();
    //Aloca dinamicamente o vetor.
    *list_users = (User *) malloc(sizeof(User)*num);

    if(!(*list_users)){
      printf("Problema de alocacao de memoria");
    }

    int i;

    fseek(arquivo, 0, SEEK_SET);
    //Coloca no vetor os dados do arquivo.
    for(i = 0; i < num; i++){
        fread(&((*list_users)[i]), sizeof(User), 1, arquivo);
    }

    fclose(arquivo);


}

/*
Recebe um ponteiro para um ponteiro de struct Post e 'carrega' o vetor com os dados do arquivo 'posts.txt'.
*/

void get_all_posts(Post **posts){
  //Abre o arquivo.
  FILE *arquivo = fopen("posts.txt", "r");

  if(!arquivo){
    printf("Nao foi possivel abrir o arquivo.");
    exit(1);
  }

  //Conta o numero de structs Post no arquivo.
  int num = count_posts();
  //Aloca dinamicamente o vetor.
  *posts = (Post *) malloc(sizeof(Post)*num);

  if(!(*posts)){
      printf("Problema de alocacao de memoria");
  }


  fseek(arquivo, 0, SEEK_SET);

  int i;
  //Coloca no vetor as structs Post do arquivo.
  for(i = 0; i < num; i++){
    fread(&((*posts)[i]), sizeof(Post), 1, arquivo);
  }

  fclose(arquivo);


}
