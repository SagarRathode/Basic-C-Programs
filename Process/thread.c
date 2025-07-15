
#ifndef NUM_INCS_DFL
#  define NUM_INCS_DFL (10000000)
#endif

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct threadinfo {
	int tid;
	long loops;
};

static void helpAndLeave(const char *progname, int status);
static void thread_pexit(int err, const char *fCall);

static void *threadFunc(void *arg);

static volatile long glob = 0;

//static void createThread(int argc1,int argv1);

static void createThread(int argc1,char argv1){
	
	pthread_t t1,t2;
	int s;
	long loops;
	
	sturct  threadinfo info1, info2;

	loops = (argc1 == 2 ? strtol(argv1, NULL, 10):NUM_INCS_DFL);
	info1.loops = info2.loops = loops;

	info1.tid = 1;
	info2.tid = 2;

	s = pthread_create(&t1,NULL,threadFunc,&info1);
	if(s != 0) {
		thread_pexit(s,"pthread_create");
	}
	s = pthread_create(&t2,NULL,threadFunc,&info2);
	if(s != 0) {
		thread_pexit(s,"pthread_create");
	}

	s = pthread_join(t1,NULL);
        if(s != 0 ) {
		thread_pexit(s,"pthread_join");
	}

	s = pthread_join(t2,NULL);
	if(s !=0 ) {
		thread_pexit(s,"pthread_join");
	}
}
int main(int argc, char *argv[]) {
	printf("argc count = %d\n",argc);
	if (argc < 2) {
		helpAndLeave(argv[0], EXIT_FAILURE);
	}

	//create thread        
	//createThread(argc,argv[1]);

	 pthread_t t1, t2;
	 int s;
	 long loops;

	 struct threadinfo info1, info2;

	loops = (argc == 2 ? strtol(argv[1], NULL, 10) : NUM_INCS_DFL);
	info1.loops = info2.loops = loops;

	/* create both threads */
	info1.tid = 1;
	info2.tid = 2;
	s = pthread_create(&t1, NULL, threadFunc, &info1);
	if (s != 0) {
		thread_pexit(s, "pthread_create");
	}
	s = pthread_create(&t2, NULL, threadFunc, &info2);
	if (s != 0) {
		thread_pexit(s, "pthread_create");
	}

	/* join each of the threads */
	s = pthread_join(t1, NULL);
	
	if (s != 0) {
		thread_pexit(s, "pthread_join");
	}

	s = pthread_join(t2, NULL);

	if (s != 0) {
		thread_pexit(s, "pthread_join");
	}
	
	printf("glob = %ld\n", glob);
	exit(EXIT_SUCCESS);
}

static void *threadFunc(void *arg) {
	struct threadinfo info = *((struct threadinfo *) arg);
	int loc;
	long j;

	for (j = 0; j < info.loops; ++j) {
		loc = glob;
		loc++;
		glob = loc;
		printf("[T%d] iteration #%ld - glob = %ld\n", info.tid, j+1, glob);
	}

	return NULL;
}

static void helpAndLeave(const char *progname, int status) {
	FILE *stream = stderr;

	if (status == EXIT_SUCCESS) {
		stream = stdout;
	}

	fprintf(stream, "Usage: %s [num_its]\n", progname);
	exit(status);
}

static void thread_pexit(int err, const char *fCall) {
	fprintf(stderr, "%s: %s\n", fCall, strerror(err));
	exit(EXIT_FAILURE);
}
