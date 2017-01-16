CC = gcc
CFLAGS = -Wall

all: aocp2p1 aocp2p2

aocp2p1: aocp2p1.c
	$(CC) $(CFLAGS) aocp2p1.c -o aocp2p1

aocp2p2: aocp2p2.c
	$(CC) $(CFLAGS) aocp2p2.c -o aocp2p2

clean:
	rm aocp2p1 aocp2p2
