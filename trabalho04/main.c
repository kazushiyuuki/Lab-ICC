#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"users.h"
#include"seguidores.h"
#include"processos.h"
#include"posts.h"

/*
Imprimi o nome da rede social com caracteres ASCII
*/
void imprime_nome(){
 printf("----------------------\n");
 printf("\nＡＮＴＩＳＯＣＩＡＬＮＥＴ\n");
 printf("\nUma rede social antisocial\n");
 printf("------------------------\n\n");
}

/*
Deleta todos os dados da rede social, incluindo
usuarios, posts e seguidores.
*/
void deleta_dados(){

  printf("digite 1 para confirmar operacao (deseja mesmo deletar\ntodos os dados da rede social?)");
  
  char r[2];
  fgetss(r, 1);

  FILE *f_a, *f_b, *f_c;

  if(r[0] == '1'){
    /*
    Abre os arquivos em mode de escrita,
    deletando, portando, o conteudo de cada um deles.
    */
    f_a = fopen("user_data.txt", "w");
    f_b = fopen("posts.txt", "w");
    f_c = fopen("seguidores.txt", "w");

    if(!f_a || !f_b || !f_c){
      printf("Nao foi possivel abrir os arquivos.");
      exit(1);
    }


  }
  else{
    return;
  }

  fclose(f_a);
  fclose(f_b);
  fclose(f_c);
  return;
}

/*
Funcao que permite a um usuario logar em sua conta.
*/
void login(){

	char login[20];

	printf("\nInsira seu login:");
	
	fgetss(login, 19);

	int i;

  //Conta o numero de usuarios existentes

  int num = count_user();
  

  User *user;
  
  /*
  Transfere os dados do arquivo para o ponteiro de vetores
  */
	all_users(&user);

	int flag = 0;


	for(i = 0; i < num; i++){

		if(strcmp(user[i].nick, login) == 0){

			printf("Logado com sucesso!\n\n");
			
			flag = 1;

      //Passa um ponteiro para o usuario logado.

			User *ponteiro = &(user[i]);

			user_screen(ponteiro);
			
			break;

		}

	}

  //Caso nao seja encontrado o Usuario
	
  if(flag == 0){
		printf("\n********************\n");
		printf("\nNao encontramos esse usuario!\n");
    printf("\n**********************\n");
	}

  free(user);
}


int main(int argc, char *argv[]){

  //Imprime nome da rede social
  imprime_nome();

	int i;
	//Vetor para receber as entradas
  char r[3];
  
  //String para user com mais seguidores
  char nick_mais_seguidores[20];
  printf("\n\n---Voce está no modo admin---\n\n");
  //Menu de funcoes da rede social
  do{

    printf("-----INFORMACOES GERAIS-------\n");
    printf("Numero de usuarios: %d\n", count_user());
    printf("Numero de posts: %d\n", count_posts());

    int max = mais_seguidores(nick_mais_seguidores);

    printf("Usuario com mais seguidores: %s (%d seguidores)\n", nick_mais_seguidores, max);

    printf("\n-------------MENU-------------\n");
  
    printf("Criar um usuario (tecle 1)");
    printf("\nVer todos os usuarios (tecle 2)");
    printf("\nFazer login (tecle 3)");
    printf("\nSair (tecla 4)");
    printf("\nListar todos os posts (tecle 5)");
    printf("\nDeletar um usuario (tecle 6)");
    printf("\nConsultar um usuario (tecle 7)");
    printf("\nDeletar todos os dados (tecle 8)\n");

    fgetss(r, 2);
    
    int a = atoi(r);

    switch(a){
      
      case 1:
        create_user();
        break;
      case 2:
        list_users();
        break;
      case 3:
        login();
        break;
      case 4:
        break;
      case 5:
        all_posts();
        break;
      case 6:
        delete_user();
        break;
      case 7:
        consultar_user();
        break;
      case 8:
        deleta_dados();
        break;
      default:
        printf("\n\n*****************");
        printf("\nentrada invalida!\n");
        printf("*****************\n\n");
        break;
        
    }

  }while(r[0] != '4');
  return 0;
}
