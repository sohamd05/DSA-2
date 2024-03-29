#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"graph.h"
#include"queue.h"

void initGraph(graph* g){
    FILE *fp;
    fp = fopen("data.txt","r");

    if(!fp)
        return ;

    int size = 0;
    fscanf(fp,"%d",&size);
    g -> size = size;
    g -> arr =  (int**)malloc(sizeof(int*)*size);
    for(int i = 0 ; i < size ; i++){
        g -> arr[i] = (int*)malloc(sizeof(int)*size);
        for(int j = 0 ; j < size ;j++){
            fscanf(fp,"%d",&g -> arr[i][j]);
        }
    }
}

void displaygraph(graph g){
	
	if(isEmptyGraph(g)== 0){
		return;
	}
	
	for(int i = 0 ; i < g.size ; i++){
		for(int j = 0 ; j < g.size ; j++){
			printf("%d\t",g.arr[i][j]);
		}
		printf("\n");
	}
return;
}

int isEmptyGraph(graph g){
	if(g.size == 0){
		return 0;
	}
	return 1;
}


void displayDegree_Of_Each_Vertex(graph g){
	
	if(isEmptyGraph(g)== 0){
		return;
	}
	
	int count = 0;
	for(int i = 0; i<g.size;i++){
		for(int j = 0; j<g.size ; j++){
			if(g.arr[i][j] != 0)
				count++;
		}
		printf("Vertex %d : Degree %d\n", i,count);
		count = 0;
	}
	return;
}

int checkAdjacentVertex(graph g, int a , int b){
	if(isEmptyGraph(g)== 0){
		return INT_MIN;
	}
	
	if(g.arr[a][b] != 0){
		return 1;
	}
	else
		return 0;
}

int verifyConnectedGraph(graph g){
	//same logic as BFS 
	if(isEmptyGraph(g)== 0){
		return 0	;
	}
	
	int *visited = (int*)calloc(g.size,sizeof(int));
	if(!visited)
		return INT_MIN;
	
	int s = 0;
	Queue q;
	initQueue(&q);
	
	enqueue(&q , s);
	
	int ver;
		
	while(!isEmpty(q)){
		ver = dequeue(&q);
		
		for(int i = 0 ; i < g.size ; i++){
			if(g.arr[ver][i] && !visited[i]){
				enqueue(&q,i);
				visited[i] = 1;
			}
		}
	}
	
	for(int i = 0; i< g.size ; i++){
		if(!visited[i])
			return 0;
	}
	return 1;	
}


int displayNOofComp(graph g){

   int *visited = (int*)calloc(g.size,sizeof(int));
   
    if(!visited)
    return INT_MIN;

    int  n = g.size; 
    int v = 0; 
    int count = 0 ;//to count components in the graph
    int s = 0 ;

    Queue q;
    initQueue(&q);
    do{
        enqueue(&q,s);
        visited[s] = 1;
        int v;

        while(!isEmpty(q)){
            v = dequeue(&q);
            printf("%d ",v);

            for(int i = 0 ; i < n ; i++){
                    if(g.arr[v][i] && !visited[i]){
                        enqueue(&q,i);
                        visited[i] = 1;
                    }
            }
        }
        count++;

        int temp = s;
        for(int i = 0 ; i < n ; i++){
            if(visited[i] != 1){
                s = i ;
                break;
                }
        }
        if(s == temp){
            break;
        }
            
    }
    while(1);
    free(visited);
   
    return count;
}	
