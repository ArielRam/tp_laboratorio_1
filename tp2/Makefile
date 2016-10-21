all: main.o lib.o
	gcc lib.o main.o -o tp2

main.o: main.c
	gcc -c main.c -o main.o

lib.o: library.c library.h
	gcc -c library.c -o lib.o

clean:
	rm lib.o main.o tp2 || true

rebuild: clean all

