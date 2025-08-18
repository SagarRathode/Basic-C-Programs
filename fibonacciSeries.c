//0 1 1 2 3 5 8 13 21
//
//
//
//
#include<stdio.h>
int main()
{
	int t1=0, t2=1;
	int n=0,i;
	printf("Enter the number of terms");
	scanf("%d",&n);
	

	printf("Fibonacci series:");
	for(i=0;i<n;i++)
	{
		printf(" %d ",t1);
                int next = t1 + t2;
		t1= t2;
		t2 = next;
		
	} 
	return 0;
}

