# lab2 task3 makefile

run: main.o abonent.o
	gcc -o run main.o abonent.o

main.o: src/main.c src/abonent.h
	gcc -c src/main.c -o main.o

abonent.o: src/abonent.c src/abonent.h
	gcc -c src/abonent.c -o abonent.o

clean:
	rm -f *.o run

start: run
	./run

rebuild: clean run

.PHONY: clean start rebuild

