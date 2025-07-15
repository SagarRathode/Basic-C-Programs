// write a program which accept file name from user and create that file in current directory

#include<stdio.h>
#include<sys/stat.h>//for  file operation  
#include<string.h> // // for string operation like read buffer
#include<fcntl.h>  // create file
#include<errno.h>

int main(int argc,char *argv[])
{
	int fd,errorno;
        

        if(argc !=2)
	{
           printf("Error: Not sufficient arguments\n");
	   return -1;

	}
            //0666 rwr permission for user,group,other

        fd = creat(argv[1],0666);
       // printf("fd:%d\n",fd);
        if(fd == -1)
	{
		printf("Error: Unable to create file.\n");
		return -1;
	}else{
		printf("%s File Created Successfully. \n",argv[1]);
	}
       
        	// unlink() system call  use for delete file
	        // fd = unlink(argv[1]);
        	//	if(fd == -1){
                //	    printf("Error: Unable to delete file.\n");
               	//	 }
         
return 0;
}
