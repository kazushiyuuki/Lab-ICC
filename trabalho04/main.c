#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"users.h"





int count_users(FILE *info){

	fseek(info, 0, SEEK_END);

	int pos = ftell(info);

	int num = pos/sizeof(User);

}

int create_user(FILE *info){
	
	User user;

	printf("Digite o nome do usuario:\n");

	clear();

	fgets(user.nome, 19, stdin);

	user.nposts = 0;

	fwrite(&user, sizeof(User), 1, info);

}

void list_users(FILE * info){

	int i;

	fseek(info, 0, SEEK_SET);
	
	int num = count_users(info);

	printf("\nNumero de usuarios: %d \n", num);

	User user[num];

	fseek(info, 0, SEEK_SET);

	for(i = 0; i < num; i++){
		
		fread(&user[i], sizeof(User), 1, info);
		printf("\nUsuario: %s ", user[i].nome);
		printf("Numero de posts: %d\n", user[i].nposts);

	}

}

void login(FILE *info){

	char login[20];

	printf("\nInsira seu login:");
	
	clear();

	fgets(login, 20, stdin);

	int i;

	int num = count_users(info);

	User user[num];

	fseek(info, 0, SEEK_SET);

	for(i = 0; i < num; i++){
		
		fread(&user[i], sizeof(User), 1, info);

	}

	int flag = 0;

	fseek(info, 0, SEEK_SET);

	for(i = 0; i < num; i++){

		if(strcmp(user[i].nome, login) == 0){

			printf("Logado com sucesso!\n\n");
			
			flag = 1;

			User *ponteiro = &(user[i]);

			user_screen(info, ponteiro);
			
			break;

		}

	}

	if(flag == 0){
		printf("Nao encontramos voce!");
	}
}


int main(int argc, char *argv[]){


	FILE *info = fopen("user_data.txt", "a+");
	
	char string[100];

	int i;


	Post n_post;
	
	char r;
	printf("Criar um usuario (tecle 1)");
	printf("\nVer todos os usuarios (tecle 2)");
	printf("\nFazer login (tecle 3)");
	r = getc(stdin);
	
	switch(r){


		case '1':
			create_user(info);
			break;
		case '2':
			list_users(info);
			break;
		case '3':
			login(info);
			break;


	}


}
