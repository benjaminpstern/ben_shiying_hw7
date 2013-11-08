#!/bin/sh

all: sort

sort: sort.c arraylist.o
	clang -g -Wall -pedantic -std=c99 -o sort sort.c 
arraylist: arraylist.c
	clang -c arraylist.c
clean:
	rm -f sort *~
