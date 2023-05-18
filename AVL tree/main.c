#include<stdio.h>
#include<stdlib.h>
#include"avl.h"

/*
int main(){
	AVL tree;
	initAVL(&tree);
	
	insertToAVL(&tree , 10);
	insertToAVL(&tree , 5);
	insertToAVL(&tree , 15);
	insertToAVL(&tree , 20);
	insertToAVL(&tree , 14);
	insertToAVL(&tree , 30);
	insertToAVL(&tree , 30);
	inorder(tree);
	printf("\n");
	removeNodeIterative(&tree, 5);
	inorder(tree);
	destroyTree(&tree);
	if(!tree)
		return 12345;
return 0;		
}
*/

int main(){
	AVL tree;
	initAVL(&tree);
	
	FILE *ptr;
    	ptr = fopen("data1.txt","r");
    	int data[20];
    	
    	for(int i=1;i<50;i++){
        
        	fscanf(ptr,"%d",data);
        	insertToAVL(&tree, *data);
    	}
	
	
	while(1){
	
	int response;
	printf("\nPlease enter your choices :- \n");
	printf("\n1. for insertion\n2. for deletion\n3. for destroy\n4. to print tree\n5. to exit\n ");
	scanf("%d",&response);
	
	switch(response){
		case 1 :
				int n;
				printf("Enter the number to be inserted :");
				scanf("%d",&n);
				insertToAVL(&tree , n);
				printf("Insertion succcessful\n");
				break;
			
		
		case 2:
			if(!tree){
				printf("tree is empty!");
			}
			else{
				int n;
				printf("Enter the number to be deleted :");
				scanf("%d",&n);
				deleteRecursive	(&tree , n);
				//inorder(tree);	
			}
			break;
			
		
		case 3:
			if(!tree)
				printf("tree is empty!");
			else{
				destroyTree(&tree);
				printf("tree successfully destroyed");
			}
			break;
		
		case 4:
			if(!tree)
				printf("tree is empty!");
			else{
				inorder(tree);
			}
			break;
		
		case 5:
			exit(0);
		
		default :
			printf("Invalid choice !");
			exit(0);
			break;
			
								 
	}
	}
	
	return 0;
}
/*
int main()
{
    AVL t;
    initAVL(&t);

    FILE *ptr;
    ptr = fopen("data.txt","r");

    char data[20];
    //exit(0);
    for(int i=1;i<50;i++)
    {
        fscanf(ptr,"%s",data);
        // fgets(data, 20, ptr);
        insertNodeIntoAVL(&t, data);
    }
    while(1)
    {
        printf("1 . Remove name \n");
        printf("2 . Display inorder \n");
        printf("3 . Destroy the tree \n");
        printf("4 . Exit \n");

        int c;

        scanf("%d",&c);


        switch(c)
        {
            case 1: if(!t)	
                        printf("Tree is empty !");
                    else
                    {      
                        char data1[20];
                        fscanf(stdin, "%s", data1);
                        printf("%s\n",data1);
                        //removeNodeIterative(&t, data1);
                        }
                    break;

            case 2: if(!t)
                        printf("Tree is empty !");
                    else
                        inorder(t);
                    printf("\n");
                    break;
            
            case 3: if(!t)
                        printf("Tree is empty !\n");
                    else
                        destroyTree(&t);
                    break;

            case 4: exit(0);
                    break;

            default: printf("Invalid choice\n");
        }

    }

    return 0;
}
*/
