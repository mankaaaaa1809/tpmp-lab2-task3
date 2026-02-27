# lab2 task3 makefile

run: main.o abonent.o
	gcc -o run main.o abonent.o

main.o: src/main.c
	gcc -c src/main.c -o main.o

abonent.o: src/abonent.c
	gcc -c src/abonent.c -o abonent.o

clean:
	rm -f *.o run

