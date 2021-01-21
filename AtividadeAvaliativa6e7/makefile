all: executavel

executavel: main.o ABB.o
	gcc -o executavel main.o ABB.o

ABB.o: ABB.c ABB.h
	gcc -c ABB.c -Wall

main.o: main.c
	gcc -c main.c -Wall

clean:
	rm main.o ABB.o executavel