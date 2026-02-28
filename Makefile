# lab2 task3 makefile

run: obj/main.o obj/abonent.o
	mkdir -p bin
	gcc -o bin/run obj/main.o obj/abonent.o

obj/main.o: src/main.c include/abonent.h
	mkdir -p obj
	gcc -Iinclude -c src/main.c -o obj/main.o

obj/abonent.o: src/abonent.c include/abonent.h
	mkdir -p obj
	gcc -Iinclude -c src/abonent.c -o obj/abonent.o

clean:
	rm -rf obj bin

start: run
	./bin/run

rebuild: clean run

.PHONY: clean start rebuild

