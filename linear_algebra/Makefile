CC      = gcc
CFLAGS  = -c -Wall -ansi -pedantic -std=c99
LFLAGS  = -o linear

linear: main.o linear_algebra.o
	$(CC) main.o linear_algebra.o $(LFLAGS)

main.o: main.c linear_algebra.h
	$(CC) $(CFLAGS) main.c 

linear_algebra.o: linear_algebra.c linear_algebra.h
	$(CC) $(CFLAGS) linear_algebra.c

clean:
	rm -f linear a.out *.o *~ *#
