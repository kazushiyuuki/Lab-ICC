users.o: users.c
	gcc -o users.o -c users.c
main.o: main.c
	gcc -o main.o -c main.c
main: main.o users.o
	gcc -o main main.o users.o
all: main

run: main 
	./main

