void clear();

typedef struct User{

	char nick[20];
  char nome[20];

}User;

typedef struct Post{

	char autor[20];
	char men[128];

}Post;

int create_user();

void list_users();

void delete_user();

void consultar_user();

void user_screen(User *user);
