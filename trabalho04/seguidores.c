#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "users.h"
#include "seguidores.h"
#include "processos.h"
#include "posts.h"

/*
Funcao para descobrir se um certo usuario segue outro.
Sao recebidos como parametros uma string com o nick (login) do usuario e o ponteiro para o usuario logado atualmente.
*/
int search_seg(char str[20], User *user_){

    Seguidor *all_seg;
    /*Coloca no vetor os dados do arquivo 'seguidores.txt'
    */
    get_all_seg(&all_seg);
    //Numero de seguidores
    int num = count_seguidores();

    int i;

    int flag = 0;

    for(i = 0; i < num; i++){

        if(!strcmp(all_seg[i].seguido, str)){

            if(!strcmp(all_seg[i].autor, user_->nick)){
              
              /*
              Caso encontre-se uma struct Seguidor cujo campo   'seguido' seja o usuario que deseja-se descobrir se e seguido pelo usuario, e o campo autor seja o nick (login) do usuario logado, isso significa que o usuario logado segue esse outro usuario.
              */
              
              flag = 1;
              break;
            }
        }

    }

    free(all_seg);

    return flag;

}

/*
Permite ao usuario logado deixar de seguir um usuario.
*/

void del_seg(char autor[20], char seguido[20]){

    Seguidor *list_seg;
    /*
    Coloca no vetor as structs Seguidor do arquivo 'seguidores.txt'
    */
    get_all_seg(&list_seg);

    int num = count_seguidores();

    int i;
    /*
    Abre-se o arquivo em mode de escrita, deletando todo o seu conteudo, que esta salvo no vetor de structs Seguidor declarado anteriormente, list_seg.
    */
    FILE *arquivo = fopen("seguidores.txt", "w");

    if(!arquivo){
      printf("Nao foi possivel abrir o arquivo.");
      exit(1);
    }

    fseek(arquivo, 0, SEEK_SET);
    /*
    Escrevem-se no arquivo todas as structs do vetor, menos a que deseja-se deletar.
    */
    for(i = 0; i < num; i++){
        if(strcmp(list_seg[i].autor, autor) || strcmp(list_seg[i].seguido, seguido)){
          fwrite(&list_seg[i], sizeof(Seguidor), 1, arquivo);
        }
    }

    fclose(arquivo);

    free(list_seg);
  
}

/*
Permite ao usuario seguir outro.
*/

void seguir(User *user){
    /*Nova struct que guardara as informacoes desse nova relacao de seguir/ser seguido.
    */
    Seguidor n_seg;
    /*O campo 'autor' e o nick (login) do usuario logado.
    */
    strcpy(n_seg.autor, user->nick);

    Seguidor *list_seg;
    /*
    Colocam-se as structs Seguidor do arquivo 'seguidores.txt' no vetor list_seg.
    */
    get_all_seg(&list_seg);

    char str[20];

    User *users;

    int i;

    int num = count_user();
    /*
    Colocam-se as structs User do arquivo 'user_data.txt' no vetor users.
    */
    all_users(&users);

    /*
    Lista todos os usuarios, informando o 'status' deles, ou seja, se o usuario logado ja segue ou nao cada um dos demais usuarios existentes.
    */

    for(i = 0; i < num; i++){
      
      if(strcmp(users[i].nick, user->nick)){

      printf("%d --------\n", i+1);
      printf("Login: %s ", users[i].nick);

      if(search_seg(users[i].nick, user)){
        printf("status: seguindo\n");
      }else{
        printf("status: ainda nao segue\n");
      }

      printf("-------------\n");
    }
    }

    printf("Digite o login do usuario que deseja seguir/deixar de seguir:");
    /*
    Entrada, tratando o caso de o usuario inserir um login inexistente no sistema.
    */
    int flag = 0;
    do{

      fgetss(str, 19);

      for(i = 0; i < num; i++){
        if(!strcmp(str, users[i].nick)){
          flag = 1;
          break;
        }
      }

      if(flag == 0){
        printf("Digite novamente o nome do usuario(%s nao existe):\n", str);
      }

    }while(flag == 0);
     /*
      Se o usuario ja esta seguindo o login (nick) escolhido, ele deixa de segui-lo. Se ainda nao segue, passa a seguir.
     */ 
    if(search_seg(str, user)){
        //deixar de seguir o usuario
        del_seg(user->nick, users[i].nick);
    }else{
        FILE *seguidores = fopen("seguidores.txt", "a");

        if(!seguidores){
          printf("Nao foi possivel abrir o arquivo.");
          exit(1);
        }

        if(!seguidores){
          printf("Problema de alocacao de memoria");
          exit(1);
        }

      strcpy(n_seg.seguido, str);
      fwrite(&n_seg, sizeof(Seguidor), 1, seguidores);

      fclose(seguidores);
    }

    free(users);

    free(list_seg);

    //free(str);

}

