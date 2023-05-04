#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
	int *arr;
	int size;
}node;

typedef node* BST;

void init_array(BST *tree){
	*tree = (node*)malloc(sizeof(node));
	(*tree) -> arr = NULL;
	(*tree) -> size = 0;
	return;
}

void insert_array_BST(BST *TREE, int key){

    BST tree = *TREE;
    
    if(tree -> size == 0){
    	tree -> arr = (int*)malloc(sizeof(int)*(tree->size + 1));
    	
    	if(!tree -> arr)
    		return;
    		
    	tree -> arr[0] = key;
    	tree -> size++;
    	return;	
    }
    
    int p = 0;
    
    while(p < tree->size && tree->arr[p] != INT_MIN){
    	if(tree->arr[p] == key)
    		return;
    		
    	if(tree->arr[p] > key)
    		p = 2 * p + 1;
    		
    	else 
    		p = 2 * p + 2;		
    }
    
    if(p < tree -> size){
    	tree -> arr[p] = key;
    	return;	
    }
    
    else{
    	tree -> arr = realloc(tree -> arr , sizeof(int)*p+1);
    	
    	if(!tree)
    		return;
    		
    	int i = tree -> size;
    	
    	while(i < p+1){
    		tree -> arr[i++] = INT_MIN;
    	}
    	tree -> size = p+1;
    	tree -> arr[p] = key;	
    }
    
    return;
    }
   
int height_array(BST tree){
	if(!tree)
		return 0;
		
	int i = tree -> size;
	int height = 0;	
	
	while(i--){
		if(tree -> arr[i] != INT_MIN){
			while(i != 0){
				height++;
				i = (i-1)/2;
			}
		}
	}
	return height;
}		 

int count_leaf_nodes(BST tree){
	if(!tree)
		return 0;
	
	int i = 0;
	int count = 0;	
	
	while(i < tree -> size){
		if(tree -> arr[i] != INT_MIN){
			if(2*i+1  >  tree -> size)
				count++;
				
			if(tree -> arr[2*i+1] == INT_MIN && tree -> arr[2*i+2] == INT_MIN)
				count++;	
		}
		i++;
	}
	return count;
}

int getLeafNodes(BST t){
    if(!t)
        return 0;
    int i = 0;
    int count = 0;
    while(i < t->size){
        if(t->arr[i] != INT_MIN){
            if(2 * i + 1 >= t->size)
                count++;
            else if(t->arr[2*i+1] == INT_MIN && t->arr[2*i+2] == INT_MIN)
                count++;
        }
        i++;
    }
    return count;
}

int isComplete_tree(BST tree){
	if(!tree)
		return 1 ;
		
	int i = 0;
	int flag = 0;
	
	while(i < tree -> size){
		if(flag && tree -> arr[i] == INT_MIN){
			return 0;
		}
		
		if(tree -> arr[i] == INT_MIN){
			flag = 1;
		}
		i++;
	}
	return 1;	
}

void level_order(BST tree){
	if(!tree)
		return;
		
	int i = 0;
	int height = height_array(tree);
	
	while(i < tree -> size){
		for(int j = i ; j < 2*i+1;j++){
			if(j >= tree->size)
				break;
			
			if(tree -> arr[j] != INT_MIN)
				printf("%d\t", tree -> arr[j]);	
			}
		i = 2*i+1;
		printf("\n");	
	}	
}

int main(){

	BST tree;
	init_array(&tree);
	insert_array_BST(&tree , 10);
	insert_array_BST(&tree , 12);
	insert_array_BST(&tree , 5);
	insert_array_BST(&tree , 11);
	insert_array_BST(&tree , 7);
	insert_array_BST(&tree , 21);
	
	for(int i = 0; i < tree->size; i++){
        if(tree->arr[i] != INT_MIN){
            	printf("%d\n", tree->arr[i]);
            }
        }
        
        printf("Height of tree is :%d\n",height_array(tree));
        printf("Leaf nodes present are : %d\n",count_leaf_nodes(tree));
        printf("Is tree complete 0 false,1 true : %d\n",isComplete_tree(tree));
	level_order(tree);
	return 0;
}
