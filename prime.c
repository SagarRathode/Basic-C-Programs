#include<stdio.h>
int main(){


	int n;
	printf("Enter number:");
	scanf("%d",&n);
	int i ,isprime=1;

	if(n<=1)
	{
		isprime = 0;
	}else{

		for(i= 2 ;i*i <= n;i++)
		{
			if(n % i == 0){
				isprime = 0;
				break;
			}
		}
	}

	if(isprime){
		printf("Number is prime \n");
	}else{
		printf("Number is not  prime \n");
	}
}
