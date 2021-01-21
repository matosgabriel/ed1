all: executavel

executavel: main.o TADConjunto.o
	gcc -o executavel main.o TADConjunto.o

TADConjunto.o: TADConjunto.c TADConjunto.h
	gcc -c TADConjunto.c -Wall

main.o: main.c
	gcc -c main.c -Wall

clean:
	rm main.o TADConjunto.o executavel