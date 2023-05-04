#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char data;
	struct node* left , right;
	int balanceFactor;
}node;

typedef node* AVL;

void initAVL(AVL *tree);
void insertAVL(AVL *tree , int data);
AVL deleteAVL(AVL *tree);
void LLrotation();
void RRrotation();
void LRrotation();
void RLrotation();
int FindBalanceFactor();
void adjustAVL();
