#include<stdio.h>
#include<stdlib.h>
#include"graph.h"

int main(){
	
	graph g;
	initGraph(&g);
	printf("\nGraph is :\n");	
	displaygraph(g);
	printf("\n");
	
	printf("\nEach vertices degree:\n");
	displayDegree_Of_Each_Vertex(g);
	
	printf("\nCheck Whether Vertexes are Adjacent or not : %d\n",checkAdjacentVertex(g, 0 ,1));
	//printf("%d\n",checkAdjacentVertex(g, 1 ,1));
	
	printf("\nIs Graph Connected : %d\n",verifyConnectedGraph(g));
	
	printf("\nNumber of Components :");
	printf("%d\n",displayNOofComp(g));
	return 0;
	
}
