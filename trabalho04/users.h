void clear();




typedef struct Post{

	char autor[20];
	char men[125];




}Post;

typedef struct User{

	char nome[20];
	int nposts;

}User;

void user_screen(FILE *info, User *user);

void create_post(FILE *info, FILE *post_list,  User *user);

void list_posts(FILE *post_list, User *user);

void delete_post(FILE *post_list, User *user);

int count_posts(FILE *post_list);

int get_position(FILE *post_list, User *user, int index);
