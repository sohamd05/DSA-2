#include"heap.h"

#include<stdio.h>
#include<stdlib.h>

void init_heap(heap* t){
	//t = (node*)malloc(sizeof(node));
	(t)->arr = (int*)malloc(sizeof(int));
	(t)->size = 0;
	return;
}



void insert_in_heap(heap* t, int data){
	
	(t) -> size = (t) -> size + 1 ; 
	(t) -> arr = (int*)realloc((t) -> arr,sizeof(int)*(t) -> size + 1 );
	(t) -> arr[(t) -> size] = data;
	int i = (t) ->size;
	//exit(0);
	while(i > 1){
		int parent = i / 2;
		
		if((t)->arr[parent] < (t)->arr[i]){
			//swap(arr[parent] , arr[i]);
			int temp;
			temp = (t)->arr[i];
			(t)->arr[i] = (t)->arr[parent];
			(t)->arr[parent] = temp;
			
			i = parent;
		}
		else
			return;
	}
}

void delete_in_heap(heap* t){
	
	if(!t){
		return;
	}	
		
	t->arr[1] = t->arr[t->size];	
	t -> size -= 1;
	int i = 1 ;
	
	
	while (i < t -> size){
		int left = (t)->arr[2 * i];
		int right = (t)->arr[2*i + 1];
		
		int larger = left>right ? 2*i : 2*i + 1;
		
		if((t)->arr[i] < (t)->arr[larger]){
			int temp;
			temp = (t)->arr[i];
			(t)->arr[i] = (t)->arr[larger];
			(t)->arr[larger] = temp;
			
			i = larger;
		}
		else
			return;
	}
}

	
void display_heap(heap t){
for(int i = 1 ; i <= t.size; i++)
{
	printf("%d ",t.arr[i]);
	
}
}
