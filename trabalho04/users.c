#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "users.h"
#include "seguidores.h"
#include "processos.h"
#include "posts.h"

/*
Cria um novo usuario.
*/
int create_user(){

  //Struct User do novo usuario

	User user;

  /*
  Entrada, com a verificacao para impedir de criar um usuario com um login (nick) ja usado anteriormente por outro.
  */
  printf("Digite o nome do usuario:\n");

  char str[20];
  fgetss(str, 19);
	strcpy(user.nome, str);
	printf("Digite o login do usuario:\n");

  int num = count_user();
  
  User *users;

  all_users(&users);
  
  int i = 0;

  int flag;
  do{
    flag = 0;
    char entry[20];
    fgetss(entry, 19);
    strcpy(user.nick,entry);
    for(i = 0; i < num; i++){
      if(!strcmp(user.nick, users[i].nick)){
          printf("Digite novamente o login do usuario(%s já utilizado):\n", user.nick);
          flag = 1;
          break;
      }
    }
  }while(flag);

  //Escreve-se o novo usuario no arquivo.
  FILE *arquivo = fopen("user_data.txt", "a");

  if(!arquivo){
    printf("Nao foi possivel abrir o arquivo.");
    exit(1);
  }

	fwrite(&user, sizeof(User), 1, arquivo);
  fclose(arquivo);

  printf("\n");

  free(users);

}
/*
Listar todos os usuarios registrados.
*/
void list_users(){

	int i;
	
  //Numero total de usuarios.
	int num = count_user();
  


	printf("\nNumero de usuarios: %d \n", num);

	User *user;

  /*
  Colocam-se todas as structs User presentes no arquivo
  'user_data.txt' no vetor user.
  */
  all_users(&user);

	for(i = 0; i < num; i++){
	
    printf("\nNome do usuario: %s ", user[i].nome);
		printf("\nLogin do usuario: %s ", user[i].nick);
		printf("\nNumero de posts: %d", count_user_posts(&user[i]));
    printf("\nSeguidores: %d", count_user_seguidores(&user[i]));
    printf("\nSeguindo: %d", count_user_seguindo(&user[i]));
    printf("\n");
	}

  free(user);

  printf("\n");

}


