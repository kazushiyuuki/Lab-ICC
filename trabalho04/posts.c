#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"users.h"
#include"seguidores.h"
#include"processos.h"
#include"posts.h"


/*
Obtem a posicao no arquivo 'posts.txt' do post que o usuario deseja deletar. Funcao essencial para a funcao delete_post.
*/

int get_position(User *user, int index){

  //Quantidade de structs Post no arquivo 'posts.txt'
	int n = count_posts();
	
  int i;

  Post *all_posts;
  /*
  Copia as informacoes do arquivo 'posts.txt' para um vetor de ponteiros.
  */
  get_all_posts(&all_posts);

	int count = 0;

  /*
  Contam-se os posts de um dado autor ate chegar no
  do index escolhido pelo usuario. Entao retorna-se esse valor, que representa a posicao i no vetor de structs do post que deseja-se deletar.
  */
	for(i = 0; i < n; i++){
		
		if(!strcmp(all_posts[i].autor, user->nick)){

			if(count == index){

				return i;


			}

      count++;

		}


	}

  free(all_posts);

}


//Conta os posts de um dado usuario.

int count_user_posts(User *user){

  Post *posts;

  /*
  Copia as informacoes do arquivo 'posts.txt' para um vetor de ponteiros.
  */
  get_all_posts(&posts);

  int i;

  int nposts = 0;

  int num = count_posts();

  /*
  Sempre que um post do autor desejado for encontrado,
  nposts e incrementada.
  */

  for(i = 0; i < num; i++){

      if(!strcmp(posts[i].autor, user->nick)){
          nposts++;
      }


  }
  free(posts);
  return nposts;
}


//Deleta um post do usuario que esta atualmente logado.


void delete_post(User *user){

  /*Lista os posts do usuario de maneira numerada,
  para que ele possa escolher o numero do post que deseja deletar.
  */
	printf("\nApagar um post: Lista do seus posts (veja a lista e escolha o numero do post que deseja deletar):\n");
  list_posts(user);

  //Numero de posts do usuario em questao
  int maior = count_user_posts(user);

	char input[5];

  int aux = 0;

  int del;

  //Recebe a entrada

  do{
      aux = 0;
      printf("\nDigite o numero do post que deseja deletar:");
	    fgetss(input, 3);

      del = atoi(input) - 1;

      if(del >= maior || del < 0){
        printf("Entrada invalida! Digite novamente!\n");
        aux = 1;
      }

  }while(aux == 1);

  /*
  Utiliza-se a funcao get_position para descobrir em que posicao o post escolhido pelo usuario esta no arquivo com todos os posts.
  */

	int index = get_position(user, del);

  //Numero total de posts no arquivo 'posts.txt'
  int num = count_posts();

	int i = 0;
	
  Post *copy_posts;

  /*
  Copiam-se as informacoes do arquivo 'posts.txt' no vetor de structs copy_posts.
  */

  get_all_posts(&copy_posts);

  int count = 0;

  /*
  Abre-se 'posts.txt' em modo escrita, deletando todo o seu conteudo (que esta salvo no vetor de structs copy_posts).
  */

  FILE *lista = fopen("posts.txt", "w");

  if(!lista){
    printf("Nao foi possivel abrir o arquivo.");
    exit(1);
  }

  /*
  Todos os posts menos o da posicao que o usuario deseja deletar sao escritos no arquivo
  */

  for(i = 0; i < num; i++){
    if(i != index){
      fwrite(&copy_posts[i], sizeof(Post), 1, lista);
    }
  }

  free(copy_posts);

	fclose(lista);

  //free(input);
}

/*
Lista todos os posts de um dado usuario.
*/

void list_posts(User *user){
	
	int i;

  //Numero de posts total do arquivo 'posts.txt'
  int num = count_posts();

	//Post all_posts[num];

  Post *all_posts;

  /*
  Copiam-se as informacoes do arquivo 'posts.txt' no vetor de structs all_posts.
  */

  get_all_posts(&all_posts);
  
  int number = count_user_posts(user);

	char posts_user[number][127];

	int cont = 0;

  /*
  Copia no vetor de structs posts_user apenas os 
  posts do usuario que esta logado.
  */

	for(i = 0; i < num; i++){

		if(!strcmp(all_posts[i].autor, user->nick)){

			strcpy(posts_user[cont], all_posts[i].men);

			cont++;

		}


	}


	i = 0;

  int a = 0;

  int flag = 0;

  /*
  Lista os pontos de 5 em 5. Caso a lista acabe,
  imprime-se 'FIM' na tela.
  */

  do{
      printf("\nPosts de %d a %d\n", a + 1, a+5);
      i = 0;
      while(i < 5 && a < number){
        printf("\nPost n %d: ", a + 1);
		    printf("\n------------------\n");
        printf("%s", posts_user[a]);
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
      }else{
        printf("\n---------FIM---------\n");
        flag = 1;
      }
    }while(flag == 0);

  free(all_posts);

  printf("\n");
  
}


/*
Cria um novo post do usuario que esta atualmente logado.
*/

void create_post(User *user){

  /*
  O campo 'autor' da struct Post post_ sera igual ao campo nick (login) do ponteiro para struct user.
  */

	Post post_;

	strcpy(post_.autor, user->nick);
  /*
  //Maximo de caracteres permitido
  int max = 127;

  /*
  Vetor de caracteres alocado dinamicamente para tratar o caso de o usuario digitar alem da capacidade do vetor (sera usado realloc para mitigar tal problema).
  */

  char texto[128];

  int flag = 0;
  
  int i = 0;

  //Recebe a entrada
  printf("Digite seu texto:");
  fgetss(texto, 127);
  //Copia-se a mensagem no campo men do Post post_.
	strcpy(post_.men, texto);

  //Escreve-se o novo post no arquivo.
  FILE *post_list = fopen("posts.txt", "a");

  if(!post_list){
    printf("Nao foi possivel abrir o arquivo.");
    exit(1);
  }
	
	fwrite(&post_, sizeof(Post), 1, post_list);

  fclose(post_list);
  
}

//Imprime todos os posts.

void all_posts(){

    int i;

    int n = count_posts();

    //Post lista[n];

    Post *lista;

    get_all_posts(&lista);
    /*
    Copiam-se as informacoes do arquivo 'posts.txt' no vetor de structs lista.
    */
    int flag = 0;
    
    int a = 0;

    //Imprimem-se os posts de 5 em 5.

    printf("\n~LISTA DE POSTAGENS~\n");
    do{
      printf("\nPosts de %d a %d\n", a + 1, a+5);
      i = 0;
      while(i < 5 && a < n){
        printf("\n\n-----Autor: %s\n", lista[a].autor);
        printf("%s\n", lista[a].men);
        a++;
        i++;
      }

      if(a < n){
        printf("\nDeseja ver os proximos 5 posts?\nDigite 1 para ver mais, outra tecla para parar");

        char r[2];

        fgetss(r, 1);

        if(strcmp(r, "1")){
        flag = 1;
        }



      }else{
        printf("\n---------FIM---------\n");
        flag = 1;
      }
    }while(flag == 0);

    free(lista);

    printf("\n");

}