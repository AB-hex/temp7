
CC=gcc
CFLAGS=-Wall -g
CLINK=$(CC)
OBJS=grades.o libgrades.so
EXEC=libgrades.so


libgrades.so: grades.o
	$(CLINK) ~shared grades.o -o libgrades.so -llinked-list -L.

grades.o: grades.h grades.c linked-list.h 
	$(CC) $(CFLAGS) -c -fpic grades.c

clean:
	rm -rf *.o *.exe libgrades.so
