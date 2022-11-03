
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

middle-of-the-linked-list: middle-of-the-linked-list.o
	$(CC) $(CFLAGS) -o middle-of-the-linked-list middle-of-the-linked-list.o

middle-of-the-linked-list.o: middle-of-the-linked-list.cpp
	$(CC) $(CFLAGS) -c middle-of-the-linked-list.cpp

clean:
	rm -rf middle-of-the-linked-list middle-of-the-linked-list.o
