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
		if(i!=0) arraylist_addEnd(list,&cptr);
		else free(cptr);
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
/*
 * returns a long that is the number at the start of the line, excluding whitespaces
 * takes in a character pointer start, the address of a character pointer rest
 * start is the array that contains characters of the line. It must have a null character at the end
 * rest is the address of a character pointer to store the non-number part.
 * this function modifies the value in memory where you store the rest of the string.
 */
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
	char* s1;
	char* s2;
	//printf("%s %s",*(char**)a,*(char**)b);
	long num1=mystrtol(*(char**)a,&s1);
	long num2=mystrtol(*(char**)b,&s2);
	//printf("%ld %ld",num1,num2);
	if(num1==num2) return strcmp(s1,s2);
	return (num1)-(num2);
}
/*
 * sorts the lines of the input based on the number at the front
 * prints the lines sorted.
 */
void numeric_sort(){
	int (*fptr)(const void* a, const void* b);
	fptr=num_cmp;
	arraylist* list=read_lines();
	char* string;
	qsort(list->array,list->size,sizeof(char*),fptr);
	for(int i=0;i<list->size;++i){
		string=*(char**)arraylist_get(list,i);
		printf("%s\n",string);
		free(string);
	}
	arraylist_free(list);
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
	s[0]=' ';
	s[1]='5';
	s[2]=' ';
	s[3]=' ';
	s[4]=' ';
	s[5]='d';
	s[6]=0;
	num=mystrtol(s,&rest);
	printf("%ld,%s", num, rest);
	free(s);
*/
/*	arraylist* stringarray=read_lines();
	char* string;
	for(int i=0;i<stringarray->size;++i){
		string=*(char**)arraylist_get(stringarray,i);
		printf("%s\n",string);
		free(string);
	}
	arraylist_free(stringarray);
*/
	numeric_sort();
	//char* x;
	//printf("%ld",mystrtol("  40  meow ",&x));
}
