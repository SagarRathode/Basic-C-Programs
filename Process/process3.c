#include<stdio.h>
#include<unistd.h>

int main()
{
	int status;
	pid_t pid;

  	printf("inside process3\n");	
        
/*	if(vfork() == 0) // same as fork() but it not use parent process space
        {
               printf("inside vfork and executed Process4.c it own address space\n");
               execl("./executable4","NULL",NULL);
        }else{
               printf("Inside Process 3\n");
               pid = wait(&status);
        }	
*/
	return 0;
}

