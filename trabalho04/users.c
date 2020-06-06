#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "users.h"


void clear(){

	while(getchar() != '\n');

}

int count_posts(FILE *post_list){

	fseek(post_list, 0, SEEK_END);

	int pos = ftell(post_list);

	int num = pos/sizeof(Post);

	fseek(post_list, 0, SEEK_SET);

	return num;	

}

int get_position(FILE *post_list, User *user, int index){

	int n = count_posts(post_list);
	int i;

	Post all_posts[n];

	int count;

	for(i = 0; i < n; i++){
		
		fread(&all_posts[i], sizeof(Post), 1, post_list);

		if(!strcmp(all_posts[i].autor, user->nome)){

			count++;

			if(count == index){

				return i;


			}

		}

	}


	return 0;

}

void delete_post(FILE *post_list, User *user){

	list_posts(post_list, user);

	char input[5];
	printf("Digite o numero do post que deseja deletar:");
	fgets(input, 5, stdin);

	char del = atoi(input);

	int index = get_position(post_list, user, del);

	int num = count_posts(post_list);

	int i = 0;

	fseek(post_list, 0, SEEK_SET);
	
	Post copy_posts[num-1];

	while(i < num){

		if(i != index){
			fread(&copy_posts[i], sizeof(Post), 1, post_list);
			i++;
		}else{

			printf("here");

			//fseek(post_list, sizeof(Post), SEEK_CUR);
		}
		
	}

	fclose(post_list);

	FILE *lista = fopen("posts.txt", "w");

	for(i = 0; i < num-1; i++){
	
		fwrite(&copy_posts[i], sizeof(Post), 1, lista);

	}

	fclose(lista);



}

void list_posts(FILE *post_list, User *user){
	
	fseek(post_list, 0, SEEK_END);

	int pos = ftell(post_list);

	int num = pos/sizeof(Post);

	int i;

	Post all_posts[num];

	fseek(post_list, 0, SEEK_SET);

	for(i = 0; i < num; i++){

	   fread(&all_posts[i], sizeof(Post), 1, post_list);

	}

	printf("\nnum: %d\n", num);

	int number = 0;

	for(i = 0; i < num; i++){
		
		if(!strcmp(all_posts[i].autor, user->nome)){
			
			number++;

		}

	}
	
	char posts_user[number][127];

	int cont = 0;

	for(i = 0; i < num; i++){

		if(!strcmp(all_posts[i].autor, user->nome)){

			strcpy(posts_user[cont], all_posts[i].men);

			cont++;

		}


	}


	i = 0;

	while(i < 5 && i < number){

		printf("\n%d\n", i);
		printf("\n------------------\n");

		printf("%s", posts_user[i]);

		printf("-------------------\n");

		i++;

	}


}


void create_post(FILE *info, FILE *post_list, User *user){

	Post post_;

	strcpy(post_.autor, user->nome);

	char texto[127];

	printf("\nDigite seu texto:");

	fgets(texto, 127, stdin);

	strcpy(post_.men, texto);
	
	fwrite(&post_, sizeof(Post), 1, post_list);
	
}

void user_screen(FILE *file, User *user){

	FILE *post_list = fopen("posts.txt", "a+");
	while(1){
		char r;
		printf("Digite 1 para criar um post");
		printf("\nDigite 2 para ver seus posts");
		printf("\nDigite 3 para apagar um post");
		r = getc(stdin);
		clear();

		if(!post_list){
			
			printf("Deu ruim!");
			exit(1);
			
		}

		switch(r){

			case '1':
				create_post(file, post_list, user);
				break;
			case '2':
				list_posts(post_list, user);
				break;
			case '3':
				delete_post(post_list, user);
				break;


		}

		if(r == '3'){

			break;

		}

	}

}
