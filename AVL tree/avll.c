#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"avl.h"

void initAVL(AVL* tree){
	*tree = NULL;
	return;
}

int height(AVL tree){
	if(!tree)
		return -1;
	
	int leftHeight = height(tree -> left);
	int rightHeight = height(tree -> right);
	
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;		
}


node* FindImbalance(AVL tree){
	
	if(!tree){
		return NULL;
	}
	
	node* p = tree;
	node* imb = NULL;
	
	int flag = 0;
	
	while(p){
		p -> BF = height(p -> left) - height(p -> right);
		
		if((abs(p -> BF) > 1) && !flag){
            		imb = p;
            		flag = 1;
        	}
        	p = p -> parent;
    	}
	return 	imb;
}


void inorder(AVL t){
  	if(!t)
        	return;

    	inorder(t -> left);
    	printf("%d\n", t->data);
    	inorder(t->right);
}

void updateBalanceFactor(AVL *t){
	
   node* p = *t;

   while(p){
        p->BF = height(p -> left) - height(p -> right);
        p = p -> parent;    
   }
}

void LLRotation(AVL* t, node *A){
    	node* B = A -> left;
    	node* BR = B -> right;
    	node* AP = A -> parent;

    	B -> parent = AP;
    
    	if(!AP)
        	*t = B;
    	else{
        	if(AP -> right == A){
            		AP -> right = B;
        	}
        	else{
            		AP -> left = B;
        	}
    	}
    	A -> parent = B;
    	B -> right = A;
    	A -> left = BR;

    	if(BR)
        	BR -> parent = A;
    
    	B -> BF = 0;
    	A -> BF = 0;
    	return;
}

void RRRotation(AVL *t, node *A){

    	node* B = A -> right;
    	node* BL = B -> left;
    	node* AP = A -> parent;

    	B -> parent = AP;

    	if(!AP)
        	*t = B;
    	else{
        	if(AP -> right == A)
            		AP -> right = B;
        	else
            		AP -> left = B;
    	}

    	B -> left = A;
    	A -> parent =  B;
    	A -> right = BL;

    	if(BL)
     	   	BL -> parent = A;

    	A -> BF = 0;
    	B -> BF = 0;

    return;
}


void LRRotation(AVL *t, node *n)
{
    RRRotation(t, n->left);
    LLRotation(t, n);
    return;
}

// RL -> LL + RR
void RLRotation(AVL *t, node *n)
{
    LLRotation(t, n->right);
    RRRotation(t, n);
    return;
}


void insertToAVL(AVL *tree, int data){
	node* nn = (node*)malloc(sizeof(node));
	nn -> data = data;
	nn -> left = NULL;
	nn -> right = NULL;
	nn -> parent = NULL;
	nn -> BF = 0;
	
	if(!nn)
		return;
	
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
	
	nn -> parent = q;
	updateBalanceFactor(&(*tree));
	node* imbal = NULL;
	imbal = FindImbalance(*tree);
	
	 while(imbal){
        
        	if(nn->data < imbal->data){
            		
            		if(imbal->left){
                		
                		if(nn-> data < imbal->left->data)
                    			LLRotation(tree, imbal);
                		else
                    			LRRotation(tree, imbal);
            			}
        	}
        	else{
            
            		if(imbal->right){
                
                if(nn->data > imbal->right->data){
                    	RRRotation(tree, imbal);
                }
                else{
                    	RLRotation(tree, imbal);
                }
            }
        }

        imbal = FindImbalance(q->parent);
    }

    return; 
}

void deleteRecursive(AVL *t, int key){

    if(!(*t)){
    	printf("tree is empty");
        return;
        }

    node *p, *q;
    p = *t;

    while(p){
        if(p -> data == key)
            break;

        q = p;

        if(p -> data > key)
            p = p -> left;
        else
            p = p -> right;
    }

    if(!p)
        return;

    
    // Node has no any children means it is a leaf node
    if(!p -> left && !p -> right){
        if(p == *t){
            
            *t = NULL;
            free(p);
            return;
        }

        if(q -> right == p)
            q -> right = NULL;
        else if(q -> left == p)
            q -> left = NULL;

        adjustTree(t,q);
        free(p);
        return;
    }
    //Node has either one of children
    if(p -> left && !p -> right){
        if(p == *t){
            *t = p -> left;
            free(p);
            return;
        }

        if(q -> right == p)
            q -> right = p -> left;
        else if(q -> left == p)
            q -> left = p -> left;
        
        adjustTree(t,q);
        free(p);
        return;
    }

    if(p -> right && !p -> left){
        if(p == *t){
            *t = p -> right;
            // balanceTree(t,q);
            free(p);
            return;
        }

        if(q -> left == p)
            q -> left = p -> right;
        else if(q -> right == p)
            q -> right = p -> right;

        adjustTree(t,q);
        free(p);
        return;
    }

    // node has both childs
    node *m;

    m = p -> left;

    while(m -> right)
    {
        m = m -> right;
    }

    p -> data = m -> data;
    deleteRecursive(&(p -> left), p -> data);

    adjustTree(&(p->left), p);

    
    return;

}

void adjustTree(AVL *t, node* nn){

    updateBalanceFactor(&nn->parent);
    node * imb = NULL;
    imb = FindImbalance(nn);
        
    while(imb)
    {
        if(nn->data < imb->data)
        {
            if(imb->left)
            {
                if(nn-> data < imb->left->data)
                    LLRotation(t, imb);
                else
                    LRRotation(t, imb);
            }
        }
        else
        {
            if(imb->right)
            {
                if(nn->data > imb->right->data)
                {
                    RRRotation(t, imb);
                }
                else
                {
                    RLRotation(t, imb);
                }
            }
        }

        imb = FindImbalance(nn->parent);
    }
    
}

void destroyTree(AVL *t){
    if(!(*t))
        return;

    destroyTree(&((*t)->left));
    destroyTree(&((*t)->right));
    free(*t);
    *t = NULL;

    return;
}
