/*
3
2 3
1 2 3
0 1 2 3
1 2 3
2 3
3 
*/


#include<stdio.h>
int main(){


	int i=1,j=1;

	for(i=0;i<7;i++)
	{	 
		 int number1=0;

    		 if (i<=3)
        	 {
          		number1 = 3 - i;
        	 }else
        	 {
            		number1 = i - 3;
        	 }

		 for(j=number1;j<=3;j++)
		 {
			
			printf("%d ",j);
			          		
		 }
		 printf("\n");
	}

}
