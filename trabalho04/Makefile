processos.o: processos.c
	gcc -o processos.o -c processos.c

posts.o: posts.c
	gcc -o posts.o -c posts.c

seguidores.o: seguidores.c
	gcc -o seguidores.o -c seguidores.c  

users.o: users.c
	gcc -o users.o -c users.c
main.o: main.c
	gcc -o main.o -c main.c

main: main.o users.o seguidores.o processos.o posts.o
	gcc -o main main.o users.o seguidores.o processos.o posts.o
all: main

run: main 
	./main

