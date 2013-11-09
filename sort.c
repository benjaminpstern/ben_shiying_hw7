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
#include "arraylist.h"
#define LINE_LENGTH 1024

int reverse=0;
int fold_case=0;

arraylist* read_lines(){
//char** read_lines(){
	int i;
	int c=0;
	char* cptr;
	//char** pptr;
	arraylist* list=arraylist_init(sizeof(char*),10);
	while(c!=EOF){
		cptr=malloc(sizeof(char)*LINE_LENGTH+1);
		if(!cptr){
			fprintf(stderr,"Out of memory");
			exit(1);
		}
		for(i=0;i<LINE_LENGTH&&(c=getchar())!=EOF&&c!='\n';++i){
			cptr[i]=c;
		}
		cptr[i]=0;
		arraylist_addEnd(list,&cptr);
	}
	/*pptr=malloc(list->size*sizeof(char*));
	if(!pptr){
                fprintf(stderr,"Out of memory");
                exit(1);
        }
	for(i=0;i < list->size;i++){
		pptr[i]=arraylist_get(list,i);
	}
	arraylist_free(list);
	return pptr;
	*/
	return list;
	//TODO
	//read the first 1024 characters of each line 
	//add them into an array of strings
	//until seeing EOF, and then return the array
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

void string_sort(){
	//TODO to be implemented
}

int main(){
  /*	long* a=malloc(sizeof(long));
	long* b=malloc(sizeof(long));
	*a = 5;
	*b = 6;
	printf("%d", num_cmp(a,b));*/
/*	char* s = malloc(sizeof(char)*5);
	char* rest;
	long num;
	s[0]='4';
	s[1]='5';
	s[2]='c';
	s[3]='d';
	s[4]=0;
	num=mystrtol(s,&rest);
	printf("%ld, %s", num, rest);
	free(s);*/
	arraylist* stringarray=read_lines();
	char* string;
	for(int i=0;i<stringarray->size;++i){
		string=*(char**)arraylist_get(stringarray,i);
		printf("%s\n",string);
		free(string);
	}
	arraylist_free(stringarray);
}