/*Lista todos os seguidores do usuario atualmente logado.
*/

void list_seguidores(User *user){
    //Numero de structs no arquivo 'seguidores.txt'
    int num = count_seguidores();
    Seguidor *list_seg;
    /*
    Coloca no vetor todos as structs do arquivo.
    */
    get_all_seg(&list_seg);

    int i;

    printf("\nSeguido por:\n");
    /*
    Imprime os elementos de list_seg cujo campo 'seguido' seja o usuario logado atualmente.
    */
    for(i = 0; i < num; i++){

        if(!strcmp(list_seg[i].seguido, user->nick)){
              printf("%s\n", list_seg[i].autor);
        }
    }

    printf("\n");

    free(list_seg);
}
/*
Lista todos os usuarios que o usuario atualmente logado segue.
*/
void list_seguindo(User *user){
    //Numero de seguidores no arquivo 'seguidores.txt'
    int num = count_seguidores();
    Seguidor *list_seg;
    /*
    Coloca no vetor todos as structs do arquivo.
    */
    get_all_seg(&list_seg);

    int i;

    printf("\nSeguindo:\n");
    /*
    Imprime os elementos de list_seg cujo campo 'autor' seja o usuario logado atualmente.
    */
    for(i = 0; i < num; i++){

        if(!strcmp(list_seg[i].autor, user->nick)){
          printf("%s\n", list_seg[i].seguido);
        }

    }

    printf("\n");

    free(list_seg);
}
/*
Retorna o numero de usuarios que o usuario logado segue.
*/
int count_user_seguindo(User *user){
    //Numero de seguidores no arquivo 'seguidores.txt'

    int num = count_seguidores();

    Seguidor *list_seg;
    /*
    Coloca no vetor todos as structs do arquivo.
    */
    get_all_seg(&list_seg);

    int i;

    int count = 0;
    /*
    Sempre que se encontra uma struct seguidor cujo campo 'autor' seja igual ao login (nick) do usuario logado, incrementa-se o contador cont.
    */
    for(i = 0; i < num; i++){

        if(!strcmp(list_seg[i].autor, user->nick)){
            count++;
        }

    }

    free(list_seg);

    return count;
}

/*
Retorna o numero de seguidores do usuario logado atualmente.
*/

int count_user_seguidores(User *user){
    //Numero de structs no arquivo 'seguidores.txt'
    int num = count_seguidores();

    Seguidor *list_seg;
    /*
    Coloca no vetor as structs presentes no arquivo 'seguidores.txt'
    */
    get_all_seg(&list_seg);

    int i;

    int count = 0;
    /*
    Sempre que se encontra uma struct seguidor cujo campo 'seguido' seja igual ao login (nick) do usuario logado, incrementa-se o contador cont.
    */
    for(i = 0; i < num; i++){

        if(!strcmp(list_seg[i].seguido, user->nick)){
            count++;
        }

    }

    free(list_seg);
    return count;
}

/*
Retorna o numero de seguidores do usuario que possui mais seguidores, e, por meio do ponteiro str, escreve o login (nick) do usuario mais seguido.
*/

