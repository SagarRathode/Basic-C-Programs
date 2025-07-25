//********************************************** 
//$   vi longjmp.m                     
//$   gcc -g -Wall -o longjmp longjmp.m
//$   ./longjmp
// *********************************************


#import<setjmp.h>
#import<stdio.h>
#import<stdlib.h>

static jmp_buf handler;
static void doEvenMoreStuff(){
	printf("entering do even more stuff\n");
	printf("done with do even more stuff\n");
}
static void doMoreStuff(){
	printf("entering doMoreStuff\n");
	doEvenMoreStuff();
	longjmp(handler,23);
	printf("done with more stuff\n");
}
static void dostuff(){
	printf("Entering dostuff\n");
	doMoreStuff();
	printf("done with dostuff\n");
}
int main(void){
	int result;
	if((result = setjmp(handler))){
		printf("longjump failed,setjump return again:%d\n",result);
	}else{
	dostuff();
	}
	return (EXIT_SUCCESS);
}
//**********************************************
//output:-
//Entering dostuff
//entering doMoreStuff
//entering do even more stuff
//done with do even more stuff
//longjump failed,setjump return again:23 //here remove all stack frames dostuff,doMorestuff
					  //ip point to in main diretly
//**********************************************
