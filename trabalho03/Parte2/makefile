jogo.o : jogo.c
	gcc -o jogo.o -c jogo.c

main.o : main.c
	gcc -o main.o -c main.c

game : jogo.o main.o
	gcc -o game jogo.o main.o

all: game

run : game
	./game

clean : 
	rm game *.o