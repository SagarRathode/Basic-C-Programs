#include<stdio.h>
#include<stdlib.h>
int main()
{
	int first,second;
	printf("Enter first,second\n");
	scanf("%d%d",&first,&second);
        	//allocate
        	int **arr = (int**)malloc(first*sizeof(int*));
            	for(int i=0;i<second;i++){	
			arr[i] = (int*)malloc(second*sizeof(int));
	    	}
           	//accept
            	printf("Enter Element\n");
            	for(int i = 0 ;i<first;i++){
			for(int j=0;j<second;j++){
	          	scanf("%d",&arr[i][j]);
			}
	    	}

           	//display
           	printf("your 2d array is:\n"); 
	   	for(int i=0;i<first;i++){
			printf("[ ");
			for(int j=0;j<second;j++){
				printf("%d ",arr[i][j]);
			}
                	printf("]");
			printf("\n");
	    	}
		// free
          	for(int i=0;i<first;i++)
	  	{
			free(arr[i]);
          	}
          	free(arr);
	return 0;
}
