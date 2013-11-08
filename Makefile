#!/bin/sh

all: sort arraylist_test

sort: sort.c arraylist.o
	clang -g -Wall -pedantic -std=c99 -o sort sort.c arraylist.o 
arraylist: arraylist.c
	clang -c arraylist.c
arraylist_test: arraylist_test.c arraylist.o
	clang -g -Wall -pedantic -std=c99 -o arraylist_test arraylist_test.c arraylist.o
clean:
	rm -f sort arraylist_test arraylist.o *~
