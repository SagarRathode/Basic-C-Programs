



#import <errno.h> 
#import <fcntl.h> 
#import <stdio.h> 
#import <stdlib.h> 
#import <string.h> 
#import <unistd.h>

// for errno and strerror()
// for open()
// for printf() and friends
// for EXIT_SUCCESS
// for strerror()
// for STDOUT_FILENO
int main (void) 
{
	close (STDOUT_FILENO);
	// open a log file, write only, and to always automatically append. 
	// oh, and create the file if it doesn't exist already
	int fd = open ("unix.txt", O_WRONLY | O_CREAT | O_APPEND,S_IRUSR | S_IWUSR); 
	if (fd == -1) 
	{
		fprintf (stderr, "can't open log file. Error %d (%s)\n", errno, strerror(errno));
		return EXIT_FAILURE; 
	}
	printf ("wheee, we have a log file open\n");
return EXIT_SUCCESS; 
}
