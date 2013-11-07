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
#include <ctype.h>
#define LINE_LENGTH 1024

int reverse=0;

char** read_lines(){
	//TODO
	//read the first 1024 characters of each line 
	//add them into an array of strings
	//until seeing EOF, and then return the array
	return NULL;
}

long mystrtol(char *start, char **rest){
	int exit=0;
	long number=0;
	int sign=1;
	int counter=0;
	char begin[LINE_LENGTH+1];
	strcpy(begin,start);
	*rest=start;
	while(!exit){
		if (begin[counter]==' '){
			counter++;
		}
		else{
			exit=1;
		}
	}
	if (begin[counter]=='+'){
		counter++;
	}
	else if (begin[counter]=='-'){
		sign=-1;
		counter++;
	}
	exit=0;
	while(!exit){
		if (!isdigit(begin[counter])){
			exit=1;
			*rest=&start[counter];
			number=number*sign;
		}
		else{
			number=number*10+(begin[counter]-'0');
			counter++;
		}
	}
	return number;
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
  /*	long* a=malloc(sizeof(long));
	long* b=malloc(sizeof(long));
	*a = 5;
	*b = 6;
	printf("%d", num_cmp(a,b));*/
	char* s = malloc(sizeof(char)*5);
	char* rest;
	long num;
	s[0]='4';
	s[1]='5';
	s[2]='c';
	s[3]='d';
	s[4]=0;
	num=mystrtol(s,&rest);
	printf("%ld, %s", num, rest);
	free(s);
}
