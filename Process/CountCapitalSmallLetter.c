#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

// Function to be considered as a thread
void *ThreadProc2(void *p)
{
	int fd, ret = 0,capCnt = 0;
	char buff[256];
	
	// If file is opened in read mode we can read the contents from 0 byte offset
	fd = open("demo.txt",O_RDONLY);
	printf("File descriptor of thread 2 is %d\n",fd);
	if(fd == -1)
	{
		printf("Unable to open file \n");
		pthread_exit(NULL);
	}

	while((ret = read(fd,buff,256)) != 0)
	{
		while(ret!=0)
		{
			if(buff[ret] >='A' && buff[ret] <= 'Z')
				capCnt++;
			ret--;
		}
	}
	close(fd);
	printf("Capital characters by thread 2 is %d\n",capCnt);
	pthread_exit(NULL);
	
}

// Function to be considered as a thread
void *ThreadProc1(void *p)
{
	
	int fd, ret = 0,smCnt = 0;
	char buff[256];
	
	// If file is opened in read mode we can read the contents from 0 byte offset
	fd = open("demo.txt",O_RDONLY);
	printf("File descriptor of thread 1 is %d\n",fd);
	if(fd == -1)
	{
		printf("Unable to open file \n");
		pthread_exit(NULL);
	}


	while((ret = read(fd,buff,256)) != 0)
	{
		while(ret!=0)
		{
			if(buff[ret] >= 'a' && buff[ret] <= 'z')
				smCnt++;
			ret--;
		}
	}
	
	close(fd);
	printf("Small characters by thread 1 is %d\n",smCnt);
	pthread_exit(NULL);
}

int main()
{

	pthread_t thread1,thread2;
	int ret1, ret2 ;

        //create thread1 
	ret1 = pthread_create(	&thread1,	// Address of pthread_t structure
				NULL,	 	// thread attributes 
				ThreadProc1,	// Function name
				NULL);		// Function parameters
	if(ret1 != 0)
	{
		printf("problem in thread1 creation\n");
	}

	
//	sleep(10); // sleep for 10 second 	


	//create thread2
	ret2 = pthread_create(	&thread2,	// Address of pthread_t structure
				NULL,	 	// thread attributes 
				ThreadProc2,	// Function name
				NULL);		// Function parameters
	if(ret2 != 0)
	{
		printf("problem in thread2 creation\n");
	}
	
	// It suspend execution of calling thread till target thread terminates
	pthread_join(	thread1,		// thread id
				NULL);		// Location of thread	
	// It suspend execution of calling thread till target thread terminates
	pthread_join(	thread2,		// thread id
				NULL);		// Location of thread	
	
	pthread_exit(NULL); 	// Terminate running thread
	return 0;
}