//Permite deletar um usuario.
void delete_user(){
  //Lista todos os usuarios para o usuario ver.
	
  list_users();

  char str[20];

  int flag;

  User *copy_users;
  /*
  Colocam-se todas as structs User presentes no arquivo 'user_data.txt' no vetor copy_users.
  */

  all_users(&copy_users);

  int i;

  //Numero total de usuarios registrados.

  int num = count_user();
  /*
  Entrada, checando para impedir que o usuario delete um usuario que nao existe.
  */
  do{
    flag = 1;
    printf("Digite o login do usuario que deseja deletar:");
    fgetss(str, 19);

    for(i = 0; i < num; i++){
      if(!strcmp(copy_users[i].nick, str)){
        flag = 0;
      }
    }

    if(flag == 1){
      printf("\n*******\nEsse usuario nao existe!\n****\n");
    }

  } while (flag);

	i = 0;

  /*
  Abre-se o arquivo 'user_data.txt' em modo leitura, apagando seu conteudo, que esta salvo no vetor copy_sers.
  */

	FILE *lista = fopen("user_data.txt", "w");

  if(!lista){
    printf("Nao foi possivel abrir o arquivo.");
    exit(1);
  }

  fseek(lista, 0, SEEK_SET);

  /*
  Escrevem-se no arquivo todos os usuarios menos o que o usuario deseja deletar.
  */
	for(i = 0; i < num; i++){
    if(strcmp(copy_users[i].nick, str)){
		  fwrite(&copy_users[i], sizeof(User), 1, lista);
    }
	}

  free(copy_users);

  fclose(lista);

  //Deletam-se todos os Posts do usuario a ser apagado.

  Post *posts;

  get_all_posts(&posts);

  num = count_posts();

  FILE *lista_posts = fopen("posts.txt", "w");

  if(!lista_posts){
    printf("Nao foi possivel abrir o arquivo.");
    exit(1);
  }

  for(i = 0; i < num; i++){
    if(strcmp(posts[i].autor, str)){
      fwrite(&posts[i], sizeof(Post), 1, lista_posts);
    }
  }

  fclose(lista_posts);

  /*Deletam-se todo o historico de seguido/seguidores do usuario a ser apagado.
  */
  Seguidor *list_seg;

  get_all_seg(&list_seg);

  num = count_seguidores();

  FILE *lista_seg = fopen("seguidores.txt", "w");

  if(!lista_seg){
    printf("Nao foi possivel abrir o arquivo.");
    exit(1);
  }

  for(i = 0; i < num; i++){
    if(strcmp(list_seg[i].autor, str)){
      fwrite(&list_seg[i], sizeof(Seguidor), 1, lista_seg);
    }
  }

  free(list_seg);

  free(posts);

	fclose(lista_seg);



}
/*
Permite ao admin consultar um usuario.
*/
void consultar_user(){

  char login[20];

	printf("\nInsira o login do usuario que deseja consultar:");
	
	fgetss(login, 19);

	int i;

  int num = count_user();

  User *user;

	all_users(&user);

	int flag = 0;

	for(i = 0; i < num; i++){
  
		if(strcmp(user[i].nick, login) == 0){

			printf("Usuario encontrado!\n\n");
			
			flag = 1;

      int del = 0;

	    while(1){

        printf("-------PERFIL-------\n");
        printf("Nome: %s\n", user[i].nome);
        printf("Login: %s\n", user[i].nick);
        printf("Numero de posts: %d\n", count_user_posts(&user[i]));
        printf("Seguidores: %d\n", count_user_seguidores(&user[i]));
        printf("Seguindo: %d\n", count_user_seguindo(&user[i]));
        printf("\n-------MENU-------\n");

          char r[3];
          printf("\nDigite 1 para ver os posts");
          printf("\nDigite 2 para ver os seguidores");
          printf("\nDigite 3 para ver quem ele segue");
          printf("\nDigite 4 para ver os posts de quem ele segue (timeline):");
          printf("\nDigite 5 para voltar a pagina anterior");
          
          fgetss(r, 2);

          int a = atoi(r);

          switch(a){

            case 1:
              printf("Lista de posts:\n");
              list_posts(&user[i]);
              break;
            case 2:
              list_seguidores(&user[i]);
              break;
            case 3:
              list_seguindo(&user[i]);
              break;
            case 4:
              timeline(&user[i]);
              break;
            case 5:
              printf("\n");
              del = 1;
              break;
            default:
              printf("\n\n*****************");
              printf("\nentrada invalida!\n");
              printf("*****************\n\n");
              break;

          }

          if(del == 1){

            break;

          }

	      }

			  break;
        
      }

		}

	if(flag == 0){
    printf("\n********************\n");
		printf("\nNao encontramos esse usuario!\n");
    printf("\n**********************\n");
	}

  free(user);

 // free(login);

}

/*
Menu inicial do usuario apos logar.
*/
void user_screen(User *user){

  int del = 0;


	while(1){

  printf("-------PERFIL-------\n");
  printf("Nome: %s\n", user->nome);
  printf("Login: %s\n", user->nick);
  printf("Numero de posts: %d\n", count_user_posts(user));
  printf("Seguidores: %d\n", count_user_seguidores(user));
  printf("Seguindo: %d\n", count_user_seguindo(user));
  printf("\n-------MENU-------\n");

		char r[3];
		printf("Digite 1 para criar um post");
		printf("\nDigite 2 para ver seus posts");
		printf("\nDigite 3 para apagar um post");
    printf("\nDigite 4 para seguir/parar de seguir alguem");
    printf("\nDigite 5 para ver seus seguidores");
    printf("\nDigite 6 para ver quem voce segue");
    printf("\nDigite 7 para ver os posts de quem voce segue (timeline):");
    printf("\nDigite 8 para voltar a pagina anterior (logout)");
		fgetss(r, 2);

    int a = atoi(r);
    
		switch(a){

			case 1:
				create_post(user);
				break;
			case 2:
        printf("Lista de posts:\n");
				list_posts(user);
				break;
			case 3:
				delete_post(user);
				break;
      case 4:
        seguir(user);
        break;
      case 5:
        list_seguidores(user);
        break;
      case 6:
        list_seguindo(user);
        break;
      case 7:
        timeline(user);
        break;
      case 8:
        printf("\n");
        del = 1;
        break;
      default:
        printf("\n\n*****************");
        printf("\nentrada invalida!\n");
        printf("*****************\n\n");
        break;

		}
		if(del == 1){

			break;

		}
	}
}
