

//First copy.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char buffer[2048];

void copy(int, int);

int main(int argc, char* argv[]) 
{
    int oldfd, newfd;

    if (argc != 3) 
    {
        printf("\nError: Insufficient Arguments\n");
        exit(1);
    }

    // Open source file
    oldfd = open(argv[1], O_RDONLY);
    if (oldfd == -1) 
    {
        printf("\nError: Unable to open source file");
        exit(1);
    }

    // Create destination file with rw-rw-rw- permissions (0666)
    newfd = creat(argv[2], 0666);
    if (newfd == -1) 
    {
        printf("\nError: Unable to create destination file");
        exit(1);
    }

    // Perform the file copy operation
    copy(oldfd, newfd);

    
    printf("File copied successfully!\n");
	exit(0);
    //return 0;
}

void copy(int old, int new) 
{
    int count;
    while ((count = read(old, buffer, sizeof(buffer))) > 0) 
    {
        if (write(new, buffer, count) != count) 
        {
            printf("Error: Write operation failed");
            exit(1);
        }
    }
}

