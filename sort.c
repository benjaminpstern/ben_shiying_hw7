/*
 * Program: sort.c
 * Usage:
 * CS241 hw7
 * Author Shiying Zheng and Ben Stern
 * Tue Nov 5 21:05:25 CST 2013
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int reverse=0;

char* next_line(){
	//TODO to be implemented
	return NULL;
}

long mystrtol(char *start, char **rest){
	//TODO to be implemented
	return 0;
}

int num_cmp (const void * a, const void * b){
	long* num1=(long*)a;
	long* num2=(long*)b;
	return (*num1)-(*num2);
}

void numeric_sort(){
	//TODO to be implemented
}

void string_sort(int case_sensitive){
	//TODO to be implemented
}

int main(){
	long* a=malloc(sizeof(long));
	long* b=malloc(sizeof(long));
	*a = 5;
	*b = 6;
	printf("%d", num_cmp(a,b));
/*	long a;
	long b;
	a=5;
	b=6;
	long* x = &a;
	long* y = &b;
	printf("%d",num_cmp(x,y));*/
}