int mais_seguidores(char *str){

    User *users;
    /*
    Coloca-se no vetor as structs presentes no arquivo 'user_data.txt' 
    */
    all_users(&users);

    //Numero total de usuarios.
    int num = count_user();

    int i;

    int max = 0;

    int index = 0;

    int num_seguidores;
    /*
    Conta-se o numero de seguidores de cada usuario. Caso algum usuario tenha mais seguidores do que max, max recebe o numero de seguidores desse usuario.
    */
    for(i = 0; i < num; i++){
        num_seguidores = count_user_seguidores(&users[i]);
        if(num_seguidores >= max){
          max = num_seguidores;
          index = i;
        }
    }
    /*
    Escreve-se o nome do usuario com mais seguidores usando o ponteiro str.
    */
    num = count_user();
    if(num > 0){
      strcpy(str, users[index].nick);
    }else{
      strcpy(str, "nao ha usuarios cadastrados");
    }
    free(users);

    return max;
}

/*
Imprime a timeline do usuario em questao.
*/
void timeline(User *user){
    Seguidor *list_seg;
    /*
    Coloca-se no vetor as structs presentes no arquivo 'seguidores.txt'.
    */
    get_all_seg(&list_seg);
    //Numero de usuarios total.
    int n_users = count_user();
    /*
    Numero de structs Seguidor no arquivo 'seguidores.txt'
    */
    int n_seg = count_seguidores();
    //Numero total de posts.
    int n_posts = count_posts();
    //Lista de usuarios seguidos pelo usuario logado.
    User *seguindo_nick = (User *) malloc(sizeof(User)*n_seg);

    if(!seguindo_nick){
      printf("Problema de alocacao de memoria");
      exit(1);
    }

    User *list_user;
    /*
    Coloca no vetor as structs User do arquivo 'user_data.txt'.
    */
    all_users(&list_user);

    int i;

    int count_seguidores = 0;
    /*
    Copia os usuarios seguidos pelo usuario logado no vetor seguindo_nick.
    */
    for(i = 0; i < n_seg; i++){
      
      if(!strcmp(list_seg[i].autor, user->nick)){
          strcpy(seguindo_nick[count_seguidores].nick,list_seg[i].seguido);
          count_seguidores++;
          
      }

    }

    Post *all_posts;
    /*
    Coloca no vetor as structs Post do arquivo 'posts.txt'.
    */
    get_all_posts(&all_posts);

    int count = 0;

    /*
    Vetor que armazena as posicoes do vetor all_posts em que ha posts que devem ser exibidos na timeline.
    */

    int *pos = (int *) malloc(sizeof(int)*n_posts);

    /*
    Para cada post, verifica-se se ele foi escrito por algum dos usuarios que o usuario logado segue. Se for o caso, anota-se a posicao desse post no vetor pos.
    */

    for(i = 0; i < n_posts; i++){

      int j = 0;

      printf("\n");

      for(j = 0; j < count_seguidores; j++){
        if(!strcmp(all_posts[i].autor, seguindo_nick[j].nick)){
            pos[count] = i;
            count++;
            break;
          }
        }
    }
        


  int a = 0;

  int flag = 0;

  int number = count;

  /*
    Imprimem-se os posts cujas posicoes foram anotadas em pos, de 5 em 5.
  */
  
  do{
      printf("\nPosts de %d a %d\n", a + 1, a+5);
      i = 0;
      while(i < 5 && a < number){
        printf("\nPost n %d: ", a + 1);
		    printf("\n------------------\n");
        printf("-----Post de: %s\n", all_posts[pos[a]].autor);
        printf("%s\n\n", all_posts[pos[a]].men);
        printf("\n-------------------\n");
        a++;
        i++;
      }

      if(a < number){
        printf("\nDeseja ver os proximos 5 posts?\nDigite 1 para ver mais, outra tecla para parar");

        char r[2];

        fgetss(r, 1);

        if(strcmp(r, "1")){
          flag = 1;
        }
        //free(r);

      }else{
        printf("\n---------FIM---------\n");
        flag = 1;
      }
    }while(flag == 0);



    free(list_seg);

    free(list_user);

    free(all_posts);

    free(pos);

    free(seguindo_nick);

}