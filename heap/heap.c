#include "heap.h"

#define MAXSIZE 100

void init(Heap *h){
  *h = (Heap ) malloc(sizeof(heap));
  (*h)->size = MAXSIZE;
  (*h)->arr = (int *) malloc(sizeof(int) * (*h)->size);
  (*h)->rear = 0;
}


void printArray(Heap h){
  int i = 0;
  while(i < h->rear){
    printf("%d\t", h->arr[i++]);
  }

  printf("\n");
}

void swap(Heap *r, int i, int j){
  int temp = (*r)->arr[i];
  (*r)->arr[i] = (*r)->arr[j];
  (*r)->arr[j] = temp;
}

void insertheap(Heap *r, int k){
  heap *h = *r;

  if (h->rear == 0){
    h->arr[0] = k;
    h->rear++;
    return;
  }

  h->arr[h->rear++] = k;
  int i = h->rear-1;
  int temp;
  while(h->arr[i] > h->arr[(i-1)/2] && (i-1)/2 >= 0){
    swap(r, i, (i-1)/2);
    i = (i-1)/2;
  }

  //printArray(h);

}

int rmheap(Heap *h){
  
  if ((*h)->rear == 0){
    return -1;
  }

  Heap t = *h;
  int res = t->arr[0];

  t->arr[0] = t->arr[--t->rear];
  t->arr[t->rear] = INT_MIN;
  int i = 0;

  while((2*i + 1) < t->rear){

    if (t->arr[i] < t->arr[(2*i+1)] || t->arr[i] < t->arr[(2*i+2)] ){

      if (t->arr[(2*i)+1] < t->arr[(2*i)+2]){
        swap(h, i, (2*i)+2);
        i = 2*i+2;

      } else if (t->arr[(2*i)+1] > t->arr[2*i+2]){
        swap(h, i, (2*i)+1);
        i = 2*i +1;

      }
    }
    else{ break; }

  }
  return res;

}

void heapSortAsc(Heap *h){

  Heap temp = *h;
  int sdtep;
  int size = temp->rear;
  while(temp->rear){
    sdtep = rmheap(h);
    //printArray(temp);
    temp->arr[temp->rear] = sdtep;
  }
  temp->rear = size;
}

void heapSortDsc(Heap *h){

  int *s = (int *) malloc(sizeof(int)*(*h)->rear);

  int i = 0;
  while((*h)->rear){
    s[i++] = rmheap(h);
  }
  (*h)->arr = s;
  (*h)->rear = i;
}

