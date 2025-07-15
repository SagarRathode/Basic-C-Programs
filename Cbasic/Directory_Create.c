/*
	Write a program which accept directory name from user and create
	new directory of that name.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>
#include<dirent.h>
#include<errno.h>
#include<string.h>

void DisplayError(int errorno){
	
		switch (errorno)
		{

            		case EEXIST:
                	printf("Error: Directory already exists.\n");
                	break;

           		case EACCES:
                	printf("Error: Permission denied to create directory.\n");                		      break;

		        case ENAMETOOLONG:
                	printf("Error: The name of the directory is too long.\n");
                	break;

           		case ENOENT:
               		printf("Error: A component of the path does not exist.\n");
                	break;
            		
			default:
                	printf("Error: Failed to create directory.");
                	break;
       		 }
}

int main(int argc, char *argv[])
{
	int ret;

	if(argc != 2)
	{
		printf("Error: Not sufficient argument\n");
		return -1;
	}

	//In this case directory named as NewDirectory is created, 
	// with read/write/search permissions for owner and group, and 
	// with read/search permissions for others.

	// mkdir() system call accept two parameters first as name of the directory
	// and second is permissions for that new directory

	ret = mkdir(argv[1], S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

	if(ret == -1)
	{
      		  // Display error based on errno
        	 DisplayError(errno);
		 return -1;
	}else{
		printf("%s Directory created successfully",argv[1]);
		
	}

	return 0;
}
