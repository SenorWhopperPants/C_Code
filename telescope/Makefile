CC      = gcc
CFLAGS  = -c -Wall -ansi -pedantic -std=c99
LFLAGS  = -o telescope

telescope: main.o telescope.o
	$(CC) main.o telescope.o $(LFLAGS)

main.o: main.c telescope.h
	$(CC) $(CFLAGS) main.c 

telescope.o: telescope.c telescope.h
	$(CC) $(CFLAGS) telescope.c

clean:
	rm -f telescope a.out *.o *~ *#
