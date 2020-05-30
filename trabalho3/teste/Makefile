entrada.o : entrada.c
	gcc -o entrada.o -c entrada.c
conta.o : conta.c
	gcc -o conta.o -c conta.c
saida.o : saida.c
	gcc -o saida.o -c saida.c
main.o : main.c
	gcc -o main.o -c main.c

main : main.o saida.o conta.o entrada.o
	gcc -o main main.o saida.o conta.o entrada.o
