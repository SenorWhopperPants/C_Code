CC      = gcc
CFLAGS  = -c -Wall -ansi -pedantic -std=c99
LFLAGS  = -o approx_sine -lm

approx_sine: main.o approx_sine.o
	$(CC) main.o approx_sine.o $(LFLAGS)

main.o: main.c approx_sine.h
	$(CC) $(CFLAGS) main.c 

approx_sine.o: approx_sine.c approx_sine.h
	$(CC) $(CFLAGS) approx_sine.c

clean:
	rm -f approx_sine a.out *.o *~ *#