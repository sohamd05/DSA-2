#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
#include"stack.h"
#include"graph.h"

void initGraph(graph *g){
	FILE *fp;
	fp = fopen("data.txt","r");
    
    	if(!fp)
        	return ;

    	int size = 0;
    	fscanf(fp,"%d",&size);

    	g -> size = size;
   	printf("Size : %d\n",size);
    	
    	g -> column = (NODE**)malloc(sizeof(NODE*) * size);
    	
    	if(!(g) -> column)
        	return ;

    	for(int i = 0 ; i < size ; i++){
            	g -> column[i] = (NODE*) malloc(sizeof(NODE));
            	
            	if(!g -> column[i]){
                	free(g -> column);
                	return ;
            	}
            	g -> column[i] = NULL;
        
        	for(int j = 0 ; j < size; j++){
            		int temp ; 
            		fscanf(fp,"%d",&temp);
            		if(temp != 0)
            		append_In_Graph(&g -> column[i],temp,j);
        	}
    	}

    printf("\n");
}

void append_In_Graph(list* linkl,int weight, int index){
	
	NODE* nn = (NODE*)malloc(sizeof(NODE));
	nn -> index = index;
	nn -> weight = weight;
	nn -> next = NULL;
	
	if(!(*linkl)){
		*linkl = nn;
		return;
	}
	
	NODE* temp = *linkl;
	
	while(temp -> next){
		temp = temp -> next;
	}
	temp -> next = *linkl;
	*linkl = nn;
	
	return;
	
}
void displayGraph(graph g){
    
    for(int i = 0 ; i < g.size; i++){
        list th = (g).column[i];
        displayList(th);
        printf("\n");
    }
    printf("\n");
    
return;
}

void displayList(list L){
    
    if(!L){
        return;
    }
    
    printf("Index : %d , Weight : %d ",L -> index,L -> weight);
    displayList(L -> next);
}

void BFS(graph g,int vertex){
		
	if(vertex >= g.size || vertex < 0 || g.size == 0 ){
	        return ;
    	}
    	Queue q;
    	initQueue(&q);

    	if(!g.column){
        	return ;
    	}

    	int *visited = (int*)calloc(g.size,sizeof(int));
    
    	if(!visited)
    		return;

    	enqueue(&q,vertex);
     	visited[vertex] = 1;

    	while(!isEmpty(q)){
        	int v = dequeue(&q);
        	
        	printf("Dequeued Node : %d\n",v);
        	int i = v ;
        
        	NODE* temp = g.column[i]; 
        	
        	while(temp){
            		if(temp -> index && !visited[temp -> index]){
                		enqueue(&q,temp -> index);
                		visited[temp -> index] = 1;
            		}
            	temp = temp -> next;
               }
       }
	
	return ;
}
void DFS(graph g,int vertex){
		
	if(vertex >= g.size || vertex < 0 || g.size == 0 ){
	        return ;
    	}
    	stack s;
    	initStack(&s,50);

    	if(!g.column){
        	return ;
    	}

    	int *visited = (int*)calloc(g.size,sizeof(int));
    
    	if(!visited)
    		return;

    	push(&s,vertex);
     	visited[vertex] = 1;

    	while(!isEmptyStack(s)){
        	int v = pop(&s);
        	
        	printf("POP Node : %d\n",v);
        	int i = v ;
        
        	NODE* temp = g.column[i]; 
        	
        	while(temp){
            		if(temp -> index && !visited[temp -> index]){
                		push(&s,temp -> index);
                		visited[temp -> index] = 1;
            		}
            	temp = temp -> next;
               }
       }
	
	return ;
}
void PrimsAlgorithm(graph ,int){
	return ;
}
void djestra(Graph,int){
	return ;
}
