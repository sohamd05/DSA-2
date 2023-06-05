#include<stdio.h>
#include<stdlib.h>
#include"graph.h"

int main(){
	graph g;
	initGraph(&g);
	displayGraph(g);
	BFS(g,3);
	printf("\n");
	DFS(g,3);
	return 0;
}
