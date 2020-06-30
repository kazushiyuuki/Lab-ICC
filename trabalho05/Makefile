jogadores.o : jogadores.c
	gcc -o jogadores.o -c jogadores.c
deck.o : deck.c
	gcc -o deck.o -c deck.c
jogo.o : jogo.c
	gcc -o jogo.o -c jogo.c
main.o : main.c
	gcc -o main.o -c main.c
main : main.o jogo.o deck.o jogadores.o
	gcc -o main main.o jogo.o deck.o jogadores.o
all : main
run : main
	./main
clean :
	rm *.o main