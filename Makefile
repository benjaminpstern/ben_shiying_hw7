#!/bin/sh

all: sort

sort: sort.c
	clang -g -Wall -pedantic -std=c99 -o sort sort.c

clean:
	rm -f sort *~