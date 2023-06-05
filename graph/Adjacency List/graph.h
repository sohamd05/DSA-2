#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
    int weight;
    int index;
    struct NODE* next;
}NODE;

typedef NODE* list;

typedef struct Graph{
    int size;
    list* column;
}Graph;

typedef Graph graph;

void initGraph(graph *g);
void append_In_Graph(list* L,int weight, int index);
void displayGraph(graph);
void BFS(graph g,int vertex);
void DFS(graph g,int vertex);
void PrimsAlgorithm(graph ,int);
void djestra(Graph,int);
void displayList(list L);
