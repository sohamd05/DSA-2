#include<stdio.h>
#include<stdlib.h>
#define LIMIT 0
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
	
}node;

typedef node* BST;

typedef struct Bnode{
	int data;
	struct Bnode* left;
	struct Bnode* right;
}Bnode;

typedef Bnode* BT;

void initBST(BST *tree){
	*tree = NULL;
	return;
}

void initBT(BT *tree){
	*tree = NULL;
	return;
}

void insert_BST(BST *tree , int data){
	node* nn = (node*)malloc(sizeof(node));
	if(!nn){
		return;
	}
	
	nn -> data = data;
	nn -> right = NULL;
	nn -> left = NULL;
	
	node* p = *tree;
	node* q = NULL;
	
	if(!p){
		*tree = nn;
		return;
	}

	while(p){  // p != NULL
		q = p;
		
		if(p ->data == data){
			return;
		}
		
		if(p -> data < data){
			p = p -> right;
		}
		else{
			p = p -> left;	
		}
	}
	
	if(q -> data > data){
		q -> left = nn;
	}
	
	if(q -> data < data){
		q -> right = nn;
	}
	return;	 
}


int search_BST(BST tree , int key){
	if(tree == NULL){
		return 0;
	}
	
	node* p = tree; 
	
	while(p){
		if(p -> data == key){
			return 1;
		}
		
		else if(p -> data > key){
			p = p -> left;
		}
		
		else {  //  key is biggger than p -> data 
			p = p -> right;
		}	
	}
	return 0;
}

int comparisonBST(BST tree, int key){
    	int comparisons=0;
    	if(!tree){
        	return 0;
    	}
    
   	node* p = tree;
    
    	while(p){
        	if(p->data == key){
           		 //printf("Found!\n");
            		 comparisons++;
            		 break;
        	}
        	
       	 	else if(p->data < key){
            		p = p->right;
            		comparisons++;
        	}
        	else{
            		p = p->left;
            		comparisons++;
        	}
    	}
    return comparisons;
}

void display_inorder_BST(BST tree){
	if(tree == NULL){
		return;
	}
	
	display_inorder_BST(tree -> left);
	printf("%d \t",tree -> data);
	display_inorder_BST(tree -> right);
	
	return;
}

BT insertBT(Bnode *tree, int x)
{
    Bnode* temp = NULL;
    int value  = rand()%100;
    //printf("\n%d\n",value);
    //printf("here");
    if(tree == NULL){
        temp = (Bnode*)malloc(sizeof(Bnode));
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if(value % 2 == 0)
    {
        tree->left = insertBT(tree->left,x);
    }
    else if(value % 2 != 0)
    {
        tree->right = insertBT(tree->right,x);
    }
    return tree;
}


int comparisonBT(BT tree, int key, int *count, int * flag){
    	(*count)++;
    	int comparisons=0;
    	// int flag = 0;
    	
    	if(!tree){
        	return 0;
    	}
    
    	else{
        	if(tree->data == key){
        		*flag = 1;
            		comparisons++;
            		return 0;
        	}
        
        	if(*flag == 0 && tree->data > key){
            		comparisonBT(tree->left, key, count,flag);
            		comparisons++;
        	}
        
        	else if(*flag == 0 && tree->right != NULL){
            		comparisonBT(tree->right, key,count,flag);
            		comparisons++;
        	}
    	}
    return comparisons;
    
}

void display_inorder_BT(BT tree){
	if(tree == NULL){
		return;
	}
	
	display_inorder_BT(tree -> left);
	printf("%d \t",tree -> data);
	display_inorder_BT(tree -> right);
	
	return;
}


int main(){
	BST tree1;
	initBST(&tree1);
	
	BT tree2;
	initBT(&tree2);
	
    	for(int i=0; i< LIMIT; i++){
        	int nodes = rand() % 100;
        	//tree1 = 
        	insert_BST(&tree1,nodes);
        	//tree2 =
        	tree2 = insertBT(tree2,nodes);
    	}
    
    	//printf("\nBST inorder : ");
    	//display_inorder_BST(tree1);
    	printf("\n");
 
    	//printf("\nBT inorder : ");
    	//display_inorder_BT(tree2);
    	printf("\n");

    	int comparisons = 0;
    	int flag = 0;
    	int srch = rand()%100;
    	printf("%d\t",LIMIT);
    	printf("%d\t",comparisonBST(tree1,srch));
    	
    	comparisonBT(tree2,srch,&comparisons,&flag);
    	printf("%d\n",comparisons);

    return 0;
}
