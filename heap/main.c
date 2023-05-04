#include"heap.h"
#include<stdio.h>
#include<stdlib.h>


int main(){
	heap tree;
	
	init_heap(&tree);
	insert_in_heap(&tree , 10);
	insert_in_heap(&tree , 15);
	insert_in_heap(&tree , 7);
	insert_in_heap(&tree , 19);
	insert_in_heap(&tree , 14);
	insert_in_heap(&tree , 19);
	delete_in_heap(&tree);
	
	display_heap(tree);
	return 0;
}
