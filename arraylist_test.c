/*
 * Program: arraylist_test.c
 * Usage:
 * CS241 hw7
 * Author Shiying Zheng and Ben Stern
 * Thu Nov  7 18:43:18 CST 2013
 */
#include "arraylist.h"
void print(int testNum, int pass){
	printf("Test %d ",testNum);
	if(pass) printf("passed\n");
	else printf("failed\n");
}
void printInt(void* i){
	int j=*((int*)i);
	printf("%d",j);
}
void printList(arraylist* list){
	int i;
	printf("[");
	for(i=0;i<list->size;++i){
		if(i!=0) printf(",");
		printf("%d",*(int*)arraylist_get(list,i));
	}
	printf("]\n");
}
int main(){
	//printf("SizeofInt is %d\n",sizeof(int));
	void* sparePointer;
	arraylist *list=arraylist_init(sizeof(int),10);
	arraylist *otherList;
	int i;
	int n=100;
	int j;
	int pass=1;
	for(i=0;i<n;++i){
		arraylist_addEnd(list,(void*)&i);
	}
	for(i=0;i<n;++i){
		j=*(int*)arraylist_get(list,i);
		if(j!=i) pass=0;
	}
	print(1,pass);
	arraylist_free(list);
	pass=1;
	list=arraylist_init(sizeof(int),10);
	for(i=0;i<n;++i){
		j=2*i;
		arraylist_add(list,i,(void*)&j);
	}
	for(i=0;i<n;++i){
		j=*(int*)arraylist_get(list,i);
		if(j!=2*i) pass=0;
	}
	print(2,pass);
	arraylist_free(list);
	pass=1;
	list=arraylist_init(sizeof(int),10);
	for(i=0;i<n;++i){
		j=i;
		arraylist_add(list,0,(void*)&j);
		//printList(list);
	}
	for(i=0;i<n;++i){
		j=*(int*)arraylist_get(list,i);
		if(j!=n-i-1) pass=0;
		//printf("%d\n",j);
	}
	print(3,pass);
	arraylist_free(list);
	pass=1;
	list=arraylist_init(sizeof(int),10);
	i=0;
	arraylist_addEnd(list,&i);
	i=9;
	arraylist_addEnd(list,&i);
	for(i=8;i>0;--i){
		arraylist_add(list,1,(void*)&i);
	}
	for(i=0;i<10;++i){
		j=*(int*)arraylist_get(list,i);
		if(j!=i) pass=0;
	}
	print(4,pass);
	arraylist_free(list);
	list=arraylist_init(sizeof(int),n);
	for(i=0;i<n;++i){
		arraylist_addEnd(list,(void*)&i);
	}
	pass=1;
	for(i=0;i<n;++i){
		sparePointer=arraylist_removeEnd(list);
		j=*(int*)sparePointer;
		//printf("%d"\n,j);
		if(j!=n-1-i) pass=0;
		free(sparePointer);
	}
	print(5,pass);
	for(i=0;i<n;++i){
		arraylist_addEnd(list,(void*)&i);
	}
	pass=1;
	for(i=0;i<n;++i){
		sparePointer=arraylist_remove(list,0);
		j=*(int*)sparePointer;
		//printf("%d"\n,j);
		if(j!=i) pass=0;
		free(sparePointer);
	}
	arraylist_free(list);
	print(6,pass);
	pass=1;
	list=arraylist_init(sizeof(int),n);
	for(i=0;i<n;++i){
		arraylist_addEnd(list,(void*)&i);
	}
	otherList=arraylist_subList(list,1,n-2);
	for(i=1;i<n-5;++i){
		j=*(int*)arraylist_get(otherList,i);
		//printf("%d\n",j);
		if(j!=i+1) pass=0;
	}
	print(7,pass);
	arraylist_free(otherList);
	arraylist_free(list);
	list=arraylist_init(sizeof(int),n);
	for(i=0;i<n;++i){
		arraylist_addEnd(list,(void*)&i);
	}
	//printList(list);
	for(i=0;i<n/2;++i){
		arraylist_swap(list,i,n-1-i);
		//printList(list);
	}
	pass=1;
	for(i=0;i<n;++i){
		j=*(int*)arraylist_get(list,i);
		if(j!=n-1-i) pass=0;
	}
	print(8,pass);
	arraylist_free(list);
	/*list=arraylist_init(sizeof(int),n);
	for(i=0;i<n;++i){
		arraylist_addEnd(list,(void*)&i);
	}
	otherList=arraylist_subList(list,1,n-2);
	printList(list);
	printList(otherList);
	for(i=0;i<n/2;++i){
		arraylist_swap(list,i,n-1-i);
		//printList(list);
	}
	pass=1;
	for(i=0;i<n;++i){
		j=*(int*)arraylist_get(list,i);
		if(j!=n-1-i) pass=0;
	}
	printList(list);
	printList(otherList);
	arraylist_print(list,printInt);
	arraylist_free(list);
	arraylist_free(otherList);*/
	
}
