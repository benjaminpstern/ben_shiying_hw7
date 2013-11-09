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
#include <strings.h>
#include <ctype.h>
#include "arraylist.h" //Here is an arraylist struct we made and we acquired Professor Kuperman's permission to use it
#define LINE_LENGTH 1024

int reverse=0;
int fold_case=0;

/*
 * read through all the lines from standard input
 * return an arraylist of the lines
 */
arraylist* read_lines(){
	int i;
	int c=0;
	char* cptr;
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
	return list;
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
/*
 * takes two void pointers a and b, which point to character pointers
 * compares two strings a and b
 * use strcasecmp for case folding compare
 * and strcmp for regular compare
 * returns an integer. if return value is 0, the strings equal; if negative, a is less than b; otherwise a is bigger than b
 */
int string_cmp(const void* a, const void* b){
        if (fold_case){
                return strcasecmp(*(const char**)a,*(const char**)b);
        }
        return strcmp(*(const char**)a, *(const char**)b);
}
/*
 * takes in two parameters a and b, which point to character pointers
 * compares two numbers at the front of a and b, if any
 * if the numbers are the same, compare the rest of a and b using string_cmp and return the value of the comparison
 * otherwise, returns an integer that is the difference of the numbers in a and b
 */
int numeric_cmp (const void * a, const void * b){
	char* s1;
	char* s2;
	//printf("%s %s",*(char**)a,*(char**)b);
	long num1=mystrtol(*(char**)a,&s1);
	long num2=mystrtol(*(char**)b,&s2);
	//printf("%ld %ld",num1,num2);
	if(num1==num2) return string_cmp(&s1,&s2);
	return (num1)-(num2);
}
/*
 * sorts the lines of the input based on the number at the front
 * prints the lines sorted.
 */
void numeric_sort(){
	int (*fptr)(const void* a, const void* b);
	fptr=numeric_cmp;
	arraylist* list=read_lines();
	char* string;
	qsort(list->array,list->size,sizeof(char*),fptr);
	for(int i=0;i<(list->size);++i){
		string=*(char**)arraylist_get(list,i);
		printf("%s\n",string);
		free(string);
	}
	arraylist_free(list);
}
/*
 * sorts the lines using ascii values
 * prints the lines sorted.
 */
void string_sort(){
	int (*fptr)(const void *a, const void* b);
	fptr=string_cmp;
	arraylist* list=read_lines();
	char* string;
	qsort(list->array,list->size,sizeof(char*),fptr);
	if(reverse){
		for (int i=(list->size)-1;i>=0;--i){
			string=*(char**)arraylist_get(list,i);
			printf("%s\n",string);
			free(string);
		}
	}
	else{
		for(int i=0;i<(list->size);++i){
                string=*(char**)arraylist_get(list,i);
                printf("%s\n",string);
                free(string);
	        }
	}
	arraylist_free(list);
}
/*
 * The main function takes care of flags and calls different sorting functions based on the flags
 */
int main(int argc, char *argv[]){
	int number_sort=0;
	int i;
	int error=0;
	for (i=1;i<argc;i++){
		if (!strcmp(argv[i],"-f")){
			fold_case=1;
		}
		else if (!strcmp(argv[i],"-n")){
			number_sort=1;
		}
		else if (!strcmp(argv[i],"-h") || !strcmp(argv[i], "-?")){
			error=1;
			break;
		}
		else if (!strcmp(argv[i],"-r")){
			reverse=1;
		}
		else{
			printf("Unknown flag %s\n\n", argv[i]);
			error=1;
			break;
		}
	}
	if(error){
		printf("Usage %s [-f] [-n]\n\n", argv[0]);
		printf("Sort lines\n\n");
		printf("	-f      Case insensitive sort\n");
		printf("	-n      Sort based on the numeric value at the front of the line\n");
		printf("	-h/-?   This message\n\n");
	}
	else{
		if (number_sort){
			numeric_sort();
		}
		else{
			string_sort();
		}
	}
}
