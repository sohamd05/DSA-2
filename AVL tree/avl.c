#include"avl.h"
#include<stdio.h>
#include<stdlib.h>

void initAVL(AVL *tree){
	*tree == NULL;
	return;
}
void insertAVL(AVL *tree , int data){
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
AVL deleteAVL(AVL *tree);
void LLrotation();
void RRrotation();
void LRrotation();
void RLrotation();
int FindBalanceFactor();
void adjustAVL();
