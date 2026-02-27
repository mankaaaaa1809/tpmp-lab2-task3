# lab2 task 3 makefile

run: main.o abonent.o
	gcc -o run main.o abonent.o

main.o: main.c
	gcc -c main.c

abonent.o: abonent.c
	gcc -c abonent.c

clean: 
	rm -f *.o run