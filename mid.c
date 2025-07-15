#include<stdio.h>
#include<string.h>
int main()
{
	  int a[8]={1,2,3,4,5,6,7,8};
          int size = 9/2;
          printf("%d",a[size]);
	 
	// factorial
	int fact = 1;
         for(int i=1;i<=5;i++)
	 {
                fact= fact*i;
         }
         printf("fact=%d",fact);
        
	// accept string from user and display
 	 char c_Name[50] = {'\0'};
 	
 	 printf("\n Kindly enter your name\n");
 	 //scanf("%[^'\n']s",c_Name);
 	scanf("%s",c_Name);
 	printf("\nYour Name \t: %s\nName Length \t: %ld\nArray Size \t: %ld \n",c_Name,strlen(c_Name),sizeof(c_Name));  
		

}
