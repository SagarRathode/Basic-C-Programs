/*
	Write a program which accept directory name from user and combine all contents of file from that directory into one file named as AllCombine.
*/

#include <sys/types.h> // for directory
#include <dirent.h> // for directory operation 
#include <stdio.h> // for i/o
#include <sys/stat.h>//for  file operation  
#include<string.h> // // for string operation like read buffer
#include<fcntl.h>  // create file
#include<unistd.h> // read (),write(),close()

int main(int argc, char *argv[]) 
{
	DIR *dir;
	struct dirent *entry;
	struct stat filestat;
	char name[100] = {'\0'};
	char buff[256] = {'\0'};
	int fd,fdread,retread,ret;

	typedef struct // typedef use as another name
	{
		char name[50];
		int size;
	}FILEINFO;

	FILEINFO obj;

	if(argc!= 2)
	{
		printf("Error: Not sufficient arguments\n");
		return -1;
	}

	// Open the directory
	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}

	fd = creat("AllCombine",0666);
	if(fd == -1)
	{
		printf("Unable to create file\n");
		return -1;
	}	

	while ((entry = readdir(dir)) != NULL)
	{
		// Create absolute path
      		sprintf(name,"%s/%s", argv[1],entry->d_name);
		stat(name,&filestat);

		// Check file type			
		if(S_ISREG(filestat.st_mode))
		{
			fdread = open(name,O_RDONLY);
			strcpy(obj.name,entry->d_name);
			obj.size = filestat.st_size;

			write(fd,&obj,sizeof(obj));
			while((retread = read(fdread,buff,sizeof(buff)))!=0)
			{
				write(fd,buff,retread);
                               
			}
			close(fdread);
		}	
	}

	// closedir() close the directory which is opened by opendir()
	closedir(dir);
	
	return 0;
}
