#include<stdio.h>
#include<unistd.h>

int main()
{
int status;
pid_t pid;

	if(fork() == 0)
	{
		execl("./executable3","NULL",NULL);
	}
	else
	{
		printf("Inside Process 2\n");
		pid = wait(&status);
	}

	return 0;
}

