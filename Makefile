main: main.c
	gcc main.c -o main -Wall -lm -O2

clean:
	rm main
