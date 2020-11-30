CC      = gcc
CFLAGS  = -c -Wall -ansi -pedantic -std=c99
LFLAGS  = -o sieve

sieve: main.o sieve.o
	$(CC) main.o sieve.o $(LFLAGS)

main.o: main.c sieve.h
	$(CC) $(CFLAGS) main.c 

sieve.o: sieve.c sieve.h
	$(CC) $(CFLAGS) sieve.c

clean:
	rm -f sieve a.out *.o *~ *#
