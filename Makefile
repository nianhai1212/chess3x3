.PHONY: exe

edit: main.o game.o 
	cc -o game main.o game.o

main.o:main.c
	cc -c main.c

game.o:game.c game.h
	cc -c game.c

clean:
	rm *.o
