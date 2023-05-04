#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int *arr;
	int size;
}node;

typedef node heap;

void init_heap(heap *t);
void insert_in_heap(heap *t , int data);
void delete_in_heap(heap *t);
void display_heap(heap t);

