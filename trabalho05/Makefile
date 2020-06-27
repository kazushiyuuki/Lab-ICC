jogo.o : jogo.c
	gcc -o jogo.o -c jogo.c
main.o : main.c
	gcc -o main.o -c main.c
main : main.o jogo.o
	gcc -o main main.o jogo.o
all : main
run : main
	./main