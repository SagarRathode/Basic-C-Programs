
//second copycall.c 
// this demonstrates execute the above  first copy Program

#include<fcntl.h>
#include<stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv [1] ) 
{
	/* Command line argument number error checking */ 
	if ( argc != 3 )
	{
		printf("Invalid Number Of Arguments\n" ) ;
		exit(1); 
	}
	if(fork() == 0)
	{
		execl("./copy","copy",argv[1],argv[2],0);
	
	}
	wait((int*)0);
	exit(0); 
}
