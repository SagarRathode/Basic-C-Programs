#include<stdio.h>
#include<unistd.h>

int main()
{
int status;
pid_t pid;

	if(fork() == 0)  // create child process use parent process page table memory
	{
		execl("./executable2","NULL",NULL);// execute current process to new process
	}
	else
	{
		printf("Inside Process 1\n");
		pid = wait(&status); // wait for status change child process terminate
	}

	return 0;
}

