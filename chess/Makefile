CC      = gcc
CFLAGS  = -c -Wall -ansi -pedantic -std=c99
LFLAGS  = -o chess

chess: main.o chess.o
	$(CC) main.o chess.o $(LFLAGS)

main.o: main.c chess.h
	$(CC) $(CFLAGS) main.c 

chess.o: chess.c chess.h
	$(CC) $(CFLAGS) chess.c

clean:
	rm -f chess a.out *.o *~ *#
