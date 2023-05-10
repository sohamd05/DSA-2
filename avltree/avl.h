#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char* data;
	int balanceFactor;	
	struct node* right;
	struct node* left;
	struct node* parent;
}node;

typedef node* AVL;

// Rotations 
void LLrotation();
void RRrotation();
void LRrotation();
void RLrotation();

//main code
void initAVL(AVL *tree);
void insertInAVL(AVL *tree , char data);
void deleteFromAvl(AVL *tree , char data);
void display(AVL tree);


//helpers
int heightOfTree(AVL tree);
void FindBalanceFactor(AVL *tree);
int max(int a, int b);




