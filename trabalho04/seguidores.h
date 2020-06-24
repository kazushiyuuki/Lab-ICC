typedef struct Seguidor{
    char autor[20];
    char seguido[20];

}Seguidor;

void seguir(User *user);

void list_seguidores(User *user);

void list_seguindo(User *user);

int count_user_seguindo(User *user);

int count_user_seguidores(User *user);

int mais_seguidores(char *str);

int search_seg(char str[20], User *user_);

void del_seg(char autor[20], char seguido[20]);

void timeline(User *user);

