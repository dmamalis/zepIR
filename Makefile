CC=gcc
CFLAGS=-I

zepir: zepirApp.c zepir.c
	$(CC) -o zepirApp zepirApp.o zepir.o -I.

clean: rm -f ./*.o