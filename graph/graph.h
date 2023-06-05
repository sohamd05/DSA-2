#include<stdio.h>

typedef struct graph{
	int **arr;
	int size;
}graph;

void initGraph(graph *g);
void displaygraph(graph g);
int isEmptyGraph(graph g);
void displayDegree_Of_Each_Vertex(graph g);
int checkAdjacentVertex(graph g, int a , int b);
int verifyConnectedGraph(graph g);
int displayNOofComp(graph g);	
