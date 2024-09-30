#include<stdio.h>
#include<stdlib.h>
int main(){
	int first,second,third;
        int i,j,k;
	printf("Enter 3 Dimenssion:(first,second,third)\n");
	scanf("%d%d%d",&first,&second,&third);
	printf("your entered array is arr[%d][%d][%d]\n",first,second,third);
	
        // allocate 3D array
	int ***arr = (int***)malloc(first*sizeof(int**));
        for(i = 0;i<first;i++){
		arr[i] = (int**)malloc(second*sizeof(int*));
		for(int j=0;j<second;j++){
			arr[i][j]=(int*)malloc(third*sizeof(int));
		}
	}
	
        //accept element 
	
	for(i=0;i<first;i++){
		for(j=0;j<second;j++){
			for(k=0;k<third;k++){
				scanf("%d",&arr[i][j][k]);
			}
		}
	}

	//display element

	printf("your enter element is:\n");
	for(i=0;i<first;i++){
		for(j=0;j<second;j++){
			for(k=0;k<third;k++){
				printf("arr[%d][%d][%d]=%d\n",i,j,k,arr[i][j][k]);
			}
		}
	}
   
	//free element
	
	for(i=0;i<first;i++){
		for(j=0;j<second;j++){
			free(arr[i][j]);
		}
		free(arr[i]);
	}
        free(arr);
	return 0;
}
