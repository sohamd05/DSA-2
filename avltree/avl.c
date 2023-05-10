#include"avl.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

// ##INITIALIZATION

void initAVL(AVL *tree){
	*tree = NULL;
	return;
}

// ## HELPERS 
int heightOfTree(AVL tree){

    if (!tree)
        return -1;

    return 1 + max(heightOfTree(tree->left), heightOfTree(tree->right));
}

int max(int a, int b){
    
    if (a > b){
        return a;
    }
    
    return b;
}

void FindBalanceFactor(AVL *tree){

    AVL temp = *tree;
    while (temp){
    
        temp->balanceFactor = heightOfTree(temp->left) - heightOfTree(temp->right); // Assigning balance factor to node as left height - right height
        temp = temp->parent;
    }
    return;
}


AVL FindImBalancedNode(AVL *tree){
    
    if (!tree)
        return NULL;
        
    AVL temp = *tree; 
    while (temp){
	// Imbalance = -1 , 0 , 1    
        if (temp->balanceFactor >= 2 || temp->balanceFactor <= -2){ // Traversing whole the parent ancestor tree for finding imbalanced node
            return temp;
        }
        temp = temp->parent;
    }
    return NULL;
}


// ## ROTATIONS

void LLrotation(AVL *tree , AVL *parentNd){
	AVL A = (*tree);
    	AVL B = A->left;
    	AVL BR = B->right;
    	AVL AP = A->parent;
    	B->parent = AP;
    
    	if (!AP){
        	*parentNd = B;
    	}
    	
    	else{
    	
        	if (AP->right == A){
            		AP->right = B;
        	}
        	
        	else{
            		AP->left = B;
        	}
    	}
    
    	A->parent = B;
    	B->right = A;
    	A->left = BR;
    
    	if (BR){
        	BR->parent = A;
    	}
    	
    	A->balanceFactor= 0;
    	B->balanceFactor= 0;

    	FindBalanceFactor(&A);          

    return;
}

void RRrotation(AVL *tree , AVL *parentNd){
	AVL A = (*tree);
    	AVL B = A->right;
    	AVL BR = B->right;
    	AVL AP = A->parent;
    	B->parent = AP;
    
    	if (!AP){
        	*parentNd = B;
    	}
    	
    	else{
    	
        	if (AP->right == A){
            		AP->right = B;
        	}
        	
        	else{
            		AP->left = B;
        	}
    	}
    
    	A->parent = B;
    	B->left = A;
    	A->right = BR;
    
    	if (BR){
        	BR->parent = A;
    	}
    	
    	A->balanceFactor= 0;
    	B->balanceFactor= 0;

    	FindBalanceFactor(&A);          

    return;
}




	
	




