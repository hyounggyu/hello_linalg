CC=gcc
CFLAGS=-I.
DEPS = linalg_lu.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

lu_c: main.o linalg_lu.o
	gcc -o lu_c main.o linalg_lu.o
