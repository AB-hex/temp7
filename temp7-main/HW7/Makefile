CC=gcc
CFLAGS=-Wall -g
CLINK=$(CC)

prog.exe: linked-list.o main.o grades.o
	$(CLINK) linked-list.o main.o -o prog.exe 

linked-list.o: linked-list.h linked-list.c
main.o: main.c linked-list.h
grades.o: grades.h grades.c linked-list.h 

clean:
	rm -f *.o *.exe