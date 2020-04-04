all: main.o findsubstr.o readline.o
	gcc main.o findsubstr.o readline.o -o mygrep

main.o: main.c findsubstr.h readline.h
	gcc -c main.c

findsubstr.o: findsubstr.c findsubstr.h
	gcc -c findsubstr.c

readline.o: readline.c readline.h
	gcc -c readline.c

clean:
	rm -f *.o mygrep