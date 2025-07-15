#include<stdio.h>
#include<stdlib.h>

char globBuff[65536]; //uninitialized data
int primes[]={2,3,5,7};// initialized data

static int square(int x)
{
  int result;              // allocated in frame square
      result = x * x;
      return result;       // return value passed via register
}

static void cube(int x)   // allocated in frame cube
{
     int result;
         result = x * x * x;
     printf("the cube of %d is:%d\n",x,result);

}
int main(int argc ,char *argv[]) // allocated in main frame 
{ 
   static int squareNumber = 5;  //initialized in data segment
   int *cubeNumber;
   int sqrResult = square(squareNumber);  // call function square
    printf("the square of %d is:%d\n ",squareNumber,sqrResult);  
    cubeNumber = malloc(4);// memory allocated in heap segment
    cube(10);
   return 0;
}
