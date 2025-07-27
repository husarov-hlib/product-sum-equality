main: main.c
	gcc main.c -o main -Wall -lm -O2 -lpthread

clean:
	rm main
