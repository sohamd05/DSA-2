#include "heap.h"

int main(){
  Heap h;
  init(&h);
  FILE *ptr;
  ptr = fopen("data.txt", "r");
  int data[50];
    	
  for(int i=1;i<50;i++){
        
      fscanf(ptr,"%d",data);
      insertheap(&h, *data);
   }
   
   
	while(1){
	
	int response;
	printf("\nPlease enter your choices :- \n");
	printf("\n1.Insert\n2. Delete\n3.Sort Descending\n4. Sort Ascending\n5. to exit\n ");
	scanf("%d",&response);
	
	switch(response){
		case 1 :
				int n;
				printf("Enter the number to be inserted :");
				scanf("%d",&n);
				insertheap(&h , n);
				printf("Insertion succcessful\n");
				break;
			
		
		case 2:
			if(!h){
				printf("heap is empty!");
			}
			else{
				rmheap(&h);
						
			}
			break;
			
		
		case 3:
			if(!h)
				printf("heap is empty!");
			else{
				printf("Descending Order :");	
  				heapSortDsc(&h);
  				printArray(h);	
			}
			break;
		
		case 4:
			if(!h)
				printf("heap is empty!");
			else{
				printf("Ascending Order :");	
  				heapSortAsc(&h);
  				printArray(h);
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

  fclose(ptr);
  return 0;
}
