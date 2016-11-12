TP4: main.o emp.o arr.o
	gcc -o TP4 main.o emp.o arr.o

main.o: src/main.c inc/ArrayList.h inc/Employee.h
	gcc -c src/main.c -o main.o

emp.o: src/Employee.c
	gcc -c src/Employee.c -o emp.o

arr.o: src/ArrayList.c
	gcc -c src/ArrayList.c -o arr.o

